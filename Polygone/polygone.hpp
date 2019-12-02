#include <iostream>
#include <string>
#include <list>
#include "point.hpp"

class Polygone {
  private:
    int color [3];
    std::list<point> Pointlist; 
    
  public : 

    Polygone();

    void Appendpoint(point);


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
