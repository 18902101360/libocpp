#include "MainWindow.h"

#include <QAbstractSocket>
#include <QCheckBox>
#include <QCoreApplication>
#include <QDateTime>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QNetworkRequest>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QTimer>
#include <QUrl>
#include <QVBoxLayout>

#include <cstring>

extern "C" {
static void on_boot16(const ocpp16_boot_notification_conf_t *conf, void *user) {
    auto *w = static_cast<MainWindow *>(user);
    w->logLine(QStringLiteral("1.6 BootNotification.conf status=%1 interval=%2s time=%3")
                   .arg(QString::fromUtf8(conf->status))
                   .arg(conf->interval)
                   .arg(QString::fromUtf8(conf->currentTime)));
    w->noteBoot16(std::strcmp(conf->status, "Accepted") == 0);
}
static void on_heartbeat16(const ocpp16_heartbeat_conf_t *conf, void *user) {
    static_cast<MainWindow *>(user)->logLine(
        QStringLiteral("1.6 Heartbeat.conf currentTime=%1").arg(QString::fromUtf8(conf->currentTime)));
}
static void on_status16(const ocpp16_status_notification_conf_t *, void *user) {
    static_cast<MainWindow *>(user)->logLine(QStringLiteral("1.6 StatusNotification.conf"));
}
static int on_reset16(const ocpp16_reset_req_t *req, ocpp16_reset_conf_t *conf, void *user) {
    ocpp_str_copy(conf->status, sizeof(conf->status), "Accepted");
    static_cast<MainWindow *>(user)->logLine(
        QStringLiteral("1.6 Reset.req type=%1 -> Accepted").arg(QString::fromUtf8(req->type)));
    return 0;
}
static void on_boot201(const ocpp201_boot_notification_conf_t *conf, void *user) {
    auto *w = static_cast<MainWindow *>(user);
    w->logLine(QStringLiteral("2.0.1 BootNotification.conf status=%1 interval=%2s time=%3")
                   .arg(QString::fromUtf8(conf->status))
                   .arg(conf->interval)
                   .arg(QString::fromUtf8(conf->currentTime)));
    w->noteBoot201(std::strcmp(conf->status, "Accepted") == 0);
}
static void on_heartbeat201(const ocpp201_heartbeat_conf_t *conf, void *user) {
    static_cast<MainWindow *>(user)->logLine(
        QStringLiteral("2.0.1 Heartbeat.conf currentTime=%1").arg(QString::fromUtf8(conf->currentTime)));
}
static void on_status201(const ocpp201_status_notification_conf_t *, void *user) {
    static_cast<MainWindow *>(user)->logLine(QStringLiteral("2.0.1 StatusNotification.conf"));
}
static int on_reset201(const ocpp201_reset_req_t *req, ocpp201_reset_conf_t *conf, void *user) {
    ocpp_str_copy(conf->status, sizeof(conf->status), "Accepted");
    static_cast<MainWindow *>(user)->logLine(
        QStringLiteral("2.0.1 Reset.req type=%1 -> Accepted").arg(QString::fromUtf8(req->type)));
    return 0;
}
}

