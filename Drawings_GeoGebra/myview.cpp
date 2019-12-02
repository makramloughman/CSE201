#include "myview.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MyView::MyView(QWidget *parent) : QGraphicsView(parent)
{
    this->segment_chosen = false; //no segment chosen
    this->circle_chosen = false; //no circe chosem
    this->inf_line_chosen = false; //no infinite line chosen
    this->n_counter = 0; //zero points selected

}

void MyView::mousePressEvent(QMouseEvent *ev)
{  
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have

    if (this->segment_chosen){
        if(this->n_counter==0){
            this->n_counter++;
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            mainW->drawPoint(this->clickedP[0]);
        }
        else if (this->n_counter==1){
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            QLineF line(this->clickedP[0],this->clickedP[1]);
            mainW->drawLine(line);
            mainW->drawPoint(this->clickedP[1]);
            mainW->drawPoint(this->clickedP[0]);

            this->clickedP.clear();
            this->segment_chosen = false;
            this->n_counter =0;
        }
    }
    else if (this->circle_chosen){
        if(this->n_counter==0){
            this->n_counter++;
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            mainW->drawPoint(this->clickedP[0]);
        }
        else if (this->n_counter==1){
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            double r = sqrt(pow(clickedP[0].x()-clickedP[1].x(),2)+pow(clickedP[0].y()-clickedP[1].y(),2));
            mainW->drawCircle(clickedP[0],r);

            this->clickedP.clear();
            this->circle_chosen = false;
            this->n_counter =0;
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
            mainW->drawInfiniteLine(f_point,s_point);

            this->clickedP.clear();
            this->inf_line_chosen = false;
            this->n_counter =0;
        }
    }
    else if (this->point_chosen){
        mainW -> drawPoint(mapToScene(ev->x(),ev->y()));
        this->point_chosen = false;
    }
    else if (this->polygon_chosen){
        if(this->n_counter == 0){
            this->n_counter++;
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            mainW->drawPoint(this->clickedP[0]);
        }
        else if (this->n_counter<=4-1){ //it works now only for n=4
            this->clickedP.push_back(mapToScene(ev->x(),ev->y()));
            QLineF line(this->clickedP[n_counter],this->clickedP[n_counter-1]);
            this->n_counter++;
            mainW->drawLine(line);
            mainW->drawPoint(this->clickedP[n_counter-1]);
            mainW->drawPoint(this->clickedP[n_counter-2]);

            if(n_counter==4)
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

    //mainW->drawScene();
}
