#include <iostream>
#include <string>
#include <vector>
#include "segment.hpp"

class Polygone:public Item {
  private:
    int color [3];
    std::vector<point> Pointlist; 
    
  public : 
    //create empty list
    Polygone();
    //add points to the list
    void append(point);

    void changecolour(R,G,B);
    // changes the colour

    // display the polygone
    void display();

    // hide the polygone
    void hide();

    // get the surface
    double surface();
  
    // duplicate
    duplicate();
  
    // translate and extand included in segment
  
    //display trace (when translated)
    void trace();

    //delete the polygone
    ~Polygone;

    
}
