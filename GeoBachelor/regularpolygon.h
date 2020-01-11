#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

#pragma once
#include "polygone.h"
#include "circle.hpp"
#include "segment.h"

class RegularPolygone : public Polygone
{
    public :
        Point center;
        Point p1;
        int n;
        std::vector<double> Colour;

        RegularPolygone(); //empty regular polygone with empty vector of points
        RegularPolygone(Point center, Point p1, int n); //creates a regular polygone with given number of sides and a segment(two points, length)

        double Perimeter();
        double Apothem();
        double Area();
        double length(); //returns the length of a side
        double angle(); //returns the value of an angle

        Circle circumscribedcircle(); //draws and create the circumscribed circle
        ~RegularPolygone();
};

#endif // REGULARPOLYGON_H
