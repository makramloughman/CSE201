#pragma once
#include <point.hpp>
#include <circle.hpp>
#include <segment.h>
#include <general_functions.h>

class Triangle: public  MathObject
{
    private:
    //creates points for triangle
    Point point1;
    Point point2;
    Point point3;
    
    int countpoints;
    std::string name; 
    std::string get_name(); //for the display

    public:
    Triangle(Point point1 , Point point2 , Point point3);
    Triangle(std::vector<QPointF> p);
    ~Triangle();

    virtual void draw();
    virtual void translate(double dx, double dy);
    virtual bool in_personal_area(double x, double y);
    Segment Baricenter2();
    Segment Baricenter3();
    double getArea();//
    double getHeight1();
    double getHeight2();
    double getHeight3();//
    double getPerimeter(); //
    bool equilateral();
    bool rectangle();
    bool isocele();
    Segment Baricenter1();
    Point getCenterofgravity();//
    Point getOrthocenter();//
    Circle Circumscribedcercle();//
    Circle getInscribedcercle();//

};
