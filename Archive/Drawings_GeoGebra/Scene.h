#ifndef SCENE_H
#define SCENE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPainter>
#pragma once

class Scene : public QGraphicsScene
{
public:
    //enum Mode {};
    Scene(QObject* parent = 0);
    void mousePressEvent(QMouseEvent *ev);
/*private:
    Mode sceneMode;
    QPointF origPoint;
    QGraphicsLineItem* itemToDraw;
    void makeItemsControllable(bool areControllable);*/
};



#endif // SCENE_H
