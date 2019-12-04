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
    //TO BE IMPLEMENTED
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