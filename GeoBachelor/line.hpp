#pragma once
#include <mathobject.h>
#include <point.hpp>

class Line : public MathObject
{
  
  private:

  public:
  
    Point p1;
    Point p2;
    
    int countpoints;
    std::string name; 
    std::string get_name(); //for the display

    virtual void draw();
    virtual void translate(double dx, double dy);
    virtual bool in_personal_area(double x, double y);

    Line(Point &p1, Point &p2); //creates a line passing through two points which correspond to the two arguments
    Line();

    //void semi_line(Point &p1, Point &p2); //creates a semi line from p1 and passing through p2
  
    double slope(); //computes the slope of the line
    
    double y_intercept(); //computes the intercept of the line with the origin
  
    Line perpendicular(Point p3);//create the perpendicular to the line passing through p3
  
    Line parallel(Point p3); //draw the parallel to the line passing through p3
    
    Point intersection(Line B); //return the point where the two lines intersect

    Point normal(Point p); //we find normal line from some points

    std::vector<Point> reflection(Point p);

    virtual ~Line();
};
