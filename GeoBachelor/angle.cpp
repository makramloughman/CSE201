#include "angle.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <mainwindow.h>

Angle::Angle(Point p1,Point m,Point p3)
{
    this->p1=p1;
    this->m=m;
    this->p3=p3;
}

Angle::~Angle()
{
    //std::cout<< "Destroying Angle"<<std::endl;
}

double Angle::get_angle_radian()
{
    double p1x=p1.getx();
    double mx=m.getx();
    double p3x=p3.getx();
    double p1y=p1.gety();
    double my=m.gety();
    double p3y=p3.gety();

    double numerator=p1y*(mx-p3x)+my*(p3x-p1x)+p3y*(p1x-mx);
    double denominator=(p1x-mx)*(mx-p3x)+(p1y-my)*(my-p3y);
    double ratio=numerator/denominator;

    return atan(ratio);
}

double Angle::get_angle_degree()
{
    double angleRad=get_angle_radian();
    double angleDeg=(angleRad*180)/M_PI;
    if (angleDeg<0){
        angleDeg=180+angleDeg;

    }

    return angleDeg;
}
