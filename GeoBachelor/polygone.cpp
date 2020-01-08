#include "polygone.h"
#include <mainwindow.h>
void Polygone::draw()
{

    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    if(this->selected)
    {
        mainW->SetPen(3,Qt::blue);
    }

    int i;
    std::vector<QPointF> help;
    for (i=0; i<size; i++){
    help.push_back(mainW->mapToMyScene(Pointlist[i].getx(),Pointlist[i].gety()));
    }
    mainW->drawPolygon(help);

    mainW->ResetPen();

}

bool Polygone::in_personal_area(double x, double y)
{
    return false;
}

void Polygone::translate(double dx, double dy)
{
    int i;
    for (i=0; i<size ;i++){
        Pointlist[i].translate(dx,dy);
    }

}

Polygone::Polygone() : MathObject()
{              // create the polygone by selecting points on the grid
    size = 0;
    Colour.push_back(0);
    Colour.push_back(0);
    Colour.push_back(0);
}

Polygone::Polygone(int k, std::vector<Point> P) : MathObject()
{     // create the polygone by adding points to the list
    for(int i=0; i<k; i++)
    {
        Pointlist.push_back(P[i]);
    }
}

void Polygone::append(Point p)
{   // append points to the list afterwards
    Pointlist.push_back(p);
}

Polygone::~Polygone()
// delete the polygone
{
    std::cout << "Destroying Polygone" << std::endl;
}
