#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QToolButton>
#include <QDebug>
#include "dropdowntoolbutton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    void Point();
    void PointOnObject();
    void Intersection();
    void MidPoint();
    void ComplexPoint();
    void Extremum();
    void Roots();

    void Line();
    void Segment();
    void Ray();
    void Polyline();
    void Vector();
    void VectorFromPoint();

private:
    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
    void createToolBars();
    void createToolButtons();

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
};

#endif // MAINWINDOW_H
