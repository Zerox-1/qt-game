#include "Enemy.h"
#include "Health.h"
#include "mainwindow.h"
#include "start.h"
#include "ui_mainwindow.h"
#include "MyRect.h"
#include <QTimer>
#include <QGraphicsView>

extern Start * s;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)



    , ui(new Ui::MainWindow), score(new Score()), health(new Health())
  , timer(new QTimer())  , player(new MyRect())
    , player2(nullptr) // Инициализация указателя на второго игрока
{

    ui->setupUi(this);setFocusPolicy(Qt::StrongFocus);
    scene = new QGraphicsScene(this);
    connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    scene->addItem(player);
    scene->addItem(score);
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);
//    player->setFlag(QGraphicsItem::ItemIsFocusable);
//    player->setFocus();

    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setParent(ui->groupBox);
    view->setGeometry(0, 0, ui->groupBox->width(), ui->groupBox->height());
    view->show();
    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);
    player->setPos(view->width() / 2, view->height() - 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StopGame()
{
    timer->stop();
    s->show();
    s->Save(score->getScore());
    delete this;
}

void MainWindow::TimerStart()
{
    timer->start(3000);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{


    if (event->key() == Qt::Key_1 && !sec) {
        player2 = new MyRect2();
        scene->addItem(player2);
        player2->setPos(0, player->y());
        sec = true;
    }
    else if(sec){

        player2->keyPressEvent(event);
    }
    player->keyPressEvent(event);
    /*if (event->key() == Qt::Key_E || event->key() == Qt::Key_W || event->key() == Qt::Key_D || event->key() == Qt::Key_S || event->key() == Qt::Key_A) {
        player2->keyPressEvent(event); // Перенаправляем события второму игроку
    }else{ }*/// Перенаправляем события первому игроку
}
