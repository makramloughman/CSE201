#include <iostream>
#iostream "Polygone.hpp"


Polygone::Polygone(){
	std::vector<point> Point;
}

void Polygone::append(point) {
// append points to the list
	push_back(point);
}

Polygone::~Polygone()
// delete the polygone
{
	delete(PointList)
}

double PointList::surface()
// get the surface
{
	double s= sum(PointList);
	return s;
}

void Polygone::hide()
// hide the polygone
{
	this -> color = rgba(0,0,0,0.5);
}

void Polygone::changecolour(R,G,B)
  // changes colour
{
	this -> colour = rgba(R,G,B);
}
