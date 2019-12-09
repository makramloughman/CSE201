#include <iostream>
#include <string>
#include <vector>
#include "segment.hpp"
#include "circle.hpp"

class Polygone:public Item {
  private:
    int color [3];
    std::vector<point> Pointlist; 
  
 /* Old version
  
  class NodeList {
    public:
      int data;
      NodeList *next;

      // create a single node with data d
      // and optional next node
      NodeList(int d,  NodeList* nxt = NULL);

      // delete this node and all successor nodes
      ~ NodeList();
  };

  class PointList {
    private:
    NodeList *first, *last;

   public:
    // create an empty list
    PointList(); */

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

class RegularPolygone : public Polygone {
  private :
  int color[3];
  std::vector<point> Pointlist;
  
  public :
  
  RegularPolygone(); //empty regular polygone with empty vector of points 
  RegularPolygone(segment, number); //creates a regular polygone with given number of sides and a segment(two points, length)

  double length(); //returns the length of a side
  float angle(); //returns the value of an angle

  point centerofcircumscribed(); //returns the coordinates of the circumscribed circle
 
  cirlce circumscribedcircle(); //draws and create the circumscribed circle


}
