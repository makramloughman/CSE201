# include ellipse.hpp
#include math.h

Ellipse:: Ellipse(Point f1, Point f2, double a)
{
    (*this).f1 = f1;
    (*this).f2 = f2;
    (*this).a = a;
}

Ellipse:: ~Ellipse()
{
    delete(f1);
    delete(f2);
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

Line Ellipse:: tangent(Point M)
{
  double b = get_b();
  double x0 = (getX1() + getX2()) / 2 ;
  double y0 = (getY1() + getY2()) / 2 ;
  double xm = M.getx();
  double ym = M.gety();
  double z = xm*xm / (a*a) + ym*ym / (b*b);
  if ((0.99999999 < z) && (z < 1.00000001))
  {
  	double k =  (- x0*y0 + y0*xm + x0*ym - ym*xm) / (a*a) ; 
  	double n = ym - k * xm;
  	std::cout << "There is only one tangent and it is y = " << k << " * x + " << n << std::endl;
    double xt1 = xm - 1;
    double yt1 = k * xt1 + n;
    return std::vector{Line(Point (xt1, yt1), M)}
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
    return std::vector{Line(Point (xt1, yt1), M), Line(Point(xm, yt2), M)}
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
    return std::vector{Line(Point (xt1, yt1), M), Line(Point(xt1, yt2), M)}
  }
  else
  {
  	std::cout << "Tangent does not exist" << std::endl;
  }
}

double Ellipse:: surface()
{
    double b = get_b()
    return math.pi * a * b
}

double Ellipse:: perimeter()
{
    //TO BE IMPLEMENTED
}

double Ellipse:: get_b()
{
    double c = get_c();
    return math.sqrt(a*a - c*c);
}

double Ellipse:: get_c()
{
    double x1 = getX1();
    double y1 = getY1();
    double x2 = getX2();
    double y2 = getY2();
    return math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
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
