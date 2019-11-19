#pragma once

class Point {

private:
    double x; 
    double y; 

    std::string name; //name of the point (a letter)
    // shape shape (circle,cross,etc)

public : 

    //Creates Point(0,0)
    Point()//{
      //  name = "";
    //}

    Point(std::string mystring) //{
      //  name = mystring;
   // }

    //Creates a Point with given coordinates
    Point(double x, double y); 

    void clickpoint(); //creates a point where we click

    void display(); //displays the point in the window
    void displaycoordinates(); //shows the coordinates next to the label in the window yhy

    void setx(); //changes the x coordinate
    void sety(); //changes the y coordinate

    void getx(); //gives the x coordinate
    void gety(); //gives the y coordinate
    
    // void givename(); //changes the name of the point
    // void hidename(); //hides the name but not the point
    // void changeshape(); //changes the shape of the point 

    void changecolour();
    void hide(); //hides the point

    void translate(); //moves the point in the window
    void display_trace(); //display the trace when the point is translate
    
    void symmetry_point(); //it creates the symmetric point by clicking on the point then the center of symmetry
    void symmetry_axis(); //creates the symmetric point with respect to the frame axis

    void distance(); //gives the distance between two points
    void angle(); //gives the angle between three points

    ~Point(); //deletes the point


    

}
