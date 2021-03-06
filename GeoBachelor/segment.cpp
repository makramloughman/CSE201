#include <iostream>
#include <cmath>
#include "segment.h"
#include "point.hpp"
#include <mainwindow.h>
#define PI 3.141592653589
using namespace std;

Segment::Segment(Point &_point1, Point &_point2) : MathObject()
{
    this->p1 = _point1;
    this->p2 = _point2;
}

void Segment::translate(double dx, double dy)
{
    p1.translate(dx,dy);
    p2.translate(dx,dy);
}

void Segment::draw()
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    if(this->selected)
    {
        mainW->SetPen(3,Qt::blue);
    }
    QPointF f1 = mainW -> mapToMyScene(p1.getx(),p1.gety());
    QPointF f2 = mainW -> mapToMyScene(p2.getx(),p2.gety());
    mainW -> drawLine(f1,f2);

    mainW->ResetPen();
}

bool Segment::in_personal_area(double x, double y)
{
    Line* l = new Line(p1,p2);
    double mx = min(p1.getx(),p2.getx());
    double Mx = p1.getx()+p2.getx()-mx;
    double my = min(p1.gety(),p2.gety());
    double My = p1.gety()+p2.gety()-my;
    if (l->in_personal_area(x,y) && x<Mx+3 && x>mx-3 && y<My+3 && y>my-3)
        return true;
    return false;
}

void Segment::zoom(double coef, double c_x, double c_y)
{
    this->p1.zoom(coef,c_x,c_y);
    this->p2.zoom(coef,c_x,c_y);
}

void display();         //displays segment
void displyendpoints(); //displays segment with endpoints
void hide();            //hide the segment
void hidepoints();      //hide the endpoint of the segment

void Segment::move_rightpoint(double x, double y){
    p2.translate(x,y);
}

void Segment::move_leftpoint(double x, double y){
    p1.translate(x,y);
}    //move left point while staying in same line to extand

double Segment::getlength(){
    double x1 = p1.getx();
    double y1 = p1.gety();
    double x2 = p2.getx();
    double y2 = p2.gety();
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}      //get distance between endpoints



Point Segment::midpoint(){
    double xp1 = p1.getx();
    double yp1 = p1.gety();
    double xp2 = p2.getx();
    double yp2 = p2.gety();
    double xm = (xp1+xp2)/2;
    double ym = (yp1+yp2)/2;
    Point p = Point(xm,ym);
    return p;
}

Line Segment::mediator()
{
    Line l =Line(p1,p2);
    Point m = midpoint();
    return l.perpendicular(m);
}

Line Segment::perpendicular(Point p){
    Line l1=Line(p1,p2);
    return l1.perpendicular(p);
}

Segment::~Segment()
{
}

