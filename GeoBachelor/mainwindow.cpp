#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "point.hpp"
#include "rectangle.h"
#include <memory>
#include <QResizeEvent>
#include <QDebug>
#include <QPushButton>


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
    createGrid();

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

    RegularPolygonAction = new QAction("Regular Polygon", this);
    PolygonAction = new QAction("Polygon",this);
    SquareAction = new QAction("Square", this);
    RectangleAction = new QAction("Rectangle", this);

    TriangleAction = new QAction("Triangle", this);
    InscribedCircleAction = new QAction("Inscribed Circle", this);
    CircumscribedCricleAction = new QAction("Circumscribed Circle", this);
    OrthoCenterAction = new QAction("Orthocenter", this);
    CenterOfGravityAction = new QAction("Center of Gravity", this);

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

    RegularPolygonAction->setIcon(QIcon(":/images/regularpolygon.png"));
    PolygonAction->setIcon(QIcon(":/images/regularpolygon.png"));
    SquareAction->setIcon(QIcon(":/images/square.png"));
    RectangleAction->setIcon(QIcon(":/images/rectangle.png"));

    TriangleAction->setIcon(QIcon(":/images/polygon.png"));
    InscribedCircleAction->setIcon(QIcon(":/images/xxx.png"));
    CircumscribedCricleAction->setIcon(QIcon(":/images/xxx.png"));
    OrthoCenterAction->setIcon(QIcon(":/images/xxx.png"));
    CenterOfGravityAction->setIcon(QIcon(":/images/xxx.png"));

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
    ClearAction->setIcon(QIcon(":/images/clear.png"));

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
    QObject::connect(SegmentAction, SIGNAL(triggered()), this, SLOT(Segment_()));
    QObject::connect(RayAction, SIGNAL(triggered()), this, SLOT(Ray()));
    QObject::connect(PolylineAction, SIGNAL(triggered()), this, SLOT(Polyline()));
    QObject::connect(VectorAction, SIGNAL(triggered()), this, SLOT(Vector()));
    QObject::connect(VectorFromPointAction, SIGNAL(triggered()), this, SLOT(VectorFromPoint()));

    QObject::connect(PerpendicularLineAction, SIGNAL(triggered()), this, SLOT(PerpendicularLine()));
    QObject::connect(ParallelLineAction, SIGNAL(triggered()), this, SLOT(ParallelLine()));
    QObject::connect(PerpendicularBisectorAction, SIGNAL(triggered()), this, SLOT(PerpendicularBisector()));
    QObject::connect(AngleBisectorAction, SIGNAL(triggered()), this, SLOT(AngleBisector()));
    QObject::connect(TangentAction, SIGNAL(triggered()), this, SLOT(Tangent()));

    QObject::connect(RegularPolygonAction, SIGNAL(triggered()), this, SLOT(RegularPolygon()));
    QObject::connect(PolygonAction, SIGNAL(triggered()),this,SLOT(Polygon()));
    QObject::connect(SquareAction, SIGNAL(triggered()), this, SLOT(Square()));
    QObject::connect(RectangleAction, SIGNAL(triggered()), this, SLOT(Rectangle()));

    QObject::connect(TriangleAction, SIGNAL(triggered()), this, SLOT(Triangle_()));
    QObject::connect(InscribedCircleAction, SIGNAL(triggered()), this, SLOT(InscribedCircle()));
    QObject::connect(CircumscribedCricleAction, SIGNAL(triggered()), this, SLOT(CircumscribedCricle()));
    QObject::connect(OrthoCenterAction, SIGNAL(triggered()), this, SLOT(OrthoCenter()));
    QObject::connect(CenterOfGravityAction, SIGNAL(triggered()), this, SLOT(CenterOfGravity()));

    QObject::connect(CircleCPTAction, SIGNAL(triggered()), this, SLOT(CircleCPT()));
    QObject::connect(CircleCRTAction, SIGNAL(triggered()), this, SLOT(CircleCRT()));

    QObject::connect(EllipseAction, SIGNAL(triggered()), this, SLOT(Ellipse_()));
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
    PolygonMenu->addAction(RegularPolygonAction);
    PolygonMenu->addAction(PolygonAction);
    PolygonMenu->addAction(SquareAction);
    PolygonMenu->addAction(RectangleAction);

    TriangleFunctionsMenu = new QMenu;
    TriangleFunctionsMenu->addAction(TriangleAction);
    TriangleFunctionsMenu->addAction(InscribedCircleAction);
    TriangleFunctionsMenu->addAction(CircumscribedCricleAction);
    TriangleFunctionsMenu->addAction(OrthoCenterAction);
    TriangleFunctionsMenu->addAction(CenterOfGravityAction);

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

    TriangleFunctionsButton = new DropDownToolButton;
    TriangleFunctionsButton->setMenu(TriangleFunctionsMenu);
    TriangleFunctionsButton->setDefaultAction(TriangleAction);
    TriangleFunctionsButton->setMinimumHeight(32);
    TriangleFunctionsButton->setMinimumWidth(44);
    TriangleFunctionsButton->setIconSize(QSize(32,32));

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

    PushButton2 = new QPushButton("Debug");
    PushButton2->setMinimumWidth(32);
    PushButton2->setMinimumHeight(39);
    QObject::connect(PushButton2, SIGNAL(clicked()), this, SLOT(PushButton3_clicked()));
}

