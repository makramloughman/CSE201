#include <iostream>
#include <cmath>
#include <line.hpp>
#include <mainwindow.h>

void SemiLine::draw()
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    QPointF f1 = mainW->mapFromGridToScene(p1.getx(),p1.gety());
    QPointF f2 = mainW->mapFromGridToScene(p2.getx(),p2.gety());
    mainW -> drawInfiniteLine(f1,f2); //Remark: We save data in Grid coordinates, so we need conversion
}

void SemiLine::translate(double xx, double yy)
{
    p1.setx(p1.getx()+xx);
    p1.sety(p1.gety()+yy);
    p2.setx(p2.getx()+xx);
    p2.sety(p2.gety()+yy);

}

SemiLine::SemiLine(Point p1, Point p2)
{
    this->p1 = p1;
    this->p2 = p2;
}
 
double SemiLine::slope(){
  double slope;
  double x1 = p1.getx();
  double x2 = p2.getx();
  double y1 = p1.gety();
  double y2 = p2.gety();
  slope = (y2 - y1) / (x2 - x1);
  return slope;
}
