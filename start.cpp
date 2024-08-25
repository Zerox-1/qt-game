#include "mainwindow.h"
#include "start.h"
#include "ui_start.h"

extern MainWindow * w;
extern Start * s;
Start::Start(QWidget *parent) :
    QMainWindow(parent),
    file(new FileScore),
    ui(new Ui::Start),
    table(new Table())
{
    ui->setupUi(this);
    table->setModal(true);
}

Start::~Start()
{
    delete ui;
}

void Start::Save(int score)
{
    file->SetScore(ui->lineEdit->text(),score);
}

void Start::on_pushButton_clicked()
{
    w=new MainWindow();
    s->hide();
    w->show();
    w->TimerStart();
}

void Start::on_pushButton_2_clicked()
{  
    w=new MainWindow();
    s->hide();
    file->GetScore(ui->lineEdit->text());
    w->show();
    w->TimerStart();
}

void Start::on_pushButton_3_clicked()
{
    table->show();
    table->ct();
}