void MainWindow::createToolBars(){
    // ui->horizontalLayout_2->addWidget(PushButton);
    ui->horizontalLayout_2->addWidget(MouseButton);
    ui->horizontalLayout_2->addWidget(PointButton);
    ui->horizontalLayout_2->addWidget(LineButton);
    ui->horizontalLayout_2->addWidget(SpecialLineButton);
    ui->horizontalLayout_2->addWidget(PolygonButton);
    ui->horizontalLayout_2->addWidget(TriangleFunctionsButton);
    ui->horizontalLayout_2->addWidget(CircleButton);
    ui->horizontalLayout_2->addWidget(ConicButton);
    ui->horizontalLayout_2->addWidget(MeasurementButton);
    ui->horizontalLayout_2->addWidget(TransformationButton);
    ui->horizontalLayout_2->addWidget(GeneralButton);
    ui->horizontalLayout_2->addWidget(PushButton2);
    ui->horizontalLayout_2->addStretch();
}

void MainWindow::createGrid()
{
    scene->clear();
    setStarted();
    ItemsDisplay();

    QObject::connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(LineEditReturn()));
    QShortcut* shortcut = new QShortcut(QKeySequence(Qt::Key_Delete), ui->listWidget);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(DeleteItem()));
    QShortcut* shortcut2 = new QShortcut(QKeySequence(Qt::Key_Backspace), ui->listWidget);
    QObject::connect(shortcut2, SIGNAL(activated()), this, SLOT(DeleteItem()));
}

void MainWindow::setStarted()
{
    Grid* g = new Grid(50,this->getHeight_View()-50,35);
    this->setGrid(g);

    ui->graphicsView->refresh_indicators();
    ui->graphicsView->move_grid_chosen=true;

    this->mainGrid->draw();
    this->mainGrid->set_BackColor(QBrush(Qt::white, Qt::SolidPattern));
    this->mainGrid->set_xaxis_label();
    this->mainGrid->set_yaxis_label();
}

