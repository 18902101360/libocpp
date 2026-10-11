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

/* Qt 5.14 充电桩窗口：两条 QWebSocket 分别跑 c_ocpp 1.6 和 2.0.1。 */
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    void applySettings(const QString &url, const QString &cpId, const QString &vendor, const QString &model);
    void setAutoExit(bool enabled);
    bool autoSucceeded() const { return autoOk_; }
    void logLine(const QString &line);
    void noteBoot16(bool accepted);
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
    struct Tx {
        QWebSocket *socket;
        MainWindow *window;
        const char *name;
    };

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
