#include <iostream>
#include "point.hpp"
#include "segment.hpp"

// I am here defining a class vector that herites from the class segment where I am adding the attribut direction
// The arrow is at the second point, and giving the direction 

Class Vector : public Segment {
  public:
  
    void setStart();  //sets the starting point
  
    void setEnd();  //sets the destination
  
    void setDirection();   //arrow pointing from start to end
};
  
