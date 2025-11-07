#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickWindow>
#include <QTimer>
#include <QQmlContext>

#include "mainwindow_events.h"
#include "naxida_actions.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    MainWindowEvents handler;
    engine.rootContext()->setContextProperty("handler", &handler);

    NaxidaActions naxidaWindow;
    engine.rootContext()->setContextProperty("naxidaWindow", &naxidaWindow);

    engine.rootContext()->setContextProperty("appPath", QCoreApplication::applicationDirPath());

    naxidaWindow.showNaxida();

    /*engine.load(QUrl(QStringLiteral("qt_hieronymus_app/Main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;*/

    return app.exec();
}
