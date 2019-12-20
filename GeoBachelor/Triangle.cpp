#include "Triangle.hpp"
#include <iostream>
#include <math.h>
#include <stdio.h>

void Triangle::draw()
{

}

void Triangle::translate(double dx, double dy)
{

}

bool Triangle::in_personal_area(double x, double y)
{
    return false;
}

Triangle::Triangle(Point point1 ,Point point2 ,Point point3)
{
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
    
    // function to make global
    /*
    std::string s("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if (countpoints >= 26) {
        countpoints_2 = (countpoints / 26) - 1;
        this -> name = s.at( countpoints_2 % s.size() ) + s.at( countpoints % s.size() ); }
    else { this->name = s.at( countpoints % s.size() ); }
    countpoints += 1; // add 1 to the counter
    */
} 

Triangle:: ~Triangle()
{

}

double Triangle:: getArea(){
    double d1 = point1.distance(point2);
    double d2 = point2.distance(point3);
    double d3 = point1.distance(point3);
    double s=(d1+d2+d3)/2;
    return sqrt(s*(s-d1)*(s-d2)*(s-d3));
}

double Triangle::getPerimeter(){
    double d1 = point1.distance(point2);
    double d2 = point2.distance(point3);
    double d3 = point1.distance(point3);
    return d1+d2+d3;
}

bool Triangle::isocele(){
    double d1 = point1.distance(point2);
    double d2 = point2.distance(point3);
    double d3 = point1.distance(point3);
    if ((d1==d2) || (d2==d3) || (d1==d3)){
        return true ;
    }
    else return false; 
}

bool Triangle::equilateral(){
    double d1 = point1.distance(point2);
    double d2 = point2.distance(point3);
    double d3 = point1.distance(point3);
    if ((d1==d2) & (d2==d3)){
        return true;
    }
    else return false;
}

bool Triangle::rectangle(){
    double d1 = point1.distance(point2);
    double d2 = point2.distance(point3);
    double d3 = point1.distance(point3);

    if (d1*d1==d2*d2+d3*d3){
        return true;
    }
    else if (d2*d2==d1*d1+d3*d3){
        return true;
    }
    else if (d3*d3==d1*d1+d2*d2){
        return true;
    }
    else return false;
}

double Triangle::getHeight1(){
    double d1 = point1.distance(point2);
    return (2*getArea())/d1;
}

double Triangle::getHeight2(){
    double d2 = point2.distance(point3);
    return (2*getArea())/d2;
}

double Triangle::getHeight3(){
    double d3 = point1.distance(point3);
    return (2*getArea())/d3;
}

/*Segment getBaricentre1(){
    Segment s=Segment(Point point2,Point point3);
    Point m=s.midpoint();
    Segment l=Segment(Point m,Point 1);
    return l
}

Segment getBaricentre2(){
    Segment s=Segment(Point point1,Point point3);
    Point m=s.midpoint();
    Segment l=Segment(Point m,Point 2);
    return l
}
Segment getBaricentre1(){
    Segment s=Segment(Point point1,Point point2);
    Point m=s.midpoint();
    Segment l=Segment(Point m,Point 3);
    return l
}
*/
/*
Point Triangle::getCenterofgravity(){

    return static *Inter::intersection(getBaricentre1,getBaricentre2);

}

Point orthocenter{
    
}
*/
