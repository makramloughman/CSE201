#pragma once
#include <mathobject.h>
#include <point.hpp>
#include <iostream>
#include <cmath>
#include <line.hpp>

class SemiLine : public MathObject
{
  private:

  public:
  
    Point p1;
    Point p2;

    virtual void draw();
    virtual void translate(double dx, double dy);
    virtual bool in_personal_area(double x, double y);
    virtual void zoom(double coef, double c_x, double c_y);

    SemiLine(Point p1, Point p2); //creates a semiline starting from the first point and going through the second point
    SemiLine();
  
    double slope(); //computes the slope of the semiline
    
    double y_intercept(); //computes the intercept of the line with the origin
  
    Line perpendicular(Point p3);//create the perpendicular to the SemiLine passing through p3
  
    Line parallel(Point p3); //draw the parallel to the semiline passing through p3
    
    Point intersection(Line B); //return the point where the two semilines intersect
};
