#include "point.hpp"
#include "line.hpp"
#include <mathobject.h>
#pragma once

class Segment : public MathObject
{

public:
    //create endpoints of segment (point1 and point2)
    Point p1;
    Point p2;


    Segment(Point _point1, Point _point2);
    ~Segment();

    virtual void translate(double dx, double dy);
    virtual void draw();

    void polarcoordinates(); //gives polar coordinates of the point

    void display();         //displays segment
    void displyendpoints(); //displays segment with endpoints

    void hide();            //hide the segment
    void hidepoints();      //hide the endpoint of the segment


    void move_rightpoint(double x, double y); //extand or shrink and then rotate (using previous methods)
    void move_leftpoint(double x, double y);  //same

    //Point point_symmetry(Point p); //symmetry wrt a point

    double getlength();      //get distance between endpoints

    void pointonsegment();     //creates point on segment
    void linethroughsegment(); //creates line passing through the segment

    void copy();               //copying segment

    Line perpendicular(); //creates the perpendicular at a distance d from _point1 (should be less then length of segment)

    Point midpoint();                  //give the midpoint of the segment

    Line mediator();                  //creates the mediator(line)



};

