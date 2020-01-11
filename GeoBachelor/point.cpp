#include <iostream>
#include <cmath>
#include "point.hpp"
#include <mainwindow.h>

Point::Point() : MathObject()
{
    this->x = 0.0;
    this->y = 0.0;
    this->name = "";
    this -> countpoints = 0;
}

Point::Point(double x, double y, int i) : MathObject()
{
    this->x = x;
    this->y = y;
}

std::string Point::get_name() {
    return name;
}

// global variable (int countpoints)
Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
    MainWindow* mainW = MainWindow::getInstance();
    this->x_g = (x - mainW->mainGrid->getX()) / mainW->mainGrid->unit;
    this->y_g = (mainW->mainGrid->getY() - y) / mainW->mainGrid->unit;
    /*
    std::string s("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if (countpoints >= 26) {
        double countpoints_2 = (countpoints / 26) - 1;
        this -> name = s.at( countpoints_2 % s.size() ) + s.at( countpoints % s.size() ); }
    else { this->name = s.at( countpoints % s.size() ); }
    */

    countpoints += 1; // add 1 to the counter
    color.push_back(0);
    color.push_back(0);
    color.push_back(0);
    this->shape = 0;
}

Point::Point(QPointF p)
{
    this->x = p.x();
    this->y = p.y();
    MainWindow* mainW = MainWindow::getInstance();
    this->x_g = (this->x - mainW->mainGrid->getX()) / mainW->mainGrid->unit;
    this->y_g = (mainW->mainGrid->getY() - this->y) / mainW->mainGrid->unit;
    this-> name = ""; //A...Z then AA...AZ ... until ZA...ZZ
    color.push_back(0);
    color.push_back(0);
    color.push_back(0);
    this->shape = 0;
}

void Point::draw() //virtual function from the class MathObject
{
     MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
     if(this->selected)
     {
         mainW->SetPen(3,Qt::blue);
     }
     mainW -> drawPoint(mainW->mapToMyScene(this->x,this->y)); //Remark: We save data in Grid coordinates, so we need conversion

     mainW->ResetPen();
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
}

Point Point::symmetry_point(Point A)
{
    Point p=Point(2*A.getx()-getx(),2*A.gety()-gety());
    return p;
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

bool Point::in_personal_area(double x, double y)
{
    double ro = distance(Point(x,y));
    if (ro<5)
    {
        return true;
    }
    return false;
}

void Point::zoom(double coef, double c_x, double c_y)
{
    setx((getx()-c_x)*coef+c_x);
    sety((gety()-c_y)*coef+c_y);

}

void Point::drawName(int i)
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    std::string str = "P"+std::to_string(i);
    QString q = QString::fromLocal8Bit(str.c_str());
    mainW->drawText(q,this->x+5,this->y-5); //Remark: We save data in Grid coordinates, so we need conversion
}

double Point::getx(){
    return x;
}

double Point::gety(){
    return y;
}

double Point::getxg(){
    return x_g;
}

double Point::getyg(){
    return y_g;
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

double Point::distanceg(Point A)
{
   return std::sqrt(std::pow(A.x_g-this->x_g, 2) + pow(A.y_g-this->y_g, 2));
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
    //std::cout << "Destroying Point( " << x << " , " << y << " )" << std::endl;
}
