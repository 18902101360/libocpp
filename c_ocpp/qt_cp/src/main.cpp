#include "MainWindow.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName(QStringLiteral("qt_ocpp_cp"));
    QCoreApplication::setApplicationVersion(QStringLiteral("1.0"));
    QCoreApplication::setOrganizationName(QStringLiteral("c_ocpp"));

    QCommandLineParser parser;
    parser.setApplicationDescription(
        QStringLiteral("Qt 5.14 charge point: c_ocpp OCPP 1.6 and 2.0.1 over QWebSocket"));
    parser.addHelpOption();
    QCommandLineOption urlOpt(QStringList() << QStringLiteral("u") << QStringLiteral("url"),
                              QStringLiteral("CSMS base URL, without charge-point id"),
                              QStringLiteral("url"), QStringLiteral("ws://127.0.0.1:9000"));
    QCommandLineOption idOpt(QStringList() << QStringLiteral("i") << QStringLiteral("id"),
                             QStringLiteral("Charge point id (URL path)"),
                             QStringLiteral("id"), QStringLiteral("CP001"));
    QCommandLineOption vendorOpt(QStringLiteral("vendor"), QStringLiteral("chargePointVendor / vendorName"),
                                 QStringLiteral("name"), QStringLiteral("Pionix"));
    QCommandLineOption modelOpt(QStringLiteral("model"), QStringLiteral("chargePointModel / model"),
                                QStringLiteral("name"), QStringLiteral("QT-CP"));
    QCommandLineOption autoOpt(QStringLiteral("auto"),
                               QStringLiteral("Connect both versions, exit 0 after BootNotification Accepted"));
    parser.addOption(urlOpt);
    parser.addOption(idOpt);
    parser.addOption(vendorOpt);
    parser.addOption(modelOpt);
    parser.addOption(autoOpt);
    parser.process(app);

    MainWindow window;
    window.applySettings(parser.value(urlOpt), parser.value(idOpt), parser.value(vendorOpt), parser.value(modelOpt));
    const bool autoExit = parser.isSet(autoOpt);
    window.setAutoExit(autoExit);
    window.show();

    if (autoExit) {
        QTimer::singleShot(0, &window, &MainWindow::startConnect);
        QTimer::singleShot(20000, &app, []() { QCoreApplication::exit(2); });
    }

    const int rc = app.exec();
    if (autoExit && !window.autoSucceeded()) {
        return rc == 0 ? 2 : rc;
    }
    return rc;
}
