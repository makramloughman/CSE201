#include <iostream>
#include "point.hpp"
#include <cmath>
# define PI 3.14159265
using namespace std;

class Segment{

public:
    //create segment:
    Segment(Point _point1,Point _point2){
        p1 = _point1
        p2 = _point2
    };
    ///
    // to get the coordinates of the endpoints:
    ///
    ///
    //now we have the coordinates of the endpoints as p1=(getx1(),gety1()) ...
    
    void createsegment( _point1 , _point2 );

    void display();         //displays segment
    void displyendpoints(); //displays segment with endpoints 

    void hide();            //hide the segment
    void hidepoints();      //hide the endpoint of the segment

    //A FINIR
    Segment::extand_shrink_right(float x, float y){
        p2.translate(x,y);
    }

    //};     //move right point while staying in same line to extand
    Segment::extand_shrink_left(float x, float y){
        p1.translate(x,y)
    }    //move left point while staying in same line to extand

    Segment::rotate_around_p2(double degree){ // to fix
        p1.angle_polarcoordinates()+= degree
    }; //rotate around p2 with some degree(could be negative)

    Segment::rotate_around_p1(double degree){  // to fix
        p2.angle_polarcoordinates()+= degree
    }; //rotate around p1 with some degree(could be negative)
    
    void moverightpoint(float x, float y, double degree){
        p2.translate(x,y);
        p2.angle_polarcoordinates()+= degree
    }; //extand or shrink and then rotate (using previous methods)
    void moveleftpoint();  //same

    void movesegment(float x, float y){
        p1.translate(x,y);
        p2.translate(x,y);
    };    //move the segment keeping it parallel to where it was

    Segment::point_symmetry(float a, float b){  //symmetry wrt a point
        p1_sym = p1.symmetry_point(float a , float b);
        p2_sym = p2.symmetry_point(float a , float b);
        return Segment(Point p1_sym,Point p2_sym);
    };


    Segment::line_symmetry();  //symmetry wrt a line(axis)

    void getlength(int x1, int x2, int y1, int y2);      //get distance between endpoints
        sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    void copy();                //copying segment

    void parallel(double distance);     //creates the parallel at some distance (could be negative)
    Segment::perpendicular(float a, float b , float xc){
        float xp1 = p1.getx();
        float yp1 = p1.gety();
        float xp2 = p2.getx();
        float yp2 = p2.gety();
        float m = (yp1-yp2)/(xp1-xp2);
        float yc = b + (a-xc)/m;
        Point point1(a , b);
        Point point2(xc , yc);
        return createsegment(point1 , point2 );
    };   //creates the perpendicular going throught (a,b)

    
    void midpt(int x1, int y1, int x2, int y2);                    //give the midpoint of the segment
         cout << float((x1 + x2)/2) << "," << float((y1 + y2) / 2);
    
    Segment::midpoint(){
        float xp1 = p1.getx();
        float yp1 = p1.gety();
        float xp2 = p2.getx();
        float yp2 = p2.gety();
        float xm = (xp1+xp2)/2
        float ym = (yp1+yp2)/2
        return Point(double xm, double ym);
    };
    
    
    void mediator();                    //creates the mediator(line)

    

}
