#include <iostream>
#include "point.hpp"
#include "segment.cpp"

class Rectangle {
private:
Point point1;
Point point2;

public :
Rectangle(const Point &p1, const Point &p2 );
double length();
double width();
double getPerimeter()const;
double getArea()const;
