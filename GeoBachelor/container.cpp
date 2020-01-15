#include "container.h"
#include <iostream>

bool Container::matching(Point p1, Point p2)
{
    return (p1.getx()==p2.getx() && p1.gety()==p2.gety());
}

bool Container::check_if_in(Point p)
{
    for(uint i=0; i<points.size();i++)
    {
        if (distance(*points[i],p)<2.5)
        {
            return true;
        }

    }
    return false;
}


Container::Container()
{
    this->number_of_bins = 7;
}

void Container::push(Point *p)
{
    this->points.push_back(p);
}

void Container::push(Line *l)
{
    this->lines.push_back(l);
}

void Container::push(Circle *c)
{
    this->circles.push_back(c);
}

void Container::push(Triangle *t)
{
    this->triangles.push_back(t);
}

void Container::push(Segment *s)
{
    this->segments.push_back(s);
}

void Container::push(Polygone *p)
{
    polygones.push_back(p);
}

void Container::push(RegularPolygone *rp)
{
    r_polygones.push_back(rp);
}

void Container::push(Functions *f)
{
    functions.push_back(f);
}

void Container::push(Ellipse *e)
{
    ellipses.push_back(e);
}

void Container::push(SemiLine *s)
{
    semi_lines.push_back(s);
}

void Container::remove(Point p)
{
    std::vector<int> pos;
    for (uint i=0;i<points.size();i++)
    {
        if(matching(p,*points[i]))
        {
            pos.push_back(i);
        }
    }
    for (uint i=0;i<pos.size();i++)
    {
        points.erase(points.begin()+pos[i]-i);
    }
}

void Container::remove(Point *p)
{
    remove(*p);
}

void Container::remove(Line l)
{
    std::vector<int> pos;
    for (uint i=0;i<lines.size();i++)
    {
        if (matching(lines[i]->p1,l.p1) && matching(lines[i]->p2,l.p2))
        {
            pos.push_back(i);
        }
    }
    for (uint i=0;i<pos.size();i++)
    {
        lines.erase(lines.begin()+pos[i]-i);
    }
}

void Container::remove(Line* l)
{
    remove(*l);
}

void Container::remove(Circle c)
{
    std::vector<int> pos;
    for (uint i=0;i<circles.size();i++)
    {
        if (matching(circles[i]->center,c.center) && circles[i]->getR()==c.getR())
        {
            pos.push_back(i);
        }
    }
    for (uint i=0;i<pos.size();i++)
    {
        circles.erase(circles.begin()+pos[i]-i);
    }
}

void Container::remove(Circle* c)
{
    remove(*c);
}

void Container::remove(Triangle t)
{
    std::vector<int> pos;
    for (uint i=0;i<triangles.size();i++)
    {
        if (matching(triangles[i]->point1,t.point1) && matching(triangles[i]->point2,t.point2) && matching(triangles[i]->point3,t.point3))
        {
            pos.push_back(i);
        }
    }
    for (uint i=0;i<pos.size();i++)
    {
        triangles.erase(triangles.begin()+pos[i]-i);
    }
}

void Container::remove(Triangle* t)
{
    remove(*t);
}

void Container::remove(Segment s)
{
    std::vector<int> pos;
    for (uint i=0;i<segments.size();i++)
    {
        if (matching(segments[i]->p1,s.p1) && matching(segments[i]->p2,s.p2))
        {
            pos.push_back(i);
        }
    }
    for (uint i=0;i<pos.size();i++)
    {
        segments.erase(segments.begin()+pos[i]-i);
    }
}

void Container::remove(Segment* s)
{
    remove(*s);
}

void Container::remove(Polygone *p)
{
    remove(*p);
}

void Container::remove(Polygone p)
{
    std::vector<int> pos;
    for (uint i=0;i<polygones.size();i++)
    {
        bool match = true;
        for(uint j=0;j<polygones[i]->Pointlist.size();j++)
        {
           if(!matching(polygones[i]->Pointlist[j],p.Pointlist[j]))
           {
               match = false;
           }
        }
        if(match)
        {
            pos.push_back(i);
        }
    }
    for (uint i=0;i<pos.size();i++)
    {
        polygones.erase(polygones.begin()+pos[i]-i);
    }
}

