#include "notepad.h"
#include "ui_notepad.h"

NotePad::NotePad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NotePad)
{
    ui->setupUi(this);
}

NotePad::~NotePad()
{
    delete ui;
}

void NotePad::on_actionNew_triggered()
{
    currentFile.clear();
       //when we create a file what we need, we have to clear the originally created file with our application
       ui->textEdit->setText(QString());
               //creation of a new file

}


void NotePad::on_actionOpen_triggered()
{
    QString filename=QFileDialog::getOpenFileName((this),"open the file");
        //dialog box decide which file the user need to open or work with
        QFile file(filename);
        //object for reading and writing files
        currentFile=filename;
        //store the file name
        if(!file.open(QIODevice::ReadOnly| QFile::Text)){
            //open file as read only else a error message
            QMessageBox::warning(this,"warning","cannot open file:"+file.errorString());
            //showing the error and message
            return;
        }

        setWindowTitle(filename);
        QTextStream in(&file);
        //interface for reading text
        QString text=in.readAll();
        //capy text in string
        ui->textEdit->setText(text);
        //show text in text widget screen
        file.close();
        //close file
}


void NotePad::on_actionSave_as_triggered()
{
    QString filename=QFileDialog::getSaveFileName(this,"save as");
       QFile file(filename);
       if(!file.open(QFile::WriteOnly| QFile::Text)){
           //write only text
           QMessageBox::warning(this,"warning", "cannot save file:"+ file.errorString());
           //error msg
           return;
       }
       currentFile=filename;
       setWindowTitle(filename);
       QTextStream out(&file);
       QString text=ui->textEdit->toPlainText();
       out<<text;
       file.close();
}


void NotePad::on_actionPrint_triggered()
{
    QPrinter printer;
        //to print use qprinter. alows to interact with any printer
        printer.setPrinterName("printer name");
        //can actually put the printer name here
        QPrintDialog pdialog(&printer,this);
        if(pdialog.exec()==QDialog::Rejected){
            //verify whether it was able to access to the printer
            QMessageBox::warning(this,"warning","cannot access printer");
            //error message
            return;
        }
        ui->textEdit->print(&printer);
}


void NotePad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void NotePad::on_actionCopy_triggered()
{
     ui->textEdit->copy();
}


void NotePad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void NotePad::on_actionUndo_triggered()
{
        ui->textEdit->undo();
}


void NotePad::on_actionRedo_triggered()
{
         ui->textEdit->redo();
}


void NotePad::on_actionExit_triggered()
{
    QApplication::quit();
}

