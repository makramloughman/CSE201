#include "polygone.h"

void Polygone::draw()
{

}

bool Polygone::in_personal_area(double x, double y)
{
    return false;
}

void Polygone::translate(double dx, double dy)
{

}

Polygone::Polygone(){              // create the polygone by selecting points on the grid
    size = 0;
    Colour.push_back(0);
    Colour.push_back(0);
    Colour.push_back(0);
}

Polygone::Polygone(int k, std::vector<Point> P)
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

std::vector<double> Polygone::changeColour(double R, double G, double B)
{
    Colour = std::vector<double>{};
    Colour.push_back(R);
    Colour.push_back(G);
    Colour.push_back(B);
}

/*std::vector<Segment> Polygone::edges()
// get the edges
{
    return Pointlist;
}
*/
// duplicate

void Polygone::hide()
// hide the polygone
{
    Colour = std::vector<double>{};
    Colour.push_back(0);
    Colour.push_back(0);
    Colour.push_back(0);
}

Polygone::~Polygone()
// delete the polygone
{

}
