#include <iostream>
#include <string>
#include <vector>
#include "segment.hpp"
#include "circle.hpp"

class Polygone:public Item {
  private:
    int color [3];
    std::vector<point> Pointlist; 
    int size;

  public : 
    //create empty list
    Polygone();
    //create a polygone
    Polygone(int k, vector<point> P);
    //add points to the list afterwards
    void append(point);
    
    Polygone(int k, vector<point>);
 
    void changecolour(R,G,B);
    // changes the colour

    // display the polygone
    void display();

    // hide the polygone
    void hide();

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
}

class RegularPolygone : public Polygone {
  private :
  int color[3];
  std::vector<point> Pointlist;
  
  public :
  
  RegularPolygone(); //empty regular polygone with empty vector of points 
  RegularPolygone(segment, number); //creates a regular polygone with given number of sides and a segment(two points, length)

  double length(); //returns the length of a side
  float angle(); //returns the value of an angle

  Point centergravity(); //returns the coordinates of the circumscribed circle
 
  Cirlce circumscribedcircle(); //draws and create the circumscribed circle

 
}
