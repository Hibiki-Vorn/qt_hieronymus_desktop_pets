#include <QIcon>
#include <QQmlContext>
#include <QQuickWindow>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "mainwindow_events.h"
#include "naxida_actions.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    MainWindowEvents handler;
    engine.rootContext()->setContextProperty("handler", &handler);

    NaxidaActions naxidaHandler;
    engine.rootContext()->setContextProperty("naxidaHandler", &naxidaHandler);

    engine.rootContext()->setContextProperty("appPath", QCoreApplication::applicationDirPath());

    engine.loadFromModule("qt_hieronymus_app", "Main");
    QList<QObject*> roots = engine.rootObjects();

    return app.exec();
}
