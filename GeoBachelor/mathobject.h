#ifndef MATHOBJECT_H
#define MATHOBJECT_H
#pragma once

class MathObject
{
public:
    MathObject();
    virtual void draw();
    virtual void translate(double dx,double dy);
    virtual bool in_personal_area(double x, double y);
    virtual ~MathObject();
    virtual void zoom(double coef,double c_x, double c_y);
    bool selected;
};

#endif // MATHOBJECT_H
