#include "grid.h"
#include "mainwindow.h"
#include <QResizeEvent>
#include <QWidget>
#include <QDebug>

Grid::Grid(double x, double y)
{
    this->x_p = x;
    this->y_p = y;
    this->unit = 50;
}

Grid::Grid(double x, double y, double unit)
{
    this->x_p = x;
    this->y_p = y;
    this->unit = unit;
}

Grid::Grid()
{
    this->x_p = 0;
    this->y_p = 0;
}

void Grid::draw()
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    QPen myPen1 = QPen(Qt::lightGray);
    myPen1.setWidth(0.5);

    double w = mainW->getWidth_View();
    double h = mainW->getHeight_View();

    // Add the vertical lines first
    for (int x=x_p+unit; x<=mainW->getWidth_View()+unit; x+=unit)
    {
        QPointF p1 = QPointF(mainW -> mapToMyScene(x,0));
        QPointF p2 = QPointF(mainW -> mapToMyScene(x,h));
        mainW->drawLine(p1,p2,myPen1);
    }

    // Add the vertical lines first (for x<x_p)

    for (double x = x_p-unit; x >= -1*unit ; x-=unit)
    {
        QPointF p1 = QPointF(mainW -> mapToMyScene(x,0));
        QPointF p2 = QPointF(mainW -> mapToMyScene(x,h));
        mainW->drawLine(p1,p2,myPen1);
    }

    // Now add the horizontal lines for y>=y_p
    for (double y = y_p; y< h + unit; y+=unit)
    {
        QPointF p1= QPointF(mainW -> mapToMyScene(0,y));
        QPointF p2= QPointF(mainW -> mapToMyScene(mainW->getWidth_View()+50,y));
        mainW->drawLine(p1,p2,myPen1);
    }

    // Now add the horizontal lines for y<y_p
    for (double y = y_p-unit; y>= -1*unit; y-=unit)
    {
        QPointF p1= QPointF(mainW -> mapToMyScene(0,y));
        QPointF p2= QPointF(mainW -> mapToMyScene(w,y));
        mainW->drawLine(p1,p2,myPen1);
    }

    double x = this->getX();
    double y = this->getY();

    QPointF x1 = QPointF(mainW->mapToMyScene(std::min(0.0,x_p), y));
    QPointF x2 = QPointF(mainW->mapToMyScene(std::max(w,x_p), y));
    QPointF y1 = QPointF(mainW->mapToMyScene(x, std::min(y_p,0.0)));
    QPointF y2 = QPointF(mainW->mapToMyScene(x, std::max(h,y_p)));

    QPen myPen = QPen(Qt::gray);
    myPen.setWidth(3);
    mainW->drawLine(x1,x2,myPen);
    mainW->drawLine(y1,y2,myPen);
}

double Grid::getX()
{
    return this->x_p;
}

double Grid::getY()
{
    return this->y_p;
}

void Grid::set_BackColor(QBrush b)
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    mainW -> setBackGroundColor_View(b);
}


void Grid::set_xaxis_label()
{
    MainWindow* mainW = MainWindow::getInstance();

    double w = mainW->getWidth_View();
    QPointF f = mainW->mapToMyScene(w-50,getY()+10);
    QGraphicsTextItem* text=mainW->scene->addText("X");
    text->setPos(f.x(), f.y());
 }

void Grid::set_yaxis_label(){
    MainWindow* mainW = MainWindow::getInstance();
    QPointF f = mainW->mapToMyScene(getX()-30,10);
    QGraphicsTextItem* text=mainW->scene->addText("Y");
    text->setPos(f.x(), f.y());
}

void Grid::move_grid(double dx, double dy){
    MainWindow* mainW = MainWindow::getInstance();
    this-> x_p+=dx;
    this -> y_p+=dy;
    mainW->clearScene();
    draw();
    set_xaxis_label();
    set_yaxis_label();
    obj.move_refresh(dx,dy);
}

void Grid::move_grid(QPointF to)
{
    move_grid(to.x()-x_p,to.y()-y_p);
}

void Grid::refresh_grid()
{
    move_grid(0,0);
}

void Grid::zoom(double coef)
{
    this->unit = this->unit*coef;
}
