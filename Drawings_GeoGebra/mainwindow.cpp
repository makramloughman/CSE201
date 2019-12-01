#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    theWindow = this; //for static variable

    ui->setupUi(this); //setting up
    scene = new QGraphicsScene(this); ///seting up the scene

       ui->graphicsView->setScene(scene);

       // anti-aliasing
       ui->graphicsView->setRenderHint(QPainter::Antialiasing);

       // The bounding rectangle of the scene
       // The scene rectangle defines the extent of the scene.
       // It is primarily used by QGraphicsView
       // to determine the view's default scrollable area,
       // and by QGraphicsScene to manage item indexing.

       scene->setSceneRect(0, 0, 100, 100);

       QLineF topLine(scene->sceneRect().topLeft(),
                      scene->sceneRect().topRight());
       QLineF leftLine(scene->sceneRect().topLeft(),
                      scene->sceneRect().bottomLeft());
       QLineF rightLine(scene->sceneRect().topRight(),
                      scene->sceneRect().bottomRight());
       QLineF bottomLine(scene->sceneRect().bottomLeft(),
                      scene->sceneRect().bottomRight());

       QPen myPen = QPen(Qt::red);

       scene->addLine(topLine, myPen);
       scene->addLine(leftLine, myPen);
       scene->addLine(rightLine, myPen);
       scene->addLine(bottomLine, myPen);
       //ellipse = scene->addEllipse(0, -100, 300, 60);
       //ellipse->setFlag(QGraphicsItem::ItemIsMovable);

}

void MainWindow::drawLine(QLineF l)
{
    QPen myPen = QPen(Qt::red);
    scene->addLine(l, myPen);

}

MainWindow* MainWindow:: getInstance()
{
    return theWindow;
}

MainWindow *MainWindow::theWindow = nullptr;

MainWindow::~MainWindow()
{
    theWindow = nullptr;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QLineF topLine(scene->sceneRect().topLeft(),
                   scene->sceneRect().topRight());
    drawLine(topLine);
}