namespace {

void fill16Handlers(ocpp16_handlers_t *h, MainWindow *window) {
    std::memset(h, 0, sizeof(*h));
    h->user = window;
    h->boot_notification_conf = on_boot16;
    h->heartbeat_conf = on_heartbeat16;
    h->status_notification_conf = on_status16;
    h->reset_req = on_reset16;
}

void fill201Handlers(ocpp201_handlers_t *h, MainWindow *window) {
    std::memset(h, 0, sizeof(*h));
    h->user = window;
    h->boot_notification_conf = on_boot201;
    h->heartbeat_conf = on_heartbeat201;
    h->status_notification_conf = on_status201;
    h->reset_req = on_reset201;
}

}  // namespace

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      urlEdit_(nullptr),
      idEdit_(nullptr),
      vendorEdit_(nullptr),
      modelEdit_(nullptr),
      use16_(nullptr),
      use201_(nullptr),
      status16_(nullptr),
      status201_(nullptr),
      log_(nullptr),
      tick_(nullptr),
      sock16_(QString(), QWebSocketProtocol::VersionLatest, this),
      sock201_(QString(), QWebSocketProtocol::VersionLatest, this),
      sess16Ready_(false),
      sess201Ready_(false),
      boot16Ok_(false),
      boot201Ok_(false),
      autoExit_(false),
      autoOk_(false) {
    tx16_.socket = &sock16_;
    tx16_.window = this;
    tx16_.name = "1.6";
    tx201_.socket = &sock201_;
    tx201_.window = this;
    tx201_.name = "2.0.1";
    memset(&sess16_, 0, sizeof(sess16_));
    memset(&sess201_, 0, sizeof(sess201_));

    ocpp_port_init();

    auto *central = new QWidget(this);
    auto *form = new QFormLayout();
    urlEdit_ = new QLineEdit(QStringLiteral("ws://127.0.0.1:9000"), central);
    idEdit_ = new QLineEdit(QStringLiteral("CP001"), central);
    vendorEdit_ = new QLineEdit(QStringLiteral("Pionix"), central);
    modelEdit_ = new QLineEdit(QStringLiteral("QT-CP"), central);
    use16_ = new QCheckBox(QStringLiteral("连接 OCPP 1.6（子协议 ocpp1.6）"), central);
    use201_ = new QCheckBox(QStringLiteral("连接 OCPP 2.0.1（子协议 ocpp2.0.1）"), central);
    use16_->setChecked(true);
    use201_->setChecked(true);
    status16_ = new QLabel(QStringLiteral("未连接"), central);
    status201_ = new QLabel(QStringLiteral("未连接"), central);
    form->addRow(QStringLiteral("CSMS 地址"), urlEdit_);
    form->addRow(QStringLiteral("桩号"), idEdit_);
    form->addRow(QStringLiteral("厂商"), vendorEdit_);
    form->addRow(QStringLiteral("型号"), modelEdit_);
    form->addRow(use16_);
    form->addRow(QStringLiteral("1.6 状态"), status16_);
    form->addRow(use201_);
    form->addRow(QStringLiteral("2.0.1 状态"), status201_);

    auto *buttons = new QHBoxLayout();
    auto *connectBtn = new QPushButton(QStringLiteral("连接并 Boot"), central);
    auto *disconnectBtn = new QPushButton(QStringLiteral("断开"), central);
    auto *statusBtn = new QPushButton(QStringLiteral("上报 StatusNotification"), central);
    buttons->addWidget(connectBtn);
    buttons->addWidget(disconnectBtn);
    buttons->addWidget(statusBtn);

    log_ = new QPlainTextEdit(central);
    log_->setReadOnly(true);
    log_->setPlaceholderText(QStringLiteral("收发的 OCPP JSON 显示在这里"));

    auto *layout = new QVBoxLayout(central);
    layout->addLayout(form);
    layout->addLayout(buttons);
    layout->addWidget(log_, 1);
    setCentralWidget(central);
    setWindowTitle(QStringLiteral("c_ocpp 充电桩 — Qt 5.14 WebSocket（OCPP 1.6 / 2.0.1）"));
    resize(860, 640);

    connect(connectBtn, &QPushButton::clicked, this, &MainWindow::startConnect);
    connect(disconnectBtn, &QPushButton::clicked, this, &MainWindow::onDisconnect);
    connect(statusBtn, &QPushButton::clicked, this, &MainWindow::onSendStatus);

    connect(&sock16_, &QWebSocket::connected, this, &MainWindow::on16Connected);
    connect(&sock16_, &QWebSocket::disconnected, this, &MainWindow::on16Disconnected);
    connect(&sock16_, &QWebSocket::textMessageReceived, this, &MainWindow::on16Text);
    connect(&sock16_, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error), this, &MainWindow::on16Error);

    connect(&sock201_, &QWebSocket::connected, this, &MainWindow::on201Connected);
    connect(&sock201_, &QWebSocket::disconnected, this, &MainWindow::on201Disconnected);
    connect(&sock201_, &QWebSocket::textMessageReceived, this, &MainWindow::on201Text);
    connect(&sock201_, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error), this, &MainWindow::on201Error);

    tick_ = new QTimer(this);
    connect(tick_, &QTimer::timeout, this, &MainWindow::onTick);
    tick_->start(100);

    logLine(QStringLiteral("协议栈是 c_ocpp（OCPP 1.6 与 2.0.1）。本窗口只提供 QWebSocket。"));
    logLine(QStringLiteral("仓库里没有 OCPP 1.2。1.6 用子协议 ocpp1.6，2.0.1 用 ocpp2.0.1。"));
}

