#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#pragma once
#include <QPainter>
#include <QWidget>
#include <QGraphicsScene>
#include <iostream>
#include <vector>
#include <grid.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT //Tells us that we use GUI

public:

    explicit MainWindow(QWidget *parent = 0); //constructor
    ~MainWindow(); //distractor
    QGraphicsScene* scene;
    static MainWindow* getInstance();


    //drawings
    void drawLine(QLineF l);
    void drawLine(QPointF p1, QPointF p2);
    void drawLine(QPointF p1, QPointF p2, QPen pen);
    void drawPoint(QPointF p);
    void drawCircle(QPointF p,double r);
    void drawInfiniteLine(QPointF p1, QPointF p2);
    void drawTriangle(QPointF p1, QPointF p2, QPointF p3); //it's the same as polygone, but we also want to have an oportunity just to draw a triangle
    void drawPolygon(std::vector<QPointF> points);

    //grid part => drawings
    //void setGrid(Grid g);
    void drawCoordinateSystem(Grid g);

    //scene functions:
    void drawScene();
    void clearScene(); //sufficient for moving the grid! (moving/zooming)

private slots:
    void on_pushButton_clicked(); //Segment
    void on_pushButton_2_clicked(); //Circle
    void on_pushButton_3_clicked(); //Line
    void on_pushButton_4_clicked(); //Point
    void on_pushButton_5_clicked(); //Quadrilateral
    void on_pushButton_6_clicked(); //Triangle

private:
    Ui::MainWindow *ui;
    static MainWindow *theWindow;

};

#endif // MAINWINDOW_H
