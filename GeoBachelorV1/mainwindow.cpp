#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createActions();
    createMenus();
    createToolButtons();
    createToolBars();
}

void MainWindow::createActions(){
    MoveAction = new QAction("Move", this);
    SelectAction = new QAction("Select", this);

    PointAction = new QAction("Point", this);
    PointOnObjectAction = new QAction("Point on Object", this);
    IntersectAction = new QAction("Intersect", this);
    MidPointAction = new QAction("Midpoint or Center", this);
    ComplexPointAction = new QAction("Complex Number", this);
    ExtremumAction = new QAction("Extremum", this);
    RootsAction = new QAction("Roots", this);

    LineAction = new QAction("Line", this);
    SegmentAction = new QAction("Segment", this);
    RayAction = new QAction("Ray", this);
    PolylineAction = new QAction("Polyliner", this);
    VectorAction = new QAction("Vector", this);
    VectorFromPointAction = new QAction("Vector from Point", this);

    PerpendicularLineAction = new QAction("Perpendicular Line", this);
    ParallelLineAction = new QAction("Parallel Line", this);
    PerpendicularBisectorAction = new QAction("Perpendicular Bisector", this);
    AngleBisectorAction = new QAction("Angle Bisector", this);
    TangentAction = new QAction("Tangent", this);

    PolygonAction = new QAction("Polygon", this);
    RegularPolygonAction = new QAction("Regular Polygon", this);

    CircleCPTAction = new QAction("Circle with Center through Point", this);
    CircleCRTAction = new QAction("Circle: Center and Radius", this);

    EllipseAction = new QAction("Ellipse", this);
    ParabolaAction = new QAction("Parabola", this);
    HyperbolaAction = new QAction("Hyperbola", this);

    AngleAction = new QAction("Angle", this);
    DistanceAction = new QAction("Distance or Length", this);
    AreaAction = new QAction("Area", this);
    SlopeAction = new QAction("Slope", this);
    RelationAction = new QAction("Relation", this);

    LineSymmetryAction = new QAction("Reflect about Line", this);
    PointSymmetryAction = new QAction("Reflect about Point", this);
    TranslateAction = new QAction("Translate by Vector", this);

    DeleteAction = new QAction("Delete", this);
    ClearAction = new QAction("Clear", this);

    MoveAction->setIcon(QIcon(":/images/move.png"));
    SelectAction->setIcon(QIcon(":/images/middlefinger.png"));

    PointAction->setIcon(QIcon(":/images/point.png"));
    PointOnObjectAction->setIcon(QIcon(":/images/pointonobject.png"));
    IntersectAction->setIcon(QIcon(":/images/intersect.png"));
    MidPointAction->setIcon(QIcon(":/images/midpoint.png"));
    ComplexPointAction->setIcon(QIcon(":/images/complexnumber.png"));
    ExtremumAction->setIcon(QIcon(":/images/extremum.png"));
    RootsAction->setIcon(QIcon(":/images/roots.png"));

    LineAction->setIcon(QIcon(":/images/join.png"));
    SegmentAction->setIcon(QIcon(":/images/segment.png"));
    RayAction->setIcon(QIcon(":/images/ray.png"));
    PolylineAction->setIcon(QIcon(":/images/polyline.png"));
    VectorAction->setIcon(QIcon(":/images/vector.png"));
    VectorFromPointAction->setIcon(QIcon(":/images/vectorfrompoint.png"));

    PerpendicularLineAction->setIcon(QIcon(":/images/orthogonal.png"));
    ParallelLineAction->setIcon(QIcon(":/images/parallel.png"));
    PerpendicularBisectorAction->setIcon(QIcon(":/images/linebisector.png"));
    AngleBisectorAction->setIcon(QIcon(":/images/angularbisector.png"));
    TangentAction->setIcon(QIcon(":/images/tangent.png"));

    PolygonAction->setIcon(QIcon(":/images/polygon.png"));
    RegularPolygonAction->setIcon(QIcon(":/images/regularpolygon.png"));

    CircleCPTAction->setIcon(QIcon(":/images/xxx.png"));
    CircleCRTAction->setIcon(QIcon(":/images/xxx.png"));

    EllipseAction->setIcon(QIcon(":/images/xxx.png"));
    ParabolaAction->setIcon(QIcon(":/images/xxx.png"));
    HyperbolaAction->setIcon(QIcon(":/images/xxx.png"));

    AngleAction->setIcon(QIcon(":/images/xxx.png"));
    DistanceAction->setIcon(QIcon(":/images/xxx.png"));
    AreaAction->setIcon(QIcon(":/images/xxx.png"));
    SlopeAction->setIcon(QIcon(":/images/xxx.png"));
    RelationAction->setIcon(QIcon(":/images/xxx.png"));

    LineSymmetryAction->setIcon(QIcon(":/images/xxx.png"));
    PointSymmetryAction->setIcon(QIcon(":/images/xxx.png"));
    TranslateAction->setIcon(QIcon(":/images/xxx.png"));

    DeleteAction->setIcon(QIcon(":/images/xxx.png"));
    ClearAction->setIcon(QIcon(":/images/xxx.png"));

    QObject::connect(MoveAction, SIGNAL(triggered()), this, SLOT(Move()));
    QObject::connect(SelectAction, SIGNAL(triggered()), this, SLOT(Select()));

    QObject::connect(PointAction, SIGNAL(triggered()), this, SLOT(Point()));
    QObject::connect(PointOnObjectAction, SIGNAL(triggered()), this, SLOT(PointOnObject()));
    QObject::connect(IntersectAction, SIGNAL(triggered()), this, SLOT(Intersection()));
    QObject::connect(MidPointAction, SIGNAL(triggered()), this, SLOT(MidPoint()));
    QObject::connect(ComplexPointAction, SIGNAL(triggered()), this, SLOT(ComplexPoint()));
    QObject::connect(ExtremumAction, SIGNAL(triggered()), this, SLOT(Extremum()));
    QObject::connect(RootsAction, SIGNAL(triggered()), this, SLOT(Roots()));

    QObject::connect(LineAction, SIGNAL(triggered()), this, SLOT(Line()));
    QObject::connect(SegmentAction, SIGNAL(triggered()), this, SLOT(Segment()));
    QObject::connect(RayAction, SIGNAL(triggered()), this, SLOT(Ray()));
    QObject::connect(PolylineAction, SIGNAL(triggered()), this, SLOT(Polyline()));
    QObject::connect(VectorAction, SIGNAL(triggered()), this, SLOT(Vector()));
    QObject::connect(VectorFromPointAction, SIGNAL(triggered()), this, SLOT(VectorFromPoint()));

    QObject::connect(PerpendicularLineAction, SIGNAL(triggered()), this, SLOT(PerpendicularLine()));
    QObject::connect(ParallelLineAction, SIGNAL(triggered()), this, SLOT(ParallelLine()));
    QObject::connect(PerpendicularBisectorAction, SIGNAL(triggered()), this, SLOT(PerpendicularBisector()));
    QObject::connect(AngleBisectorAction, SIGNAL(triggered()), this, SLOT(AngleBisector()));
    QObject::connect(TangentAction, SIGNAL(triggered()), this, SLOT(Tangent()));

    QObject::connect(PolygonAction, SIGNAL(triggered()), this, SLOT(Polygon()));
    QObject::connect(RegularPolygonAction, SIGNAL(triggered()), this, SLOT(RegularPolygon()));

    QObject::connect(CircleCPTAction, SIGNAL(triggered()), this, SLOT(CircleCPT()));
    QObject::connect(CircleCRTAction, SIGNAL(triggered()), this, SLOT(CircleCRT()));

    QObject::connect(EllipseAction, SIGNAL(triggered()), this, SLOT(Ellipse()));
    QObject::connect(ParabolaAction, SIGNAL(triggered()), this, SLOT(Parabola()));
    QObject::connect(HyperbolaAction, SIGNAL(triggered()), this, SLOT(Hyperbola()));

    QObject::connect(AngleAction, SIGNAL(triggered()), this, SLOT(Angle()));
    QObject::connect(DistanceAction, SIGNAL(triggered()), this, SLOT(Distance()));
    QObject::connect(AreaAction, SIGNAL(triggered()), this, SLOT(Area()));
    QObject::connect(SlopeAction, SIGNAL(triggered()), this, SLOT(Slope()));
    QObject::connect(RelationAction, SIGNAL(triggered()), this, SLOT(Relation()));

    QObject::connect(LineSymmetryAction, SIGNAL(triggered()), this, SLOT(LineSymmetry()));
    QObject::connect(PointSymmetryAction, SIGNAL(triggered()), this, SLOT(PointSymmetry()));
    QObject::connect(TranslateAction, SIGNAL(triggered()), this, SLOT(Translate()));

    QObject::connect(DeleteAction, SIGNAL(triggered()), this, SLOT(Delete()));
    QObject::connect(ClearAction, SIGNAL(triggered()), this, SLOT(Clear()));
}

