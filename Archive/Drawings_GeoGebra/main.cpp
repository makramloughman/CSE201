#include <mainwindow.h>
#include <QApplication>
#include <QtGui>
#include <grid.h>
#include <myview.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w; //defining the main window
    w.setWindowState(Qt::WindowMaximized); //set FULLSCREEN
    w.show(); //show the window

    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    Grid* g = new Grid(-50,300);
    mainW->drawCoordinateSystem(*g);

    return a.exec();
}
