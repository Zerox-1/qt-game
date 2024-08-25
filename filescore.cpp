#include "filescore.h"
#include "mainwindow.h"

#include <QFile>
#include <QTextStream>
extern MainWindow * w;
FileScore::FileScore()
{

}

void FileScore::GetScore(QString name)
{
    QFile inputFile("D:/Users/Zerox/Documents/QT/game/Score.txt");
    QByteArray data;
    if (inputFile.open(QIODevice::ReadOnly))
    {
       data = inputFile.readAll();
       QStringList a=QString(data).split(",",QString::SkipEmptyParts);
       for(int i=0;i<a.size();i++){
           if(a[i].split(",",QString::SkipEmptyParts)[0]==name){
               w->score->setScore(a[i].split(":",QString::SkipEmptyParts)[1].toInt());
               break;
           }
       }
       inputFile.close();
    }
}

void FileScore::SetScore(QString name,int score)
{
    QFile file("D:/Users/Zerox/Documents/QT/game/Score.txt");
    QByteArray data;
    QStringList a;bool tr=false;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return ;
    }
    QTextStream *in= new QTextStream(&file);
    in->setCodec("ANSI");
    while (!in->atEnd()) {
        QString line = in->readAll();
        a=line.split(",",QString::SkipEmptyParts);
    }
    file.close();
    for(int i=0;i<a.size();i++){
        if(a[i].split(",",QString::SkipEmptyParts)[0]==name){
            a[i]=name+":"+QString::number(score);
            tr=true;
            break;
        }
    }
    if(!tr){
        a.append(name+":"+QString::number(score));
    }
    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream *out = new QTextStream(&file);
        QString e;
        for(int i=0;i<a.size();i++){
            e+=a[i]+",";
        }
        *out<<e;
        file.close();
        return;
    }
}
