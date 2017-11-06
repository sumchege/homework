#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQuickWidgets/QQuickWidget>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include "clockcircle.h"
#include "levelgauge.h"
#include "qchannel_serial.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // All the required qml layer types should be registered here
    qmlRegisterType<QChannel_Serial>("QChannelSerial", 1, 0, "QChannelSerial");
//    qmlRegisterType<clockCircle>("ClockCircle", 1, 0, "ClockCircle");
//    qmlRegisterType<LevelGauge>("LevelGauge", 1,0, "LevelGauge");

    QList<QSerialPortInfo> pil = QSerialPortInfo::availablePorts();
    QStringList psl = QStringList();
    for(int i = 0; 1<pil.size(); i++)
    {
        qDebug() << pil[i].portName();
    }

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/QSerial.qml")));

    return app.exec();
}
