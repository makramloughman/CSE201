#include "rectangle.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <segment.h>
#include <mainwindow.h>
#include <mathobject.h>


Rectangle::Rectangle(Point p1 ,Point p2 ,Point p3 ) : MathObject()
{
    if (Verifier(p1,p2,p3))
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->p4 = getlastpoint();
    }





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
    if (Verifier(p1,p2,p3))
    {
        this->p1 = p[0];
        this->p2 = p[1];
        this->p3 = p[2];
        this->p4 = getlastpoint();
    }

    
}

Rectangle:: ~Rectangle()
{
    //std::cout<<"Destroying Rectangle"<<std::endl;
}

Segment Rectangle::diagonale()
{
    Segment p1p2=Segment(p1,p2);
    Segment p2p3=Segment(p2,p3);
    Segment p1p3=Segment(p1,p3);

    double d1=p1p2.getlength();
    double d2=p2p3.getlength();
    double d3=p1p3.getlength();


    if ((sqrt(d1)==sqrt(d2)+sqrt(d3)))
        {
        return Segment(p1,p2);


    }

    if ((sqrt(d2)==sqrt(d1)+sqrt(d3)))
    {
        return Segment(p2,p3);

    }
    if  ((sqrt(d3)==sqrt(d2)+sqrt(d1)))
    {
        return Segment(p1,p3);

    }




}

bool Rectangle::Verifier(Point p1,Point p2,Point p3)
{
    Segment p1p2=Segment(p1,p2);
    Segment p2p3=Segment(p2,p3);
    Segment p1p3=Segment(p1,p3);

    double d1=p1p2.getlength();
    double d2=p2p3.getlength();
    double d3=p1p3.getlength();


    if ((sqrt(d1)==sqrt(d2)+sqrt(d3)))
        {
        Segment diagonal=Segment(p1,p2);

        return true ;
    }

    if ((sqrt(d2)==sqrt(d1)+sqrt(d3)))
    {
        Segment diagonal=Segment(p2,p3);
        return true;
    }

    if  ((sqrt(d3)==sqrt(d2)+sqrt(d1)))
    {
        Segment diagonal=Segment(p1,p3);
        return true;
    }

    else
    {
        return false;
    }


}

Point Rectangle::getlastpoint()
{
    MainWindow* mainW = MainWindow::getInstance();
    Point a=diagonale().p1;
    Point b=diagonale().p2;
    double f=a.getyg();
    double h=b.getyg();
    double fp=f*mainW->mainGrid->unit+mainW->mainGrid->getX();
    double hp=mainW->mainGrid->getY()-h*mainW->mainGrid->unit;

    if (a.getyg()>b.getyg())
        {


        return Point(fp,hp);
        }
    else
        {
           return Point(hp,fp)  ;
        }




}

void Rectangle::draw()
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    if(this->selected)
    {
        mainW->SetPen(3,Qt::blue);
    }

    std::vector<QPointF> help;
    help.push_back(mainW->mapToMyScene(p1.getx(),p1.gety()));
    help.push_back(mainW->mapToMyScene(p2.getx(),p2.gety()));
    help.push_back(mainW->mapToMyScene(p3.getx(),p1.gety()));
    help.push_back(mainW->mapToMyScene(p4.getx(),p4.gety()));
    mainW->drawPolygon(help);

    mainW->ResetPen();
}

void Rectangle::translate(double dx, double dy)
{

    p1.translate(dx,dy);
    p2.translate(dx,dy);
    p3.translate(dx,dy);
    p4.translate(dx,dy);
}

bool Rectangle::in_personal_area(double x, double y)
{
    return false;
}



