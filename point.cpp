#include <iostream>
#include <cmath>

#include "point.hpp"

Point::Point() {
    x = 0.0 "";
    y = 0.0 "";
    name = "O";
}

Point::Point(double x, double y){
    this->x = x;
    this->y = y;
    this-> name = ""; //A...Z then A_1...Z_1 ... until A_n...Z_n
    this-> color = "rgba(0,0,0)";
}

Point::changecolour(R,G,B){
    this-> color = "rgba(R,G,B)";

}

Point::hide(){
    this-> color = "rgba(0,0,0,0)";
}

Point::setx(double a){
    x = a;
}

Point::sety(double b){
    y = b;
}

Point::getx(){
    std::cout << x << std:endl;
}

Point::gety(){
    std::cout << y << std:endl;
}

Point::givename(std::string n){
    name = n;
}

Point::symmetry_axisy(){
    B = Point(-x, y);
    B.name = name +"'";
}

Point::symmetry_axisx(){
    B = Point(x, -y);
    B.name = name +"'"+"'";
}

Point::distance(Point A, Point B){
   return std::sqrt(std::pow(A.x-B.x, 2) + pow(A.y-B.y, 2));
}

Point::~Point() {
  std::cout << "Destroying Point( " << x << " , " << y << " )" << std::endl;
}
