#include circle.cpp
#include math.h

Circle:: Circle(Point p, double r)
{
  center = p;
  radius = r;
}

Circle:: ~Circle()
{
  delete(p);
}

double Circle:: getX()
{
  return p.getx();
}

double Circle:: getY()
{
  return p.gety();
}

double Circle:: getR()
{
  return r;
}

double Circle:: setX(double x)
{
  double y = p.gety();
  center = new Point(x, y);
}

double Circle:: setY(double y)
{
  double x = p.getx();
  center = new Point(x,y);
}

double Circle:: setR(double r)
{
  (*this).r = r;
}

double Circle:: surface()
{
  return r*r*math.pi;
}

double Circle:: perimeter()
{
  return 2*r*math.pi;
}

double Circle::diameter()
{
  return 2*r;
}

Line Circle::tangent(Point m)
{
//for this I need class Line to be finished so I can correctly use its functions!!!!
}
