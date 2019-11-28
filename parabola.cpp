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
  //TO BE IMPLEMENTED
}

Line Parabola:: tangent(Point M)
{
  //TO BE IMPLEMENTED
}

Point Parabola:: vertex()
{
  //TO BE IMPLEMENTED
}
