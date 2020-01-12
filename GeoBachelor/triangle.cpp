#include "triangle.hpp"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <mainwindow.h>

void Triangle::draw()
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    if(this->selected)
    {
        mainW->SetPen(3,Qt::blue);
    }

    std::vector<QPointF> help;
    help.push_back(mainW->mapToMyScene(point1.getx(),point1.gety()));
    help.push_back(mainW->mapToMyScene(point2.getx(),point2.gety()));
    help.push_back(mainW->mapToMyScene(point3.getx(),point3.gety()));
    mainW->drawPolygon(help);

    mainW->ResetPen();
}

void Triangle::translate(double dx, double dy)
{
    point1.translate(dx, dy);
    point2.translate(dx, dy);
    point3.translate(dx, dy);
}

bool Triangle::in_personal_area(double x, double y)
{
    Segment* s1 = new Segment(point1, point2);
    Segment* s2 = new Segment(point2, point3);
    Segment* s3 = new Segment(point3, point1);
    if (s1->in_personal_area(x,y) || s2->in_personal_area(x,y) || s3->in_personal_area(x,y))
        return true;
    return false;
}

void Triangle::zoom(double coef, double c_x, double c_y)
{
    this->point1.zoom(coef,c_x,c_y);
    this->point2.zoom(coef,c_x,c_y);
    this->point3.zoom(coef,c_x,c_y);
}

Triangle::Triangle(Point point1 ,Point point2 ,Point point3) : MathObject()
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

Triangle::Triangle(std::vector<QPointF> p)
{
    this->point1=p[0];
    this->point2=p[1];
    this->point3=p[2];
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
    return d1 + d2 + d3;
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

Segment Triangle::Baricenter1(){
    Segment seg=Segment(point2, point3);
    Point m=seg.midpoint();
    return Segment( m, point1);
}

Segment Triangle::Baricenter2(){
    Segment s=Segment(point1,point3);
    Point m=s.midpoint();
    return Segment(m, point2);
}

Segment Triangle::Baricenter3(){
    Segment s=Segment(point1,point2);
    Point m=s.midpoint();
    return Segment(m, point3);
}

Point Triangle::getCenterofgravity(){
    Segment seg1=Baricenter1();
    Segment seg2=Baricenter2();
    return *intersection(seg1,seg2)[0];

}

Point Triangle::getOrthocenter(){
    Segment s1=Segment(point1,point2);
    Segment s2=Segment(point2,point3);
    Line m1=s1.perpendicular(point3);
    Line m2=s2.perpendicular(point1);
    return *intersection(m1,m2)[0];
}

Circle Triangle::Circumscribedcercle(){
    Segment s1=Segment(point1,point2);
    Segment s2=Segment(point2,point3);
    Point m11=s1.midpoint();
    Point m21=s2.midpoint();
    Line m1=s1.perpendicular(m11);
    Line m2=s2.perpendicular(m21);
    Point o = *intersection(m1,m2)[0];
    double r=distance(o,point1);
    return Circle(o,r);
}

Circle Triangle::getInscribedcercle(){
    double c = point1.distance(point2);
    double a = point2.distance(point3);
    double  b= point1.distance(point3);
    Point* o=new Point((a*point1.getx()+b*point2.getx()+c*point3.getx())/(a+b+c),(a*point1.gety()+b*point2.gety()+c*point3.gety())/(a+b+c));
    double r=(2*getArea())/getPerimeter();
    return Circle(*o,r+0.001);
}