void MainWindow::applySettings(const QString &url, const QString &cpId, const QString &vendor, const QString &model) {
    if (!url.isEmpty()) {
        urlEdit_->setText(url);
    }
    if (!cpId.isEmpty()) {
        idEdit_->setText(cpId);
    }
    if (!vendor.isEmpty()) {
        vendorEdit_->setText(vendor);
    }
    if (!model.isEmpty()) {
        modelEdit_->setText(model);
    }
}

void MainWindow::setAutoExit(bool enabled) {
    autoExit_ = enabled;
}

void MainWindow::logLine(const QString &line) {
    const QString stamp = QDateTime::currentDateTime().toString(QStringLiteral("hh:mm:ss.zzz"));
    log_->appendPlainText(stamp + QStringLiteral("  ") + line);
}

void MainWindow::setLinkStatus(QLabel *label, const QString &text) {
    label->setText(text);
}

QString MainWindow::chargePointUrl() const {
    QString base = urlEdit_->text().trimmed();
    while (base.endsWith(QLatin1Char('/'))) {
        base.chop(1);
    }
    QUrl url(base);
    const QString id = idEdit_->text().trimmed();
    url.setPath(QStringLiteral("/") + id);
    return url.toString();
}

int MainWindow::sendThunk(const void *data, size_t len, void *user) {
    auto *tx = static_cast<Tx *>(user);
    if (tx == nullptr || tx->socket == nullptr || tx->socket->state() != QAbstractSocket::ConnectedState) {
        return -1;
    }
    const QString text = QString::fromUtf8(static_cast<const char *>(data), static_cast<int>(len));
    if (tx->socket->sendTextMessage(text) < 0) {
        return -1;
    }
    tx->window->logLine(QStringLiteral("%1 TX %2").arg(QString::fromUtf8(tx->name), text));
    return 0;
}

void MainWindow::openLink(QWebSocket &sock, const QString &subprotocol) {
    if (sock.state() != QAbstractSocket::UnconnectedState) {
        sock.abort();
    }
    const QUrl url(chargePointUrl());
    QNetworkRequest request(url);
    request.setRawHeader("Sec-WebSocket-Protocol", subprotocol.toUtf8());
    logLine(QStringLiteral("打开 %1  子协议 %2").arg(request.url().toString(), subprotocol));
    sock.open(request);
}

void MainWindow::startConnect() {
    boot16Ok_ = false;
    boot201Ok_ = false;
    autoOk_ = false;
    const bool want16 = use16_->isChecked();
    const bool want201 = use201_->isChecked();
    if (!want16 && !want201) {
        logLine(QStringLiteral("至少勾选一个 OCPP 版本"));
        if (autoExit_) {
            QCoreApplication::exit(1);
        }
        return;
    }
    if (want16) {
        setLinkStatus(status16_, QStringLiteral("正在连接"));
        openLink(sock16_, QStringLiteral("ocpp1.6"));
    } else {
        setLinkStatus(status16_, QStringLiteral("未启用"));
    }
    if (want201) {
        setLinkStatus(status201_, QStringLiteral("正在连接"));
        openLink(sock201_, QStringLiteral("ocpp2.0.1"));
    } else {
        setLinkStatus(status201_, QStringLiteral("未启用"));
    }
}