void Container::remove(RegularPolygone *rp)
{
    remove(*rp);
}

void Container::remove(RegularPolygone rp)
{
    std::vector<int> pos;
    for (uint i=0;i<r_polygones.size();i++)
    {
        bool match = true;
        for(uint j=0;j<r_polygones[i]->Pointlist.size();j++)
        {
           if(!matching(r_polygones[i]->Pointlist[j],rp.Pointlist[j]))
           {
               match = false;
           }
        }
        if(match)
        {
            pos.push_back(i);
        }
    }
    for (uint i=0;i<pos.size();i++)
    {
        r_polygones.erase(r_polygones.begin()+pos[i]-i);
    }
}

void Container::remove(Functions f)
{
    std::vector<int> pos;
    for (uint i=0;i<functions.size();i++)
    {
        if(f.expression==functions[i]->expression)
        {
            pos.push_back(i);
        }
    }
    for (uint i=0;i<pos.size();i++)
    {
        functions.erase(functions.begin()+pos[i]-i);
    }
}

void Container::remove(Ellipse *e)
{
    remove(*e);
}

void Container::remove(Ellipse e)
{
    std::vector<int> pos;
    for (uint i=0;i<ellipses.size();i++)
    {
        if(matching(ellipses[i]->f1,e.f1)&&matching(ellipses[i]->f2,e.f2)&&ellipses[i]->a==e.a)
        {
            pos.push_back(i);
        }
    }
    for (uint i=0;i<pos.size();i++)
    {
        ellipses.erase(ellipses.begin()+pos[i]-i);
    }
}

void Container::remove(SemiLine *s)
{
    remove(*s);
}

void Container::remove(SemiLine s)
{
    std::vector<int> pos;
    for (uint i=0;i<semi_lines.size();i++)
    {
        if (matching(semi_lines[i]->p1,s.p1) && matching(semi_lines[i]->p2,s.p2))
        {
            pos.push_back(i);
        }
    }
    for (uint i=0;i<pos.size();i++)
    {
        semi_lines.erase(semi_lines.begin()+pos[i]-i);
    }
}

bool Container::check_if_selected(Segment s)
{
    for (uint i = 0;i<segments.size();i++)
    {
         if(((matching(segments[i]->p1,s.p1) && matching(segments[i]->p2,s.p2))||(matching(segments[i]->p2,s.p1) && matching(segments[i]->p1,s.p2))) && segments[i]->selected)
         {
             return true;
         }
    }
    return false;
}

bool Container::check_if_in(Segment s)
{
    for (uint i = 0;i<segments.size();i++)
    {
         if(((matching(segments[i]->p1,s.p1) && matching(segments[i]->p2,s.p2))||(matching(segments[i]->p2,s.p1) && matching(segments[i]->p1,s.p2))))
         {
             return true;
         }
    }
    return false;
}

void Container::remove(Functions *f)
{
    remove(*f);
}

void Container::move_refresh(double dx, double dy)
{
    for(uint i=0;i<circles.size();i++)
    {
        circles[i]->translate(dx,dy);
        circles[i]->draw();
    }
    for(uint i=0;i<lines.size();i++)
    {
        lines[i]->translate(dx,dy);
        lines[i]->draw();
    }
    for(uint i=0;i<segments.size();i++)
    {
        segments[i]->translate(dx,dy);
        segments[i]->draw();
    }
    for(uint i=0;i<triangles.size();i++)
    {
        triangles[i]->translate(dx,dy);
        triangles[i]->draw();
    }

    for(uint i=0;i<polygones.size();i++)
    {
        polygones[i]->translate(dx,dy);
        polygones[i]->draw();
    }


    for(uint i=0;i<r_polygones.size();i++)
    {
        r_polygones[i]->translate(dx,dy);
        r_polygones[i]->draw();
    }

    for(uint i=0;i<ellipses.size();i++)
    {
        ellipses[i]->translate(dx,dy);
        ellipses[i]->draw();
    }

    for(uint i=0;i<semi_lines.size();i++)
    {
        semi_lines[i]->translate(dx,dy);
        semi_lines[i]->draw();
    }

    for(uint i=0;i<functions.size();i++)
    {
        functions[i]->draw();
    }

    for(uint i=0;i<points.size();i++) //ORDER MATTERS
    {
        points[i]->translate(dx,dy);
        points[i]->draw();
        points[i]->drawName(i);
    }
}

