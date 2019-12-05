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

 RegularPolygone::RegularPolygone() //empty regular polygone with empty vector of points 
 {
  std::vector<point> Pointlist
 }

 RegularPolygone::RegularPolygone(segment, number){
	
 }

 RegularPolygone::centerofcircumscribed(){
 	segment s1 = createsegment(Pointlist[0] , Pointlist[1])
	segement s2 = createsegment(Pointlist[1] , Pointlist[2])
	 
	m1 = this -> mediator(s1)
	m2 = this -> mediator(s2)
		
	return intersection(m1,m2) //need this
 }

 RegularPolygone::circumscribedcircle(){
	 point c = centerofcircumscribed()
	 double r = this->distance(c, Pointlist[0])
	 return Circle(c, r)
 }

 RegularPolygone::length(){
	 return this->distance(Pointlist[0],Pointlist[1])
 }

 RegularPolygone::angle(){
	 //noidea
 }
