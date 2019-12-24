 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <point.hpp>
#include <help.h>
#include <memory>
#include "rectangle.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    theWindow = this;
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
       ui->graphicsView->setScene(scene);
       ui->graphicsView->setRenderHint(QPainter::Antialiasing);
       scene->setSceneRect(0, 0, 300, 300);
    createActions();
    createMenus();
    createToolButtons();
    createToolBars();
    this->started = false;

    QPen myPen = QPen();
    myPen.setWidth(1.5);
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

    TriangleAction = new QAction("Triangle", this);
    SquareAction = new QAction("Square", this);
    RectangleAction = new QAction("Rectangle", this);
    PolygonAction=new QAction("Polygon",this);
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

    TriangleAction->setIcon(QIcon(":/images/polygon.png"));
    SquareAction->setIcon(QIcon(":/images/square.png"));
    RectangleAction->setIcon(QIcon(":/images/rectangle.png"));
    RegularPolygonAction->setIcon(QIcon(":/images/regularpolygon.png"));
    PolygonAction->setIcon(QIcon(":/images/regularpolygon.png"));

    CircleCPTAction->setIcon(QIcon(":/images/circle2.png"));
    CircleCRTAction->setIcon(QIcon(":/images/circlepointradius.png"));

    EllipseAction->setIcon(QIcon(":/images/ellipse.png"));
    ParabolaAction->setIcon(QIcon(":/images/parabola.png"));
    HyperbolaAction->setIcon(QIcon(":/images/hyperbola3.png"));

    AngleAction->setIcon(QIcon(":/images/angle.png"));
    DistanceAction->setIcon(QIcon(":/images/distance.png"));
    AreaAction->setIcon(QIcon(":/images/area.png"));
    SlopeAction->setIcon(QIcon(":/images/slope.png"));
    RelationAction->setIcon(QIcon(":/images/relation.png"));

    LineSymmetryAction->setIcon(QIcon(":/images/mirroratline.png"));
    PointSymmetryAction->setIcon(QIcon(":/images/mirroratpoint.png"));
    TranslateAction->setIcon(QIcon(":/images/translatebyvector.png"));

    DeleteAction->setIcon(QIcon(":/images/delete.png"));
    ClearAction->setIcon(QIcon(":/images/xxx.png"));

    QObject::connect(MoveAction, SIGNAL(triggered()), this, SLOT(Move()));
    QObject::connect(SelectAction, SIGNAL(triggered()), this, SLOT(Select()));

    QObject::connect(PointAction, SIGNAL(triggered()), this, SLOT(Point_()));
    QObject::connect(PointOnObjectAction, SIGNAL(triggered()), this, SLOT(PointOnObject()));
    QObject::connect(IntersectAction, SIGNAL(triggered()), this, SLOT(Intersection()));
    QObject::connect(MidPointAction, SIGNAL(triggered()), this, SLOT(MidPoint()));
    QObject::connect(ComplexPointAction, SIGNAL(triggered()), this, SLOT(ComplexPoint()));
    QObject::connect(ExtremumAction, SIGNAL(triggered()), this, SLOT(Extremum()));
    QObject::connect(RootsAction, SIGNAL(triggered()), this, SLOT(Roots()));

    QObject::connect(LineAction, SIGNAL(triggered()), this, SLOT(Line_()));
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

    QObject::connect(TriangleAction, SIGNAL(triggered()), this, SLOT(Triangle()));
    QObject::connect(SquareAction, SIGNAL(triggered()), this, SLOT(Square()));
    QObject::connect(RectangleAction, SIGNAL(triggered()), this, SLOT(Rectangle()));
    QObject::connect(RegularPolygonAction, SIGNAL(triggered()), this, SLOT(RegularPolygon()));
    QObject::connect(PolygonAction, SIGNAL(triggered()),this,SLOT(Polygon()));

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
    PolygonMenu->addAction(TriangleAction);
    PolygonMenu->addAction(SquareAction);
    PolygonMenu->addAction(RectangleAction);
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
    PolygonButton->setDefaultAction(TriangleAction);
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

