#pragma once
#include "hyperbola.hpp"
#include <math.h>

Hyperbola:: Hyperbola(Point v1, Point v2, double b)
{
    (*this).v1 = v1;
    (*this).v2 = v2;
    (*this).b = b;
}

Hyperbola:: ~Hyperbola()
{
    std::cout << "Deleting a hyperbola with vertex points v1 = ( "<< getX1() << ", "<< getY1() <<" ) and v2 = (" << getX2() << ", "<< getY2() <<" )"<< std::endl;
}

Point Hyperbola:: getV1()
{
    return v1;
}

Point Hyperbola:: getV2()
{
    return v2;
}

double Hyperbola:: getX1()
{
    return v1.getx();
}

double Hyperbola:: getY1()
{
    return v1.gety();
}

double Hyperbola:: getX2()
{
    return v2.getx();
}

double Hyperbola:: getY2()
{
    return v2.gety();
}

Line Hyperbola:: tangent(Point M)
{
    //TO BE IMPLEMENTED
}

Point Hyperbola:: focus1()
{
	double x1 = getX1();
	double x2 = getX2();
	double y1 = getY1();
	double y2 = getY2();
	double a = sqrt(pow((x2-x1),2) + pow((y1-y2),2))/2;
	double c = sqrt(a*a + b*b);
	double k = (y2-y1)/(x2-x1);
	double n = y1 - (k * x1);
	double x01 = (-sqrt(a*a*k*k + a*a -2*a*c*k*k - 2*a*c + c*c*k*k + c*c -k*k*x1*x1 - 2*k*n*x1 + 2*y1*n*k - n*n + 2*n*y1 - y1*y1) - k*n + k*y1 + x1 ) / (1 + k*k);
	double x02 = (sqrt(a*a*k*k + a*a -2*a*c*k*k - 2*a*c + c*c*k*k + c*c -k*k*x1*x1 - 2*k*n*x1 + 2*y1*n*k - n*n + 2*n*y1 - y1*y1) - k*n + k*y1 + x1 ) / (1 + k*k);
	double y01 = k * x01 + n;
	double y02 = k * x02 + n;
	
	if (sqrt(pow((x01-x2),2) + pow((y01-y2),2)) > sqrt(pow((x02-x2),2) + pow((y02-y2),2)))
	{
		std::cout << "first focus is ( " << x01 << ", " << y01 << " )" << std::endl;
        return Point(x01, y01);
	}
	else
	{
		std::cout << "first focus is ( " << x02 << ", " << y02 << " )" << std::endl;
        return Point(x02, y02);
	}
	
}

Point Hyperbola:: focus2()
{
    double x1 = getX1();
    double x2 = getX2();
    double y1 = getY1();
    double y2 = getY2();
    double a = sqrt(pow((x2-x1),2) + pow((y1-y2),2))/2;
    double c = sqrt(a*a + b*b);
    double k = (y2-y1)/(x2-x1);
    double n = y1 - (k * x1);
    double x01 = (-sqrt(a*a*k*k + a*a -2*a*c*k*k - 2*a*c + c*c*k*k + c*c -k*k*x2*x2 - 2*k*n*x2 + 2*y2*n*k - n*n + 2*n*y2 - y2*y2) - k*n + k*y2 + x2 ) / (1 + k*k);
    double x02 = (sqrt(a*a*k*k + a*a -2*a*c*k*k - 2*a*c + c*c*k*k + c*c -k*k*x2*x2 - 2*k*n*x2 + 2*y2*n*k - n*n + 2*n*y2 - y2*y2) - k*n + k*y2 + x2 ) / (1 + k*k);
    double y01 = k * x01 + n;
    double y02 = k * x02 + n;
	
    if (sqrt(pow((x01-x1),2) + pow((y01-y1),2)) > sqrt(pow((x02-x1),2) + pow((y02-y1),2)))
	{
	    std::cout << "first focus is ( " << x01 << ", " << y01 << " )" << std::endl;
            return Point(x01, y01);
	}
    else
	{
	    std::cout << "first focus is ( " << x02 << ", " << y02 << " )" << std::endl;
            return Point(x02, y02);
	}
}

Point Hyperbola:: center()
{
    return Point((getX1() + getX2())/2, (getY1() + getY2())/2 );
}

double Hyperbola:: get_a()
{
    double x1 = getX1();
    double y1 = getY1();
    double x2 = getX2();
    double y2 = getY2();
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double Hyperbola:: get_c()
{
    double a = get_a();
    return sqrt(a * a + b * b);
}

double Hyperbola:: get_e()
{
    double a = get_a();
    return sqrt(1 + b*b/(a*a));
}

Line Hyperbola:: majoraxis()
{
    return Line(v1, v2);
}

Line Hyperbola:: minoraxis()
{
    return majoraxis().perpendicular(Point((getX1() + getX2())/2, (getY1() + getY2())/2));
}

std::vector<Line> Hyperbola:: asymptotes()
{
    std::vector<Line> l;
    double a = get_a();
    double k1 = b/a; 
    double k2 = -b/a;
    Point c = center();
    double xc = c.getx();
    double yc = c.gety();
    double n1 = yc - k1 * xc;
    double n2 = yc - k2 * xc;
    double x1 = xc - 1;
    double y1 = k1 * x1 + n1;
    double x2 = xc - 1;
    double y2 = k2 * x2 + n2;
    Line l1 = Line(Point(x1,y1), Point(xc,yc));
    Line l2 = Line(Point(x2,y2), Point(xc,yc));
    l.push_back(l1);
    l.push_back(l2);
    return l;
}
