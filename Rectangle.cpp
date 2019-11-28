


Rectangle::Rectangle(double p1, double p2){
    this->p1 = p1;
    this->p2 = p2;
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

double Rectangle::perimeter(){
    return length()+width()
}

double Rectangle::area(){
    return length()*width()
}

