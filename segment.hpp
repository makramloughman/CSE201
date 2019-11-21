#include "point.hpp"
class Segment{

public:
    //create endpoints of segment (point1 and point2)
    Point(double x1, double y1) _point1;
    Point(double x2, double y2) _point2;

    void createsegment( _point1 , _point2 );

    void display();         //displays segment
    void displyendpoints(); //displays segment with endpoints 

    void hide();            //hide the segment
    void hidepoints();      //hide the endpoint of the segment

    void extandright();     //move right point while staying in same line to extand
    void extandleft();      //move left point while staying in same line to extand

    void shrinkright();     //move right point while staying in same line to shrink
    void shrinkleft();      //move right point while staying in same line to shrink

    void rotate(Point(double x, double y), double degree); //rotate around pont(x,y) with some degree(could be negative)
    
    void moverightpoint(); //extand or shrink and then rotate (using previous methods)
    void moveleftpoint();  //same

    void movesegment();    //move the segment keeping it parallel to where it was

    void point_symmetry(); //symmetry wrt a point
    void line_symmetry();  //symmetry wrt a line(axis)

    void getlength();      //get distance between endpoints

    void pointonsegment();     //creates point on segment
    void linethroughsegment(); //creates line passing through the segment

    void copy();               //copying segment

    void parallel(double distance);   //creates the parallel at some distance (could be negative)
    void perpendicular(int distance); //creates the perpendicular at a distance d from _point1 (should be less then length of segment)

    void midpoint();                  //give the midpoint of the segment

    void mediator();                  //creates the mediator(line)

    

}
