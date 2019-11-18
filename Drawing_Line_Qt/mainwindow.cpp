#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter q(this); //Like a form in C#
    q.setFont(QFont("Times", 16, QFont::Bold));
    q.drawText(QPoint(50,50),"The first text");
    q.drawLine(50,50,100,100);
}
