#pragma once

class Point {

private:
    double x; 
    double y; 

    std::string name; //name of the point (a letter)
    //color //default color is black rgba(0,0,0)
    // shape (circle,cross,etc)

public : 

    //Creates Point(0,0)
    Point();

    Point(std::string mystring) //{
      //  name = mystring;
   // }

    //Creates a Point with given coordinates
    Point(double x, double y); 

    void clickpoint(); //creates a point where we click

    void display(); //displays the point in the window
    void displaycoordinates(); //shows the coordinates next to the label in the window

    void setx(double a); //changes the x coordinate
    void sety(double b); //changes the y coordinate

    void getx(); //gives the x coordinate
    void gety(); //gives the y coordinate
    
    void givename(std::string n); //changes the name of the point
    // void hidename(); //hides the name but not the point
    // void changeshape(); //changes the shape of the point 

    void changecolour(R,G,B); 
    void hide(); //hides the point by setting opacity level to 0

    void translate(); //moves the point in the window
    void display_trace(); //display the trace when the point is translate
    
    void symmetry_point(Point A, Point B); //it creates the symmetric point of A wtr to B
    void symmetry_axisy(); //creates the symmetric point with respect to the y axis
    void symmetry_axisx(); //creates the symmetric point with respect to the y axis

    void distance(Point A, Point B); //gives the distance between two points
    void angle(Point A, Point B, Point C); //gives the angle between three points

    ~Point(); //deletes the point
}
