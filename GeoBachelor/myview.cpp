#include "myview.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <general_functions.h>

MyView::MyView(QWidget *parent) : QGraphicsView(parent)
{
    this->point_chosen = false; //no segment chosen

    this->segment_chosen = false; //no segment chosen
    this->inf_line_chosen = false; //no infinite line chosen

    this->polygon_chosen = false; //no polygon chosen
    this->n_counter = 0; //zero points selected
    this->n_polygon = 0; //no polygon chosen

    this->select_object_chosen = false;

    this->circle_chosen = false; //no circe chosem
    this->circle_chosen_with_radius = false;
    this->ellipse_chosen = false;

    this->move_grid_chosen = true;
    this->move_grid_pressed = false;
    this->move_grid_released = true;
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
            QLineF line = QLineF(this->clickedP[0],this->clickedP[1]);
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

            int m = mainW->mainGrid->obj.points.size();
            mainW->mainGrid->obj.points[m-1]->drawName(m-1);
            mainW->mainGrid->obj.points[m-2]->drawName(m-2);

            mainW->mainGrid->refresh_grid();
            refresh_indicators();
            this-> move_grid_chosen = true;

        }
        mainW->ItemsDisplay();
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

               //changed to view
            Point *p1 = new Point(mainW->mapFromMyScene(clickedP[0].x(),clickedP[0].y()));
                //changed to view
            mainW->mainGrid->obj.push(new Circle(*p1,Point(ev->x(),ev->y()))); //Figured out
            mainW->mainGrid->obj.push(p1); //adding also the center of the circle (for suitable for translating)
            int m = mainW->mainGrid->obj.points.size();
            mainW->mainGrid->obj.points[m-1]->drawName(m-1);

            mainW->mainGrid->refresh_grid();
            refresh_indicators();
            this-> move_grid_chosen = true;
        }
        mainW->ItemsDisplay();
    }

    else if (circle_chosen_with_radius)
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

               //changed to view
            Point *p1 = new Point(mainW->mapFromMyScene(clickedP[0].x(),clickedP[0].y()));
            Point *p2 = new Point(ev->x(),ev->y());
            //changed to view
            mainW->mainGrid->obj.push(new Circle(*p1,Point(ev->x(),ev->y()))); //Figured out
            mainW->mainGrid->obj.push(p1); //adding also the center of the circle (for suitable for translating)
            mainW->mainGrid->obj.push(p2);
            mainW->mainGrid->obj.push(new Segment(*p1,*p2));

            int m = mainW->mainGrid->obj.points.size();
            mainW->mainGrid->obj.points[m-1]->drawName(m-1);
            mainW->mainGrid->obj.points[m-2]->drawName(m-2);

            mainW->mainGrid->refresh_grid();
            refresh_indicators();
            this-> move_grid_chosen = true;
        }
    }

    else if (this->inf_line_chosen)
    {
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

            //changed to view instead of grid
            Point* p1 = new Point(mainW->mapFromMyScene(this->clickedP[0].x(),clickedP[0].y()));
            Point* p2 = new Point(ev->x(),ev->y());
            Line* p = new Line(*p1,*p2);
            mainW -> mainGrid -> obj.push(p);
            mainW -> mainGrid -> obj.push(p1);
            mainW -> mainGrid -> obj.push(p2);

            int m = mainW->mainGrid->obj.points.size();
            mainW->mainGrid->obj.points[m-1]->drawName(m-1);
            mainW->mainGrid->obj.points[m-2]->drawName(m-2);

            mainW->mainGrid->refresh_grid();
            refresh_indicators();
            this->move_grid_chosen = true;
        }
        mainW->ItemsDisplay();
    }
    else if (this->point_chosen)
    {
        mainW->drawPoint(mapToScene(ev->x(),ev->y()));
        QPointF help = QPointF(ev->x(),ev->y());
        mainW->mainGrid->obj.push(new Point(help));

        int m = mainW->mainGrid->obj.points.size();
        mainW->mainGrid->obj.points[m-1]->drawName(m-1);

        refresh_indicators();
        this->move_grid_chosen = true;
        mainW->ItemsDisplay();
    }
    else if (this->polygon_chosen)
    {
        if(this->n_counter == 0){
            this->n_counter++;
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            mainW->drawPoint(this->clickedP[0]);

            Point* p = new Point(ev->x(),ev->y());
            mainW->mainGrid->obj.push(p);

            int m = mainW->mainGrid->obj.points.size();
            mainW->mainGrid->obj.points[m-1]->drawName(m-1);

        }
        else if (this->n_counter<=n_polygon-1)
        {
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            QLineF line(this->clickedP[n_counter],this->clickedP[n_counter-1]);
            this->n_counter++;
            mainW->drawLine(line);
            mainW->drawPoint(this->clickedP[n_counter-1]);
            mainW->drawPoint(this->clickedP[n_counter-2]);

            Point* p = new Point(ev->x(),ev->y());
            mainW->mainGrid->obj.push(p);

            int m = mainW->mainGrid->obj.points.size();
            mainW->mainGrid->obj.points[m-1]->drawName(m-1);
        }
        if(n_counter==n_polygon)
            {
                QLineF line(this->clickedP[n_counter-1],this->clickedP[0]);
                mainW->drawLine(line);
                for (int i=0;i<n_counter;i++)
                    mainW->drawPoint(clickedP[i]);

                std::vector<QPointF> help; //transfering back to View coordinates
                for(int i=0;i<n_counter;i++)
                {
                    help.push_back(mainW->mapFromMyScene(clickedP[i].x(),clickedP[i].y()));
                }

                if (n_polygon==3)
                {
                    mainW->mainGrid->obj.push(new Triangle(help));
                    mainW->ItemsDisplay();
                }
                else
                {
                    std::vector<Point*> h;
                    for(uint k=0; k<help.size();k++)
                    {
                        h.push_back(new Point(help[k].x(),help[k].y()));
                    }
                    mainW->mainGrid->obj.push(new Polygone(h.size(),h));
                    std::cout<<mainW->mainGrid->obj.polygones.size()<<endl;
                    std::cout<<mainW->mainGrid->obj.points.size()<<endl;
                    std::cout<<n_counter<<endl;
                    std::cout<<h.size()<<endl;

                }

                mainW->mainGrid->refresh_grid();
                refresh_indicators();
                this-> move_grid_chosen = true;
            }
    }

    else if(ellipse_chosen)
    {
        if(this->n_counter==0)
        {
            this->n_counter++;
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            mainW->drawPoint(this->clickedP[n_counter-1]);
        }
        else if(this->n_counter==1)
        {
            this->n_counter++;
            Point *p = new Point(mainW->mapFromMyScene(clickedP[0].x(),clickedP[0].y()));
            this->clickedP.push_back(mapToScene(ev->x(),p->gety()));
            mainW->drawPoint(this->clickedP[n_counter-1]);
        }
        else
        {
            //changed to view
            Point *p1 = new Point(mainW->mapFromMyScene(clickedP[0].x(),clickedP[0].y()));
            Point *p2 = new Point(mainW->mapFromMyScene(clickedP[1].x(),clickedP[1].y()));
            Point *p3 = new Point(ev->x(),p1->gety());


            double a = abs((p1->getx()+p2->getx())/2-p3->getx());

            mainW->mainGrid->obj.push(new Ellipse(p1,p2,a)); //Figured out
            mainW->mainGrid->obj.push(p1); //adding also the center of the circle (for suitable for translating)
            mainW->mainGrid->obj.push(p2);
            mainW->mainGrid->obj.push(p3);

            int m = mainW->mainGrid->obj.points.size();
            mainW->mainGrid->obj.points[m-1]->drawName(m-1);
            mainW->mainGrid->obj.points[m-2]->drawName(m-2);

            mainW->mainGrid->refresh_grid();
            refresh_indicators();
            this-> move_grid_chosen = true;
        }
    }

    else if (this->select_object_chosen)
    {
        bool b = mainW->mainGrid->obj.find_personal_and_store(chosen_objects,ev->x(),ev->y());
        if(b)
        {
           mainW->mainGrid->obj.refresh();
           //std::cout<<chosen_objects.size()<<std::endl;
        }

        if (this->move_grid_chosen)
            {
                this->move_grid_pressed = true;
                this->move_grid_released= false;
                last_clicked = QPointF(ev->x(),ev->y());
            }
    }


    else if (this->move_grid_chosen)
    {
        this->move_grid_pressed = true;
        this->move_grid_released= false;
        last_clicked = QPointF(ev->x(),ev->y());

    }
}

