#include "maindash.h"
#include <QApplication>

int main(int argc, char *argv[])
//where all execution is beginned
{
    QApplication a(argc, argv);
    //QApplication function create the application object for us
    MainDash w;
    w.show();
    //display the main application
    return a.exec();
    //put the application into a loop
}
