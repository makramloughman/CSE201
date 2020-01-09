#pragma once
#include <math.h>
#include <iostream>
#include "point.hpp"
#include "line.hpp"
#include <iostream>
#include <vector>
#include "mathobject.h"
#include "point.hpp"

class Circle: public MathObject
{
    private:
        int countpoints;
        std::string name; 
        std::string get_name(); //for the display

    public:
        virtual void draw();
        virtual void translate(double dx, double dy);
        virtual bool in_personal_area(double x, double y);
        virtual void zoom(double coef, double c_x, double c_y);

        Point center; //center of the circle
        double r; // radius of the circle
        double r_t;
        Circle(Point& p, double r); //constructor
        Circle(Point& center, Point x);
        ~Circle(); // destructor
        double getX(); // returns x coordinate of the center
        double getY(); // returns y coordinate of the center
        double getR(); // returns radius
        void setX(double x); // set x coordinate of the center
        void setY(double y); // set y coordinate of the center
        void setR(double r); // set radius of the circle
        void movecenter(double x, double y); //moves the center to the position (x, y)
        double surface(); // returns surface of the circle
        double perimeter(); // returns perimeter of the circle
        double diameter(); // return diameter of the circle
        std::vector<Line> tangent(Point M); // returns tangents to the circle that contain point M
};


