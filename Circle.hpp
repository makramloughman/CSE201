class Circle{
    private:
        Point center; //center of the circle
        double r; // radius of the circle
    public:
        double getX();
        double getY();
        double getR();
        double surface();
        double perimeter();
        Line tangent(Point M);
};


