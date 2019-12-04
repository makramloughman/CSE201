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
    //TO BE IMPLEMENTED
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
    //TO BE IMPLEMENTED
}

Line Ellipse:: minoraxis()
{
    //TO BE IMPLEMENTED
}
