#include "Triangle.hpp"
Triangle::Triangle(double point1 ,double point2 ,double point3)
{
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
} 

Triangle:: ~Triangle(){
   delete(point1)  
   delete(point2)
   delete(point3)
}

double Triangle:: getArea(){
    segment s1 = new segment(&point1,&point2);
    a=s1.getlength();
    segment s2 = new segment(&point2,&point3);
    b=s2.getlength();
    segment s3 = new segment(&point1,&point3);
    c=s3.getlength();
    s=(a+b+c)/2
    return s*(s-a)*(s-b)*(s-c)
}

double Triangle::getPerimeter(){
    return a+b+c
}

bool Triangle::isocele(){
    segment s1 = new segment(&point1,&point2);
    segment s2 = new segment(&point2,&point3);
    segment s3 = new segment(&point1,&point3);
    if ((s1==s2) || (s2==s3) || (s1==s3)){
        return true ;
    }
    else return false; 
}

bool Triangle::equilateral(){
    segment s1 = new segment(&point1,&point2);
    segment s2 = new segment(&point2,&point3);
    segment s3 = new segment(&point1,&point3);
    if ((s1==s2) & (s2==s3)){
        return true 
    }
    else return false;
}

bool Triangle::rectangle(){
    if 
}






