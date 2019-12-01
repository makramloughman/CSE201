#ifndef MYVIEW_H
#define MYVIEW_H

#pragma once
#include <QtWidgets>
#include <QMainWindow>
#include <QPainter>
#include <QDialog>
#include <QGraphicsScene>
#include <QMouseEvent>


#include <QApplication>

class MyView : public QGraphicsView
{
    public:
        explicit MyView(QWidget *parent = 0); //constructor
        void mousePressEvent(QMouseEvent *ev);
};

#endif // MYVIEW_H
