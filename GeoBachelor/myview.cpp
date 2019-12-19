#include "myview.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MyView::MyView(QWidget *parent) : QGraphicsView(parent)
{
    this->point_chosen = false; //no segment chosen
    this->segment_chosen = false; //no segment chosen
    this->circle_chosen = false; //no circe chosem
    this->inf_line_chosen = false; //no infinite line chosen
    this->polygon_chosen = false; //no polygon chosen
    this->n_counter = 0; //zero points selected
    this->n_polygon = 0; //no polygon chosen
    this->move_grid_chosen = false;
    this->move_grid_pressed = false;
    this->select_object_chosen = false;
}

void MyView::mousePressEvent(QMouseEvent *ev)
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have

    if (this->segment_chosen)
    {
        if(this->n_counter==0)
        {
            this->n_counter++;
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            mainW->drawPoint(this->clickedP[0]);
        }

        else if (this->n_counter==1)
        {
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            QLineF line(this->clickedP[0],this->clickedP[1]);
            mainW->drawLine(line);
            mainW->drawPoint(this->clickedP[1]);
            mainW->drawPoint(this->clickedP[0]);

            QPointF h = mainW-> mapFromMyScene(this->clickedP[0].x(),this->clickedP[0].y());

            Point* p1 = new Point(h.x(),h.y());
            Point* p2 = new Point(ev->x(),ev->y());

            Segment* s = new Segment(*p1,*p2);
            mainW->mainGrid->obj.push(s);
            mainW->mainGrid->obj.push(p1);
            mainW->mainGrid->obj.push(p2);

            this->clickedP.clear();
            this->segment_chosen = false;
            this->n_counter =0;
        }
    }

    else if (this->circle_chosen)
    {
        if(this->n_counter==0){
            this->n_counter++;
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            mainW->drawPoint(this->clickedP[0]);
        }

        else if (this->n_counter==1)
        {
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            double r = sqrt(pow(clickedP[0].x()-clickedP[1].x(),2)+pow(clickedP[0].y()-clickedP[1].y(),2));
            mainW->drawCircle(clickedP[0],r);

            this->clickedP.clear();
            this->circle_chosen = false;
            this->n_counter =0;
               //changed to view
            Point *p1 = new Point(mainW->mapFromMyScene(clickedP[0].x(),clickedP[0].y()));
                //changed to view
            mainW->mainGrid->obj.push(new Circle(*p1,Point(ev->x(),ev->y()))); //Figured out
            mainW->mainGrid->obj.push(p1); //adding also the center of the circle (for suitable for translating)
        }
    }

    else if (this->inf_line_chosen){
        if(this->n_counter==0){
            this->n_counter++;
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            mainW->drawPoint(this->clickedP[0]);
        }
        else if (this->n_counter==1){
            //we are drawing the infinite

            QPointF f_point = mapFromScene(this->clickedP[0].x(),clickedP[0].y());
            QPointF s_point = QPointF(ev->x(),ev->y());
            mainW->drawPoint(mapToScene(ev->x(),ev->y()));
            mainW->drawInfiniteLine(f_point,s_point);
            this->clickedP.clear();
            this->inf_line_chosen = false;
            this->n_counter = 0;
            //changed to view instead of grid
            Point* p1 = new Point(mainW->mapFromMyScene(this->clickedP[0].x(),clickedP[0].y()));
            Point* p2 = new Point(ev->x(),ev->y());
            Line* p = new Line(*p1,*p2);
            mainW -> mainGrid -> obj.push(p);
            mainW -> mainGrid -> obj.push(p1);
            mainW -> mainGrid -> obj.push(p2);

        }
    }
    else if (this->point_chosen){
        //User chose the feature to create a point using mouse
        mainW -> drawPoint(mapToScene(ev->x(),ev->y()));
        this->point_chosen = false;
            // changed to view (mapFromViewToGrid)
        QPointF help = QPointF(ev->x(),ev->y());
        mainW->mainGrid->obj.push(new Point(help));
    }
    else if (this->polygon_chosen){
        if(this->n_counter == 0){
            this->n_counter++;
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            mainW->drawPoint(this->clickedP[0]);
        }
        else if (this->n_counter<=n_polygon-1){
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            QLineF line(this->clickedP[n_counter],this->clickedP[n_counter-1]);
            this->n_counter++;
            mainW->drawLine(line);
            mainW->drawPoint(this->clickedP[n_counter-1]);
            mainW->drawPoint(this->clickedP[n_counter-2]);

            if(n_counter==n_polygon)
            {
                //or call mainW->drawPolygon(clickedP) => too much job
                QLineF line(this->clickedP[n_counter-1],this->clickedP[0]);
                mainW->drawLine(line);
                for (int i=0;i<n_counter;i++)
                    mainW->drawPoint(clickedP[i]);

                this->clickedP.clear();
                this->polygon_chosen = false;
                this->n_counter =0;
            }
        }
    }

    else if (this->move_grid_chosen)
    {
        this->move_grid_chosen = false;
        this->move_grid_pressed = true;
        last_clicked = QPointF(ev->x(),ev->y());

    }

    else if (this->select_object_chosen)
    {
        this->select_object_chosen = false;

        bool b = false;
        for(int i=0;i<mainW->mainGrid->obj.circles.size();i++)
        {
            bool b = mainW->mainGrid->obj.circles[i]->in_personal_area(ev->x(),ev->y());
            if(b)
            {

            }

        }
    }
}

void MyView::mouseMoveEvent(QMouseEvent *ev)
{
    if(this->move_grid_pressed)
    {
        MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
        double dx = ev->x()-last_clicked.x();
        double dy = ev->y()-last_clicked.y();
        mainW ->mainGrid->move_grid(dx,dy);
        last_clicked = QPointF(ev->x(),ev->y());
    }
}

void MyView::mouseReleaseEvent(QMouseEvent *ev)
{
    if(!this->move_grid_chosen && this->move_grid_pressed)
    {
        MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
        this->move_grid_pressed = false;
        double dx = ev->x()-last_clicked.x();
        double dy = ev->y()-last_clicked.y();
        mainW ->mainGrid->move_grid(dx,dy);
        last_clicked = QPointF(0,0);
    }
}
