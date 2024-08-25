#ifndef FILESCORE_H
#define FILESCORE_H

#include <QString>



class FileScore
{
public:
    FileScore();
    void GetScore(QString name);
    void SetScore(QString name,int score);
};

#endif // FILESCORE_H
