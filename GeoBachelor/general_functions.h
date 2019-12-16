#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H

#pragma once
#include <point.hpp>
#include <line.hpp>
#include <cmath>
#include <iostream>
#include <circle.hpp>
#include <vector>

std::vector<Point> intersection(Line l1, Line l2); //copied from Line.hpp
std::vector<Point> intersection(Line line,Circle circle);


#endif // GENERAL_FUNCTIONS_H
