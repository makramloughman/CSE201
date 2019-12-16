#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H

#pragma once
#include <point.hpp>
#include <line.hpp>
#include <cmath>
#include <iostream>
#include <circle.hpp>
#include <vector>

double distance(Point p1, Point p2);
std::vector<Point> intersection(Line l1, Line l2); //copied from Line.hpp
std::vector<Point> intersection(Line line,Circle circle);
std::vector<Point> intersection(Circle circle,Line line);
std::vector<Point> intersection(Circle c1,Circle c2);

#endif // GENERAL_FUNCTIONS_H
