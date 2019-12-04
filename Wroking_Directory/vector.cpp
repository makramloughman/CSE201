#include "vector.hpp"
#pragma once

Class Vector : public Segment {
  public:
    void setStart(); //sets the root
         Point(double x1, double y1) start;
  
    void setEnd(); //sets the destination
          Point(double x2, double y2) end; 
  
    void setDirection();  //set the pointing arrow to the second point
    // check with graphic 

};
