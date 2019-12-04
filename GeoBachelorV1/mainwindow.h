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
    void Move();
    void Select();

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

    void PerpendicularLine();
    void ParallelLine();
    void PerpendicularBisector();
    void AngleBisector();
    void Tangent();

    void Polygon();
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

private:
    Ui::MainWindow *ui;
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

    QAction* PolygonAction;
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
