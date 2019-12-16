
#include <general_functions.h>

std::vector<Point> intersetion(Line l1, Line l2)
{
    std::vector<Point> vec;
    double a1 = l1.slope();
    double a2 = l2.slope();
    double b1 = l1.y_intercept();
    double b2 = l2.y_intercept();
    if ((a1-a2)>pow(10,-5)) //some thresh hold (since we wrote that vertical line have 10^10 slope (and not +inf)
    {
        double xstar = (b1 - b2)/(a2 - a1);
        double ystar = a1 * xstar + b1;
        vec.push_back(Point(xstar, ystar));
    }
    return vec;
}
