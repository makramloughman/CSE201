#include <iostream>
#include <cmath>
#include <line.hpp>
#include <mainwindow.h>


void Line::draw()
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    QPointF f1 = QPointF(p1.getx(),p1.gety());
    QPointF f2 = QPointF(p2.getx(),p2.gety());
    mainW -> drawInfiniteLine(f1,f2);
}

void Line::translate(double dx, double dy)
{
    p1.translate(dx,dy);
    p2.translate(dx,dy);
}

Line::Line(Point &p1, Point &p2)
{
    this->p1 = p1;
    this->p2 = p2;
    
    // function to make global
    std::string s("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if (countpoints >= 26) {
        countpoints_2 = (countpoints / 26) - 1;
        this -> name = s.at( countpoints_2 % s.size() ) + s.at( countpoints % s.size() ); }
    else { this->name = s.at( countpoints % s.size() ); }
    countpoints += 1; // add 1 to the counter
}


Line::Line()
{
    this->p1 = Point();
    this->p2 = Point();
}
  
double Line::slope(){
  double slope = 0;
  double x1 = p1.getx();
  double x2 = p2.getx();
  double y1 = p1.gety();
  double y2 = p2.gety();
  if (x1!=x2)
  {
     slope = (y2 - y1) / (x2 - x1);
  }
  else
  {
     slope = pow(10,20); //something big => for vertical lines
  }

  return slope;
}

double Line::y_intercept(){
  double y_intercept;
  double a = this->slope();
  double x1 = p1.getx();
  double y1 = p1.gety();
  y_intercept = y1 - a*x1;
  return y_intercept;
}

Line Line::perpendicular(Point p3){
  double a = this->slope();
  double b1 = this->y_intercept();
  double x0 = p3.getx();
  double y0 = p3.gety();
  double b2 = y0 + (1/a)*x0; //the equation of the perpendicular line is now y = -(1/a) + b2
  double xstar = (b2 - b1)/(a + (1/a));
  double ystar = -(1/a)*xstar + b2;;
  Point pstar = Point(xstar, ystar);
  Line per = Line(pstar, p3);
  return per;
  }

Line Line::parallel(Point p3)
{
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

Line::~Line()
{
    std::cout << "Destroying Line" << std::endl;
}
