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
    PointInRegionAction = new QAction("Point in region", this);
    IntersectAction = new QAction("Intersect", this);
    MidPointAction = new QAction("Midpoint", this);

    PointAction->setIcon(QIcon(":/images/GeoGebra_button_point.png"));
    PointInRegionAction->setIcon(QIcon(":/images/GeoGebra_button_point_in_region.png"));
    IntersectAction->setIcon(QIcon(":/images/GeoGebra_button_intersect.png"));
    MidPointAction->setIcon(QIcon(":/images/GeoGebra_button_midpoint.png"));

    QObject::connect(PointAction, SIGNAL(triggered()), this, SLOT(Point()));
    QObject::connect(PointInRegionAction, SIGNAL(triggered()), this, SLOT(PointInRegion()));
    QObject::connect(IntersectAction, SIGNAL(triggered()), this, SLOT(Intersection()));
    QObject::connect(MidPointAction, SIGNAL(triggered()), this, SLOT(MidPoint()));
}

void MainWindow::createMenus(){
    PointMenu = new QMenu;
    PointMenu->addAction(PointAction);
    PointMenu->addAction(PointInRegionAction);
    PointMenu->addAction(IntersectAction);
    PointMenu->addAction(MidPointAction);
}

void MainWindow::createToolButtons(){
    PointButton = new DropDownToolButton;
    PointButton->setMenu(PointMenu);
    PointButton->setDefaultAction(PointAction);
}

void MainWindow::createToolBars(){
    ui->horizontalLayout_2->addWidget(PointButton);
}

void MainWindow::Point(){
    qDebug() << "MainWindow::Point()";
}

void MainWindow::PointInRegion(){
    qDebug() << "MainWindow::alignCenter()";
}

void MainWindow::Intersection(){
    qDebug() << "MainWindow::Intersection()";
}

void MainWindow::MidPoint(){
    qDebug() << "MainWindow::MidPoint()";
}

MainWindow::~MainWindow()
{
    delete ui;
}