void MainWindow::onDisconnect() {
    sock16_.close();
    sock201_.close();
    ocpp_port_timer_stop(0);
    ocpp_port_timer_stop(1);
    sess16Ready_ = false;
    sess201Ready_ = false;
    setLinkStatus(status16_, QStringLiteral("已断开"));
    setLinkStatus(status201_, QStringLiteral("已断开"));
    logLine(QStringLiteral("已断开两条连接"));
}

void MainWindow::onTick() {
    ocpp_port_timer_tick(100);
}

void MainWindow::sendBoot16() {
    ocpp16_boot_notification_req_t boot;
    ocpp16_boot_notification_req_example(&boot);
    const QByteArray vendor = vendorEdit_->text().toUtf8();
    const QByteArray model = modelEdit_->text().toUtf8();
    ocpp_str_copy(boot.chargePointVendor, sizeof(boot.chargePointVendor), vendor.constData());
    ocpp_str_copy(boot.chargePointModel, sizeof(boot.chargePointModel), model.constData());
    const ocpp_err_t rc = ocpp16_session_send_boot_notification(&sess16_, &boot);
    if (rc != OCPP_OK) {
        logLine(QStringLiteral("1.6 发送 BootNotification 失败 rc=%1").arg(static_cast<int>(rc)));
    }
}

void MainWindow::sendBoot201() {
    ocpp201_boot_notification_req_t boot;
    ocpp201_boot_notification_req_example(&boot);
    const QByteArray vendor = vendorEdit_->text().toUtf8();
    const QByteArray model = modelEdit_->text().toUtf8();
    ocpp_str_copy(boot.chargingStation.vendorName, sizeof(boot.chargingStation.vendorName), vendor.constData());
    ocpp_str_copy(boot.chargingStation.model, sizeof(boot.chargingStation.model), model.constData());
    const ocpp_err_t rc = ocpp201_session_send_boot_notification(&sess201_, &boot);
    if (rc != OCPP_OK) {
        logLine(QStringLiteral("2.0.1 发送 BootNotification 失败 rc=%1").arg(static_cast<int>(rc)));
    }
}

void MainWindow::sendStatus16() {
    if (!sess16Ready_) {
        return;
    }
    ocpp16_status_notification_req_t req;
    ocpp16_status_notification_req_example(&req);
    const ocpp_err_t rc = ocpp16_session_send_status_notification(&sess16_, &req);
    if (rc != OCPP_OK) {
        logLine(QStringLiteral("1.6 StatusNotification 发送失败 rc=%1").arg(static_cast<int>(rc)));
    }
}

void MainWindow::sendStatus201() {
    if (!sess201Ready_) {
        return;
    }
    ocpp201_status_notification_req_t req;
    ocpp201_status_notification_req_example(&req);
    const ocpp_err_t rc = ocpp201_session_send_status_notification(&sess201_, &req);
    if (rc != OCPP_OK) {
        logLine(QStringLiteral("2.0.1 StatusNotification 发送失败 rc=%1").arg(static_cast<int>(rc)));
    }
}

void MainWindow::onSendStatus() {
    sendStatus16();
    sendStatus201();
}

void MainWindow::on16Connected() {
    ocpp16_handlers_t handlers;
    fill16Handlers(&handlers, this);
    ocpp_link_t link;
    ocpp_link_init(&link, 0, &MainWindow::sendThunk, &tx16_, 0, 1);
    ocpp16_session_init(&sess16_, &handlers, &link);
    sess16Ready_ = true;
    setLinkStatus(status16_, QStringLiteral("已连接，发送 Boot"));
    logLine(QStringLiteral("1.6 WebSocket 已连接"));
    sendBoot16();
}

