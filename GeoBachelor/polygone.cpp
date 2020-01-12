#include "polygone.h"
#include <mainwindow.h>
void Polygone::draw()
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    if(this->selected)
    {
        mainW->SetPen(3,Qt::blue);
    }

    std::vector<QPointF> help;
    for (uint i=0; i<Pointlist.size(); i++){
        help.push_back(mainW->mapToMyScene(Pointlist[i].getx(),Pointlist[i].gety()));
        qDebug() << Pointlist[i].getx() << Pointlist[i].gety();
    }
    mainW->drawPolygon(help);

    mainW->ResetPen();
}

bool Polygone::in_personal_area(double x, double y)
{
    for(uint i=0;i<Pointlist.size()-1;i++)
    {
        Segment* s = new Segment(Pointlist[i],Pointlist[i+1]);
        if(s->in_personal_area(x,y))
            return true;
    }
    Segment* s = new Segment(Pointlist[0],Pointlist[Pointlist.size()-1]);
    if(s->in_personal_area(x,y))
        return true;
    return false;
}

void Polygone::zoom(double coef, double c_x, double c_y)
{
    for(uint i=0;i<Pointlist.size();i++)
    {
        Pointlist[i].zoom(coef,c_x,c_y);
    }
}

void Polygone::translate(double dx, double dy)
{
    for (uint i=0; i<Pointlist.size() ;i++){
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

Polygone::Polygone(int k, std::vector<Point*> P) : MathObject()
{     // create the polygone by adding points to the list
    for(int i=0; i<k; i++)
    {
        Pointlist.push_back(*P[i]);
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
