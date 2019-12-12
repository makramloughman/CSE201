#ifndef MATHOBJECT_H
#define MATHOBJECT_H


class MathObject
{
public:
    MathObject();
    virtual void draw();
    virtual void translate(double x,double y);
};

#endif // MATHOBJECT_H