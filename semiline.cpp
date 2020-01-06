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
  Line* l = new Line(p1, p2);
  return l->slope();
}

double SemiLine::y_intercept(){
  Line* l = new Line(p1, p2)
  return l->y_intercept();
}

SemiLine SemiLine::perpendicular(Point p3){
  Line* l = new Line(p1, p2)
  }

Line Line::parallel(Point p3){
  double a = this->slope();
  double x0 = p3.getx();
  double y0 = p3.gety();
  double x = x0 + 1;
  double y = y0 + a;
  Point pstar(x, y);
  Line par = Line(pstar, p3);
  return par;
  }

Point Line::intersection(Line B){
  double a1 = this->slope();
  double a2 = B.slope();
  double b1 = this->y_intercept();
  double b2 = B.y_intercept();
  double xstar = (b1 - b2)/(a2 - a1);
  double ystar = a1 * xstar + b1;
  Point pstar(xstar, ystar);
  return pstar;
  }
