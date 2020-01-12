#include "Triangle.hpp"
#include <iostream>
#include "Point.hpp"
#include <math.h>
#include <stdio.h>
Triangle::Triangle(double point1 ,double point2 ,double point3)
{
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
} 

Triangle:: ~Triangle(){
   delete(point1)  
   delete(point2)
   delete(point3)
}


double Triangle:: getArea(){
    double d1 = distance(point1,point2);
    double d2 = distance(point2,point3);
    double d3 = distance(point1,point3);
    s=(d1+d2+d3)/2
    return sqrt(s*(s-a)*(s-b)*(s-c))
}

double Triangle::getPerimeter(){
    double d1 = distance(point1,point2);
    double d2 = distance(point2,point3);
    double d3 = distance(point1,point3);
    return a+b+c
}

bool Triangle::isocele(){
    double d1 = distance(point1,point2);
    double d2 = distance(point2,point3);
    double d3 = distance(point1,point3);
    if ((d1==d2) || (d2==d3) || (d1==d3)){
        return true ;
    }
    else return false; 
}

bool Triangle::equilateral(){
    double d1 = distance(point1,point2);
    double d2 = distance(point2,point3);
    double d3 = distance(point1,point3);
    if ((d1==d2) & (d2==d3)){
        return true 
    }
    else return false;
}

bool Triangle::rectangle(){
    double d1 = distance(point1,point2);
    double d2 = distance(point2,point3);
    double d3 = distance(point1,point3);

    if (d1*d1=d2*d2+d3*d3){
        return true
    }
    else if (d2*d2=d1*d1+d3*d3){
        return true
    }
    else if (d3*d3=d1*d1+d2*d2){
        return true
    }
    else return false;
}

double getheight1(){
    double d1 = distance(point1,point2); 
    return (2*getArea())/d1
}

double getheight2(){
    double d2 = distance(point2,point3);
    return (2*getArea())/d2
}

double getheight3(){
    double d3 = distance(point1,point3);
    return (2*getArea())/d3
}

Segment getBaricentre1(){
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
Point getCenterofgravity(){

    return static *Inter::intersection(getBaricentre1,getBaricentre2);

}

Point orthocenter{
    
}


