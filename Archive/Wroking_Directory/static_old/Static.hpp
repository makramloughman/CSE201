#include "point.hpp"
#include <iostream>
#include "segment.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "point.hpp"
#pragma once

class Inter:
{
public:
    static Point intersection(Line line1 , Line line2);
    static Point intersection(Line line, Segment segment);
    static Poinintersection(Circle circle1, Circle circle2);
    static Point intersection(Circle circle, )