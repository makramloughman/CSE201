#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

#pragma once
#include "polygone.h"
#include "circle.hpp"
#include "segment.h"

class RegularPolygone : public Polygone
{
    public :
        std::vector<double> Colour;
        std::vector<Point> Pointlist;

        RegularPolygone(); //empty regular polygone with empty vector of points
        RegularPolygone(Segment segment, int n); //creates a regular polygone with given number of sides and a segment(two points, length)

        double Perimeter();
        double Apothem();
        double Area();
        double length(); //returns the length of a side
        double angle(); //returns the value of an angle

        Point centergravity(); //returns the coordinates of the circumscribed circle

        Circle circumscribedcircle(); //draws and create the circumscribed circle
        ~RegularPolygone();
};

#endif // REGULARPOLYGON_H
