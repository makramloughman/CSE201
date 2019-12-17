/*#ifndef SEGMENT_H
#define SEGMENT_H
=======
>>>>>>> Stashed changes
#include "point.hpp"
#include "line.hpp"
#pragma once
class Segment : public Line {

public:
    //create endpoints of segment (point1 and point2)
    Point p1;
    Point p2;


    Segment(Point _point1, Point _point2);
    ~Segment();

    void polarcoordinates(); //gives polar coordinates of the point

    void display();         //displays segment
    void displyendpoints(); //displays segment with endpoints

    void hide();            //hide the segment
    void hidepoints();      //hide the endpoint of the segment


    void moverightpoint(); //extand or shrink and then rotate (using previous methods)
    void moveleftpoint();  //same

    void movesegment();    //move the segment keeping it parallel to where it was

    void point_symmetry(); //symmetry wrt a point

    void getlength();      //get distance between endpoints

    void pointonsegment();     //creates point on segment
    void linethroughsegment(); //creates line passing through the segment

    void copy();               //copying segment

    void perpendicular(int distance); //creates the perpendicular at a distance d from _point1 (should be less then length of segment)

    void midpoint();                  //give the midpoint of the segment

    void mediator();                  //creates the mediator(line)



};
*/