void Container::refresh()
{
    move_refresh(0,0);
}

bool Container::find_personal_and_store(Container &c, double x, double y)
{
    for(uint i=0;i<points.size();i++)
    {
        bool b =points[i] -> in_personal_area(x,y);

        if(b)
        {
            if (!points[i]->selected)
            {
                c.push(points[i]); //POINTER, PAY ATTENTION
                points[i]->selected = true;
            }
            else
            {
                c.remove(points[i]);
                points[i]->selected = false;
            }
            return true;
        }
    }

    for(uint i=0;i<segments.size();i++)
    {
        bool b =segments[i] -> in_personal_area(x,y);
        if(b)
        {
            if (!segments[i]->selected)
            {
                c.push(segments[i]); //POINTER, PAY ATTENTION
                segments[i]->selected = true;
            }
            else
            {
                c.remove(segments[i]);
                segments[i]->selected = false;
            }

            for(uint i=0;i<polygones.size();i++)
            {
                bool yes = true;
                for(uint j = 0; j<polygones[i]->Pointlist.size()-1;j++)
                {
                    Segment* s = new Segment(polygones[i]->Pointlist[j],polygones[i]->Pointlist[j+1]);
                    yes = yes && check_if_selected(*s);
                }
                Segment* s = new Segment(polygones[i]->Pointlist[0],polygones[i]->Pointlist[polygones[i]->Pointlist.size()-1]);
                yes = yes && check_if_selected(*s);
                if(yes)
                {
                    c.push(polygones[i]); //POINTER, PAY ATTENTION
                    polygones[i]->selected = true;
                }
                else
                {
                    c.remove(polygones[i]);
                    polygones[i]->selected = false;
                }
            }

            for(uint i=0;i<r_polygones.size();i++)
            {
                bool yes = true;
                for(uint j = 0; j<r_polygones[i]->Pointlist.size()-1;j++)
                {
                    Segment* s = new Segment(r_polygones[i]->Pointlist[j],r_polygones[i]->Pointlist[j+1]);
                    yes = yes && check_if_selected(*s);
                }
                Segment* s = new Segment(r_polygones[i]->Pointlist[0],r_polygones[i]->Pointlist[r_polygones[i]->Pointlist.size()-1]);
                yes = yes && check_if_selected(*s);
                if(yes)
                {
                    c.push(r_polygones[i]); //POINTER, PAY ATTENTION
                    r_polygones[i]->selected = true;
                }
                else
                {
                    c.remove(r_polygones[i]);
                    r_polygones[i]->selected = false;
                }
            }

            for(uint i=0;i<triangles.size();i++)
            {
                bool yes = true;;
                Segment* s1 = new Segment(triangles[i]->point1,triangles[i]->point2);
                Segment* s2 = new Segment(triangles[i]->point2,triangles[i]->point3);
                Segment* s3 = new Segment(triangles[i]->point1,triangles[i]->point3);
                yes = yes && check_if_selected(*s1) && check_if_selected(*s2) && check_if_selected(*s3);
                if(yes)
                {
                    c.push(triangles[i]); //POINTER, PAY ATTENTION
                    triangles[i]->selected = true;
                }
                else
                {
                    c.remove(triangles[i]);
                    triangles[i]->selected = false;
                }
            }

            return true;
        }
    }


    for(uint i=0;i<circles.size();i++)
    {
        bool b =circles[i] -> in_personal_area(x,y);
        if(b)
        {
            if (!circles[i]->selected)
            {
                c.push(circles[i]); //POINTER, PAY ATTENTION
                circles[i]->selected = true;
            }
            else
            {
                c.remove(circles[i]);
                circles[i]->selected = false;
            }
            return true;
        }

    }

    for(uint i=0;i<lines.size();i++)
    {
        bool b =lines[i] -> in_personal_area(x,y);
        if(b)
        {
            if (!lines[i]->selected)
            {
                c.push(lines[i]); //POINTER, PAY ATTENTION
                lines[i]->selected = true;
            }
            else
            {
                c.remove(lines[i]);
                lines[i]->selected = false;
            }
            return true;
        }
    }

    for(uint i=0;i<semi_lines.size();i++)
    {
        bool b =semi_lines[i] -> in_personal_area(x,y);
        if(b)
        {
            if (!semi_lines[i]->selected)
            {
                c.push(semi_lines[i]); //POINTER, PAY ATTENTION
                semi_lines[i]->selected = true;
            }
            else
            {
                c.remove(semi_lines[i]);
                semi_lines[i]->selected = false;
            }
            return true;
        }
    }

    for(uint i=0;i<functions.size();i++)
    {
        bool b =functions[i] -> in_personal_area(x,y);
        if(b)
        {
            if (!functions[i]->selected)
            {
                c.push(functions[i]); //POINTER, PAY ATTENTION
                functions[i]->selected = true;
            }
            else
            {
                c.remove(functions[i]);
                functions[i]->selected = false;
            }
            return true;
        }
    }

    for(uint i=0;i<ellipses.size();i++)
    {
        bool b =ellipses[i] -> in_personal_area(x,y);
        if(b)
        {
            if (!ellipses[i]->selected)
            {
                c.push(ellipses[i]); //POINTER, PAY ATTENTION
                ellipses[i]->selected = true;
            }
            else
            {
                c.remove(ellipses[i]);
                ellipses[i]->selected = false;
            }
            return true;
        }
    }

    return false;
}

