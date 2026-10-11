/*
 * 充电桩窗口。一条 QWebSocket 对一个 c_ocpp session。
 * 套接字和软件定时器表都不是线程安全的，收发留在 GUI 线程。
 */
#ifndef QT_OCPP_MAINWINDOW_H
#define QT_OCPP_MAINWINDOW_H

#include "ocpp16.h"
#include "ocpp201.h"

#include <QMainWindow>
#include <QWebSocket>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPlainTextEdit;
class QTimer;

/**
 * MainWindow - OCPP 1.6 与 2.0.1 各一条 WebSocket
 *
 * 桩号是 URL 路径，不是 HTTP Basic 用户。这个测试平台给未登记的路径回 404。
 */
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    void applySettings(const QString &url, const QString &cpId, const QString &vendor, const QString &model);
    void setAutoExit(bool enabled);
    bool autoSucceeded() const { return autoOk_; }
    void logLine(const QString &line);
    /**
     * noteBoot16 - 记录 1.6 Boot 是否被接受
     * @accepted: status 为 Accepted 时为真。Pending 也是合法应答，但不能当作已批准。
     */
    void noteBoot16(bool accepted);
    /** 同 noteBoot16，对应 2.0.1。 */
    void noteBoot201(bool accepted);

public slots:
    void startConnect();

private slots:
    void onDisconnect();
    void onSendStatus();
    void onTick();
    void on16Connected();
    void on16Disconnected();
    void on16Text(const QString &message);
    void on16Error(QAbstractSocket::SocketError error);
    void on201Connected();
    void on201Disconnected();
    void on201Text(const QString &message);
    void on201Error(QAbstractSocket::SocketError error);

private:
    /**
     * Tx - ocpp_link_t.send 的 user 指针
     *
     * 链接里只能存一个 void *。套接字和窗口都要，所以包在一起。
     * 对象必须活过 session，send 回调会在心跳定时器里被调用。
     */
    struct Tx {
        QWebSocket *socket;
        MainWindow *window;
        const char *name;
    };

    /**
     * sendThunk - c_ocpp 的发送回调
     * @data: 一帧已经编好的 OCPP JSON
     * @len: 字节数，不含额外的结尾 NUL
     * @user: Tx *
     *
     * 返回 0 表示交给了 QWebSocket。非 0 会被 session 记成 OCPP_ERR_IO。
     * 必须是不捕获的函数：ocpp_port_send_fn 是 C 函数指针。
     */
    static int sendThunk(const void *data, size_t len, void *user);

    void openLink(QWebSocket &sock, const QString &subprotocol);
    void sendBoot16();
    void sendBoot201();
    void sendStatus16();
    void sendStatus201();
    void finishAutoIfReady();
    QString chargePointUrl() const;
    void setLinkStatus(QLabel *label, const QString &text);

    QLineEdit *urlEdit_;
    QLineEdit *idEdit_;
    QLineEdit *vendorEdit_;
    QLineEdit *modelEdit_;
    QCheckBox *use16_;
    QCheckBox *use201_;
    QLabel *status16_;
    QLabel *status201_;
    QPlainTextEdit *log_;
    QTimer *tick_;

    QWebSocket sock16_;
    QWebSocket sock201_;
    Tx tx16_;
    Tx tx201_;
    ocpp16_session_t sess16_;
    ocpp201_session_t sess201_;
    bool sess16Ready_;
    bool sess201Ready_;
    bool boot16Ok_;
    bool boot201Ok_;
    bool autoExit_;
    bool autoOk_;
};

#endif
