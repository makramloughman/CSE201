#pragma once

class Line {
  
  private:
  
    Point *p1;
    Point *p2;

  public:
  
    Line(Point &p1, Point &p2); //creates a line passing through two points which correspond to the two arguments
    
    //void semi_line(Point &p1, Point &p2); //creates a semi line from p1 and passing through p2
  
    double slope(); //computes the slope of the line
    
    double equation(); //computes the equation of the line
  
    Line mediatrice(Point &p3);//create the medriatrice to the line passing through p3
  
    Line parallel(Point &p3); //draw the parallel to the line passing through p3
  
}
