#include <iostream>
#include <string>
#include <list>
#include "point.hpp"

class Polygone {
  private:
    int color [3];
    std::list<point> Pointlist; 
    
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

    //delete the polygone
    ~Polygone;

    
}
