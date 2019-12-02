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

using namespace std;


#include <QApplication>

class MyView : public QGraphicsView
{
    public:
        explicit MyView(QWidget *parent = 0); //constructor
        void mousePressEvent(QMouseEvent *ev);
        std::vector<QPointF> clickedP;
        bool segment_chosen; //You have chosen to draw a segment
        bool circle_chosen;
        bool inf_line_chosen;
        bool point_chosen;
        bool polygon_chosen; //It works only for 4 points, for now
        int n_counter; //we will have many options, so this one counts the number of points we have chosen after clicking certain option
};

#endif // MYVIEW_H
