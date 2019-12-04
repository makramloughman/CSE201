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
}

void MainWindow::createMenus(){
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
}

void MainWindow::createToolButtons(){
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
}

void MainWindow::createToolBars(){
    ui->horizontalLayout_2->addWidget(PointButton);
    ui->horizontalLayout_2->addWidget(LineButton);
    ui->horizontalLayout_2->addStretch();
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

MainWindow::~MainWindow()
{
    delete ui;
}