void Container::deselect()
{
    for(uint i=0;i<circles.size();i++)
    {
        circles[i]->selected = false;
    }
    for(uint i=0;i<points.size();i++)
    {
        points[i]->selected = false;
    }
    for(uint i=0;i<lines.size();i++)
    {
        lines[i]->selected = false;
    }
    for(uint i=0;i<segments.size();i++)
    {
        segments[i]->selected = false;
    }
    for(uint i=0;i<triangles.size();i++)
    {
        triangles[i]->selected = false;
    }
    for(uint i=0;i<polygones.size();i++)
    {
        polygones[i]->selected = false;
    }
    for(uint i=0;i<r_polygones.size();i++)
    {
        r_polygones[i]->selected = false;
    }
    for(uint i=0;i<functions.size();i++)
    {
        functions[i]->selected = false;
    }
    for(uint i=0;i<ellipses.size();i++)
    {
        ellipses[i]->selected = false;
    }
    for(uint i=0;i<semi_lines.size();i++)
    {
        semi_lines[i]->selected = false;
    }
}

int Container::size()
{
    return circles.size()+points.size()+lines.size()+segments.size()+triangles.size()+polygones.size()+r_polygones.size()+functions.size()+ellipses.size()+semi_lines.size();
}

void Container::empty_bins()
{
    points.clear(); //tag of points is 0
    lines.clear();//tag of lines is 1
    circles.clear();//tag of circles is 2
    segments.clear(); //tag of segments is 3
    triangles.clear(); //tag of triangles is 4
    polygones.clear();
    r_polygones.clear();
    functions.clear();
    ellipses.clear();
    semi_lines.clear();
}

