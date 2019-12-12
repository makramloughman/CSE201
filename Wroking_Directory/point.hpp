#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <mathobject.h>
#include <QGraphicsScene>

class Point : public MathObject
{

private:
    double x; 
    double y; 

    std::string name; //name of the point (a letter)
    std::vector<double> color; // vector of size 3x1 corresponding to rgb
    int shape; // 0 for dot; 1 for circle; 2 for cross...

    //int namecolor [3] //color of the point's name
        
public : 

    //Creates Point(0,0)
    Point();

    //Creates a Point with given coordinates
    Point(double x, double y); 
    Point(QPointF p);

    virtual void draw();
    virtual void translate(double c, double y); //moves the point in the window

    void clickpoint(); //creates a point where we click

    void display(); //displays the point in the window
    void displaycoordinates(); //shows the coordinates next to the label in the window

    void setx(double a); //changes the x coordinate
    void sety(double b); //changes the y coordinate

    double getx(); //gives the x coordinate
    double gety(); //gives the y coordinate
    
    void givename(std::string n); //changes the name of the point
    void hidename(); //hides the name but not the point
    void changeshape(); //changes the shape of the point 

    void changecolour(double R,double G,double B);
    void hide(); //hides the point by setting opacity level to 0

    void display_trace(); //display the trace when the point is translate
    
    void symmetry_point(Point A, Point B); //it creates the symmetric point of A wtr to B
    void symmetry_axisy(); //creates the symmetric point with respect to the y axis
    
    void symmetry_axisx(); //creates the symmetric point with respect to the y axis
    void symmetry_line(); //creates the symmetric point with respect to a line

    double distance(Point A, Point B); //gives the distance between two points
    double angle(Point A, Point B, Point C); //gives the angle between three points
    float radius_polarcoordinates(); //gives the radius from polar coordinates of the point (r,theta)
    float angle_polarcoordinates(); //gives the angle from polar coordinates of the point (r,theta)

    ~Point(); //deletes the point
};
