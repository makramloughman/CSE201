#pragma once
#include <fparser.hh>
#include <iostream>
#include <cmath>

class Functions : public MathObject
{
    public:

    Functions(std::string exp);
    std::string expression; 
    std::string get_expression(); //in order to get the expression of the function
    double evaluate_function();
    virtual void draw();
    virtual void translate(double dx, double dy);
    virtual bool in_personal_area(double x, double y);
    virtual void zoom(double coef,double x, double y);
};
