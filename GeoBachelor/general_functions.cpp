#include <general_functions.h>

double distance(Point p1, Point p2)
{
    return sqrt(pow(p1.getx()-p2.getx(), 2) + pow(p1.gety()-p2.gety(), 2));
}

Point intersection(Line l1, Line l2) //copied from Line.hpp
{
    double a1 = l1.slope();
    double a2 = l2.slope();
    double b1 = l1.y_intercept();
    double b2 = l2.y_intercept();
    double xstar = (b1 - b2)/(a2 - a1);
    double ystar = a1 * xstar + b1;
    Point pstar(xstar, ystar);
    return pstar;
}
