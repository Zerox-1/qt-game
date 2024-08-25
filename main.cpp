#include "mainwindow.h"
#include "start.h"

#include <QApplication>
MainWindow * w;
Start * s;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    s=new Start();
    s->show();
    return a.exec();
}
