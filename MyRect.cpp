#include <QKeyEvent>
#include "Bullet.h"
#include <QGraphicsScene>
#include "Enemy.h"
#include "MyRect.h"
#include "mainwindow.h"
#include "myrect2.h"

extern MainWindow * w;
MyRect::MyRect(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/player.png"));
    sec=false;
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_J) {
        if (pos().x() > 0) {
            setPos(x() - 10, y());
        }
    }
    if (event->key() == Qt::Key_L) {
        if (pos().x() < scene()->width() - 100) {
            setPos(x() + 10, y());
        }
    }
    if (event->key() == Qt::Key_I) {
        if (pos().y() > 0) {
            setPos(x(), y() - 10);
        }
    }
    if (event->key() == Qt::Key_K) {
        if (pos().y() < scene()->height() - 100) {
            setPos(x(), y() + 10);
        }
    }
    if (event->key() == Qt::Key_O) {
        Bullet *bullet = new Bullet();
        bullet->setPos(x() + 45, y() - 50);
        scene()->addItem(bullet);
    }
}

void MyRect::spawn()
{
    Enemy * enemy=new Enemy();
    scene()->addItem(enemy);
}
