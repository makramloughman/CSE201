#ifndef MYVIEW_H
#define MYVIEW_H

#pragma once
#include <QtWidgets>
#include <QMainWindow>
#include <QPainter>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <iostream>
#include <vector>
#include <cmath>
#include "grid.h"
#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "mathobject.h"
#include "container.h"

using namespace std;

#include <QApplication>

class MyView : public QGraphicsView
{
    public:
        explicit MyView(QWidget *parent = 0); //constructor

        void mousePressEvent(QMouseEvent *ev);
        void mouseMoveEvent(QMouseEvent *ev);
        void mouseReleaseEvent(QMouseEvent *ev);
        void wheelEvent(QWheelEvent *event);

        std::vector<QPointF> clickedP;
        bool point_chosen;
        bool segment_chosen;

        bool circle_chosen;
        bool circle_chosen_with_radius;
        bool ellipse_chosen;

        bool inf_line_chosen;

        bool move_grid_chosen;
        bool move_grid_pressed; //I chose to move grid and I pressed
        bool move_grid_released;
        QPointF last_clicked;

        bool select_object_chosen;
        Container chosen_objects;

        bool polygon_chosen; //triangle, quadrilateral, more sided polygons...
        int n_polygon; // number of points of certain polygon that we have chosen

        int n_counter; //we will have many options, so this one counts the number of points we have chosen after clicking certain option

        void refresh_indicators();
};

#endif // MYVIEW_H
