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
};

#endif // MATHOBJECT_H