void MainWindow::createMenus(){
    MouseMenu = new QMenu;
    MouseMenu->addAction(MoveAction);
    MouseMenu->addAction(SelectAction);

    PointMenu = new QMenu;
    PointMenu->addAction(PointAction);
    PointMenu->addAction(PointOnObjectAction);
    PointMenu->addAction(IntersectAction);
    PointMenu->addAction(MidPointAction);
    PointMenu->addAction(ComplexPointAction);
    PointMenu->addAction(ExtremumAction);
    PointMenu->addAction(RootsAction);

    LineMenu = new QMenu;
    LineMenu->addAction(LineAction);
    LineMenu->addAction(SegmentAction);
    LineMenu->addAction(RayAction);
    LineMenu->addAction(PolylineAction);
    LineMenu->addAction(VectorAction);
    LineMenu->addAction(VectorFromPointAction);

    SpecialLineMenu = new QMenu;
    SpecialLineMenu->addAction(PerpendicularLineAction);
    SpecialLineMenu->addAction(ParallelLineAction);
    SpecialLineMenu->addAction(PerpendicularBisectorAction);
    SpecialLineMenu->addAction(AngleBisectorAction);
    SpecialLineMenu->addAction(TangentAction);

    PolygonMenu = new QMenu;
    PolygonMenu->addAction(PolygonAction);
    PolygonMenu->addAction(RegularPolygonAction);

    CircleMenu = new QMenu;
    CircleMenu->addAction(CircleCPTAction);
    CircleMenu->addAction(CircleCRTAction);

    ConicMenu = new QMenu;
    ConicMenu->addAction(EllipseAction);
    ConicMenu->addAction(ParabolaAction);
    ConicMenu->addAction(HyperbolaAction);

    MeasurementMenu = new QMenu;
    MeasurementMenu->addAction(AngleAction);
    MeasurementMenu->addAction(DistanceAction);
    MeasurementMenu->addAction(AreaAction);
    MeasurementMenu->addAction(SlopeAction);
    MeasurementMenu->addAction(RelationAction);

    TransformationMenu = new QMenu;
    TransformationMenu->addAction(LineSymmetryAction);
    TransformationMenu->addAction(PointSymmetryAction);
    TransformationMenu->addAction(TranslateAction);

    GeneralMenu = new QMenu;
    GeneralMenu->addAction(DeleteAction);
    GeneralMenu->addAction(ClearAction);
}

