#include <general_functions.h>
#include <segment.h>

double distance(Point p1, Point p2)
{
    return sqrt(pow(p1.getx()-p2.getx(),2)+pow(p1.gety()-p2.gety(),2));
}

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

std::vector<Point> intersection(Circle circle, Line line)
{
    return intersection(line,circle);
}

std::vector<Point> intersection(Circle c1, Circle c2)
{
    double R = distance(c1.center,c2.center);
    std::vector<Point> vec;
    double r1 = c1.getR();
    double r2 = c2.getR();
    double x1 = c1.getX();
    double y1 = c1.getY();
    double x2 = c2.getX();
    double y2 = c2.getY();
    if (R<r1+r2)
    {
        double x  = (x2-x1)*(r1*r1-r2*r2)/(2*R*R) + (x1+x2)/2 + sqrt(2*(r1*r1+r2*r2)/(R*R)-pow((r1*r1-r2*r2),2)/pow(R,4)-1)*(y2-y1)/2;
        double xx = (x2-x1)*(r1*r1-r2*r2)/(2*R*R) + (x1+x2)/2 - sqrt(2*(r1*r1+r2*r2)/(R*R)-pow((r1*r1-r2*r2),2)/pow(R,4)-1)*(y2-y1)/2;
        double y  = (y2-y1)*(r1*r1-r2*r2)/(2*R*R) + (y1+y2)/2 + sqrt(2*(r1*r1+r2*r2)/(R*R)-pow((r1*r1-r2*r2),2)/pow(R,4)-1)*(x1-x2)/2;
        double yy = (y2-y1)*(r1*r1-r2*r2)/(2*R*R) + (y1+y2)/2 - sqrt(2*(r1*r1+r2*r2)/(R*R)-pow((r1*r1-r2*r2),2)/pow(R,4)-1)*(x1-x2)/2;
        vec.push_back(Point(x,y));
        vec.push_back(Point(xx,yy));
    }
    else if (abs(R-r1+r2)<pow(10,-5))
    {
        double x  = (x2-x1)*(r1*r1-r2*r2)/(2*R*R) + (x1+x2)/2 + sqrt(2*(r1*r1+r2*r2)/(R*R)-pow((r1*r1-r2*r2),2)/pow(R,4)-1)*(y2-y1);
        double y  = (y2-y1)*(r1*r1-r2*r2)/(2*R*R) + (y1+y2)/2 + sqrt(2*(r1*r1+r2*r2)/(R*R)-pow((r1*r1-r2*r2),2)/pow(R,4)-1)*(x1-x2);
        vec.push_back(Point(x,y));
    }

    return vec;
}

/*std::vector<Point> intersection(Segment segment1, Segment segment2)

{
    std::vector<Point> vec;
    Line line1= Line( segment1.p1 , segment1.p2);
    Line line2= Line( segment2.p1 , segment2.p2);


    Point inter_point=intersection(line1,line2)[0];
    double h1=(inter_point.getx()-segment1.p1.getx())/(segment1.p2.getx()-segment1.p1.getx());
    double h2=(inter_point.gety()-segment1.p1.gety())/(segment1.p2.gety()-segment1.p1.gety());
    double h3=(inter_point.getx()-segment2.p1.getx()/segment2.p2.getx()-segment2.p1.getx());
    double h4=(inter_point.gety()-segment2.p1.gety()/segment2.p2.gety()-segment2.p1.gety());
    if ((0<=h1<=1) && (0<=h2<=1) && (0<=h3<=1) && ((0<=h4<=1)))
    {
        vec.push_back(inter_point);
    }

    return vec;

}

*/