void MainWindow::drawLine(QLineF l)
{
    scene->addLine(l, myPen);
}

void MainWindow::drawLine(QPointF p1, QPointF p2)
{
    MainWindow::drawLine(QLineF(p1,p2));
}

void MainWindow::drawLine(QPointF p1, QPointF p2, QPen pen)
{
    QLineF f = QLineF(p1, p2);
    scene->addLine(f, pen);
}

void MainWindow::drawPoint(QPointF p)
{
    double rad = 3;
    scene->addEllipse(p.x()-rad, p.y()-rad, rad*2.0, rad*2.0,
                      myPen, QBrush(Qt::SolidPattern));
}

void MainWindow::drawPoint(Point p)
{
    double rad = 3;
    scene->addEllipse(p.getx()-rad, p.gety()-rad, rad*2.0, rad*2.0,
                      myPen, QBrush(Qt::SolidPattern));
}

void MainWindow::drawCircle(QPointF p, double r)
{
    scene->addEllipse(p.x()-r, p.y()-r, r*2.0, r*2.0,
                      myPen);
}

void MainWindow::drawCircle(QPointF p1, QPointF p2)
{
    double r = sqrt(pow(p1.x()-p2.x(),2)+pow(p1.y()-p2.y(),2));
    scene->addEllipse(p1.x()-r, p1.y()-r, r*2.0, r*2.0,
                      myPen);
}

void MainWindow::drawInfiniteLine(QPointF p1, QPointF p2) //inViewCoordinates
{
    //construct y = k*x + n
    double slope = 0;
    double term = 0;
    if (p1.x()!=p2.x()){
        slope = (p1.y()-p2.y())/(p1.x()-p2.x()); //k
        term = (p1.y() - slope * p1.x()); //n
    }



    //now, we create two points on the edges of the form
    //WE ARE ASSUMING SLOPE!=0

    int y0 = 0; //at this y-coordinate is the first point
    int y1 = ui->graphicsView->height();
    int x1 = ui->graphicsView->width();

    if(slope!=0)
    {
        QPointF p11 = ui->graphicsView->mapToScene((y0 - term)/slope, y0);
        QPointF p21 = ui->graphicsView->mapToScene((y1 - term)/slope, y1);
        MainWindow::drawLine(p11,p21);
    }

    else if (p1.x()==p2.x())
    {
        QPointF p11 = ui->graphicsView->mapToScene(p1.x(), y0);
        QPointF p21 = ui->graphicsView->mapToScene(p2.x(), y1);
        MainWindow::drawLine(p11,p21);
    }
    else
    {
        QPointF p11 = ui->graphicsView->mapToScene(0, p1.y());
        QPointF p21 = ui->graphicsView->mapToScene(x1, p2.y());
        MainWindow::drawLine(p11,p21);
    }
}

void MainWindow::drawInfiniteLine(Point p1, Point p2)
{
    QPointF f1 = QPointF(p1.getx(),p1.gety());
    QPointF f2 = QPointF(p2.getx(),p2.gety());
    drawInfiniteLine(f1,f2);
}

void MainWindow::drawInfiniteLine(Line l)
{
    drawInfiniteLine(l.p1,l.p2);
}

void MainWindow::drawTriangle(QPointF p1, QPointF p2, QPointF p3)
{
    std::vector<QPointF> ps;
    ps.push_back(p1);
    ps.push_back(p2);
    ps.push_back(p3);
    MainWindow::drawPolygon(ps);
}

/*void MainWindow::drawRectangle(QPointF p1, QPointF p3)
{
   QPointF l=(mainW->mapToMyScene(point1.getx(),point1.gety()))
   QpointF q
   MainWindow::drawLine()
}*/

