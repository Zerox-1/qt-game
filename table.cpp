#include "table.h"
#include "ui_table.h"

#include <QApplication>
#include <QListWidget>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QVBoxLayout>
#include <QDebug>

#include <qfile.h>
#include <qtextcodec.h>

Table::Table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);;
}

Table::~Table()
{
    delete ui;
}

void Table::ct()
{
    ui->listWidget->clear();
    QFile file("D:/Users/Zerox/Documents/QT/game/Score.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Не удалось открыть файл";
            return ;
        }
    QTextStream *in= new QTextStream(&file);
    in->setCodec("ANSI");
    QStringList a;
    while (!in->atEnd()) {
        QString line = in->readAll();
        a=line.split(",",QString::SkipEmptyParts);
    }
    for (int i=0;i<a.size();i++) {
        ui->listWidget->addItem(a[i]);
    }

        file.close();
}
