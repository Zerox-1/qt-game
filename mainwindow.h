#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Health.h"
#include "MyRect.h"
#include "myrect2.h"
#include "Score.h"
#include "filescore.h"

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void StopGame();
    void TimerStart();

protected:
    void keyPressEvent(QKeyEvent *event) override;

public:
    Ui::MainWindow *ui;
    Score *score;
    Health *health;
    QTimer *timer;
    MyRect *player;
    MyRect2 *player2;
    QGraphicsScene *scene;
    bool sec = false; // для отслеживания создания второго игрока
};
#endif // MAINWINDOW_H
