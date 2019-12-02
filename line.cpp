#include <iostream>
#include <cmath>

#include "line.hpp"

Line::Line()
  
double Line::slope(){
  double slope;
  double x1 = &p1.getx();
  double x2 = &p2.getx();
  double y1 = &p1.gety();
  double y2 = &p2.gety();
  slope = (y2 - y1) / (x2 - x1);
  return slope;
}

double Line::y_intercept(){
  double y_intercept;
  double a = Line.slope;
  double x1 = p1.getx();
  double y1 = p1.gety();
  y_intercept = y1 - a*x1;
  return y_intercept;
}

Line::perpendicular(Point &p3){
  double a = Line.slope;
  double b1 = Line.y_intercept();
  double x0 = &p3.getx();
  double y0 = &p3.gety();
  double b2 = y0 + (1/a)*x0 //the equation of the perpendicular line is now y = -(1/a) + b2
  double xstar;
  xstar = (b2 - b1)/(a + (1/a);
  double ystar;
  ystar = -(1/a)*xstar + b2;
  Point pstar(xstar, ystar);
  Line per(*pstar, p3);
  return per;
  }

Line::parallel(Point &p3){
  double a = Line.slope;
  double x0 = &p3.getx();
  double y0 = &p3.gety();
  double x = x0 + 1;
  double y = y0 + a;
  Point pstar(x, y);
  Line par(*pstar, p3);
  return par;
  }
  
  
