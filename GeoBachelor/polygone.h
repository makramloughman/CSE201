#pragma once
#include <iostream>
#include <string>
#include <vector>
//#include "segment.hpp"
#include <point.hpp>
#include "circle.hpp"
#include <mathobject.h>

class Polygone : public MathObject
{
  public :

    virtual void draw();
    virtual void translate();

    std::vector<double> Colour;

    std::vector<Point> Pointlist;
    int size;

    //create empty list
    Polygone();
    //create a polygone
    Polygone(int k, std::vector<Point> P);
    //add points to the list afterwards
    void append(Point p);

    std::vector<double> changeColour(double R,double G,double B);
    // changes the colour

    // display the polygone
    void display();

    // hide the polygone
    void hide();

    // get the edge
    //std::vector<Segment> edge();

    // translate and extand included in segment

    //display trace (when translated)
    void trace();

    //delete the polygone
    ~Polygone();
};

