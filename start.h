#ifndef START_H
#define START_H

#include "filescore.h"
#include "table.h"

#include <QMainWindow>

namespace Ui {
class Start;
}

class Start : public QMainWindow
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();
    FileScore * file;
    void Save(int score);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Start *ui;
    Table * table;
};

#endif // START_H
