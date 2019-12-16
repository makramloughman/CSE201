#include <general_functions.h>

std::vector<Point> intersection(Line l1, Line l2)
{
    std::vector<Point> vec;
    double a1 = l1.slope();
    double a2 = l2.slope();
    double b1 = l1.y_intercept();
    double b2 = l2.y_intercept();
    if (a1!=a2) //some thresh hold (since we wrote that vertical line have 10^10 slope (and not +inf)
    {
        double xstar = (b1 - b2)/(a2 - a1);
        double ystar = a1 * xstar + b1;
        vec.push_back(Point(xstar, ystar));
    }
    return vec;
}

std::vector<Point> intersection(Line line,Circle circle){

    std::vector<Point> vec;
    double m=line.slope();
    double d=line.y_intercept();
    double a=circle.getX();
    double b=circle.getY();
    double r=circle.getR();

    double delta = r*r*(1+m*m)-pow((b-m*a-d),2);

    /*double A=1+s*s;
    double B=2*(s*c-s*b-a);
    double C=b*b-2*c*b+c*c+a*a-r*r;*/

    if (delta>0)
    {
        double x1=(a+b*m-d*m+sqrt(delta))/(1+m*m);
        double y1=(d+a*m+b*m*m+m*sqrt(delta))/(1+m*m);
        double x2=(a+b*m-d*m-sqrt(delta))/(1+m*m);
        double y2=(d+a*m+b*m*m-m*sqrt(delta))/(1+m*m);
        vec.push_back(Point(x1,y1));
        vec.push_back(Point(x2,y2));
    }

    if (delta==0)
    {
        double x1=(a+b*m-d*m)/(1+m*m);
        double y1=(d+a*m+b*m)/(1+m*m);
        vec.push_back(Point(x1,y1));
    }
    return vec;

}
