#include <iostream>
#include <cmath>
#include <functions.hpp>
#include <mainwindow.h>
#include <general_functions.h>
#include <fparser.hh>
#include <fparser_mpfr.hh>
#include <fparser_gmpint.hh>
#include <segment.hpp>

//we will use a library called Function Parser for C++ which allows us to pass 
//from strings to real function expressions. The expression is first parsed into an expression tree. 
//Once this is done, the compiled tree structure is re-used with different variable values to achieve 
//very fast evaluation performance.


void Functions::draw_function(std::string s,"x")
{
    MainWindow* mainW = MainWindow::getInstance();
    QpointF p1 = mainW->mapFromViewToGrid(0,mainGrid-> getY());
    QpointF p2 = mainW->mapFromViewToGrid(mainW->getWidth_View(),mainGrid-> getY());
    double delta = (p2.x()-p1.x())/mainW->getWidth_View();
    FunctionParser fp;
    fp.Parse(s, v);
    double values[mainW->getWidth_View()+1]; //store the values computed by the function
    /*
    for ( int i = p1.x();i<=p2.x();i=i+delta)
    {
        double variables[1] = {i};
        double values[] = fp.Eval(variables);
        */

    for (int i =0; i <= mainW->getWidth_View(); i=i+1)
    {
        double variables[1] = {p1.x()+i*delta};
        double values[i] = fp.Eval(variables);
    }
    for (int j=0; j <= mainW->getWidth_View(); j=j+1)
    {
        Point* p1 = new Point(variables[j],values[j]);
        Point* p2 = new Point(variables[j+1], values[j+1])
        Segment* d= new Segment(*p1, *p2)
        *d.draw();
    }







}

