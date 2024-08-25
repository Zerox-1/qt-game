#ifndef MYRECT2_H
#define MYRECT2_H

#include <qgraphicsitem.h>



class MyRect2:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    MyRect2(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};

#endif // MYRECT2_H
