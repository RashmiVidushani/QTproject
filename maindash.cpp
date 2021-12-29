#include "maindash.h"
#include "ui_maindash.h"
#include "notepad.h"
#include "calculator.h"
#include "timer.h"
#include <QTimer>
#include <QDateTime>
#include <QFontDatabase>

MainDash::MainDash(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainDash)
{
    ui->setupUi(this);
    connect(ui->notebtn,SIGNAL(click()),this,SLOT(openNotepad()));  //slot for notepad button
    connect(ui->timerbtn,SIGNAL(click()),this,SLOT(openTimer()));   //slot for timer button
    connect(ui->calbtn,SIGNAL(click()),this,SLOT(openCalculator()));//slot for Calculator button
    //Display of main dashboard
 QTimer*timer=new QTimer(this);
 connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));    //slot for time
     timer->start();
     
     QFontDatabase::addApplicationFont(":/font/Digital Dismay.otf");
         QFont digital("Digital dismay", 55, QFont::Normal);
         ui->Digital_clock->setFont(digital);
         ui->Digital_clock->setStyleSheet("color:green");// time font and features

         QDate date=QDate::currentDate();   //get date
         QString date_text=date.toString("dd MMMM yyyy");// date format
         ui->Digital_date->setText(date_text);          //set date
          QString day_text=date.toString("dddd");       //get day
         ui->Day->setText(day_text);                    //set day
}

void MainDash::showTime(){
    QTime time= QTime:: currentTime();                  //get Time
        QString time_text=time.toString("hh : mm : ss");//time format
        ui->Digital_clock->setText(time_text);
}
MainDash::~MainDash()
{
    delete ui;
}
void MainDash::openNotepad(){
    notePad= new NotePad();
    notePad->show();
}   // method to open the notepad 

void MainDash::openTimer(){
    timer =new Timer();
    timer->show();
}   // method to open the timer

void MainDash::openCalculator(){
    calculator= new Calculator();
    calculator->show();
}   // method to open the calculator 
void MainDash::on_notebtn_clicked()
{
openNotepad();
}//methodbutton assigned


void MainDash::on_timerbtn_clicked()
{
    openTimer();
}


void MainDash::on_calbtn_clicked()
{
   openCalculator();
}

