


Rectangle::Rectangle(const Point &p1, const Point &p2){
    this->point1 = p1;
    this->point2 = p2;
}

Rectangle::~ Rectangle(){
    delete(p1);
    delete(p2);
}

double Rectangle::length(){
    Point(p1.getx(),p2.gety()) B; 
        return distance(p1,B)
}

double Rectangle::width(){
    Point(p1.getx(),p2.gety()) B;
        return distance(p2,B)

}

double Rectangle::getPerimeter()const{
    return length()+width()
}

double Rectangle::getArea()const{
    return length()*width()
}

