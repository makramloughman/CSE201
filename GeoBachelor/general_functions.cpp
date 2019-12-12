#include <general_functions.h>

double distance(Point p1, Point p2)
{
    return sqrt(pow(p1.getx()-p2.getx(), 2) + pow(p1.gety()-p2.gety(), 2));
}
