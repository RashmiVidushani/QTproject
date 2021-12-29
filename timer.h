#ifndef TIMER_H
#define TIMER_H
#include <QDialog>
#include <QTimer>
#include <QMainWindow>

namespace Ui {
class Timer;
}

class Timer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Timer(QWidget *parent = nullptr);
    ~Timer();

private slots:
    void on_StartTimer_clicked();
    void on_PauseTimer_clicked();
    void on_StopTimer_clicked();
    void process();

private:
    Ui::Timer *ui;
    short int minutes;
    short int seconds;
    bool pause;
    QTimer reload;

};

#endif // TIMER_H
