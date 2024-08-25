#include <QKeyEvent>
#include "Bullet.h"
#include <QGraphicsScene>
#include "Enemy.h"
#include "myrect2.h"

MyRect2::MyRect2(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/player.png"));
}

void MyRect2::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A) {
        if (pos().x() > 0) {
            setPos(x() - 10, y());
        }
    }
    if (event->key() == Qt::Key_D) {
        if (pos().x() < scene()->width() - 100) {
            setPos(x() + 10, y());
        }
    }
    if (event->key() == Qt::Key_W) {
        if (pos().y() > 0) {
            setPos(x(), y() - 10);
        }
    }
    if (event->key() == Qt::Key_S) {
        if (pos().y() < scene()->height() - 100) {
            setPos(x(), y() + 10);
        }
    }
    if (event->key() == Qt::Key_E) {
        Bullet *bullet = new Bullet();
        bullet->setPos(x() + 45, y() - 50);
        scene()->addItem(bullet);
    }
}

void MyRect2::spawn()
{
    Enemy * enemy=new Enemy();
    scene()->addItem(enemy);
}