void MyView::mouseMoveEvent(QMouseEvent *ev)
{
    if(!this->move_grid_released && this->move_grid_pressed)
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
    if(!this->move_grid_released && this->move_grid_chosen && this->move_grid_pressed)
    {
        MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
        this->move_grid_pressed = false;
        this->move_grid_released = true;
        double dx = ev->x()-last_clicked.x();
        double dy = ev->y()-last_clicked.y();
        mainW->mainGrid->move_grid(dx,dy);
        last_clicked = QPointF(0,0);
    }
}

void MyView::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier)
    {
        MainWindow* mainW = MainWindow::getInstance();

        double angle = event->angleDelta().y();
        double factor = qPow(1.0002, angle);

        mainW->clearScene();
        mainW->mainGrid->zoom(factor);
        mainW->mainGrid->obj.zoom(factor,mainW->mainGrid->getX(),mainW->mainGrid->getY());
        mainW->ui->graphicsView->chosen_objects.empty_bins();
        mainW->ui->graphicsView->refresh_indicators();
        mainW->ui->graphicsView->move_grid_chosen = true;
        mainW->mainGrid->obj.deselect();
        mainW->mainGrid->refresh_grid();
    }
}

void MyView::refresh_indicators()
{
    this->clickedP.clear();

    this->point_chosen = false; //no segment chosen

    this->segment_chosen = false; //no segment chosen
    this->inf_line_chosen = false; //no infinite line chosen

    this->polygon_chosen = false; //no polygon chosen
    this->n_counter = 0; //zero points selected
    this->n_polygon = 0; //no polygon chosen

    this->select_object_chosen = false;

    this->circle_chosen = false; //no circe chosem
    this->circle_chosen_with_radius = false;
    this->ellipse_chosen = false;

    this->move_grid_chosen = false;
    this->move_grid_pressed = false;
    this->move_grid_released = true;
}
