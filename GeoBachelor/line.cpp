#include <iostream>
#include <cmath>
#include <line.hpp>
#include <mainwindow.h>
#include <general_functions.h>

void Line::draw()
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    if(this->selected)
    {
        mainW->SetPen(3 , Qt::blue);
    }

    QPointF f1 = QPointF( p1.getx() , p1.gety() );
    QPointF f2 = QPointF(p2.getx() ,p2.gety() );
    mainW -> drawInfiniteLine(f1, f2);

    mainW->ResetPen();
}

void Line::translate(double dx, double dy)
{
    p1.translate(dx, dy);
    p2.translate(dx, dy);
}

bool Line::in_personal_area(double x, double y)
{
    Point norm = normal(Point(x, y));
    double d = distance(norm,Point(x, y));
    if (d <= 5)
    {
        return true;
    }
    return false;
}

void Line::zoom(double coef, double c_x, double c_y)
{
    this->p1.zoom(coef,c_x,c_y);
    this->p2.zoom(coef,c_x,c_y);
}

Line::Line(Point &p1, Point &p2) : MathObject()
{
    this->p1 = p1;
    this->p2 = p2;

    // function to make global
    std::string s("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    /*
    if (countpoints >= 26) {
        countpoints_2 = (countpoints / 26) - 1;
        this -> name = s.at( countpoints_2 % s.size() ) + s.at( countpoints % s.size() ); }
    else { this->name = s.at( countpoints % s.size() ); }
    countpoints += 1; // add 1 to the counter
    */
}


Line::Line() :MathObject()
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
     slope = pow(10,20); //something big => for vertical lines, here we deal with the case where the slope tends to be infinite
  }
  if (slope==0)
  {
      slope = pow(10,-5);
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
  double dist = distance(p3,Point(x0,a*x0+b1));

  if(dist<pow(10,-5)) //if point is on line
  {
    Point p =Point(x0-50, (50-x0)/a+y0+x0/a);
    Line l = Line(p,p3);
    return l;
  }
  else if(a != 0 && a<pow(10,5)) //normal line
  {
    double b2 = y0 + (1/a)*x0; //the equation of the perpendicular line is now y = -(1/a) + b2
    double xstar = (b2 - b1)/(a + (1/a));
    double ystar = -(1/a)*xstar + b2;;
    Point pstar = Point(xstar, ystar);
    Line per = Line(pstar, p3);
    return per;
  }
  else if (a > pow(10, 5)) //vertical line
  {
      Point pstar = Point(p1.getx(),p3.gety());
      Line l =Line(pstar,p3);
      return l;
  }
  else
  {
      Point pstar = Point(p3.getx(),p1.gety());
      Line l = Line(pstar,p3);
      return l;
  }
}

Line Line::parallel(Point p3)
{
  double a = this->slope();
  double x0 = p3.getx();
  double y0 = p3.gety();
  double x = x0 - 50;
  double y = y0 - 50*a;
  Point pstar(x, y);
  Line par = Line(pstar, p3);
  return par;
}

Point Line::intersection(Line B)
{
  double a1 = this->slope();
  double a2 = B.slope();
  double b1 = this->y_intercept();
  double b2 = B.y_intercept();
  double xstar = (b1 - b2)/(a2 - a1);
  double ystar = a1 * xstar + b1;
  Point pstar(xstar, ystar);
  return pstar;
}

Point Line::normal(Point p)
{
    Line l = perpendicular(p);
    return intersection(l);
}

std::vector<Point> Line::reflection(Point p)
{
    double m = this->slope();
    double b = this->y_intercept();
    double x = p.getx();
    double y = p.gety();
    double dist = distance(p,Point(x,m*x+b));
    std::vector<Point> refl;
    if(dist > pow(10, -5))
    {
        double u = ((1-m*m)*x+2*m*y-2*m*b)/(1+m*m);
        double v = ((m*m-1)*y+2*m*x+2*b)/(1+m*m);
        Point* help = new Point(u,v);
        refl.push_back(*help);
    }
    return refl;
}

Line::~Line()
{
    //std::cout << "Destroying Line" << std::endl;
}
