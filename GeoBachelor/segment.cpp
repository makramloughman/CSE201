/*#include <iostream>
#include <cmath>
#include "segment.h"
#include "point.hpp"
#define PI 3.14159265
using namespace std;

Segment::Segment(Point _point1, Point _point2) {
    this->p1 = _point1;
    this->p2 = _point2;
}

void display();         //displays segment
void displyendpoints(); //displays segment with endpoints
void hide();            //hide the segment
void hidepoints();      //hide the endpoint of the segment

void Segment::moverightpoint(float x, float y){
    p2.setx(p2.getx()+x);
    p2.sety(p2.gety()+y);
}

void Segment::moveleftpoint(float x, float y){
    p1.setx(p1.getx()+x);
    p1.sety(p1.gety()+y);
}    //move left point while staying in same line to extand

void Segment::movesegment(float x, float y){
    p1.setx(p1.getx()+x);
    p2.setx(p2.getx()+x);
    p1.sety(p1.gety()+y);
    p2.sety(p2.gety()+y);
}    //move the segment keeping it parallel to where it was

Segment Segment::point_symmetry(float a, float b){  //symmetry wrt a point
    p1_sym = p1.symmetry_point(float a , float b);
    p2_sym = p2.symmetry_point(float a , float b);
    return Segment(Point p1_sym,Point p2_sym);
}


double Segment::getlength(){
    float xp1 = p1.getx();
    float yp1 = p1.gety();
    float xp2 = p2.getx();
    float yp2 = p2.gety();
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}      //get distance between endpoints



Point Segment::midpoint(){
    float xp1 = p1.getx();
    float yp1 = p1.gety();
    float xp2 = p2.getx();
    float yp2 = p2.gety();
    float xm = (xp1+xp2)/2;
    float ym = (yp1+yp2)/2;
    return Point(double xm, double ym);
}

Segment Segment::mediator(){
    return Segment.perpendicular(float Segment.midpoint().getx() , float Segment.midpoint().getx(), float 0)
}                    //creates the mediator(line)



}
*/
