#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQuickWidgets/QQuickWidget>

#include "clockcircle.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // All the required qml layer types should be registered here
    qmlRegisterType<clockCircle>("ClockCircle", 1, 0, "ClockCircle");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
