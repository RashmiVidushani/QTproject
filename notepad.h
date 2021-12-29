#ifndef NOTEPAD_H
#define NOTEPAD_H
#include <QFile>//for working with files
#include <QFileDialog>//dialog boxes
#include <QTextStream>//for reading texts from files
#include <QMessageBox>//for user errors
#include <QtPrintSupport/QPrinter>//ability to print
#include <QtPrintSupport/QPrintDialog>//choose the printer you need to print with
#include <QMainWindow>

namespace Ui {
class NotePad;
}

class NotePad : public QMainWindow
{
    Q_OBJECT

public:
    explicit NotePad(QWidget *parent = nullptr);
    ~NotePad();

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_as_triggered();
    void on_actionPrint_triggered();
    void on_actionCut_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionExit_triggered();
private:
    Ui::NotePad *ui;
    QString currentFile="";//entered by the user
};
#endif // NOTEPAD_H
