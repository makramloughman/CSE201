#pragma once
#include "point.hpp"
#include <iostream>
#include "segment.h"
#include "general_functions.h"

class Rectangle: public  MathObject
{
    private:
        //create point for rectangle
        Point p1;
        Point p2;
        Point p3;
        Point p4;

        int countpoints;
        std::string name;
        std::string get_name(); //for the display

    public:
        Rectangle(Point p1 , Point p2 , Point p3 );
        Rectangle(std::vector<QPointF> p);
        ~Rectangle();


        bool Verifier(Point p1, Point p2, Point p3);
        Point getlastpoint();

        virtual void draw();
        virtual void translate(double dx, double dy);
        virtual bool in_personal_area(double x, double y);



        double length();
        double width();
        double getPerimeter();
        double getArea();
        Point getCenter();
        Segment diagonale();
};
