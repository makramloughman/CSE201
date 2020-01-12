#include <iostream>
#include <string>
#include <vector>
#include "segment.hpp"
#include "circle.hpp"

class Polygone {
  public : 
  
    std::vector<double> Colour;
    Colour.pushback(0);
    Colour.pushback(0);
    Colour.pushback(0);
    std::vector<point> Pointlist; 
    int size;

    //create empty list
    Polygone();
    //create a polygone
    Polygone(int k, vector<point> P);
    //add points to the list afterwards
    void append(point);
    
    Polygone(int k, vector<point>);
 
    std::vector<double> changeColour(R,G,B);
    // changes the colour

    // display the polygone
    std::vector<double> display();

    // hide the polygone
    std::vector<double> hide();

    // get the surface
    double surface();
  
    // get the edge
    std::vector<Segment> edge();
  
    // duplicate
    void duplicate();
  
    // translate and extand included in segment
  
    //display trace (when translated)
    void trace();

    //delete the polygone
    ~Polygone;
};

class RegularPolygone : public Polygone {
  public :
  
  std::vector<double> Colour;
  Colour.pushback(0);
  Colour.pushback(0);
  Colour.pushback(0);
  std::vector<point> Pointlist;
  
  RegularPolygone(); //empty regular polygone with empty vector of points 
  RegularPolygone(segment, number); //creates a regular polygone with given number of sides and a segment(two points, length)

  double length(); //returns the length of a side
  float angle(); //returns the value of an angle

  Point centergravity(); //returns the coordinates of the circumscribed circle
 
  Cirlce circumscribedcircle(); //draws and create the circumscribed circle

 
}
