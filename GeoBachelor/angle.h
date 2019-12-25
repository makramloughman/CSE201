#pragma once
#include <iostream>
#include <string>
#include <vector>
//#include "segment.hpp"
#include <point.hpp>
#include "circle.hpp"
#include <mathobject.h>

class Angle :public MathObject
{
public:
    Point p1;
    Point m;
    Point p3;
    
    std::string name; 
    std::string get_name(); //for the display
    
    Angle(Point p1,Point m,Point p3);
    ~Angle();
    
    double get_angle_radian();
    double get_angle_degree();
    
    
    
};


