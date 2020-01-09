#include"general_functions.h"
#include "regularpolygon.h"
#include <cmath>
#define _USE_MATH_DEFINES


RegularPolygone::RegularPolygone() //empty regular polygone with empty vector of points
{
    size = 0;
    Colour.push_back(0);
    Colour.push_back(0);
    Colour.push_back(0);
}


RegularPolygone::RegularPolygone(Segment segment, int n)
{
    int i;
    double s=segment.getlength();
    size=n;
    double radius=s/2*sin(180/n);
    for(i=0; i<n ;i++){

        Point vertice=Point(radius*cos(2*M_PI*i/n),radius*sin(2*M_PI*i/n));
        Pointlist.push_back(vertice);

    }


}

double RegularPolygone::angle(){
    double angle=2*M_PI/size;
    return angle;
}

double RegularPolygone::length(){
    Segment seg=Segment(Pointlist[0],Pointlist[1]);
    return seg.getlength();
}

double RegularPolygone::Perimeter(){
    Segment seg=Segment(Pointlist[0],Pointlist[1]);
    double s=seg.getlength();
    return s*size;
    
}

double RegularPolygone::Apothem(){
    Segment seg=Segment(Pointlist[0],Pointlist[1]);
    double s=seg.getlength();
    return s/(2*tan(180/size));
}

double RegularPolygone::Area(){
    double A=Apothem();
    double P=Perimeter();
    return (P*A)/2;
}



Point RegularPolygone:: centergravity(){
   Segment s1 = Segment(Pointlist[0] , Pointlist[1]);
   Segment s2 = Segment(Pointlist[1] , Pointlist[2]);

   Line m1=s1.mediator();
   Line m2=s2.mediator();


   return *intersection(m1,m2)[0];
}

Circle RegularPolygone::circumscribedcircle(){
    Point c=centergravity();
    double r=distance(c,Pointlist[0]);
    return Circle(c, r);
}

RegularPolygone::~RegularPolygone()
// delete the regularpolygone
{
    //std::cout << "Destroying RegularPolygone" << std::endl;
}
