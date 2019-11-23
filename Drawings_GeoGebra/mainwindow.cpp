#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::showMaximized(); //FullScreen mode of the window

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) //Seting the rectangle where all the drawings are gonna happen
{
     QPainter setup_rectangle(this);
     QSize s = this -> size();
     int width = 600; // width of our rectangle
     int height = 400; // height of our rectangle
     int left = s.width()/2-width/2; //left corner
     int top = s.height()/2-height/2;

     setup_rectangle.setPen(Qt::black); //black frame of the rectangle
     QBrush brush(Qt::white); //initialy, white rectangle

     QRect r(QPoint(left, top), QSize(width, height));
     setup_rectangle.fillRect(r, brush);
     setup_rectangle.drawRect(r);
}

