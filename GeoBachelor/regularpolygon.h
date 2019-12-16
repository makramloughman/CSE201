#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H
#pragma once
#include <polygone.h>
#include <circle.hpp>

class RegularPolygone : public Polygone {
  public :

  std::vector<double> Colour;
  std::vector<Point> Pointlist;

  RegularPolygone(); //empty regular polygone with empty vector of points
  RegularPolygone(double l, int n); //creates a regular polygone with given number of sides and a segment(two points, length)

  double length(); //returns the length of a side
  float angle(); //returns the value of an angle

  Point centergravity(); //returns the coordinates of the circumscribed circle

  Circle circumscribedcircle(); //draws and create the circumscribed circle


};


#endif // REGULARPOLYGON_H
