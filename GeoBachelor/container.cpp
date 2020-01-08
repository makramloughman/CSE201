#include "container.h"

bool Container::matching(Point p1, Point p2)
{
    return (p1.getx()==p2.getx() && p1.gety()==p2.gety());
}

Container::Container()
{
    this->number_of_bins = 5;
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
    for(int i=0;i<points.size();i++) //ORDER MATTERS
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
            return true;
        }
    }

    for(uint i=0;i<triangles.size();i++)
    {
        bool b =triangles[i] -> in_personal_area(x,y);
        if(b)
        {
            if (!triangles[i]->selected)
            {
                c.push(triangles[i]); //POINTER, PAY ATTENTION
                triangles[i]->selected = true;
            }
            else
            {
                c.remove(triangles[i]);
                triangles[i]->selected = false;
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
}

int Container::size()
{
    return circles.size()+points.size()+lines.size()+segments.size()+triangles.size();
}

void Container::empty_bins()
{
    points.clear(); //tag of points is 0
    lines.clear();//tag of lines is 1
    circles.clear();//tag of circles is 2
    segments.clear(); //tag of segments is 3
    triangles.clear(); //tag of triangles is 4
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

    n=c.points.size();
    for(uint i=0;i<n;i++)
    {
        remove(c.points[0]);
        c.remove(c.points[0]);
    }
}

std::vector<Point *> Container::IntersectObjects()
{
    std::vector<Point*> vec;

    //firstly, add the segments from triangles:
    for(int i=0;i<triangles.size();i++)
    {
        push(new Segment(triangles[i]->point1,triangles[i]->point2));
        push(new Segment(triangles[i]->point2,triangles[i]->point3));
        push(new Segment(triangles[i]->point1,triangles[i]->point3));
    }

    for(uint i=0;i<lines.size();i++)
    {
        for (uint j=i+1;j<lines.size();j++)
        {
            std::vector<Point*> help;
            help = intersection(*lines[i],*lines[j]);
            for(uint k=0;k<help.size();k++)
            {
                vec.push_back(help[k]);
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
                vec.push_back(help[k]);
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
                vec.push_back(help[k]);
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
                vec.push_back(help[k]);
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
                vec.push_back(help[k]);
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
                vec.push_back(help[k]);
            }
        }
    }

    empty_bins();
    return vec;
}



