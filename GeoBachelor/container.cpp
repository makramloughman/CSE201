#include "container.h"

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

void Container::move_refresh(double dx, double dy)
{
    for(int i=0;i<circles.size();i++)
    {
        circles[i]->translate(dx,dy);
        circles[i]->draw();
    }
    for(int i=0;i<points.size();i++)
    {
        points[i]->translate(dx,dy);
        points[i]->draw();
    }
    for(int i=0;i<lines.size();i++)
    {
        lines[i]->translate(dx,dy);
        lines[i]->draw();
    }
    for(int i=0;i<segments.size();i++)
    {
        segments[i]->translate(dx,dy);
        segments[i]->draw();
    }
    for(int i=0;i<triangles.size();i++)
    {
        triangles[i]->translate(dx,dy);
        triangles[i]->draw();
    }

}

void Container::refresh()
{
    move_refresh(0,0);
}

bool Container::find_personal_and_store(Container &c, double x, double y)
{
    for(int i=0;i<circles.size();i++)
    {
        if (!circles[i]->selected){
        bool b =circles[i] -> in_personal_area(x,y);
        if(b)
        {
            c.push(circles[i]); //POINTER, PAY ATTENTION
            circles[i]->selected = true;
            return true;
        }
        }
    }
    for(int i=0;i<points.size();i++)
    {
        if (!points[i]->selected){
        bool b =points[i] -> in_personal_area(x,y);
        if(b)
        {
            c.push(points[i]); //POINTER, PAY ATTENTION
            points[i]->selected = true;
            return true;
        }
        }
    }
    for(int i=0;i<lines.size();i++)
    {
        if (!lines[i]->selected){
        bool b =lines[i] -> in_personal_area(x,y);
        if(b)
        {
            c.push(lines[i]); //POINTER, PAY ATTENTION
            lines[i]->selected = true;
            return true;
        }
        }
    }
    for(int i=0;i<segments.size();i++)
    {
        if (!segments[i]->selected){
        bool b =segments[i] -> in_personal_area(x,y);
        if(b)
        {
            c.push(segments[i]); //POINTER, PAY ATTENTION
            segments[i]->selected = true;
            return true;
        }
        }
    }
    for(int i=0;i<triangles.size();i++)
    {
        if (!triangles[i]->selected){
        bool b =triangles[i] -> in_personal_area(x,y);
        if(b)
        {
            c.push(triangles[i]); //POINTER, PAY ATTENTION
            triangles[i]->selected = true;
            return true;
        }
        }
    }
    return false;
}

std::vector<bool> Container::non_empty_tags()
{
    std::vector<bool> tags;

    if(points.size()==0)
    {
        tags.push_back(false);
    }
    else
    {
        tags.push_back(true);
    }

    if(lines.size()==0)
    {
        tags.push_back(false);
    }
    else
    {
        tags.push_back(true);
    }

    if(circles.size()==0)
    {
        tags.push_back(false);
    }
    else
    {
        tags.push_back(true);
    }

    if(segments.size()==0)
    {
        tags.push_back(false);
    }
    else
    {
        tags.push_back(true);
    }

    if(triangles.size()==0)
    {
        tags.push_back(false);
    }
    else
    {
        tags.push_back(true);
    }
}

int Container::size()
{
    return circles.size()+points.size()+lines.size()+segments.size()+triangles.size();
}



