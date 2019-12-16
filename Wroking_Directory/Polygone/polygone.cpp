#include <iostream>
#iostream "Polygone.hpp"


Polygone::Polygone(){              // create the polygone by selecting points on the grid
	size = 0;
}

Polygone::Polygone(int k, vector<point> P){     // create the polygone by adding points to the list
	size = k;
	for(int i=0; i<size; i++) {
		Pointlist.pushback(P[i]);
	}
}
	
void Polygone::append(point) {   // append points to the list afterwards
	Pointlist.pushback(point);
}

double Polygone::surface()
// get the surface
{
	// double s= sum(PointList);
	double s = 0;
	for(int i=0;i<size;i++) s+=len[i];
	return s;
}

std::vector<Segment> Polygone::edges()
// get the edges
{
	return Pointlist;
}

// duplicate
void Polygone::duplicate(int k, vector<point> P) {
	// TO CHECK
	size = k;
	for(int i=0; i<size; i++) {
	Pointlist.pushback(P[i]);
}

std::vector<double> Polygone::hide()
// hide the polygone
{
	Colour.pushback(0.5);
}

// display the polygone
std::vector<double> Polygone::display() {
	Colour.pushback(0);
}

std::vector<double> Polygone::changeColour(R,G,B)
  // changes colour
{
	Colour.pushback(R);
	Colour.pushback(G);
	Colour.pushback(B);
}


Polygone::~Polygone()
// delete the polygone
{
	delete Point;
}


// REGULAR POLYGONES


 RegularPolygone::RegularPolygone() //empty regular polygone with empty vector of points 
 {
  std::vector<point> Pointlist
 }

 RegularPolygone::RegularPolygone(segment, number){
	
 }

 Point RegularPolygone:: centergravity(){
 	segment s1 = Segment(Pointlist[0] , Pointlist[1])
	segement s2 = Segment(Pointlist[1] , Pointlist[2])
	 
	m1 = this -> mediator(s1)
	m2 = this -> mediator(s2)
		
	return intersection(m1,m2) //need this
 }

 Circle RegularPolygone::circumscribedcircle(){
	 point c = centerofcircumscribed()
	 double r = this->distance(c, Pointlist[0])
	 return Circle(c, r)
 }

 double RegularPolygone::length(){
	 return this->distance(Pointlist[0],Pointlist[1])
 }

 float RegularPolygone::angle(){
       A = Pointlist[0].angle(Pointlist[1],Pointlist[2])
       return A
 }
