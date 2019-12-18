#include <iostream>
#include <cmath>
#include "point.hpp"
#include <mainwindow.h>

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
     mainW -> drawPoint(mainW->mapToMyScene(this->x,this->y)); //Remark: We save data in Grid coordinates, so we need conversion
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

void Point::translate(double dx, double dy) //virtual function from the class MathObject
{
    x = x+dx;
    y = y+dy;
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

void Point::symmetry_axisy(){
    Point B = Point(-x, y);
    B.name = name +"'";
}

void Point::symmetry_axisx(){
    Point B = Point(x, -y);
    B.name = name +"'"+"'";
}

/*void Point::symmetry_point(float a , float b){ //sym wrt point with coordinates (x,y)
    Point A = Point(2*a-x,2*b-y);
    return A;
}
*/

double Point::distance(Point A)
{
   return std::sqrt(std::pow(A.x-this->x, 2) + pow(A.y-this->y, 2));
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
