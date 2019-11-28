#pragma once

class Line {
  
  private:
  
    Point *p1;
    Point *p2;

  public:
  
    Line(Point &p1, Point &p2); //creates a line passing through two points which correspond to the two arguments
    
    void semi_line(Point &p1, Point &p2); //creates a semi line from p1 and passing through p2
  
    void slope(Point &p1,  Point &p2); //computes the slope of the line
    
    void equation(Point &p1, Point &p2); //computes the equation of the line
  
    void mediatrice(Point &p1, Point &p2, Point &p3);//draw the medriatrice to the line (p1, p2) passing through p3
  
    void parllel(Point &p1, Point &p2, Point &p3); //draw the parallel to the line (p1, p2) passing through p3
  
}
