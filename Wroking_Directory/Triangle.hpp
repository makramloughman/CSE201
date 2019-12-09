
class Triangle: public  Item{
    private:
    //creates points for triangle
    Point point1;
    Point point2;
    Point point3;
    
    
    public:
    double getArea();//
    double getHeight1();
    double getHeight2();
    double getHeight3();//
    double getParameter(); //
    bool equilateral();
    bool rectangle();
    bool isocele();
    Segment getBaricentre1();
    Point getCenterofgravity();//
    Point getOrthocenter();//
    Circle Circumscribedcercle();//
    Circle getInscribedcercle();//
}