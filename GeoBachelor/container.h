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

    std::vector<Point*> points; //tag of points is 0
    std::vector<Line*> lines; //tag of lines is 1
    std::vector<Circle*> circles; //tag of circles is 2
    std::vector<Segment*> segments; //tag of segments is 3
    std::vector<Triangle*> triangles; //tag of triangles is 4
    int number_of_bins; //it is 5 here => points,lines,circles,segments,triangles

    void move_refresh(double dx, double dy);
    void refresh();
    bool find_personal_and_store(Container &c,double x, double y); //also make AN object selected if possible

    void deselect();

    std::vector<bool> non_empty_tags(); //check which ones are non-empty => we need this for intersections

    int size();
private:


};

#endif // CONTAINER_H
