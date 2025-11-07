#ifndef NAXIDA_ACTIONS_H
#define NAXIDA_ACTIONS_H

#include <QIcon>
#include <QTimer>
#include <QPixmap>
#include <QObject>
#include <QString>
#include <QQuickWindow>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QCoreApplication>
#include <QQuickItem>
#include <QDebug>

class NaxidaActions : public QObject {
    Q_OBJECT
    QML_ELEMENT

public:
    explicit NaxidaActions(QQmlApplicationEngine* eng = nullptr, QObject* parent = nullptr)
        : QObject(parent)
    {
        // ✅ 如果没传 engine，就自己创建一个
        if (eng) {
            engine = eng;
            ownEngine = false;
        } else {
            engine = new QQmlApplicationEngine(this);
            ownEngine = true;
        }

        engine->rootContext()->setContextProperty("naxidaHandler", this);
        engine->rootContext()->setContextProperty("appPath", QCoreApplication::applicationDirPath());

        // ✅ 创建 QML 组件
        QQmlComponent comp(engine, QUrl(QStringLiteral("qt_hieronymus_app/Naxida.qml")));
        if (comp.status() != QQmlComponent::Ready) {
            qWarning() << "❌ Naxida.qml 加载失败:" << comp.errorString();
            return;
        }

        QObject* obj = comp.create(engine->rootContext());
        if (!obj) {
            qWarning() << "❌ 创建 Naxida 窗口失败";
            return;
        }

        // ✅ 转换为 QQuickWindow
        NaxidaContainer = qobject_cast<QQuickWindow*>(obj);
        if (!NaxidaContainer) {
            qWarning() << "❌ Naxida.qml 不是一个 QQuickWindow";
            delete obj;
            return;
        }

        QQuickItem* item = qobject_cast<QQuickItem*>(obj);
        if (item) {
            QPointF globalPos = item->mapToGlobal(QPointF(0,0));
            qDebug() << "global pos:" << globalPos;
        }


        NaxidaContainer->setFlags(Qt::FramelessWindowHint);
        NaxidaContainer->setColor(Qt::transparent);
        NaxidaContainer->setTitle("Naxida");

        // ✅ 获取 Image 元素
        Naxida = NaxidaContainer->findChild<QObject*>("naxida_image");
        setNaxidaSwing(0);
        if (!Naxida)
            qWarning() << "⚠️ 没找到 objectName 为 'naxida_image' 的对象";

        connect(NaxidaContainer, &QQuickWindow::xChanged, this, [this]() {
            qDebug() << "window moved to x=" << NaxidaContainer->x();
        });
        connect(NaxidaContainer, &QQuickWindow::yChanged, this, [this]() {
            qDebug() << "window moved to y=" << NaxidaContainer->y();
        });

        // 定时器轮询窗口位置
        QTimer* timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, [this]() {
            if (NaxidaContainer)// 使用 QWindow::geometry() 获取屏幕位置
                qDebug() << "window global pos:" << NaxidaContainer->geometry().topLeft();

        });
        timer->start(30); // 每 30ms 输出一次


    }

    ~NaxidaActions() override {
        // ✅ 仅在自己 new 的情况下释放
        if (ownEngine && engine) {
            delete engine;
            engine = nullptr;
        }
    }

    Q_INVOKABLE void showNaxida() {
        if (!NaxidaContainer) return;
        NaxidaContainer->show();
    }

    Q_INVOKABLE void hideNaxida() {
        if (NaxidaContainer)
            NaxidaContainer->hide();
    }

    Q_INVOKABLE void setNaxidaSwing(short frame) {
        if (!Naxida) return;
        if (frame < 0 || frame > 32) return;

        QString path = QString("file://%1/assets/naxida_swing/qing_%2.png")
                           .arg(QCoreApplication::applicationDirPath())
                           .arg(frame);

        Naxida->setProperty("source", path);
        frame = (frame + 1) % 33;
        QTimer::singleShot(10, [this, frame]() { setNaxidaSwing(frame); });
    }

    Q_INVOKABLE void reportPos(qreal x, qreal y) {
        qDebug() << "window moved to:" << x << y;
    }

    Q_INVOKABLE void setPos(qreal x, qreal y) {
        NaxidaContainer->setPosition(x,y);
    }


private:
    QQmlApplicationEngine* engine = nullptr;
    bool ownEngine = false;  // ✅ 标记是否自己 new 的
    QObject* Naxida = nullptr;
    QQuickWindow* NaxidaContainer = nullptr;
};

#endif // NAXIDA_ACTIONS_H
