
class Triangle: public  Item{
    private:
    //creates points for triangle
    Point point1;
    Point point2;
    Point point3;
    
    
    public:
    double getArea();//
    double getHeight(); //
    double getParameter(); //
    Point getCenterofgravity();//
    Point getOrthocenter();//
    Circle Circumscribedcercle();//
    Circle getInscribedcercle();//
}