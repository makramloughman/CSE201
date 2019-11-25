#pragma once
// include files for point and line
class Circle{
    private:
        Point center; //center of the circle
        double r; // radius of the circle
    public:
        Circle(Point p, radius r); //constructor
        ~Circle(); // destructor
        double getX(); // returns x coordinate of the center
        double getY(); // returns y coordinate of the center
        double getR(); // returns radius
        double setX(double x); // set x coordinate of the center
        double setY(double y); // set y coordinate of the center
        double setR(double r); // set radius of the circle
        double surface(); // returns surface of the circle
        double perimeter(); // returns perimeter of the circle
        double diameter(); // return diameter of the circle
        Line tangent(Point M); // returns tangents to the circle that contain point M
};


