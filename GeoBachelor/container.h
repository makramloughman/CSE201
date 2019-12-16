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

class Container
{
public:
    std::vector<Point> points;
    std::vector<Line> lines;
    std::vector<Circle> circles;
    std::vector<Triangle> triangles;

    Container();
};

#endif // CONTAINER_H
