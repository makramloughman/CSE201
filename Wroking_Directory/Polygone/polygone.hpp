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

class RegularPolygone : public Polygone {
  private :
  int color[3];
  std::vector<point> Pointlist;
  
  public :
  
  RegularPolygone(); //empty regular polygone with empty vector of points 
  RegularPolygone(segment, number); //creates a regular polygone with given number of sides and a segment(two points, length)

  void length(); //returns the length of a side
  void angle(); //returns the value of an angle

  void centerofcircumscribed(); //returns the c`oordinates of the circumscribed circle
  void centerofinscribed(); //returns the coordinates of the inscribed circle 

  void circumscribedcircle(); //draws and create the circumscribed circle
  void inscribedcircle(); //draws and create the inscribed circle
  

}
