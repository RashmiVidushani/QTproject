#include "timer.h"
#include "ui_timer.h"
#include <QFontDatabase>

Timer::Timer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Timer)
{
    ui->setupUi(this);
    QFontDatabase::addApplicationFont(":/font/Digital Dismay.otf");
            QFont digital("Digital dismay", 80, QFont::Normal);
            ui->minutes->setFont(digital);
            ui->minutes->setStyleSheet("color:blue");
            ui->seconds->setFont(digital);
            ui->seconds->setStyleSheet("color:green");
        seconds=0;
        minutes=0;
        pause=false;
        connect(&reload,SIGNAL(timeout()),this,SLOT(process()));
}

Timer::~Timer()
{
    delete ui;
}

void Timer::on_StartTimer_clicked()
{
    reload.start(1000);
}


void Timer::on_PauseTimer_clicked()
{
    if(pause==false){
           reload.stop();
           pause=true;

       }
       else{
           pause=false;
           reload.start(1000);
       }
}


void Timer::on_StopTimer_clicked()
{
    minutes=0;
       seconds=0;
       pause=false;
       ui->minutes->setText(QString ::number (minutes));
       ui->seconds->setText(QString ::number (seconds));
       reload.stop();
}

void Timer:: process(){
    seconds=seconds+1;
        if(seconds==60){
            seconds=0;
            minutes=1;
        }
        else{
            ui->seconds->setText(QString ::number (seconds));
            ui->minutes->setText(QString ::number (minutes));
        }
}

