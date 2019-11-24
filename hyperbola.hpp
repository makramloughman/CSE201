// include files for point and line
class Hyperbola{
    private:
        Point f1; // coordinates of one focal point
        Point f2; // coordinates of the second focal point
        double a; // size of semi-major axis
    public:
        Point getX(); // gives coordinates of the first focal point
        Point getY(); // gives coordinates of the second focal point
        double getX1(); // gives x coordinate of the first focal point
        double getY1(); // gives y coordinate of the first focal point
        double getX2(); // gives x coordinate of the second focal point
        double getY2(); // gives y coordinate of the second focal point
        Line tangent(Point M); // returns tangent lines from the point M
        double get_b();// returns the size of the semi-minor axis
        double get_c(); //returns linear eccentricity of the hyperbola
        double get_e(); // returns eccentricity of the hyperbola
        Line majoraxis(); // returns major axis of the hyperbola
        Line minoraxis(); //returns minor axis of the hyperbola
        Line asymptotes(); // returns asymtotes of the hyperbola
};