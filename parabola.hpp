//include files for point and line
class Parabola{
    private:
        Point focus; // the focus of the parablaola
        Line directix; // the directrix of the parabola
    public:
        Point getF(); // returns the focus of the parabola
        Line getD(); // returns the directrix of the parabola
        Line symmetric(); // returns the line which separates the parabola into two identical mirror images
        Line tangent(Point M); // returns tangent lines from point M  
        Point vertex(); // returns the vertex of the parabola
};