#include "mainwindow.h"
#include <QApplication>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("GeoBachelor");
    w.show();

    return a.exec();
}
