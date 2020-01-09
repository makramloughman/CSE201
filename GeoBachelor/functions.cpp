#include <mainwindow.h>
#include <functions.hpp>


//we will use a library called Function Parser for C++ which allows us to pass 
//from strings to real function expressions. The expression is first parsed into an expression tree. 
//Once this is done, the compiled tree structure is re-used with different variable values to achieve 
//very fast evaluation performance.


Functions::Functions(std::string exp)
{
    this->expression=exp;
}

void Functions::draw()
{
    MainWindow* mainW = MainWindow::getInstance();
    QPointF p1 = mainW->mapFromViewToGrid(0,mainW->mainGrid-> getY());
    QPointF p2 = mainW->mapFromViewToGrid(mainW->getWidth_View(),mainW->mainGrid-> getY());
    int n = 2*mainW->getWidth_View();
    double delta = (p2.x()-p1.x())/ n;
    FunctionParser fp;
    fp.Parse(expression, "x");
    double values[n+1];
    //store the values computed by the function
    /*
    for ( int i = p1.x();i<=p2.x();i=i+delta)
    {
        double variables[1] = {i};
        double values[] = fp.Eval(variables);
        */

    for (int i =0; i <= n; i=i+1)
    {
        double variables[1] = {p1.x()+i*delta};
        values[i] = fp.Eval(variables);
    }
    for (int j=0; j <= n; j=j+1)
    {
        Point* p11 = new Point(p1.x()+j*delta,values[j]);
        Point* p21 = new Point(p1.x()+(j+1)*delta, values[j+1]);
        Point* a = new Point(mainW->mapFromGridToView(p11->getx(),p11->gety()));
        Point* b = new Point(mainW->mapFromGridToView(p21->getx(),p21->gety()));

        Segment* d= new Segment(*a, *b);
        d->draw();

    }
}

void Functions::translate(double dx, double dy)
{

}

bool Functions::in_personal_area(double x, double y)
{
    return false;
}

void Functions::zoom(double coef, double x, double y)
{

}

