#pragma once

class Line : public Item
{
  
  private:
  
    Point *p1;
    Point *p2;

  public:
  
    Line(Point &p1, Point &p2); //creates a line passing through two points which correspond to the two arguments
    
    //void semi_line(Point &p1, Point &p2); //creates a semi line from p1 and passing through p2
  
    double slope(); //computes the slope of the line
    
    double y_intercept(); //computes the intercept of the line with the origin
  
    Line perpendicular(Point &p3);//create the perpendicular to the line passing through p3
  
    Line parallel(Point &p3); //draw the parallel to the line passing through p3
    
    Point intersection(Point &p1, Point &p2, Point &p3, Point &p4); //return the point where the two lines intersect