void MainWindow::drawPolygon(std::vector<QPointF> points)
{
    int n = points.size();
    for(int i=0;i<n-1;i++)
    {
        MainWindow::drawLine(points[i],points[i+1]);
    }
    MainWindow::drawLine(points[0],points[n-1]);
}


void MainWindow::drawCoordinateSystem()
{
    this->mainGrid->draw();
}

void MainWindow::setGrid(Grid* g)
{
    this->mainGrid = g;
}

MainWindow* MainWindow:: getInstance()
{
    return theWindow;
}

void MainWindow::SetPen(double width, QColor c)
{
    myPen.setWidth(width);
    myPen.setColor(c);
}

void MainWindow::ResetPen()
{
    myPen = QPen();
    myPen.setWidth(1.5);
}

void MainWindow::drawScene()
{
    scene->addRect(scene->sceneRect());
}
void MainWindow::clearScene()
{
    scene->clear();
}

QPointF MainWindow::mapFromGridToScene(double x, double y)
{
    //naya to implement
    QPointF p =mapFromGridToView(x,y);
    return mapToMyScene(p.x(),p.y());
}

QPointF MainWindow::mapFromSceneToGrid(double x, double y)
{
    //Naya to implement
    QPointF p = mapFromMyScene(x,y);
    return mapFromViewToGrid(p.x(),p.y());
}

int MainWindow::getWidth_View()
{
    return ui->graphicsView->width();
}

int MainWindow::getHeight_View()
{
    return ui->graphicsView->height();
}

void MainWindow::setBackGroundColor_View(QBrush b)
{
    scene->setBackgroundBrush(b);
}

QPointF MainWindow::mapToMyScene(double x, double y)
{
    return ui->graphicsView->mapToScene(x,y);
}

QPointF MainWindow::mapFromMyScene(double x, double y)
{
    return ui->graphicsView->mapFromScene(x,y);
}

QPointF MainWindow::mapFromViewToGrid(double x, double y)
{
    //Naya to implement
    double x_g =(x - mainGrid-> getX())/ mainGrid->unit;
    double y_g = (mainGrid-> getY()-y)/ mainGrid->unit;

    return QPointF(x_g,y_g);
}

QPointF MainWindow::mapFromGridToView(double x, double y)
{
    //Naya to implement
    double x_v = (x*mainGrid->unit + mainGrid-> getX());
    double y_v = (-y*mainGrid->unit + mainGrid-> getY());
    return QPointF(x_v,y_v);
}

MainWindow *MainWindow::theWindow = nullptr; //declare static

void MainWindow::Move()
{
    ui->graphicsView->refresh_indicators();
    ui->graphicsView-> move_grid_chosen = true;
}

void MainWindow::Select()
{
    ui->graphicsView->refresh_indicators();
    ui->graphicsView->select_object_chosen = true;
}

void MainWindow::Point_()
{
    ui->graphicsView->refresh_indicators();
    ui->graphicsView->point_chosen = true;
}

