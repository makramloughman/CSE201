#include "Scene.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

/*void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(sceneMode == DrawLine){
        if(!itemToDraw){
            itemToDraw = new QGraphicsLineItem(0, this);
            itemToDraw->setPen(QPen(Qt::black, 3, Qt::SolidLine));
            itemToDraw->setPos(origPoint);
        }
        itemToDraw->setLine(0,0,
                            event->scenePos().x() - origPoint.x(),
                            event->scenePos().y() - origPoint.y());
    }
    else
        QGraphicsScene::mouseMoveEvent(event);
}*/

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{

}

void Scene::mousePressEvent(QMouseEvent *ev)
{
   /* MainWindow* mainW = MainWindow::getInstance();
    int  x1 = ev->x();
    int  y1 = ev->y();

    QLineF topLine(mainW->scene->sceneRect().topLeft(),
                   QPointF(x1,y1));
    mainW->drawLine(topLine);
    mainW->close();
    */
}

