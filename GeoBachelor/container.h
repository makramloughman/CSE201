#ifndef CONTAINER_H
#define CONTAINER_H
#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <point.hpp>
#include <line.hpp>
#include <circle.hpp>
#include <Triangle.hpp>
#include <segment.h>

class Container
{
public:
    Container();
    void push(Point* p);
    void push(Line* l);
    void push(Circle* c);
    void push(Triangle* t);
    void push(Segment* s);

    std::vector<Point*> points;
    std::vector<Line*> lines;
    std::vector<Circle*> circles;
    std::vector<Triangle*> triangles;
    std::vector<Segment*> segments;

private:


};

#endif // CONTAINER_H
