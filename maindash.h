#ifndef MAINDASH_H
#define MAINDASH_H
#include "notepad.h"
#include "calculator.h"
#include "timer.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainDash; }
QT_END_NAMESPACE

class MainDash : public QMainWindow
{
    Q_OBJECT

public:
    MainDash(QWidget *parent = nullptr);
    ~MainDash();

public slots:
    void openNotepad();
    void openTimer();
    void openCalculator();

private slots:
    void on_notebtn_clicked();
    void on_timerbtn_clicked();
    void showTime();
    void on_calbtn_clicked();

private:
    Ui::MainDash *ui;
    NotePad*notePad;
    Timer*timer;
    Calculator* calculator;
};
#endif // MAINDASH_H
