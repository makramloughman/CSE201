#ifndef CONTAINER_H
#define CONTAINER_H
#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "segment.h"
#include <general_functions.h>
#include <regularpolygon.h>
#include <polygone.h>


class Container
{
    private:
        bool matching(Point p1, Point p2);

    public:
        Container();

        void push(Point* p);
        void push(Line* l);
        void push(Circle* c);
        void push(Triangle* t);
        void push(Segment* s);
        void push(Polygone* p);
        void push(RegularPolygone* rp);

        void remove(Point p);
        void remove(Point* p);
        void remove(Line l);
        void remove(Line* l);
        void remove(Circle c);
        void remove(Circle* c);
        void remove(Triangle t);
        void remove(Triangle* t);
        void remove(Segment s);
        void remove(Segment* s);
        void remove(Polygone* p);
        void remove(Polygone p);
        void remove(RegularPolygone* rp);
        void remove(RegularPolygone rp);

        std::vector<Point*> points;
        std::vector<Line*> lines;
        std::vector<Circle*> circles;
        std::vector<Segment*> segments;
        std::vector<Triangle*> triangles;
        std::vector<Polygone*> polygones;
        std::vector<RegularPolygone*> r_polygones;
        int number_of_bins; //it is 5 here => points,lines,circles,segments,triangles

        void move_refresh(double dx, double dy); //move all the objects bu dx.dy and refresh the grid
        void refresh(); //some refresh related to graphics
        bool find_personal_and_store(Container &c,double x, double y); //also make AN object selected if possible

        void deselect(); //deselect all the objects
        int size(); //return the size

        void empty_bins(); //clean the entire container
        void cleanFrom(Container &c); //remove all the elemnts which are in c

        void zoom(double coef, double c_x, double c_y);

        std::vector<Point*> IntersectObjects(); //this will give intersections between ALL the objects and the clean the Container
};

#endif // CONTAINER_H
