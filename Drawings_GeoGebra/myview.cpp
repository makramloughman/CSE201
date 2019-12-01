#include "myview.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MyView::MyView(QWidget *parent) : QGraphicsView(parent)
{
}

void MyView::mousePressEvent(QMouseEvent *ev)
{
    MainWindow* mainW = MainWindow::getInstance();
    QPointF f = mapToScene(ev->x(),ev->y());
    QLineF topLine(mainW->scene->sceneRect().topLeft(),
                   f);
    mainW->drawLine(topLine);

}





