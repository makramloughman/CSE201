#include <circle.hpp>
#include <mainwindow.h>

// include files for class Point

void Circle::draw()
{
    MainWindow* mainW = MainWindow::getInstance();
    QPointF help1 = QPointF(center.getx(),center.gety()+r);
    QPointF help = mainW -> mapToMyScene(help1.x(),help1.y());
    QPointF cen = mainW->mapToMyScene(center.getx(),center.gety()); //doesn't work?
    mainW->drawPoint(cen);
    mainW->drawCircle(cen,help);

}

void Circle::translate(double dx, double dy){

    center.translate(dx,dy);
}

bool Circle::in_personal_area(double x, double y)
{
    double ro = distance(Point(x,y),center);
    if (ro>r-5 && ro<r+5)
    {
        return true;
    }
    return false;
}

Circle:: Circle(Point &p, double r)
{
  this->center = p;
  this->r = r;
}

Circle::Circle(Point &center, Point x)
{
    this->center = center;
    this->r = sqrt(pow(x.getx()-center.getx(),2)+pow(x.gety()-center.gety(),2));
}

Circle:: ~Circle()
{
    std::cout << "Destroying Circle( " << center.getx() << " , " << center.gety() << " , "<< r <<" )"<< std::endl;

}

double Circle:: getX()
{
  return center.getx();
}

double Circle:: getY()
{
  return center.gety();
}

double Circle:: getR()
{
  return r;
}

void Circle:: setX(double x)
{
  double y = center.gety();
  center = Point(x, y);
}

void Circle:: setY(double y)
{
  double x = center.getx();
  center = Point(x,y);
}

void Circle:: setR(double r)
{
  (*this).r = r;
}

void Circle:: movecenter(double x, double y)
{
  setX(x);
  setY(y);
}

double Circle:: surface()
{
  return r*r*M_PI;
}

double Circle:: perimeter()
{
  return 2*r*M_PI;
}

double Circle::diameter()
{
  return 2*r;
}

std::vector<Line> Circle::tangent(Point M)
{
    std::vector<Line> l;
    double r = getR();
    double xp = M.getx();
    double yp = M.gety();
    double a = center.getx();
    double b = center.gety();
    double del = pow(xp-a,2)+pow(yp-b,2)-pow(r,2);

    std::cout<<xp<<" "<<yp<<" "<<a<<" "<<b<<" "<<r<<endl;

    if (del>0)
    {
        double x1 = (r*r*(xp-a)+r*(yp-b)*sqrt(del))/(pow(xp-a,2)+pow(yp-b,2)) + a;
        double y1 = (r*r*(yp-b)-r*(xp-a)*sqrt(del))/(pow(xp-a,2)+pow(yp-b,2)) + b;
        double x2 = (r*r*(xp-a)-r*(yp-b)*sqrt(del))/(pow(xp-a,2)+pow(yp-b,2)) + a;
        double y2 = (r*r*(yp-b)+r*(xp-a)*sqrt(del))/(pow(xp-a,2)+pow(yp-b,2)) + b;
        Point p1 = Point(x1,y1);
        Point p2 = Point(x2,y2);
        Line l1 = Line(p1,M);
        Line l2 = Line(p2,M);
        l.push_back(l1);
        l.push_back(l2);
    }
    else if (del==0)
    {
        double x1 = (r*r*(xp-a)+r*(yp-b)*sqrt(del))/(pow(xp-a,2)+pow(yp-b,2)) + a;
        double y1 = (r*r*(yp-a)-r*(xp-b)*sqrt(del))/(pow(xp-a,2)+pow(yp-b,2)) + b;
        Point p = Point(x1,y1);
        Line l1 = Line(p,M);
        l.push_back(l1);
    }

    return l;
  /*
  double x1 = M.getx();
  double y1 = M.gety();
  double x0 = center.getx();
  double y0 = center.gety();
  double d = (x0 -x1) * (x0 - x1) + (y0 -y1) * (y0-y1);
  if (x0 != x1)
  {
    double b = (d - 2 * r + y0*y0 - y1*y1 + x0*x0 - x1*x1) / (2*(x0 -x1));
    double a = (y1 -y0) / (x0 - x1);
    double n = a * a + 1;
    double m = 2 * a * (b - x0) - 2 * y0;
    double p = (b - x0) * (b -x0) + y0 * y0 - r * r;
    if (m*m - 4 * n * p < 0)
    {
      std::cout << "Tangent line does not exist" << std::endl;
    }
    else if (m*m - 4 * n * p == 0)
    {
      std::cout << "There is only one tangent line" << std::endl;
      double y = -m/(2 * n);
      double x = a * y + b;
      Point h = Point(x,y);
      l.push_back(Line(h, M));
    }
    else
    {
      double delta = sqrt(m * m - 4 * n * p);
      double yt1 = (-m - delta) / (2 * n);
      double yt2 = (-m + delta) / (2 * n);
      double xt1 = a * yt1 + b;
      double xt2 = a * yt2 + b;
      std::vector<Line> l;
      Point h1 = Point(xt1, yt1);
      Point h2 = Point(xt2, yt2);
      l.push_back(Line(h1, M));
      l.push_back(Line(h2, M));
      return l;
    }
    
  }
  else if (y1 != y0)
  {
    double b = (d - 2 * r + y0*y0 - y1*y1) / (2*(y0 -y1));
    double a = 0;
    double n = a * a + 1;
    double m = 2 * a * (b - y0) - 2 * x0;
    double p = (b - y0) * (b -y0) + x0 * x0 - r * r;
    if (m*m - 4 * n * p < 0)
    {
      std::cout << "Tangent line does not exist" << std::endl;
    }
    else if (m*m - 4 * n * p == 0)
    {
      std::cout << "There is only one tangent line" << std::endl;
      double x = -m/(2 * n);
      double y = a * x + b;
      Point h = Point(x,y);
      l.push_back(Line(h, M));
      return l;
    }
    else
    {
      double delta = sqrt(m * m - 4 * n * p);
      double xt1 = (-m - delta) / (2 * n);
      double xt2 = (-m + delta )/ (2 * n);
      double yt1 = a * xt1 + b;
      double yt2 = a * xt2 + b;

      Point h1 = Point(xt1, yt1);
      Point h2 = Point(xt2, yt2);
      l.push_back(Line(h1, M));
      l.push_back(Line(h2, M));
      return l;
    }
  }
  else
  {
    std::cout << "Tangent does not exist" << std::endl;
  }
    */
}
