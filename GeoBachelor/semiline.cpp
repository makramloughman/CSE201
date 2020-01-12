#include <mainwindow.h>
#include <semiline.hpp>

void SemiLine::draw()
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    if(this->selected)
    {
        mainW->SetPen(3 , Qt::blue);
    }
    QPointF f1 = QPointF(p1.getx(),p1.gety());
    QPointF f2 = QPointF(p2.getx(),p2.gety());
    mainW -> drawSemiLine(f1,f2); //Remark: We save data in Grid coordinates, so we need conversion
    mainW->ResetPen();
}

void SemiLine::translate(double dx, double dy)
{
    p1.setx(p1.getx()+dx);
    p1.sety(p1.gety()+dy);
    p2.setx(p2.getx()+dx);
    p2.sety(p2.gety()+dy);

}

bool SemiLine::in_personal_area(double x, double y)
{
    Line* l = new Line(p1,p2);
    bool b = l->in_personal_area(x,y);
    if(!b)
    {
        return false;
    }

    if(p1.getx()>p2.getx())
    {
        if(x<p1.getx()+2)
        {
            return true;
        }
    }

    if(p1.getx()<p2.getx())
    {
        if(x>p1.getx()-2)
        {
            return true;
        }
    }
    return false;
}

void SemiLine::zoom(double coef, double c_x, double c_y)
{
    p1.zoom(coef,c_x,c_y);
    p2.zoom(coef,c_x,c_y);
}


SemiLine::SemiLine(Point p1, Point p2)
{
    this->p1 = p1;
    this->p2 = p2;
}
 
double SemiLine::slope(){
  double slope;
  Line* l = new Line(p1, p2);
  return l->slope();
}

double SemiLine::y_intercept(){
  Line* l = new Line(p1, p2);
  return l->y_intercept();
}

Line SemiLine::perpendicular(Point p3){
  Line* l = new Line(p1, p2);
  return l->perpendicular( p3 );
  }

Line SemiLine::parallel(Point p3){
  Line* l = new Line(p1, p2);
  return l->parallel(p3);
  }

Point SemiLine::intersection(Line B){
  Line* l = new Line(p1, p2);
  return l->intersection(B);
  }
