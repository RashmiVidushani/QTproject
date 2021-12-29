#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:
    void clickNumber();// for clicking numbers
    void clickMathbtn();// for operation buttons
    void clickEqualbtn();// for equal button
    void clickClearbtn();//for clear
};

#endif // CALCULATOR_H
