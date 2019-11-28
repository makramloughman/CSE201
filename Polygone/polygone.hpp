#include <iostream>
#include <string>
#include "point.hpp"

class Polygone {
  
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
    PointList();
    // add an element to the list
    void append();
  }
  
    // display the polygone
    void display();
  
    //delete the polygone
    ~Polygone;

    // get the surface
    double surface();
}