void MainWindow::ItemsDisplay()
{
    ui->listWidget->clear();

    unsigned size = mainGrid->obj.points.size();
    Point* curr = 0;
    for (unsigned i = 0; i < size; i++)
    {
        curr = mainGrid->obj.points[i];
        if (curr != NULL)
        {
            QString text = tr("Point:  (%1,%2)").arg(curr->getxg()).arg(curr->getyg());
            QListWidgetItem *item = new QListWidgetItem(text,ui->listWidget);
            item->setData(Qt::UserRole,i);
        }
    }

    if (size > 0)
    {
        QString text = "";
        QListWidgetItem *item = new QListWidgetItem(text,ui->listWidget);
    }

    unsigned size2 = mainGrid->obj.lines.size();
    Line* curr2 = 0;
    for (unsigned i = 0 ; i < size2; i++)
    {
        curr2 = mainGrid->obj.lines[i];
        if (curr2 != NULL)
        {
            QString text;
            if (curr2->y_intercept_g() >= 0)
            {
                text = tr("Line:  y = %1 x + %2").arg(curr2->slope_g()).arg(curr2->y_intercept_g());
            }
            else
            {
                text = tr("Line:  y = %1 x - %2").arg(curr2->slope_g()).arg(abs(curr2->y_intercept_g()));
            }
            QListWidgetItem *item = new QListWidgetItem(text,ui->listWidget);
            item->setData(Qt::UserRole,i);
        }
    }

    if (size2 > 0)
    {
        QString text2 = "";
        QListWidgetItem *item2 = new QListWidgetItem(text2,ui->listWidget);
    }

    unsigned size3 = mainGrid->obj.segments.size();
    Segment* curr3 = 0;
    for (unsigned i = 0 ; i < size3; i++)
    {
        curr3 = mainGrid->obj.segments[i];
        if (curr3 != NULL)
        {
            QString text = tr("Segment:  (%1,%2) \n                     (%3,%4)").arg(curr3->p1.getxg()).arg(curr3->p1.getyg()).arg(curr3->p2.getxg()).arg(curr3->p2.getyg());
            QListWidgetItem *item = new QListWidgetItem(text,ui->listWidget);
            item->setData(Qt::UserRole,i);
        }
    }

    if (size3 > 0)
    {
        QString text3 = "";
        QListWidgetItem *item3 = new QListWidgetItem(text3,ui->listWidget);
    }

    unsigned size4 = mainGrid->obj.circles.size();
    Circle* curr4 = 0;
    for (unsigned i = 0 ; i < size4; i++)
    {
        curr4 = mainGrid->obj.circles[i];
        if (curr4 != NULL)
        {
            QString text = tr("Circle:  center = (%1,%2) \n              radius = %3").arg(curr4->center.getxg()).arg(curr4->center.getyg()).arg(curr4->r_t);
            QListWidgetItem *item = new QListWidgetItem(text,ui->listWidget);
            item->setData(Qt::UserRole,i);
        }
    }

    if (size4 > 0)
    {
        QString text4 = "";
        QListWidgetItem *item4 = new QListWidgetItem(text4,ui->listWidget);
    }

    unsigned size5 = mainGrid->obj.triangles.size();
    Triangle* curr5 = 0;
    for (unsigned i = 0 ; i < size5; i++)
    {
        curr5 = mainGrid->obj.triangles[i];
        if (curr5 != NULL)
        {
            QString text = tr("Triangle:  (%1,%2) \n                   (%3,%4) \n                   (%5,%6)").arg(curr5->point1.getxg()).arg(curr5->point1.getyg()).arg(curr5->point2.getxg()).arg(curr5->point2.getyg()).arg(curr5->point3.getxg()).arg(curr5->point3.getyg());
            QListWidgetItem *item = new QListWidgetItem(text,ui->listWidget);
            item->setData(Qt::UserRole,i);
        }
    }

    if (size5 > 0)
    {
        QString text5 = "";
        QListWidgetItem *item5 = new QListWidgetItem(text5,ui->listWidget);
    }

    unsigned size6 = mainGrid->obj.functions.size();
    Functions* curr6 = 0;
    for (unsigned i = 0 ; i < size6; i++)
    {
        curr6 = mainGrid->obj.functions[i];
        if (curr6 != NULL)
        {
            QString function = QString::fromStdString(curr6->expression);
            QString text = tr("Function:  %1").arg(function);
            QListWidgetItem *item = new QListWidgetItem(text,ui->listWidget);
            item->setData(Qt::UserRole,i);
        }
    }
}

void MainWindow::LineEditReturn()
{
    QString input_tmp = ui->lineEdit->text();
    std::string input = input_tmp.toUtf8().constData();
    std::cout << input.substr(0,5) << std::endl;
    if (input.substr(0,5) == "Point")
    {
        int first_parenthesis = input.find("(");
        int comma = input.find(",", first_parenthesis+1);
        int second_parenthesis = input.find(")", comma+1);
        double x_g = std::stod(input.substr(first_parenthesis+1,comma));
        double y_g = std::stod(input.substr(comma+1,second_parenthesis));
        std::cout << x_g << y_g << std::endl;
    }
    else
    {
        Functions *f = new Functions(input);
        f->draw();
        mainGrid->obj.push(f);
        ItemsDisplay();
        ui->lineEdit->clear();
    }
}

