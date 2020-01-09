#pragma once
//include files for point and line
#include "line.hpp"
#include "point.hpp"

class Parabola: public MathObject
{
    private:
        Point focus; // the focus of the parablaola
        Line directrix; // the directrix of the parabola
    public:
    
        virtual void draw();
        virtual void translate(double dx, double dy);
        virtual bool in_personal_area(double x, double y);
    
        Parabola(Point f, Line d); // constructor
        ~Parabola(); // destructor
        Point getF(); // returns the focus of the parabola
        double getX(); // returns x coordinate of the focus
        double getY(); // returns y coordinate of the focus
        Line getD(); // returns the directrix of the parabola
        Line symmetric(); // returns the line which separates the parabola into two identical mirror images
        Line tangent(Point M); // returns tangent lines from point M  
        Point vertex(); // returns the vertex of the parabola
};
