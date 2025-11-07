#ifndef NAXIDA_ACTIONS_H
#define NAXIDA_ACTIONS_H

#include <QIcon>
#include <QTimer>
#include <QLabel>
#include <QPixmap>
#include <QObject>
#include <QTransform>
#include <QQuickWindow>
#include <QQmlApplicationEngine>
#include <QQuickImageProvider>

class NaxidaActions : public QObject{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit NaxidaActions(QQmlApplicationEngine* eng = nullptr, QObject *parent = nullptr)
        : QObject(parent), engine(eng) {}

    Q_INVOKABLE void setNaxidaImg(QObject* Img) {
        if (!Img) return;
        Img->setProperty("source","file:/"+QCoreApplication::applicationDirPath()+"/assets/nxd.png");

    }

private:
    QQmlApplicationEngine* engine;
};

#endif // NAXIDA_ACTIONS_H
