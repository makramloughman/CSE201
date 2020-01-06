#pragma once
#include <mathobject.h>
#include <point.hpp>

class SemiLine : public MathObject
{
  
  private:

  public:
  
    Point p1;
    Point p2;

    virtual void draw();
    virtual void translate(double xx, double yy);

    SemiLine(Point p1, Point p2); //creates a semiline starting from the first point and going through the second point
    SemiLine();
  
    double slope(); //computes the slope of the semiline
    
    double y_intercept(); //computes the intercept of the line with the origin
  
    SemiLine perpendicular(Point p3);//create the perpendicular to the SemiLine sarting by the point on the Semiline and passing through p3
  
    SemiLine parallel(Point p3); //draw the parallel to the semiline passing through p3, semiline starts at the same x as the semiline
    
    Point intersection(SemiLine B); //return the point where the two semilines intersect
};
