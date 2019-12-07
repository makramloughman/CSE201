#include "point.hpp"
#include "segment.hpp"
#include "line.hpp"
#include "circle.hpp"
#include <iostream>
#pragma once
class Inter:
{
    public:
    static *intersection(Line line1,Line line2);
    //
    static *intersection(Line line,Segment segment);
    //
    static *intersection(Circle circle1, Circle circle2);
    //
    static *intersection(Line line,Circle circle);
    //
    static *intersection(Segment segment,Circle circle)
    //
}