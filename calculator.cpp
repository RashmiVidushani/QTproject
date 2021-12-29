#include "calculator.h"
#include "ui_calculator.h"
#include <QFontDatabase>
double calval=0.0;
bool divtrigger=false;
bool multrigger=false;
bool addtrigger=false;
bool subtrigger=false;

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    QFontDatabase::addApplicationFont(":/font/Digital Dismay.otf");
            QFont digital("Digital dismay", 80, QFont::Normal);
            ui->display->setFont(digital);//font type added to the display

    ui->display->setText(QString::number(calval));//show the value of calval variable
    QPushButton * numberbtn[10];//array for number buttons
    for(int i = 0; i<10;++i){
        QString butName="btn"+ QString::number(i);
        numberbtn[i]=Calculator:: findChild<QPushButton*>(butName);
        connect(numberbtn[i],SIGNAL(released()),this,SLOT(clickNumber()));//connecting the number buttons with the slots
    }
    connect(ui->btnadd,SIGNAL(released()),this,SLOT(clickMathbtn()));   //connecting the add button with the slots
    connect(ui->btnsub,SIGNAL(released()),this,SLOT(clickMathbtn()));   //connecting the substract button with the slots
    connect(ui->btnmul,SIGNAL(released()),this,SLOT(clickMathbtn()));   //connecting the multiply button with the slots
    connect(ui->btndiv,SIGNAL(released()),this,SLOT(clickMathbtn()));   //connecting the divide button with the slots
    connect(ui->equal,SIGNAL(released()),this,SLOT(clickEqualbtn()));   //connecting the equal button with the slots
    connect(ui->btnclear,SIGNAL(released()),this,SLOT(clickClearbtn()));//connecting the clear button with the slots
}

Calculator::~Calculator()
{
    delete ui;
}
//method for clicking number buttons

void Calculator::clickNumber(){
    QPushButton *btn= (QPushButton *)sender();
    QString butval=btn->text();//get number
     QString displayval=ui->display->text(); //display on display
     if((displayval.toDouble()==0)||(displayval.toDouble()==0.0)){
         ui->display->setText(butval);
     }
         else{
         QString newVal= displayval+butval;
         double dblnewval=newVal.toDouble();
         ui->display->setText(QString::number(dblnewval,'g',10));// happens after the 10th val
     }
}
void Calculator::clickMathbtn(){
    divtrigger=false;
    multrigger=false;
    addtrigger=false;
    subtrigger=false;
    QString displayval=ui->display->text();
    calval=displayval.toDouble();
    QPushButton*btn =(QPushButton *)sender();
    QString butval=btn->text();     // the operations
    if(QString :: compare(butval, "/", Qt:: CaseInsensitive)==0){
        divtrigger =true;
    }
    else if(QString :: compare(butval, "*", Qt:: CaseInsensitive)==0){
        multrigger =true;
    }
    else if(QString :: compare(butval, "+", Qt:: CaseInsensitive)==0){
        addtrigger =true;
    }
    else{
        subtrigger =true;
    }
        ui->display->setText("");
}
void Calculator::clickEqualbtn(){
    double result=0.0;
    QString displayval=ui->display->text();
    double dbldisplayval=displayval.toDouble(); // conducting the operations
    if(addtrigger||subtrigger||multrigger||divtrigger){
        if(addtrigger){
            result=calval+dbldisplayval;
        }
         else if(subtrigger){
            result=calval-dbldisplayval;
        }
        else if(multrigger){
            result=calval*dbldisplayval;
        }
         else{
            result=calval/dbldisplayval;
        }
    }
    ui->display->setText(QString::number(result));
}
void Calculator::clickClearbtn(){
    ui->display->setText("");   //clear
}


