#include "Health.h"
#include "Score.h"
#include "mainwindow.h"

#include <QFont>
extern MainWindow & w;

Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    health=3;

    setPlainText("Health: "+QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease()
{
    if(health>0){
        health--;
        setPlainText("Health: "+QString::number(health));
    }
    else{
        w.StopGame();
        health=2;
    }
}

int Health::getHealth()
{
    return health;
}
