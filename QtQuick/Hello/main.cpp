#include <QGuiApplication>
#include <QQuickView>
#include <QQmlApplicationEngine>

#include "counter.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    // qmlRegisterType <Counter>("it.sam.counter", 1, 0, "Counter");

    QUrl url = QStringLiteral("qrc:/mvc.qml");
    QQmlApplicationEngine engine(url);
    // QQuickView view(url);
    // view.show();
    return app.exec();
}
