#pragma once
#include <point.hpp>
#include <line.hpp>
#include <cmath>
#include <mainwindow.h>
#include <iostream>

/*double distance(Point p1, Point p2)
{
    return sqrt(pow(p1.getx()-p2.getx(), 2) + pow(p1.gety()-p2.gety(), 2));
}
*/
/*
std::vector<Point> intersectionLL(Line *l1, Line *l2) //copied from Line.hpp
{
    std::vector<Point> vec;
    double a1 = l1->slope();
    double a2 = l2->slope();
    double b1 = l1->y_intercept();
    double b2 = l2->y_intercept();
    if ((a1-a2)>pow(10,-5)) //some thresh hold (since we wrote that vertical line have 10^10 slope (and not +inf)
    {
        double xstar = (b1 - b2)/(a2 - a1);
        double ystar = a1 * xstar + b1;
        vec.push_back(Point(xstar, ystar));
    }
    return vec;
}


std::vector<Point> intersection_SS(Segment segment1,Segment segment2)
{
    vector<Point> vec;

    Line line1= Line( segment1._point1 , segment1._point2);
    Line line2= Line( segment2._point1 , segment2._point2);

    double s1=line1.slope();
    double s2=line2.slope();
    double c1=line1.y_intersection();
    double c2=line2.y_intersection();

    Point inter_point= intersection(Line line1,Line line2);
     if ((0=<inter_point.getx()-segment1._point1.getx()/segment1._point2.getx()-segment1._point1.getx()<=1) &&
         (0=<inter_point.gety()-segment1._point1.gety()/segment1._point2.gety()-segment1._point1.gety()<=1) &&
         (0=<inter_point.getx()-segment2._point1.getx()/segment2._point2.getx()-segment2._point1.getx()<=1) &&
         (0=<inter_point.gety()-segment2._point1.gety()/segment2._point2.gety()-segment2._point1.gety()<=1))
    {
        vec.push_back(inter_point);
    }

    return vec;
}

vector<Point> interesection_LS(Line line ,Segment segment){
    vector<Point> vec;

    Line linebis= Line( segment._point1 , segment._point2);
    double s=linebis.slope();
    double c=linebis.y_intercept();
    Point inter_point= intersection(Line line ,Line linebis);
    
    if (0=<inter_point.getx()-segment._point1.getx()/segment._point2.getx()-segment._point1.getx()<=1) and 
    (0=<inter_point.gety()-segment._point1.gety()/segment._point2.gety()-segment._point1.gety()<=1){
        vec.push_back(inter_point);
    }

    return vec;
}

vector<Point> interesection_LS(Line line ,Segment segment){
    
    vector<Point> vec;

    Line linebis= Line( segment._point1 , segment._point2);
    double s=linebis.slope();
    double c=linebis.y_intercept();
    Point inter_point= intersection(Line line ,Line linebis);
    
    if (0=<inter_point.getx()-segment._point1.getx()/segment._point2.getx()-segment._point1.getx()<=1) and 
    (0=<inter_point.gety()-segment._point1.gety()/segment._point2.gety()-segment._point1.gety()<=1){
        
        vec.push_back(inter_point)
        
    }
   
    return vec;

}

std::vector<Point> intersection(Line line, Circle circle)
{
    
    std::vector<Point> vec;
    
    double s=line.slope();
    double c1=line.y_intercept();
    double a1=circle.getX();
    double b1=circle.getY();
    double r=circle.getR();

    double A=1+s*s;
    double B=2*(s*c1-s*b1-a1);
    double C=b1*b1-2*c1*b1+c1*c1+a1*a1-r*r;

      

    if (B*B-4*A*C>0){
        
        
        double x1=(-B+sqrt(B*B-4*A*C))/2*A;
        double y1=s*x1+c1;
        double x2=(-B-sqrt(B*B-4*A*C))/2*A;
        double y2=s*x2+c1;
        
        vec.push_back(Point(x1,y1));
        vec.push_back(Point(x2,y2));
      

    }

    if (B*B-4*A*C==0)
    {
    
        double x1=-B/2*A;
        double y1=s*x1+c1;

        vec.push_back(Point(x1,y1));

        
    }
    return vec;
  
}

std::vector<Point> intersection(Circle circle1,Circle circle2){

    std::vector<Point> vec;
    double x1=circle1.getX();
    double y1=circle1.getY();
    double r1=circle1.getR();
    double x2=circle2.getX();
    double y2=circle2.getY();
    double r2=circle2.getR();

    double d=distance(Point(x1,y1),Point(x2,y2));
    
    //d is the horizontal and vertical distances between the circle centers  

    if (d==0 and r1==r2){
        std::cout<<"There is infinite intersection"<< std::endl;
        return  vec;// infinite interesection ie:circles coincide
    }

    if (d>r1+r2){

        std::cout<<"There is not intersection"<<std::endl;
        return vec; //no interesection
    }

    if (d<abs(r1-r2)){

        std::cout<< "There is not interection one circle cointain the other one"<<std::endl;
        return vec; // One circle contain the other one 

    }
    if (d==r1+r2){
         double w1=x2-x1/(r1+r2)*r1+x1;
         double w2=y2-y1/(r1+r2)*r1+y1;

        vec.push_back(Point(w1,w2));
        
        return vec;

    }

    else {

    
       double a=(r1*r1-r2*r2+d*d) /2*d;
       double h=sqrt(r1*r1-a*a);

       //point 2 is the point where the line through 
       //he circle interesction points crosses the line 
       //between the circle centers.
       double q = (x2-x1)*a/d + x1;
       double s = (y2-y1)*a/d + y1;
       Point p2 = Point(q,s);
       
       double x3=q+h*(y2-y1)/d;
       double y3=s-h*(x2-x1)/d;
       double x4=q-h*(y2-y1)/d;
       double y4=s+h*(x2-x1)/d;
       
       vec.push_back(Point(x3,y3));
       vec.push_back(Point(x4,y4));

       return vec; 
    }
    

}


std::vector<Point> intersection_SC(Segment segment,Circle circle){
    
    vector<Point> vec;

    Line line_of_seg= Line( segment._point1 , segment._point2);
    double s=line_of_seg.slope();
    double c=line_of_seg.y_intercept();
    Point inter_point= intersection(Line line_of_seg ,Circle circle);

    if (0=<inter_point.getx()-segment._point1.getx()/segment._point2.getx()-segment._point1.getx()<=1) and 
    (0=<inter_point.gety()-segment._point1.gety()/segment._point2.gety()-segment._point1.gety()<=1){
        
        vec.push_back(inter_point);   
    }
    return vec;

}

vector<Point> intersection_PP(Polygone polygone1,Polygone polygone2){

}

*/

template <typename T1,typename T2> std::vector<Point*> intersection(T1 l1,T2 l2)
{
    std::vector<Point*> l{};
    return l;
}

template <> std::vector<Point*> intersection <int,int>(int l1, int l2)
{
    std::vector<Point*> vec{};
    /*
    double a1 = l1.slope();
    double a2 = l2.slope();
    double b1 = l1.y_intercept();
    double b2 = l2.y_intercept();
    if ((a1-a2)>pow(10,-5)) //some thresh hold (since we wrote that vertical line have 10^10 slope (and not +inf)
    {

        double xstar = (b1 - b2)/(a2 - a1);
        double ystar = a1 * xstar + b1;
        std::cout << "Destroying Point( " << xstar << " , " << ystar << " )" << std::endl;
        vec.push_back(new Point(xstar, ystar));
    }*/
    return vec;
}