void Container::cleanFrom(Container &c)
{
    uint n = c.circles.size();
    for(uint i=0;i<n;i++)
    {
        remove(c.circles[0]);
        remove(c.circles[0]->center);
        c.remove(c.circles[0]);
    }

    n = c.lines.size();
    for(uint i=0;i<n;i++)
    {
        remove(c.lines[0]);
        remove(c.lines[0]->p1);
        remove(c.lines[0]->p2);
        c.remove(c.lines[0]);
    }

    n = c.semi_lines.size();
    for(uint i=0;i<n;i++)
    {
        remove(c.semi_lines[0]);
        remove(c.semi_lines[0]->p1);
        remove(c.semi_lines[0]->p2);
        c.remove(c.semi_lines[0]);
    }

    n = c.segments.size();
    for(uint i=0;i<n;i++)
    {
        remove(c.segments[0]);
        remove(c.segments[0]->p1);
        remove(c.segments[0]->p2);
        c.remove(c.segments[0]);
    }

    n = c.triangles.size();
    for(uint i=0;i<n;i++)
    {
        remove(c.triangles[0]);
        remove(c.triangles[0]->point1);
        remove(c.triangles[0]->point2);
        remove(c.triangles[0]->point3);
        c.remove(c.triangles[0]);
    }

    n = c.polygones.size();
    for(uint i=0;i<n;i++)
    {
        remove(c.polygones[0]);
        for(uint j=0;j<c.polygones[i]->Pointlist.size();j++)
        {
            remove(c.polygones[i]->Pointlist[j]);
        }
        c.remove(c.polygones[0]);
    }

    n = c.r_polygones.size();
    for(uint i=0;i<n;i++)
    {
        remove(c.r_polygones[0]);
        for(uint j=0;j<c.r_polygones[i]->Pointlist.size();j++)
        {
            remove(c.r_polygones[i]->Pointlist[j]);
        }
        c.remove(c.r_polygones[0]);
    }

    n = c.functions.size();
    for(uint i=0;i<n;i++)
    {
        remove(c.functions[i]);
    }

    n = c.ellipses.size();
    for(uint i=0;i<n;i++)
    {
        remove(c.ellipses[i]);
    }

    n=c.points.size();
    for(uint i=0;i<n;i++)
    {
        remove(c.points[0]);
        c.remove(c.points[0]);
    }
}

void Container::zoom(double coef, double c_x, double c_y)
{
    for(uint i=0;i<circles.size();i++)
    {
        circles[i]->zoom(coef,c_x,c_y);
    }
    for(uint i=0;i<points.size();i++)
    {
        points[i]->zoom(coef,c_x,c_y);
    }
    for(uint i=0;i<lines.size();i++)
    {
        lines[i]->zoom(coef,c_x,c_y);
    }
    for(uint i=0;i<segments.size();i++)
    {
        segments[i]->zoom(coef,c_x,c_y);
    }
    for(uint i=0;i<triangles.size();i++)
    {
        triangles[i]->zoom(coef,c_x,c_y);
    }
    for(uint i=0;i<polygones.size();i++)
    {
        polygones[i]->zoom(coef,c_x,c_y);
    }
    for(uint i=0;i<r_polygones.size();i++)
    {
        r_polygones[i]->zoom(coef,c_x,c_y);
    }
    for(uint i=0;i<ellipses.size();i++)
    {
        ellipses[i]->zoom(coef,c_x,c_y);
    }
    for(uint i=0;i<semi_lines.size();i++)
    {
        semi_lines[i]->zoom(coef,c_x,c_y);
    }

}

