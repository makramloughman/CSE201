#include "mainwindow.h"
#include <QApplication>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w; //defining the main window
    w.setWindowState(Qt::WindowMaximized); //set FULLSCREEN
    w.show(); //show the window
    return a.exec();
}
