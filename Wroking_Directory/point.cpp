#include  <iostream>
#include <cmath>
#include "point.hpp"
#include <mainwindow.h>
#include "line.hpp"
#include "circle.hpp"

Point::Point() {
    this->x = 0.0;
    this->y = 0.0;
    this->name = "O";
}

Point::Point(double x, double y){
    this->x = x;
    this->y = y;
    this-> name = ""; //A...Z then A_1...Z_1 ... until A_n...Z_n
    color.push_back(0);
    color.push_back(0);
    color.push_back(0);
    this->shape = 0;
}

Point::Point(QPointF p)
{
    this->x = p.x();
    this->y = p.y();
    this-> name = ""; //A...Z then A_1...Z_1 ... until A_n...Z_n
    color.push_back(0);
    color.push_back(0);
    color.push_back(0);
    this->shape = 0;
}

void Point::draw() //virtual function from the class MathObject
{
     MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
     mainW -> drawPoint(mainW->mapFromGridToScene(this->x,this->y)); //Remark: We save data in Grid coordinates, so we need conversion
}

void Point::changecolour(double R,double G,double B){
    color.push_back(R);
    color.push_back(G);
    color.push_back(B);
}

void Point::hide(){
    color.push_back(0);
    color.push_back(0);
    color.push_back(0.5);

    //this-> namecolor = rgba(0,0,0.5);
}

void Point::setx(double a){
    this->x = a;
}

void Point::sety(double b){
    y = b;
}

void Point::translate(double a, double b) //virtual function from the class MathObject
{
    x = x+a;
    y = y+b;
}

double Point::getx(){
    return x;
}

double Point::gety(){
    return y;
}


void Point::givename(std::string n){
    name = n;
}

void Point::hidename() {
 //this -> namecolor = rgba(0,0,0,0.5); // the point appears transparent
}

Point Point::symmetry_axisy(){
    B = Point(-x, y);
    return B
}

Point Point::symmetry_axisx(){
    B = Point(x, -y);
    return B
}

Point Point::symmetry_point(Point A , Point B){ //sym wrt point with coordinates (x,y)
    L = Line(A,B)
    D = this->distance(A,B)
    C = Circle(B, D)
    S = C.line_intersection(L)
    return S
}

Point Point::symmetry_line(Point A, Line B){
    C = B.perpendicular(A)
    D = C.intersection(B)
    E = this-> symmetry_point(A,E)
    return E
     
}

double Point::distance(Point A, Point B)
{
   return std::sqrt(std::pow(A.x-B.x, 2) + pow(A.y-B.y, 2));
}



//gives the radius from polar coordinates of the point (r,theta)
float radius_polarcoordinates(Point point)
{
    float r = sqrt(pow(point.getx(),2)+pow(point.gety(),2));     //radius = sqrt(x^2+y^2)
    return r;
}

//gives the angle from polar coordinates of the point (r,theta)
float angle_polarcoordinates(Point point)
{
    float theta = atan(point.gety() / point.getx() ) * 180 / M_PI; //angle in degree theta = atan(y/x) *180/pi
    return theta;
}

Point::~Point()
{
  std::cout << "Destroying Point( " << x << " , " << y << " )" << std::endl;
}
