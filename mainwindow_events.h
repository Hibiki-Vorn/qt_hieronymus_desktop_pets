#ifndef MAINWINDOW_EVENTS_H
#define MAINWINDOW_EVENTS_H

#include <QIcon>
#include <QTimer>
#include <QLabel>
#include <QPixmap>
#include <QObject>
#include <QTransform>
#include <QQmlContext>
#include <QQuickWindow>
#include <QQmlComponent>
#include <QGuiApplication>
#include <QQuickImageProvider>
#include <QQmlApplicationEngine>

#include "naxida_actions.h"

class MainWindowEvents : public QObject{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit MainWindowEvents(QQmlApplicationEngine* eng = nullptr, QObject *parent = nullptr)
        : QObject(parent), engine(eng) {}

    Q_INVOKABLE void setWindowTranparent(QQuickWindow* Window) {
        if (!Window) return;
        Window->setFlags(Qt::FramelessWindowHint);
        Window->setColor(Qt::transparent);
    }

    Q_INVOKABLE void setWindowIcon(QQuickWindow* Window, QString Icon) {
        if (Window) {
            Window->setIcon(QIcon(Icon));
        }
    }

    Q_INVOKABLE void RotateImage(QObject* img) {
        if (!img) return;

        QVariant angleVar = img->property("currentAngle");
        if (!angleVar.isValid() || !angleVar.canConvert<int>()) return;

        int angle = angleVar.toInt();
        angle += 1;

        img->setProperty("currentAngle", angle);
    }

    Q_INVOKABLE void startRotateImage(QObject* img) {
        if (!img) return;
        QVariant shouldRotate = img->property("shouldRotate");
        if (!shouldRotate.isValid() || !shouldRotate.canConvert<bool>()) return;
        if (shouldRotate.toBool()) {
            RotateImage(img);
            QTimer::singleShot(10, [this, img](){ startRotateImage(img); });
        }
    }

    Q_INVOKABLE void disableWindowMaximum(QQuickWindow* window) {
        if (!window) return;
        window->setFlags(window->flags() & ~Qt::WindowMaximizeButtonHint);
    }

    Q_INVOKABLE QPoint getWindowPos(QQuickWindow* window) {
        return window->position();
    }

private:
    QQmlApplicationEngine* engine;
};

#endif // MAINWINDOW_EVENTS_H
