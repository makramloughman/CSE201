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
    
    Point *array;
   

    
    double s=line.slope();
    double c=line.y_intercept();
    double a=circle.getX();
    double b=circle.getY();
    double r=circle.getR();

    double A=1+s*s;
    double B=2(s*c-s*b-a);
    double C=b*b-2c*b+c*c+a*a-r*r;

    if (B*B-4*A*C<0){
        return;
    }

    if (B*B-4*A*C>0){
        array=new Point[2];
        
        double x1=(-B+sqrt(B*B-4*A*C))/2*A;
        double y1=s*x1+c;
        double x2=(-B-sqrt(B*B-4*A*C))/2*A;
        double y2=s*x2+c;
        
        *array[0]=Point(x1,y1);
        *array[1]=Point(x2,y2);
        
        return *array

    }

    if (B*B-4*A*C=0){
        
        double x1=-B/2*A;
        double y1=s*x1+c;

        return Point(x1,y1);

    }
}

static interesection
