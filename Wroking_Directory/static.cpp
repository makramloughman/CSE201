#include "static.cpp"
#include<math.o>
using namespace std;

static * Inter::interesection(Line line1,Line line2)
    Point *array;

{
    double s1=line1.slope();
    double b1=line1.y_intercept();
    double s2=line2.slope();
    double b2=line2.y_intercept();

    if (s1==s2){
        return NULL
    }
    else{
    double x=(b2-b1)/(s2-s1)
    double y=s1*x+b1

    array=new Point[1]
    *array[0]=Point(x,y);
    return array;
    }
}
static * Inter::interesection(Line line ,Segment segment){
    Point *array;

    Line linebis= Line( segment._point1 , segment._point2);
    double s=linebis.slope();
    double c=linebis.y_intercept();
    Point inter_point= intersection(Line line ,Line linebis);
    
    if (0=<inter_point.getx()-segment._point1.getx()/segment._point2.getx()-segment._point1.getx()<=1) and 
    (0=<inter_point.gety()-segment._point1.gety()/segment._point2.gety()-segment._point1.gety()<=1){
        
        array= new Point[1];
        *array[0]=inter_point

        return array;
        
    }
    else{
        return NULL;
    }

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
        return NULL;   
    }

    if (B*B-4*A*C>0){
        array=new Point[2];
        
        double x1=(-B+sqrt(B*B-4*A*C))/2*A;
        double y1=s*x1+c;
        double x2=(-B-sqrt(B*B-4*A*C))/2*A;
        double y2=s*x2+c;
        
        *array[0]=Point(x1,y1);
        *array[1]=Point(x2,y2);
        return array;

    }

    if (B*B-4*A*C==0){
        array=new Point[1]
        double x1=-B/2*A;
        double y1=s*x1+c;

        *array[0]=Point(x1,y1)

        return array;
    }
  
}

static *intersection(Circle circle1,Circle circle2){

    Point *array;
    double x1=circle1.getX();
    double y1=cirlce1.getY();
    double r1=cirlce1.getR();
    double y1=circle2.getX();
    double y2=circle2.getY();
    double r2=circle2.getR();

    double d=distance(Point(x1,y1),Point(x2,y2));
    
    //d is the horizontal and vertical distances between the circle centers  

    if (d==0 and r1==r2){
        
        return NULL // infinite interesection ie:circles coincide
    }

    if (d>r1+r2){

        return NULL //no interesection
    }

    if (d<Math.Abs(r1-r2)){

        return NULL // One circle contain the other one 

    }
    if (d==r1+r2){
        array= new Point[0]
         double w1=x1-x2/(r1+r2)*r1+x2;
         double w2=y1-y2/(r0+r2)
        
        *array[0]=Point()

    }
}


