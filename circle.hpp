// include files for point and line
class Circle{
    private:
        Point center; //center of the circle
        double r; // radius of the circle
    public:
        double getX(); // returns x coordinate of the center
        double getY(); // returns y coordinate of the center
        double getR(); // returns radius
        double surface(); // returns surface of the circle
        double perimeter(); // returns perimeter of the circle
        Line tangent(Point M); // returns tangents to the circle that contain point M
};


