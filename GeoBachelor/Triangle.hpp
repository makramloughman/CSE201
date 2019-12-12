#pragma once
#include <point.hpp>
#include <circle.hpp>

class Triangle: public  MathObject
{
    private:
    //creates points for triangle
    Point point1;
    Point point2;
    Point point3;
    
    
    public:
    Triangle(Point point1 , Point point2 , Point point3);
    ~Triangle();
    double getArea();//
    double getHeight1();
    double getHeight2();
    double getHeight3();//
    double getPerimeter(); //
    bool equilateral();
    bool rectangle();
    bool isocele();
    //Segment getBaricentre1(); CHANGE LATER
    Point getCenterofgravity();//
    Point getOrthocenter();//
    Circle Circumscribedcercle();//
    Circle getInscribedcercle();//
};
