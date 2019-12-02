#pragma once
// include files for point and line
class Hyperbola: public Item{
    private:
        Point v1; // coordinates of the first vertex
        Point v2; // coordinates of the second vertex
        double b; // size of semi-minor axis
    public:
        Hyperbola(Point f1, Point f2m double a); // constructor
        ~Hyperbola(); // destructor
        Point getV1(); // gives coordinates of the first vertex
        Point getV2(); // gives coordinates of the second vertex
        double getX1(); // gives x coordinate of the first vertex
        double getY1(); // gives y coordinate of the first vertex
        double getX2(); // gives x coordinate of the second vertex
        double getY2(); // gives y coordinate of the second vertex
        Line tangent(Point M); // returns tangent lines from the point M
        Point focus1(); // returns one focus
        Point focus2(); // returns other focus
        double get_a();// returns the size of the semi-major axis
        double get_c(); //returns linear eccentricity of the hyperbola
        double get_e(); // returns eccentricity of the hyperbola
        Line majoraxis(); // returns major axis of the hyperbola
        Line minoraxis(); //returns minor axis of the hyperbola
        Line asymptotes(); // returns asymtotes of the hyperbola
};