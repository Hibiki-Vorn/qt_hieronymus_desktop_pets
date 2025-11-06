#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QIcon>
#include "mainwindow_events.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    MainWindowEvents handler;
    engine.rootContext()->setContextProperty("handler", &handler);

    engine.loadFromModule("qt_hieronymus_app", "Main");
    QList<QObject*> roots = engine.rootObjects();
    if (!roots.isEmpty()) {
        QObject *root = roots.first();
        QQuickWindow *window = qobject_cast<QQuickWindow *>(root);
        if (window) {
            window->setIcon(QIcon(":/qt/qml/qt_hieronymus_app/logo.svg"));
        }
    }

    return app.exec();
}