void MainWindow::createToolButtons(){
    MouseButton = new DropDownToolButton;
    MouseButton->setMenu(MouseMenu);
    MouseButton->setDefaultAction(MoveAction);
    MouseButton->setMinimumHeight(32);
    MouseButton->setMinimumWidth(44);
    MouseButton->setIconSize(QSize(32,32));

    PointButton = new DropDownToolButton;
    PointButton->setMenu(PointMenu);
    PointButton->setDefaultAction(PointAction);
    PointButton->setMinimumHeight(32);
    PointButton->setMinimumWidth(44);
    PointButton->setIconSize(QSize(32,32));

    LineButton = new DropDownToolButton;
    LineButton->setMenu(LineMenu);
    LineButton->setDefaultAction(LineAction);
    LineButton->setMinimumHeight(32);
    LineButton->setMinimumWidth(44);
    LineButton->setIconSize(QSize(32,32));

    SpecialLineButton = new DropDownToolButton;
    SpecialLineButton->setMenu(SpecialLineMenu);
    SpecialLineButton->setDefaultAction(PerpendicularLineAction);
    SpecialLineButton->setMinimumHeight(32);
    SpecialLineButton->setMinimumWidth(44);
    SpecialLineButton->setIconSize(QSize(32,32));

    PolygonButton = new DropDownToolButton;
    PolygonButton->setMenu(PolygonMenu);
    PolygonButton->setDefaultAction(PolygonAction);
    PolygonButton->setMinimumHeight(32);
    PolygonButton->setMinimumWidth(44);
    PolygonButton->setIconSize(QSize(32,32));

    CircleButton = new DropDownToolButton;
    CircleButton->setMenu(CircleMenu);
    CircleButton->setDefaultAction(CircleCPTAction);
    CircleButton->setMinimumHeight(32);
    CircleButton->setMinimumWidth(44);
    CircleButton->setIconSize(QSize(32,32));

    ConicButton = new DropDownToolButton;
    ConicButton->setMenu(ConicMenu);
    ConicButton->setDefaultAction(EllipseAction);
    ConicButton->setMinimumHeight(32);
    ConicButton->setMinimumWidth(44);
    ConicButton->setIconSize(QSize(32,32));

    MeasurementButton = new DropDownToolButton;
    MeasurementButton->setMenu(MeasurementMenu);
    MeasurementButton->setDefaultAction(AngleAction);
    MeasurementButton->setMinimumHeight(32);
    MeasurementButton->setMinimumWidth(44);
    MeasurementButton->setIconSize(QSize(32,32));

    TransformationButton = new DropDownToolButton;
    TransformationButton->setMenu(TransformationMenu);
    TransformationButton->setDefaultAction(LineSymmetryAction);
    TransformationButton->setMinimumHeight(32);
    TransformationButton->setMinimumWidth(44);
    TransformationButton->setIconSize(QSize(32,32));

    GeneralButton = new DropDownToolButton;
    GeneralButton->setMenu(GeneralMenu);
    GeneralButton->setDefaultAction(DeleteAction);
    GeneralButton->setMinimumHeight(32);
    GeneralButton->setMinimumWidth(44);
    GeneralButton->setIconSize(QSize(32,32));
}

