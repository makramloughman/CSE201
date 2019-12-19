#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QToolButton>
#include <QDebug>
#include "dropdowntoolbutton.h"
#include <QPainter>
#include <QWidget>
#include <QGraphicsScene>
#include <iostream>
#include <vector>
#include <grid.h>
#include <point.hpp>
#include <mathobject.h>
#include <line.hpp>
#include <circle.hpp>
#include <general_functions.h>
#include <typeinfo>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsScene* scene;
    static MainWindow* getInstance();
    void drawLine(QLineF l);
    void drawLine(QPointF p1, QPointF p2);
    void drawLine(QPointF p1, QPointF p2, QPen pen);
    void drawPoint(QPointF p);
    void drawPoint(Point p);
    void drawCircle(QPointF p,double r);
    void drawCircle(QPointF p1, QPointF p2);
    void drawInfiniteLine(QPointF p1, QPointF p2); //need it in ViewCoordinates!!!!!
    void drawTriangle(QPointF p1, QPointF p2, QPointF p3); // it's the same as polygone, but we also want to have an oportunity just to draw a triangle
    void drawPolygon(std::vector<QPointF> points);

    //grid part => drawings
    Grid* mainGrid;
    void drawCoordinateSystem(); //just using the functions of the grid
    void setGrid(Grid* g); //seting the main grid

    //scene functions:
    void drawScene(); //drawing rectangle
    void clearScene(); //sufficient for moving the grid! (moving/zooming)

    //Coordinate systems => conversions
    QPointF mapFromGridToScene(double x,double y); //Grid to Scene
    QPointF mapFromSceneToGrid(double x, double y); //Scene to Grid
    QPointF mapToMyScene(double x,double y); // View to Scene
    QPointF mapFromMyScene(double x,double y); //Scene to View
    QPointF mapFromGridToView(double x, double y); //Grid to View
    QPointF mapFromViewToGrid(double x, double y); //View to Grid

    //GraphicsView
    int getWidth_View();
    int getHeight_View();
    void setBackGroundColor_View(QBrush b);

    std::vector<std::string> letters;

public slots:
    void Move();
    void Select();

    void Point_(); //DO NOT WRITE IT AS Point, since that's the class..
    void PointOnObject();
    void Intersection();
    void MidPoint();
    void ComplexPoint();
    void Extremum();
    void Roots();

    void Line_();
    void Segment();
    void Ray();
    void Polyline();
    void Vector();
    void VectorFromPoint();

    void PerpendicularLine();
    void ParallelLine();
    void PerpendicularBisector();
    void AngleBisector();
    void Tangent();

    void Triangle();
    void Square();
    void Rectangle();
    void RegularPolygon();
    void CircleCPT();
    void CircleCRT();

    void Ellipse();
    void Parabola();
    void Hyperbola();

    void Angle();
    void Distance();
    void Area();
    void Slope();
    void Relation();

    void LineSymmetry();
    void PointSymmetry();
    void Translate();

    void Delete();
    void Clear();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    static MainWindow *theWindow;
    bool started; //if the user clicked start button

    void createActions();
    void createMenus();
    void createToolBars();
    void createToolButtons();

    QAction* MoveAction;
    QAction* SelectAction;
    QMenu* MouseMenu;
    DropDownToolButton* MouseButton;

    QAction* PointAction;
    QAction* PointOnObjectAction;
    QAction* IntersectAction;
    QAction* MidPointAction;
    QAction* ComplexPointAction;
    QAction* ExtremumAction;
    QAction* RootsAction;
    QMenu* PointMenu;
    DropDownToolButton* PointButton;

    QAction* LineAction;
    QAction* SegmentAction;
    QAction* RayAction;
    QAction* PolylineAction;
    QAction* VectorAction;
    QAction* VectorFromPointAction;
    QMenu* LineMenu;
    DropDownToolButton* LineButton;

    QAction* PerpendicularLineAction;
    QAction* ParallelLineAction;
    QAction* PerpendicularBisectorAction;
    QAction* AngleBisectorAction;
    QAction* TangentAction;
    QMenu* SpecialLineMenu;
    DropDownToolButton* SpecialLineButton;

    QAction* TriangleAction;
    QAction* SquareAction;
    QAction* RectangleAction;
    QAction* RegularPolygonAction;
    QMenu* PolygonMenu;
    DropDownToolButton* PolygonButton;

    QAction* CircleCPTAction; // center through point tool
    QAction* CircleCRTAction; // center and radius
    QMenu* CircleMenu;
    DropDownToolButton* CircleButton;

    QAction* EllipseAction;
    QAction* ParabolaAction;
    QAction* HyperbolaAction;
    QMenu* ConicMenu;
    DropDownToolButton* ConicButton;

    QAction* AngleAction; // get angle
    QAction* DistanceAction; // get distance
    QAction* AreaAction; //get area
    QAction* SlopeAction; // get slope
    QAction* RelationAction; // get relation between two objects
    QMenu* MeasurementMenu;
    DropDownToolButton* MeasurementButton;

    QAction* LineSymmetryAction;
    QAction* PointSymmetryAction;
    QAction* TranslateAction; // translate by vector
    QMenu* TransformationMenu;
    DropDownToolButton* TransformationButton;

    QAction* DeleteAction;
    QAction* ClearAction;
    QMenu* GeneralMenu;
    DropDownToolButton* GeneralButton;
};

#endif // MAINWINDOW_H