void MainWindow::on201Connected() {
    ocpp201_handlers_t handlers;
    fill201Handlers(&handlers, this);
    ocpp_link_t link;
    ocpp_link_init(&link, 1, &MainWindow::sendThunk, &tx201_, 1, 1);
    ocpp201_session_init(&sess201_, &handlers, &link);
    sess201Ready_ = true;
    setLinkStatus(status201_, QStringLiteral("已连接，发送 Boot"));
    logLine(QStringLiteral("2.0.1 WebSocket 已连接"));
    sendBoot201();
}

void MainWindow::on16Disconnected() {
    ocpp_port_timer_stop(0);
    sess16Ready_ = false;
    setLinkStatus(status16_, QStringLiteral("已断开"));
    logLine(QStringLiteral("1.6 WebSocket 已断开"));
}

void MainWindow::on201Disconnected() {
    ocpp_port_timer_stop(1);
    sess201Ready_ = false;
    setLinkStatus(status201_, QStringLiteral("已断开"));
    logLine(QStringLiteral("2.0.1 WebSocket 已断开"));
}

void MainWindow::on16Text(const QString &message) {
    logLine(QStringLiteral("1.6 RX %1").arg(message));
    if (!sess16Ready_) {
        return;
    }
    const QByteArray bytes = message.toUtf8();
    const ocpp_err_t rc = ocpp16_session_rx(&sess16_, bytes.constData(), static_cast<size_t>(bytes.size()));
    if (rc != OCPP_OK) {
        logLine(QStringLiteral("1.6 session_rx 失败 rc=%1").arg(static_cast<int>(rc)));
    }
}

void MainWindow::on201Text(const QString &message) {
    logLine(QStringLiteral("2.0.1 RX %1").arg(message));
    if (!sess201Ready_) {
        return;
    }
    const QByteArray bytes = message.toUtf8();
    const ocpp_err_t rc = ocpp201_session_rx(&sess201_, bytes.constData(), static_cast<size_t>(bytes.size()));
    if (rc != OCPP_OK) {
        logLine(QStringLiteral("2.0.1 session_rx 失败 rc=%1").arg(static_cast<int>(rc)));
    }
}

void MainWindow::on16Error(QAbstractSocket::SocketError error) {
    logLine(QStringLiteral("1.6 socket 错误 %1 %2").arg(static_cast<int>(error)).arg(sock16_.errorString()));
    setLinkStatus(status16_, QStringLiteral("错误"));
    if (autoExit_) {
        QCoreApplication::exit(1);
    }
}

void MainWindow::on201Error(QAbstractSocket::SocketError error) {
    logLine(QStringLiteral("2.0.1 socket 错误 %1 %2").arg(static_cast<int>(error)).arg(sock201_.errorString()));
    setLinkStatus(status201_, QStringLiteral("错误"));
    if (autoExit_) {
        QCoreApplication::exit(1);
    }
}

void MainWindow::noteBoot16(bool accepted) {
    boot16Ok_ = accepted;
    setLinkStatus(status16_, accepted ? QStringLiteral("Boot Accepted") : QStringLiteral("Boot 未接受"));
    finishAutoIfReady();
}

void MainWindow::noteBoot201(bool accepted) {
    boot201Ok_ = accepted;
    setLinkStatus(status201_, accepted ? QStringLiteral("Boot Accepted") : QStringLiteral("Boot 未接受"));
    finishAutoIfReady();
}

void MainWindow::finishAutoIfReady() {
    if (!autoExit_ || autoOk_) {
        return;
    }
    const bool need16 = use16_->isChecked();
    const bool need201 = use201_->isChecked();
    if ((need16 && !boot16Ok_) || (need201 && !boot201Ok_)) {
        return;
    }
    autoOk_ = true;
    logLine(QStringLiteral("BootNotification 已接受，自动退出"));
    QTimer::singleShot(0, qApp, []() { QCoreApplication::exit(0); });
}
