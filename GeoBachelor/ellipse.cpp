#pragma once
#include <ellipse.hpp>
#include <math.h>
#include <iostream>
#include <vector>
#include <mainwindow.h>
#include <general_functions.h>

void Ellipse::draw() // TO BE IMPLEMENTED
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    if(this->selected)
    {
        mainW->SetPen(3 , Qt::blue);
    }

    double rx = a;
    double ry = get_b();
    Point* cen = new Point((f1.getx()+f2.getx())/2,(f1.gety()+f2.gety())/2);
    mainW-> drawEllipse(*cen,rx,ry);
    mainW->ResetPen();

}


void Ellipse::translate(double dx, double dy){

    f1.translate(dx,dy);
    f2.translate(dx,dy);
}

bool Ellipse::in_personal_area(double x, double y) //TO BE IMPLEMENTED
{
    Point* cen = new Point((f1.getx()+f2.getx())/2.0000001,(f1.gety()+f2.gety())/2.0000001);
    double b = get_b();
    double y1 = b*b*(1-pow(x-cen->getx(),2)/(a*a))+cen->gety();
    double y2 = -b*b*(1-pow(x-cen->getx(),2)/(a*a))+cen->gety();

    if (1<0.2)
    {
        return true;
    }
    return false;
}

void Ellipse::zoom(double coef, double c_x, double c_y)
{
    a*=coef;
    f1.zoom(coef,c_x,c_y);
    f2.zoom(coef,c_x,c_y);
}


Ellipse:: Ellipse(Point *f1, Point *f2, double a)
{
    (*this).f1 = *f1;
    (*this).f2 = *f2;
    (*this).a = a;
}

Ellipse:: ~Ellipse()
{
   std::cout << "Deleting an ellipse with focal points f1 = ( "<< getX1() << ", "<< getY1() <<" ) and f2 = (" << getX2() << ", "<< getY2() <<" )"<< std::endl;
}

Point Ellipse:: getF1()
{
    return f1;
}

Point Ellipse:: getF2()
{
    return f2;
}

double Ellipse:: getX1()
{
    return f1.getx();
}

double Ellipse:: getY1()
{
    return f1.gety();
}

double Ellipse:: getX2()
{
    return f2.getx();
}

double Ellipse:: getY2()
{
    return f2.gety();
}

std::vector<Line> Ellipse:: tangent(Point M)
{
  std::vector<Line> l;
  double b = get_b();
  double x0 = (getX1() + getX2()) / 2 ;
  double y0 = (getY1() + getY2()) / 2 ;
  double xm = M.getx();
  double ym = M.gety();
  double z = xm*xm / (a*a) + ym*ym / (b*b);
  if ((0.999 < z) && (z < 1.001))
  {
  	double k =  (- x0*y0 + y0*xm + x0*ym - ym*xm) / (a*a) ; 
  	double n = ym - k * xm;
  	std::cout << "There is only one tangent and it is y = " << k << " * x + " << n << std::endl;
    double xt1 = xm - 1;
    double yt1 = k * xt1 + n;
    Point p1 = Point(xt1, yt1);
    Line l1 = Line(p1,M);
    l.push_back(l1);
  }
  else if (((a == x0 - xm) || (a == xm - x0)) && (x0 - xm) * (y0 - ym) != 0)
  {
  	double k = (y0 * y0 - b *b - 2 * y0 * ym + ym * ym) / (2 * (y0 - ym) * (x0 - xm));
  	double n = ym - k * xm;
  	std::cout << "There are two tangents: " << std::endl;
	std::cout << "y = " << k << " * x + " << n << std::endl;
	std::cout << "x = " << xm << std::endl;
    double xt1 = xm - 1;
    double yt1 = k * xt1 + n; 
    double yt2 = ym + 1;
    Point p1 = Point(xt1, yt1);
    Point p2 = Point(xt1, yt2);
    Line l1 = Line(p1,M);
    Line l2 = Line(p2,M);
    l.push_back(l1);
    l.push_back(l2);
  }
  else if(a * a - x0 * x0 + 2 * x0 * xm - xm * xm != 0)
  {
    double k1 = (sqrt(-a*a*b*b + a*a*y0*y0 - 2*a*a*y0*ym + a*a*ym*ym + b*b*x0*x0 - 2*b*b*x0*xm + b*b*xm*xm) - x0*y0 + y0*xm + x0*ym - ym*xm) / (a*a - x0*x0 + 2*x0*xm - xm*xm);
    double k2 = (-sqrt(-a*a*b*b + a*a*y0*y0 - 2*a*a*y0*ym + a*a*ym*ym + b*b*x0*x0 - 2*b*b*x0*xm + b*b*xm*xm) - x0*y0 + y0*xm + x0*ym - ym*xm) / (a*a - x0*x0 + 2*x0*xm - xm*xm);
    
    
    double n1 = ym - k1 * xm;
    double n2 = ym - k2 * xm;
  	std::cout << "There are two tangents: " << std::endl;
	std::cout << " y = " << k1 << " * x + " << n1 << std::endl;
    std::cout << " y = " << k2 << " * x + " << n2 << std::endl; 
    double xt1 = xm - 1;
    double yt1 = k1 * xt1 + n1; 
    double yt2 = k2 * xt1 + n2;
    Point p1 = Point(xt1, yt1);
    Point p2 = Point(xt1, yt2);
    Line l1 = Line(p1,M);
    Line l2 = Line(p2,M);
    l.push_back(l1);
    l.push_back(l2);
  }
  else
  {
  	std::cout << "Tangent does not exist" << std::endl;
  }
    return l;
}

double Ellipse:: surface()
{
    double b = get_b();
    return M_PI * a * b;
}

double Ellipse:: perimeter()
{
    int i = 0;
    int n = 100; // can be changed in order to change precision of the integral
    double s = 0, theta;
    double e = get_e();
    for (i; i < n; i++)
    {
        theta = theta + i*M_PI/(2*n);
        s += sqrt(1 - e*e*sin(theta)*sin(theta)) * M_PI / (2 * n);
    }
    return 4 * a * s;
}

double Ellipse:: get_b()
{
    double c = get_c();
    return sqrt(a*a - c*c);
}

double Ellipse:: get_c()
{
    double x1 = getX1();
    double y1 = getY1();
    double x2 = getX2();
    double y2 = getY2();
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double Ellipse:: get_e()
{
    double c = get_c();
    return c/a;
}

Line Ellipse:: majoraxis()
{
   return Line(f1, f2);
}

Line Ellipse:: minoraxis()
{
    return majoraxis().perpendicular(Point(    (getX1()+getX2())/2  , (getY2() + getY1())/2  ));
}
