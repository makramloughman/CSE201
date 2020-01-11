#include"general_functions.h"
#include "regularpolygon.h"
#include <mainwindow.h>
#include <cmath>
#define _USE_MATH_DEFINES

RegularPolygone::RegularPolygone() //empty regular polygone with empty vector of points
{
    size = 0;
    Colour.push_back(0);
    Colour.push_back(0);
    Colour.push_back(0);
}

RegularPolygone::RegularPolygone(Point center, Point p1, int n)
/* n is the number of segment */
{
    MainWindow* mainW = MainWindow::getInstance();
    int i;
    double x=center.getxg();
    double y=center.getyg();
    size=n;
    double radius=center.distanceg(p1);
    double angle=2*M_PI/size;
    for(i=0; i<n ;i++){

        double ag=x+radius*cos(2*M_PI*i/n);
        double bg=y+radius*sin(2*M_PI*i/n);
        double a=ag*mainW->mainGrid->unit+mainW->mainGrid->getX();
        double b=mainW->mainGrid->getY()-bg*mainW->mainGrid->unit;

        Point vertice=Point(a,b);
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
