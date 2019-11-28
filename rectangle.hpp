#include <iostream>
#include "point.hpp"
#include "segment.cpp"

class Rectangle {
private:
Point p1;
Point p2;

public :
double length();
double width();
double perimeter();
double area();
