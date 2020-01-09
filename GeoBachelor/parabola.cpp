# include <parabola.hpp>
Parabola:: Parabola(Point f, Line d)
{
  focus = f;
  directrix = d;
}

Parabola:: ~Parabola()
{
  delete(focus);
  delete(directrix);
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
  return directrix.perpendicular(f);
}

Line Parabola:: tangent(Point M)
{
  //TO BE IMPLEMENTED
}

Point Parabola:: vertex()
{
  double xf = getX();
  double yf = getY();
  double k = d.slope();
  double n = d.y_intercept();
  double x = (-n + yf + xf/k) / (k + 1/k);
  double y = k * x + n;
  return Point( x + xf) / 2, (y+yf) / 2);
}

Line Parabola::tangent(point M){
  double x0 = M.getx();
  double y0 = M.gety();
  double b1 = d.y_intercept();
  double a1 = d.slope();
  double distance1 = M.distance(M,f);
  Line A = d.perpendicular(M);
  Point Astar = A.intersection(d);
  double distance2 = M.distance(M,Astar);
  if (distance2 < distance1){
    