std::vector<Point *> Container::IntersectObjects()
{
    std::vector<Point*> vec;

    //firstly, add the segments from triangles:
    /*
    for(uint i=0;i<triangles.size();i++)
    {
        push(new Point(triangles[i]->point1.getx(),triangles[i]->point1.gety()));
        push(new Point(triangles[i]->point2.getx(),triangles[i]->point2.gety()));
        push(new Point(triangles[i]->point3.getx(),triangles[i]->point3.gety()));

        push(new Segment(triangles[i]->point1,triangles[i]->point2));
        push(new Segment(triangles[i]->point2,triangles[i]->point3));
        push(new Segment(triangles[i]->point1,triangles[i]->point3));
    }

    for(uint i = 0;i<polygones.size();i++)
    {
        for(uint j=0;j<polygones[i]->Pointlist.size()-1;j++)
        {
            push(new Segment(polygones[i]->Pointlist[j],polygones[i]->Pointlist[j+1]));
            push(new Point(polygones[i]->Pointlist[j].getx(),polygones[i]->Pointlist[j].gety()));
        }
        push(new Segment(polygones[i]->Pointlist[0],polygones[i]->Pointlist[polygones[i]->Pointlist.size()-1]));
        push(new Point(polygones[i]->Pointlist[polygones[i]->Pointlist.size()-1].getx(),polygones[i]->Pointlist[polygones[i]->Pointlist.size()-1].gety()));
    }

    for(uint i = 0;i<r_polygones.size();i++)
    {
        for(uint j=0;j<r_polygones[i]->Pointlist.size()-1;j++)
        {
            push(new Point(r_polygones[i]->Pointlist[j].getx(),r_polygones[i]->Pointlist[j].gety()));
            push(new Segment(r_polygones[i]->Pointlist[j],r_polygones[i]->Pointlist[j+1]));
        }
        push(new Point(r_polygones[i]->Pointlist[r_polygones[i]->Pointlist.size()-1].getx(),r_polygones[i]->Pointlist[r_polygones[i]->Pointlist.size()-1].gety()));
        push(new Segment(r_polygones[i]->Pointlist[0],r_polygones[i]->Pointlist[r_polygones[i]->Pointlist.size()-1]));
    }
    */

    for(uint i=0;i<lines.size();i++)
    {
        for (uint j=i+1;j<lines.size();j++)
        {
            std::vector<Point*> help;
            help = intersection(*lines[i],*lines[j]);
            for(uint k=0;k<help.size();k++)
            {
                if(!check_if_in(*help[k]))
                {
                    vec.push_back(help[k]);
                    push(help[k]);

                }
            }
        }
    }

    for(uint i=0;i<semi_lines.size();i++)
    {
        for (uint j=i+1;j<semi_lines.size();j++)
        {
            std::vector<Point*> help;
            help = intersection(*semi_lines[i],*semi_lines[j]);
            for(uint k=0;k<help.size();k++)
            {
                if(!check_if_in(*help[k]))
                {
                    vec.push_back(help[k]);
                    push(help[k]);

                }
            }
        }
    }

    for(uint i=0;i<segments.size();i++)
    {
        for (uint j=i+1;j<segments.size();j++)
        {
            std::vector<Point*> help;
            help = intersection(*segments[i],*segments[j]);
            for(uint k=0;k<help.size();k++)
            {
                if(!check_if_in(*help[k]))
                {
                    vec.push_back(help[k]);
                    push(help[k]);

                }
            }
        }
    }

    for(uint i=0;i<circles.size();i++)
    {
        for (uint j=i+1;j<circles.size();j++)
        {
            std::vector<Point*> help;
            help = intersection(*circles[i],*circles[j]);
            for(uint k=0;k<help.size();k++)
            {
                if(!check_if_in(*help[k]))
                {
                    vec.push_back(help[k]);
                    push(help[k]);

                }
            }
        }
    }

    for(uint i=0;i<lines.size();i++)
    {
        for (uint j=0;j<segments.size();j++)
        {
            std::vector<Point*> help;
            help = intersection(*lines[i],*segments[j]);
            for(uint k=0;k<help.size();k++)
            {
                if(!check_if_in(*help[k]))
                {
                    vec.push_back(help[k]);
                    push(help[k]);

                }
            }
        }
    }

    for(uint i=0;i<lines.size();i++)
    {
        for (uint j=0;j<semi_lines.size();j++)
        {
            std::vector<Point*> help;
            help = intersection(*semi_lines[i],*lines[j]);
            for(uint k=0;k<help.size();k++)
            {
                if(!check_if_in(*help[k]))
                {
                    vec.push_back(help[k]);
                    push(help[k]);
                }
            }
        }
    }

    for(uint i=0;i<lines.size();i++)
    {
        for (uint j=0;j<circles.size();j++)
        {
            std::vector<Point*> help;
            help = intersection(*lines[i],*circles[j]);
            for(uint k=0;k<help.size();k++)
            {
                if(!check_if_in(*help[k]))
                {
                    vec.push_back(help[k]);
                    push(help[k]);
                }
            }
        }
    }

    for(uint i=0;i<lines.size();i++)
    {
        for (uint j=0;j<ellipses.size();j++)
        {
            std::vector<Point*> help;
            help = intersection(*ellipses[i],*lines[j]);
            for(uint k=0;k<help.size();k++)
            {
                if(!check_if_in(*help[k]))
                {
                    vec.push_back(help[k]);
                    push(help[k]);
                }
            }
        }
    }

    for(uint i=0;i<segments.size();i++)
    {
        for (uint j=0;j<circles.size();j++)
        {
            std::vector<Point*> help;
            help = intersection(*segments[i],*circles[j]);
            for(uint k=0;k<help.size();k++)
            {
                if(!check_if_in(*help[k]))
                {
                    vec.push_back(help[k]);
                    push(help[k]);

                }
            }
        }
    }
    empty_bins();
    return vec;
}
