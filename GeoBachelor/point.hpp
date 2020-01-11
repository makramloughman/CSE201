#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "mathobject.h"
#include <QGraphicsScene>

class Point : public MathObject
{
    private:
        double x;
        double y;
        double x_g; // grid coordinate x
        double y_g; // grid coordinate y
        std::vector<double> color; // vector of size 3x1 corresponding to rgb
        int shape; // 0 for dot; 1 for circle; 2 for cross...

    public :
        int countpoints;
        std::string name;
        std::string get_name(); //for the display

        //Creates Point(0,0)
        Point();

        //Creates a Point with given coordinates
        Point(double x, double y, int i);
        Point(double x, double y);
        Point(QPointF p);

        virtual void draw();
        virtual void translate(double dx, double dy); //moves the point in the window
        virtual bool in_personal_area(double x, double y);
        virtual void zoom(double coef, double c_x, double c_y);

        void drawName(int i);

        void clickpoint(); //creates a point where we click

        void display(); //displays the point in the window
        void displaycoordinates(); //shows the coordinates next to the label in the window

        void setx(double a); //changes the x coordinate
        void sety(double b); //changes the y coordinate

        double getx(); //gives the x coordinate
        double gety(); //gives the y coordinate
        double getxg(); //gives the x_g coordinate
        double getyg(); //gives the y_g coordinate

        void givename(std::string n); //changes the name of the point
        void hidename(); //hides the name but not the point
        void changeshape(); //changes the shape of the point

        void changecolour(double R,double G,double B);
        void hide(); //hides the point by setting opacity level to 0

        void display_trace(); //display the trace when the point is translate

        Point symmetry_point(Point A); //it creates the symmetric point of A wtr to B
        void symmetry_axisy(); //creates the symmetric point with respect to the y axis
        void symmetry_axisx(); //creates the symmetric point with respect to the y axis

        double distance(Point A); //gives the distance between two points
        double angle(Point A, Point B, Point C); //gives the angle between three points
        float radius_polarcoordinates(); //gives the radius from polar coordinates of the point (r,theta)
        float angle_polarcoordinates(); //gives the angle from polar coordinates of the point (r,theta)

        ~Point(); //deletes the point
};
