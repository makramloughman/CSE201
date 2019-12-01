#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#pragma once
#include <QPainter>
#include <QDialog>
#include <QGraphicsScene>
#include <QTimer>
#include "Scene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT //Tells us that we use GUI

public:
    explicit MainWindow(QWidget *parent = 0); //constructor
    ~MainWindow(); //distractor
    void drawLine(QLineF l);
    QGraphicsScene* scene;
    static MainWindow* getInstance();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsEllipseItem *ellipse;
    static MainWindow *theWindow;

};

#endif // MAINWINDOW_H