void MainWindow::DeleteItem()
{
    QString item = ui->listWidget->currentItem()->text();
    int number = ui->listWidget->currentItem()->data(Qt::UserRole).toInt();
    if (item[0] == "P")
    {
        ui->graphicsView->chosen_objects.push(mainGrid->obj.points[number]);
        mainGrid->obj.points[number]->selected = true;
        Delete();
    }
    if (item[0] == "L")
    {
        ui->graphicsView->chosen_objects.push(mainGrid->obj.lines[number]);
        mainGrid->obj.lines[number]->selected = true;
        Delete();
    }
    if (item[0] == "S")
    {
        ui->graphicsView->chosen_objects.push(mainGrid->obj.segments[number]);
        mainGrid->obj.segments[number]->selected = true;
        Delete();
    }
    if (item[0] == "C")
    {
        ui->graphicsView->chosen_objects.push(mainGrid->obj.circles[number]);
        mainGrid->obj.circles[number]->selected = true;
        Delete();
    }
    if (item[0] == "T")
    {
        ui->graphicsView->chosen_objects.push(mainGrid->obj.triangles[number]);
        mainGrid->obj.triangles[number]->selected = true;
        Delete();
    }
    if (item[0] == "F")
    {
        ui->graphicsView->chosen_objects.push(mainGrid->obj.functions[number]);
        mainGrid->obj.functions[number]->selected = true;
        Delete();
    }
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    // qDebug() << event->size();
    QMainWindow::resizeEvent(event);
    this->mainGrid->move_grid(50-mainGrid->getX(),this->getHeight_View()-50-mainGrid->getY());
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

void MainWindow::drawInfiniteLine(QPointF p1, QPointF p2) // in ViewCoordinates
{
    // construct y = k*x + n
    double slope = 0;
    double term = 0;
    if (p1.x()!=p2.x()){
        slope = (p1.y()-p2.y())/(p1.x()-p2.x()); // k
        term = (p1.y() - slope * p1.x()); // n
    }

    // now, we create two points on the edges of the form
    // WE ARE ASSUMING SLOPE != 0

    int y0 = 0; // at this y-coordinate is the first point
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

void MainWindow::drawPolygon(std::vector<QPointF> points)
{
    int n = points.size();
    for(int i=0;i<n-1;i++)
    {
        MainWindow::drawLine(points[i],points[i+1]);
    }
    MainWindow::drawLine(points[0],points[n-1]);
}

void MainWindow::drawEllipse(Point p, double rx, double ry)
{
    QPointF f = mapToMyScene(p.getx(),p.gety());
    scene->addEllipse(f.x(),f.y(),2*rx,2*ry,myPen);
}

void MainWindow::drawText(QString text, double x, double y)
{
    QGraphicsSimpleTextItem* text1=scene->addSimpleText(text);
    text1->setPos(mapToMyScene(x,y));
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
    QPointF p =mapFromGridToView(x,y);
    return mapToMyScene(p.x(),p.y());
}

QPointF MainWindow::mapFromSceneToGrid(double x, double y)
{
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
    double x_g =(x - mainGrid-> getX())/ mainGrid->unit;
    double y_g = (mainGrid-> getY()-y)/ mainGrid->unit;

    return QPointF(x_g,y_g);
}

QPointF MainWindow::mapFromGridToView(double x, double y)
{
    double x_v = (x*mainGrid->unit + mainGrid-> getX());
    double y_v = (-y*mainGrid->unit + mainGrid-> getY());
    return QPointF(x_v,y_v);
}

MainWindow *MainWindow::theWindow = nullptr; // declare static

void MainWindow::Move()
{
    ui->graphicsView->refresh_indicators();
    ui->graphicsView->chosen_objects.empty_bins();
    ui->graphicsView-> move_grid_chosen = true;
    mainGrid->obj.deselect();
    mainGrid->refresh_grid();
}

void MainWindow::Select()
{
    ui->graphicsView->refresh_indicators();
    ui->graphicsView->select_object_chosen = true;
    ui->graphicsView->move_grid_chosen = true;
}

void MainWindow::Point_()
{
    ui->graphicsView->refresh_indicators();
    ui->graphicsView->point_chosen = true;
}

void MainWindow::PointOnObject(){
    qDebug() << "MainWindow::PointOnObject()";
}

void MainWindow::Intersection()
{
    //We have intersections only between segments,lines and circles, so, it's not a big problem
    std::vector<Point*> vec;
    vec = ui->graphicsView->chosen_objects.IntersectObjects();
    for(uint i=0;i<vec.size();i++)
    {
        mainGrid->obj.push(vec[i]);
    }
    mainGrid->obj.deselect();
    mainGrid->refresh_grid();
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

void MainWindow::Line_()
{
    if(ui->graphicsView->chosen_objects.size()==2 && ui->graphicsView->chosen_objects.points.size()==2)
    {
        Point* p1 = new Point(ui->graphicsView->chosen_objects.points[0]->getx(),ui->graphicsView->chosen_objects.points[0]->gety());
        Point* p2 = new Point(ui->graphicsView->chosen_objects.points[1]->getx(),ui->graphicsView->chosen_objects.points[1]->gety());
        Line* s = new Line(*p1,*p2);
        mainGrid->obj.push(s);
        ui->graphicsView->chosen_objects.empty_bins();
        ui->graphicsView->refresh_indicators();
        ui->graphicsView->move_grid_chosen = true;
        mainGrid->obj.deselect();
        mainGrid->refresh_grid();
    }
    else
    {
        ui->graphicsView->refresh_indicators();
        ui->graphicsView->inf_line_chosen = true;
    }
    ItemsDisplay();
}

void MainWindow::Segment_()
{
    if(ui->graphicsView->chosen_objects.size()==2 && ui->graphicsView->chosen_objects.points.size()==2)
    {
        Point* p1 = new Point(ui->graphicsView->chosen_objects.points[0]->getx(),ui->graphicsView->chosen_objects.points[0]->gety());
        Point* p2 = new Point(ui->graphicsView->chosen_objects.points[1]->getx(),ui->graphicsView->chosen_objects.points[1]->gety());
        Segment* s = new Segment(*p1,*p2);
        mainGrid->obj.push(s);
        ui->graphicsView->chosen_objects.empty_bins();
        ui->graphicsView->refresh_indicators();
        ui->graphicsView->move_grid_chosen = true;
        mainGrid->obj.deselect();
        mainGrid->refresh_grid();
    }
    else
    {
        ui->graphicsView->refresh_indicators();
        ui->graphicsView->segment_chosen = true;
    }
    ItemsDisplay();
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

void MainWindow::PerpendicularLine()
{
    if(ui->graphicsView->chosen_objects.lines.size()==1 && ui->graphicsView->chosen_objects.points.size()==1)
    {
        Line l = ui->graphicsView->chosen_objects.lines[0]->perpendicular( *ui->graphicsView->chosen_objects.points[0]);
        ui->graphicsView->chosen_objects.empty_bins();
        ui->graphicsView->refresh_indicators();
        ui->graphicsView->move_grid_chosen = true;
        mainGrid->obj.push(new Line(l.p1,l.p2));
        mainGrid->obj.push(new Point(l.p1.getx(),l.p1.gety()));
        mainGrid->obj.deselect();
        mainGrid->refresh_grid();
    }
    ItemsDisplay();
}

void MainWindow::ParallelLine(){
    if(ui->graphicsView->chosen_objects.lines.size()==1 && ui->graphicsView->chosen_objects.points.size()==1)
    {
        Line l = ui->graphicsView->chosen_objects.lines[0]->parallel(*ui->graphicsView->chosen_objects.points[0]);
        ui->graphicsView->chosen_objects.empty_bins();
        ui->graphicsView->refresh_indicators();
        ui->graphicsView->move_grid_chosen = true;
        mainGrid->obj.push(new Line(l.p1,l.p2));
        mainGrid->obj.push(new Point(l.p1.getx(),l.p1.gety()));
        mainGrid->obj.deselect();
        mainGrid->refresh_grid();
    }
    ItemsDisplay();
}

void MainWindow::PerpendicularBisector(){
    if(ui->graphicsView->chosen_objects.segments.size()==1)
    {
        Line l = ui->graphicsView->chosen_objects.segments[0]->mediator();
        ui->graphicsView->chosen_objects.empty_bins();
        ui->graphicsView->refresh_indicators();
        ui->graphicsView->move_grid_chosen = true;
        mainGrid->obj.push(new Line(l.p1,l.p2));
        mainGrid->obj.push(new Point(l.p1.getx(),l.p1.gety()));
        mainGrid->obj.push(new Point(l.p2.getx(),l.p2.gety()));
        mainGrid->obj.deselect();
        mainGrid->refresh_grid();
    }
    ItemsDisplay();
}

void MainWindow::AngleBisector(){
    qDebug() << "MainWindow::AngleBisector()";
}

void MainWindow::Tangent(){
    if(ui->graphicsView->chosen_objects.circles.size()==1 && ui->graphicsView->chosen_objects.points.size()==1)
    {
        std::vector<Line> l = ui->graphicsView->chosen_objects.circles[0]->tangent(*ui->graphicsView->chosen_objects.points[0]);
        ui->graphicsView->chosen_objects.empty_bins();
        ui->graphicsView->refresh_indicators();
        ui->graphicsView->move_grid_chosen = true;
        for(uint i=0;i<l.size();i++)
        {
            mainGrid->obj.push(new Line(l[i].p1,l[i].p2));
            mainGrid->obj.push(new Point(l[i].p1.getx(),l[i].p1.gety()));
        }
        mainGrid->obj.deselect();
        mainGrid->refresh_grid();
    }
    else if(ui->graphicsView->chosen_objects.ellipses.size()==1 && ui->graphicsView->chosen_objects.points.size()==1)
    {
        std::vector<Line> l = ui->graphicsView->chosen_objects.ellipses[0]->tangent(*ui->graphicsView->chosen_objects.points[0]);
        ui->graphicsView->chosen_objects.empty_bins();
        ui->graphicsView->refresh_indicators();
        ui->graphicsView->move_grid_chosen = true;
        for(uint i=0;i<l.size();i++)
        {
            mainGrid->obj.push(new Line(l[i].p1,l[i].p2));
            std::vector<Point*> v = intersection(*ui->graphicsView->chosen_objects.ellipses[0],l[i]);
            mainGrid->obj.push(new Point(v[0]->getx(),v[0]->gety()));
        }
        mainGrid->obj.deselect();
        mainGrid->refresh_grid();
    }
    ItemsDisplay();
}

void MainWindow::Triangle_()
{
    if(ui->graphicsView->chosen_objects.size()==3 && ui->graphicsView->chosen_objects.points.size()==3)
    {
        Point* p1 = new Point(ui->graphicsView->chosen_objects.points[0]->getx(),ui->graphicsView->chosen_objects.points[0]->gety());
        Point* p2 = new Point(ui->graphicsView->chosen_objects.points[1]->getx(),ui->graphicsView->chosen_objects.points[1]->gety());
        Point* p3 = new Point(ui->graphicsView->chosen_objects.points[2]->getx(),ui->graphicsView->chosen_objects.points[2]->gety());
        Triangle* s = new Triangle(*p1,*p2,*p3);
        mainGrid->obj.push(s);
        ui->graphicsView->chosen_objects.empty_bins();
        ui->graphicsView->refresh_indicators();
        ui->graphicsView->move_grid_chosen = true;
        mainGrid->obj.deselect();
        mainGrid->refresh_grid();
    }
    else
    {
        ui->graphicsView->refresh_indicators();
        ui->graphicsView->polygon_chosen = true;
        ui->graphicsView->n_polygon = 3;
    }
    ItemsDisplay();
}

void MainWindow::Square(){
    ui->graphicsView->refresh_indicators();
    ui->graphicsView->polygon_chosen = true;
    ui->graphicsView->n_polygon = 4;
}

void MainWindow::Rectangle()
{
    qDebug() << "MainWindow::Rectangle()";
}

void MainWindow::RegularPolygon(){
    qDebug() << "MainWindow::RegularPolygon()";
}

void MainWindow::Polygon(){
    qDebug() <<"MainWindow::Polygon()";
}

void MainWindow::CircleCPT()
{
    if(ui->graphicsView->chosen_objects.size()==2 && ui->graphicsView->chosen_objects.points.size()==2)
    {
        Point* p1 = new Point(ui->graphicsView->chosen_objects.points[0]->getx(),ui->graphicsView->chosen_objects.points[0]->gety());
        Point* p2 = new Point(ui->graphicsView->chosen_objects.points[1]->getx(),ui->graphicsView->chosen_objects.points[1]->gety());
        Circle* s = new Circle(*p1,*p2);
        mainGrid->obj.push(s);
        ui->graphicsView->chosen_objects.empty_bins();
        ui->graphicsView->refresh_indicators();
        ui->graphicsView->move_grid_chosen = true;
        mainGrid->obj.deselect();
        mainGrid->refresh_grid();
    }
    else
    {
        ui->graphicsView->circle_chosen = true;
    }
    ItemsDisplay();
}

void MainWindow::CircleCRT()
{
    ui->graphicsView->circle_chosen_with_radius = true;
}

void MainWindow::Ellipse_()
{
     ui->graphicsView->ellipse_chosen = true;
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

void MainWindow::LineSymmetry()
{
    if(ui->graphicsView->chosen_objects.lines.size()==1 && ui->graphicsView->chosen_objects.points.size()==1)
    {
        std::vector<Point> l = ui->graphicsView->chosen_objects.lines[0]->reflection(*ui->graphicsView->chosen_objects.points[0]);
        ui->graphicsView->chosen_objects.empty_bins();
        ui->graphicsView->refresh_indicators();
        ui->graphicsView->move_grid_chosen = true;
        for(uint i=0;i<l.size();i++)
        {
            mainGrid->obj.push(new Point(l[i].getx(),l[i].gety()));
        }
        mainGrid->obj.deselect();
        mainGrid->refresh_grid();
    }
    ItemsDisplay();
}

void MainWindow::PointSymmetry()
{
    if(ui->graphicsView->chosen_objects.points.size()==2)
    {
        Point p = ui->graphicsView->chosen_objects.points[0]->symmetry_point(*ui->graphicsView->chosen_objects.points[1]);
        ui->graphicsView->chosen_objects.empty_bins();
        ui->graphicsView->refresh_indicators();
        ui->graphicsView->move_grid_chosen = true;
        mainGrid->obj.push(new Point(p.getx(),p.gety()));
        mainGrid->obj.deselect();
        mainGrid->refresh_grid();
    }
    ItemsDisplay();
}

void MainWindow::Translate()
{
    qDebug() << "MainWindow::Translate()";
}

void MainWindow::InscribedCircle()
{
    qDebug() << "MainWindow::InscribedCircle()";
}

void MainWindow::CircumscribedCricle()
{
    qDebug() << "MainWindow::CircumscribedCircle()";
}

void MainWindow::OrthoCenter()
{
    qDebug() << "MainWindow::OrthoCenter()";
}

void MainWindow::CenterOfGravity()
{
    qDebug() << "MainWindow::CenterOfGravity()";
}

void MainWindow::Delete()
{
    mainGrid->obj.cleanFrom(ui->graphicsView->chosen_objects);
    mainGrid->refresh_grid();
    ItemsDisplay();
}

void MainWindow::Clear(){
    mainGrid->obj.empty_bins();
    scene->clear();
    mainGrid->draw();
    mainGrid->set_BackColor(QBrush(Qt::white, Qt::SolidPattern));
    mainGrid->set_xaxis_label();
    mainGrid->set_yaxis_label();
    ItemsDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
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
    delete RegularPolygonAction;
    delete PolygonAction;
    delete SquareAction;
    delete RectangleAction;
    delete PolygonMenu;
    delete PolygonButton;
    delete TriangleAction;
    delete InscribedCircleAction;
    delete CircumscribedCricleAction;
    delete OrthoCenterAction;
    delete CenterOfGravityAction;
    delete TriangleFunctionsMenu;
    delete TriangleFunctionsButton;
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
    delete PushButton2;
}

void MainWindow::PushButton3_clicked()
{
    //drawEllipse(QPointF(150,100),100,50);
    Point* p1 = new Point(150.0,100.0);
    Point* p2 = new Point(200.0,100.0);
    Ellipse* e = new Ellipse(p1,p2,100.0);
    Point p = Point(0,0);
    std::vector<Line> v = e->tangent(p);
    v[0].draw();
    v[1].draw();
    e->draw();
    mainGrid->obj.push(e);
    //mainGrid->refresh_grid();
}