void MainWindow::PointOnObject(){
    qDebug() << "MainWindow::PointOnObject()";
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

void MainWindow::Line_(){
    ui->graphicsView->refresh_indicators();
    ui->graphicsView->inf_line_chosen = true;
}

void MainWindow::Segment(){
    ui->graphicsView->refresh_indicators();
    ui->graphicsView->segment_chosen = true;
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

void MainWindow::Triangle()
{
    ui->graphicsView->refresh_indicators();
    ui->graphicsView->polygon_chosen = true;
    ui->graphicsView->n_polygon = 3;
}

void MainWindow::Square(){
    qDebug() << "MainWindow::Square()";
}

void MainWindow::Rectangle(){
    ui->graphicsView->refresh_indicators();
    ui->graphicsView->polygon_chosen = true;
    ui->graphicsView->n_polygon = 2;
}

void MainWindow::RegularPolygon(){
    qDebug() << "MainWindow::RegularPolygon()";
}

void MainWindow::Polygon(){
    qDebug() <<"MainWindow::Polygon()";
}

void MainWindow::CircleCPT(){
    ui->graphicsView->circle_chosen = true;
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
    scene->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete MoveAction;
    delete SelectAction;
    delete MouseMenu;
    delete MouseButton;
    delete PointAction;
    delete PointOnObjectAction;
    delete IntersectAction;
    delete MidPointAction;
    delete ComplexPointAction;
    delete ExtremumAction;
    delete RootsAction;
    delete PointMenu;
    delete PointButton;
    delete LineAction;
    delete SegmentAction;
    delete RayAction;
    delete PolylineAction;
    delete VectorAction;
    delete VectorFromPointAction;
    delete LineMenu;
    delete LineButton;
    delete PerpendicularLineAction;
    delete ParallelLineAction;
    delete PerpendicularBisectorAction;
    delete AngleBisectorAction;
    delete TangentAction;
    delete SpecialLineMenu;
    delete SpecialLineButton;
    delete TriangleAction;
    delete SquareAction;
    delete RectangleAction;
    delete RegularPolygonAction;
    delete PolygonAction;
    delete PolygonMenu;
    delete PolygonButton;
    delete CircleCPTAction;
    delete CircleCRTAction;
    delete CircleMenu;
    delete CircleButton;
    delete EllipseAction;
    delete ParabolaAction;
    delete HyperbolaAction;
    delete ConicMenu;
    delete ConicButton;
    delete AngleAction;
    delete DistanceAction;
    delete AreaAction;
    delete SlopeAction;
    delete RelationAction;
    delete MeasurementMenu;
    delete MeasurementButton;
    delete LineSymmetryAction;
    delete PointSymmetryAction;
    delete TranslateAction;
    delete TransformationMenu;
    delete TransformationButton;
    delete DeleteAction;
    delete ClearAction;
    delete GeneralMenu;
    delete GeneralButton;

}

void MainWindow::on_pushButton_clicked()
{
    if(!started)
    {
        this->started = true;
        Grid* g = new Grid(50,this->getHeight_View()-50,25);
        setGrid(g);
        g->draw();
        g->set_BackColor(QBrush(Qt::white, Qt::SolidPattern));
        g->set_xaxis_label();
        g->set_yaxis_label();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    std::cout<<"you entered this button"<<endl;
    //std::cout<<typeid(mainGrid->obj.segments[0]).name()<<endl;
    //std::cout<<typeid(mainGrid->obj.circles[0]).name()<<endl;

    /*std::vector<MathObject*> v;
    Line* x = new Line();
    v.push_back(x);
    std::cout<<typeid(*x).name()<<endl;
    std::cout<<typeid(*v[0]).name()<<endl;*/
    /*Line* a = new Line();
    std::unique_ptr<Line> p(a);
    std::cout<<typeid(p).name()<<endl;
    std::vector<std::unique_ptr<MathObject>> v;
    v.push_back(std::move(p));
    std::cout<<typeid(v[0]).name()<<endl;
    std::cout<<maxx(*v[0],*v[0])<<endl;*/

    MathObject* a = new Line();
    MathObject** b = &a;
    std::vector<MathObject**> v;
    v.push_back(b);
    std::cout<<typeid(**v[0]).name()<<endl;
    //std::cout<<maxx(**v[0],**v[0])<<endl;


    /*//std::cout<<typeid(Segment()).name()<<endl;


    std::vector<Point> in = intersection(*mainGrid->obj.segments[0],*mainGrid->obj.circles[0]);

    std::cout << in.size() << std::endl;
    if (in.size()==0)
    {
        std::cout<<"no intersection was found"<<endl;
    }
    QPointF f1 = mapToMyScene(in[0].getx(),in[0].gety());
    QPointF f2 = mapToMyScene(in[1].getx(),in[1].gety());
    drawPoint(f1);
    drawPoint(f2);
    */
}

