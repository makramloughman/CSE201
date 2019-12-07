#include "static.cpp"
using namespace std;

static Point Inter::interesection(Line line1,Line line2)
{
    double s1=line1.slope();
    double b1=line1.y_intercept();
    double s2=line2.slope();
    double b2=line2.y_intercept();

    double x=(b2-b1)/(s2-s1)
    double y=s1*x+b1
    
    return Point(x,y)

}

static * Inter::intersection(Line line,Circle circle){
    
    
    double s=line.slope();
    double c=line.y_intercept();
    double a=circle.getX();
    double b=circle.getY();
    double r=circle.getR();

    double A=1+s*s;
    double B=2(s*c-s*b-a);
    double C=b*b-2c*b+c*c+a*a-r*r;

    if (B*B-4*A*C){

    }
}
