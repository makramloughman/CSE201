#include <iostream>
#include "point.hpp"
#include <cmath>
# define PI 3.14159265
using namespace std;

class Segment{

public:
    //create endpoints of segment (point1 and point2)
    Point(double x1, double y1) _point1; 
    Point(double x2, double y2) _point2;
    
    Segment(Point _point1,Point _point2){
        p1 = _point1
        p2 = _point2
    };
    ///
    // to get the coordinates of the endpoints:
    ///
    float getx1(){
        return getx(p1)
    };
    
    float gety1(){
        return gety(p1)
    };
    
    float getx2(){
        return getx(p2)
    };
    
    float gety2(){
        return gety(p2)
    };
    ///
    //now we have the coordinates of the endpoints as p1=(getx1(),gety1()) ...
    
    void createsegment( _point1 , _point2 );

    void display();         //displays segment
    void displyendpoints(); //displays segment with endpoints 

    void hide();            //hide the segment
    void hidepoints();      //hide the endpoint of the segment

    //A FINIR
    //void extandright(float x){
    //    _point2.

    //};     //move right point while staying in same line to extand
    void extandleft();      //move left point while staying in same line to extand

    void shrinkright();     //move right point while staying in same line to shrink
    void shrinkleft();      //move right point while staying in same line to shrink

    Point rotate(Point(double x, double y), double degree); //rotate around pont(x,y) with some degree(could be negative)
    
    void moverightpoint(); //extand or shrink and then rotate (using previous methods)
    void moveleftpoint();  //same

    void movesegment();    //move the segment keeping it parallel to where it was

    void point_symmetry(); //symmetry wrt a point
    void line_symmetry();  //symmetry wrt a line(axis)

    void getlength(int x1, int x2, int y1, int y2);      //get distance between endpoints
        sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    
    void pointonsegment();     //creates point on segment
    void linethroughsegment(); //creates line passing through the

    void copy();                //copying segment

    void parallel(double distance);     //creates the parallel at some distance (could be negative)
    void perpendicular(int distance);   //creates the perpendicular at a distance d from _point1 (should be less then length of segment)

    void midpoint(int x1, int y1, int x2, int y2);                    //give the midpoint of the segment
         cout << float((x1 + x2)/2) << "," << float((y1 + y2) / 2);
    
    void mediator();                    //creates the mediator(line)

    

}
