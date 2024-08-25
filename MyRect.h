#ifndef MYRECT_H
#define MYRECT_H


#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QGraphicsScene>

class MyRect:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    MyRect(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    bool sec;
public slots:
    void spawn();
};

#endif // MYRECT_H
