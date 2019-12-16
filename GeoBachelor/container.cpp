#include "container.h"

Container::Container()
{

}

void Container::push(Point *p)
{
    this->points.push_back(p);
}

void Container::push(Line *l)
{
    this->lines.push_back(l);
}

void Container::push(Circle *c)
{
    this->circles.push_back(c);
}

void Container::push(Triangle *t)
{
    this->triangles.push_back(t);
}


