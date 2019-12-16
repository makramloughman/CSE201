# inlcude parabola.hpp
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