void MainWindow::createToolBars(){
    ui->horizontalLayout_2->addWidget(MouseButton);
    ui->horizontalLayout_2->addWidget(PointButton);
    ui->horizontalLayout_2->addWidget(LineButton);
    ui->horizontalLayout_2->addWidget(SpecialLineButton);
    ui->horizontalLayout_2->addWidget(PolygonButton);
    ui->horizontalLayout_2->addWidget(CircleButton);
    ui->horizontalLayout_2->addWidget(ConicButton);
    ui->horizontalLayout_2->addWidget(MeasurementButton);
    ui->horizontalLayout_2->addWidget(TransformationButton);
    ui->horizontalLayout_2->addWidget(GeneralButton);
    ui->horizontalLayout_2->addStretch();
}

void MainWindow::Move(){
    qDebug() << "MainWindow::Move()";
}

void MainWindow::Select(){
    qDebug() << "MainWindow::Select()";
}

void MainWindow::Point(){
    qDebug() << "MainWindow::Point()";
}

void MainWindow::PointOnObject(){
    qDebug() << "MainWindow::alignCenter()";
}

void MainWindow::Intersection(){
    qDebug() << "MainWindow::Intersection()";
}

void MainWindow::MidPoint(){
    qDebug() << "MainWindow::MidPoint()";
}

void MainWindow::ComplexPoint(){
    qDebug() << "MainWindow::ComplexPoint()";
}

void MainWindow::Extremum(){
    qDebug() << "MainWindow::Extremum()";
}

void MainWindow::Roots(){
    qDebug() << "MainWindow::Roots()";
}

void MainWindow::Line(){
    qDebug() << "MainWindow::Line()";
}

void MainWindow::Segment(){
    qDebug() << "MainWindow::Roots()";
}

void MainWindow::Ray(){
    qDebug() << "MainWindow::Ray()";
}

void MainWindow::Polyline(){
    qDebug() << "MainWindow::Polyline()";
}

void MainWindow::Vector(){
    qDebug() << "MainWindow::Vector()";
}

void MainWindow::VectorFromPoint(){
    qDebug() << "MainWindow::VectorFromPoint()";
}

void MainWindow::PerpendicularLine(){
    qDebug() << "MainWindow::PerpendicularLine()";
}

void MainWindow::ParallelLine(){
    qDebug() << "MainWindow::ParallelLine()";
}

void MainWindow::PerpendicularBisector(){
    qDebug() << "MainWindow::PerpendicularBisector()";
}

void MainWindow::AngleBisector(){
    qDebug() << "MainWindow::AngleBisector()";
}

void MainWindow::Tangent(){
    qDebug() << "MainWindow::Tangent()";
}

void MainWindow::Polygon(){
    qDebug() << "MainWindow::Polygon()";
}

void MainWindow::RegularPolygon(){
    qDebug() << "MainWindow::RegularPolygon()";
}

void MainWindow::CircleCPT(){
    qDebug() << "MainWindow::CircleCPT()";
}

void MainWindow::CircleCRT(){
    qDebug() << "MainWindow::CircleCRT()";
}

void MainWindow::Ellipse(){
    qDebug() << "MainWindow::Ellipse()";
}

void MainWindow::Parabola(){
    qDebug() << "MainWindow::Parabola()";
}

void MainWindow::Hyperbola(){
    qDebug() << "MainWindow::Hyperbola()";
}

void MainWindow::Angle(){
    qDebug() << "MainWindow::Angle()";
}

void MainWindow::Distance(){
    qDebug() << "MainWindow::Distance()";
}

void MainWindow::Area(){
    qDebug() << "MainWindow::Area()";
}

void MainWindow::Slope(){
    qDebug() << "MainWindow::Slope()";
}

void MainWindow::Relation(){
    qDebug() << "MainWindow::Relation()";
}

void MainWindow::LineSymmetry(){
    qDebug() << "MainWindow::LineSymmetry()";
}

void MainWindow::PointSymmetry(){
    qDebug() << "MainWindow::PointSymmetry()";
}

void MainWindow::Translate(){
    qDebug() << "MainWindow::Translate()";
}

void MainWindow::Delete(){
    qDebug() << "MainWindow::Delete()";
}

void MainWindow::Clear(){
    qDebug() << "MainWindow::Clear()";
}

MainWindow::~MainWindow()
{
    delete ui;
}
