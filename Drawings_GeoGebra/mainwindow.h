#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#pragma once
#include <QPainter>
#include <QWidget>
#include <QDialog>
#include <QGraphicsScene>
#include <QTimer>
#include "Scene.h"
#include <iostream>
#include <vector>

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
    //Grid g =>Waiting for the Grid

    //drawings
    void drawLine(QLineF l);
    void drawLine(QPointF p1, QPointF p2);
    void drawPoint(QPointF p);
    void drawCircle(QPointF p,double r);
    void drawInfiniteLine(QPointF p1, QPointF p2);
    void drawPolygon(std::vector<QPointF> points);

    //scene functions:
    void drawScene();
    void clearScene(); //sufficient for moving the grid! (moving/zooming)

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    static MainWindow *theWindow;

};

#endif // MAINWINDOW_H
