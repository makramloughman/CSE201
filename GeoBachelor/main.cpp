#include "mainwindow.h"
#include <QApplication>
#include<stdlib.h>
#include<stdio.h>
#include<fparser.hh>

int main(int argc, char *argv[])
{

    /*FunctionParser fp;
    fp.Parse("sqrt(x*x + y*y)", "x,y");
    double variables[2] = { 1, 1 };
    double result = fp.Eval(variables);
    std::cout<<result<<std::endl;*/

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.setWindowTitle("GeoBachelor");
    w.show();

    return a.exec();
}
