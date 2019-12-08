#include "point.hpp"
#include "segment.hpp"
#include "line.hpp"
#include "circle.hpp"
#include <iostream>
#pragma once
class Inter:
{
    public:
    static *intersection_LL(Line line1,Line line2);
    //
    static *intersection_LS(Line line,Segment segment);
    //
    static *intersection_CC(Circle circle1, Circle circle2);
    //
    static *intersection_LC(Line line,Circle circle);
    //
    static *intersection_SC(Segment segment,Circle circle)
    //
}