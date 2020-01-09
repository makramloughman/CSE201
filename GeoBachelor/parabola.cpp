# include <parabola.hpp>
Parabola:: Parabola(Point f, Line d)
{
  focus = f;
  directrix = d;
}

Parabola:: ~Parabola()
{
      std::cout << "Destroying Parabola: focus: ( " << focus.getx() << " , " << focus.gety() << " ), directrix: y =  "<< directrix.slope() << "* x + " << directrix.y_intercept() << std::endl;
}

Point Parabola:: getF()
{
  return focus;
}

double Parabola:: getX()
{
  return focus.getx();
}

double Parabola:: getY()
{
  return focus.gety();
}

Line Parabola:: getD()
{
  return directrix;
}

Line Parabola:: symmetric()
{
  return directrix.perpendicular(focus);
}

Point Parabola:: vertex()
{
  double xf = getX();
  double yf = getY();
  double k = directrix.slope();
  double n = directrix.y_intercept();
  double x = (-n + yf + xf/k) / (k + 1/k);
  double y = k * x + n;
  return Point( (x + xf) / 2, (y+yf) / 2);
}

/*Line Parabola::tangent(Point M){
  double x0 = M.getx();
  double y0 = M.gety();
  double b1 = directrix.y_intercept();
  double a1 = directrix.slope();
  double distance1 = M.distance(M,focus);
  Line A = directrix.perpendicular(M);
  Point Astar = A.intersection(directrix);
  double distance2 = M.distance(M,Astar);
  if (distance2 < distance1){
  */
    
