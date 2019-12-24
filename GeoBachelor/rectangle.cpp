#include "rectangle.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <mainwindow.h>



Rectangle::Rectangle(Point p1 ,Point p3 ) : MathObject()
{
    this->p1 = p1;
    this->p3 = p3;


    // function to make global
    /*
    std::string s("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if (countpoints >= 26) {
        countpoints_2 = (countpoints / 26) - 1;
        this -> name = s.at( countpoints_2 % s.size() ) + s.at( countpoints % s.size() ); }
    else { this->name = s.at( countpoints % s.size() ); }
    countpoints += 1; // add 1 to the counter
    */
}

Rectangle::Rectangle(std::vector<QPointF> p)
{
    this->p1=p[0];
    this->p3=p[1];
}

Rectangle:: ~Rectangle()
{
    //std::cout<<"Destroying Rectangle"<<std::endl;
}


Point Rectangle::get_p2()
{
    return Point(p3.getx(),p1.gety());
}

Point Rectangle::get_p4()
{

   return Point(p1.getx(),p3.gety());
}

void Rectangle::draw()
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    if(this->selected)
    {
        mainW->SetPen(3,Qt::blue);
    }

    Point p2=get_p2();
    Point p4=get_p4();
    std::vector<QPointF> help;
    help.push_back(mainW->mapToMyScene(p1.getx(),p1.gety()));
    help.push_back(mainW->mapToMyScene(p2.getx(),p2.gety()));
    help.push_back(mainW->mapToMyScene(p3.getx(),p3.gety()));
    help.push_back(mainW->mapToMyScene(p4.getx(),p4.gety()));
    mainW->drawPolygon(help);

    mainW->ResetPen();
}

void Rectangle::translate(double dx, double dy)
{
    Point p2=get_p2();
    Point p4=get_p4();
    p1.translate(dx,dy);
    p2.translate(dx,dy);
    p3.translate(dx,dy);
    p4.translate(dx,dy);
}

bool Rectangle::in_personal_area(double x, double y)
{
    return false;
}

