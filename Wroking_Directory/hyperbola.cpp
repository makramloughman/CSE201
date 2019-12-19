#include hyperbola.hpp
#include math.h

Hyperbola:: Hyperbola(Point v1, Point v2, double b)
{
    (*this).v1 = v1;
    (*this).v2 = v2;
    (*this).b = b;
}

Hyperbola:: ~Hyperbola()
{
    delete(v1);
    delete(v2);
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
    //TO BE IMPLEMENTED
}

double Hyperbola:: get_a()
{
    double x1 = getX1();
    double y1 = getY1();
    double x2 = getX2();
    double y2 = getY2();
    return math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double Hyperbola:: get_c()
{
    double a = get_a();
    return math.sqrt(a * a + b * b);
}

double Hyperbola:: get_e()
{
    double a = get_a();
    return math.sqrt(1 + b*b/(a*a));
}

Line Hyperbola:: majoraxis()
{
    //TO BE IMPLEMENTED
}

Line Hyperbola:: minoraxis()
{
    //TO BE IMPLEMENTED
}

Line Hyperbola:: asymptotes()
{
    //TO BE IMPLEMENTED
}
