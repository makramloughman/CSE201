#pragma once
#include <mathobject.h>
#include <point.hpp>
#include <segment.hpp>

class Functions : public MathObject
{
    public:
    
    std::string expression; 
    std::string get_expression(); //in order to get the expression of the function
    double evaluate_function();
    virtual void draw_function(std::string s,"x");
    virtual void translate(double dx, double dy);
    virtual bool in_personal_area(double x, double y);

}
