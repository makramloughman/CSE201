
# pragma once

// include files for point and line
#include "point.hpp"
#include "line.hpp"
#include <vector>

class Ellipse: public MathObject{
    private:
    public:
        Point f1; // coordinates of one focal point
        Point f2; // coordinates of the second focal point
        double a; // size of semi-major axis

        virtual void draw();
        virtual void translate(double dx, double dy);
        virtual bool in_personal_area(double x, double y);
        virtual void zoom(double coef, double c_x, double c_y);

        Ellipse(Point* f1, Point* f2, double a); // constructor
        ~Ellipse(); //destructor
        Point getF1(); // gives coordinates of the first focal point
        Point getF2(); // gives coordinates of the second focal point
        double getX1(); // gives x coordinate of the first focal point
        double getY1(); // gives y coordinate of the first focal point
        double getX2(); // gives x coordinate of the second focal point
        double getY2(); // gives y coordinate of the second focal point
        std::vector<Line> tangent(Point M); // returns tangent lines from the point M
        double surface(); //returns surface of the ellipse
        double perimeter(); // returns perimeter of the ellipse - note that there is no exact formula for this, so numerical solution will be implemented 
        double get_b();// returns the size of the semi-minor axis
        double get_c(); //returns linear eccentricity of the ellipse
        double get_e(); // returns eccentricity of the ellipse
        Line majoraxis(); // returns major axis of the ellipse
        Line minoraxis(); //returns minor axis of the ellipse
};
