#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    theWindow = this; //for static variable

    ui->setupUi(this); //setting up
    scene = new QGraphicsScene(this); ///seting up the scene

       ui->graphicsView->setScene(scene);
       ui->graphicsView->setRenderHint(QPainter::Antialiasing);
       scene->setSceneRect(0, 0, 300, 300);
       //ellipse = scene->addEllipse(0, -100, 300, 60);
       //ellipse->setFlag(QGraphicsItem::ItemIsMovable);

}

void MainWindow::drawLine(QLineF l)
{
    QPen myPen = QPen();
    myPen.setWidth(1.5);
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
                      QPen(Qt::blue), QBrush(Qt::SolidPattern));
}

void MainWindow::drawCircle(QPointF p, double r)
{
    QPen myPen = QPen();
    myPen.setWidth(1.5);
    scene->addEllipse(p.x()-r, p.y()-r, r*2.0, r*2.0,
                      myPen);
}

void MainWindow::drawInfiniteLine(QPointF p1, QPointF p2)
{
    //construct y = k*x + n
    double slope = (p1.y()-p2.y())/(p1.x()-p2.x()); //k
    double term = (p1.y() - slope * p1.x()); //n

    //now, we create two points on the edges of the form
    //WE ARE ASSUMING SLOPE!=0

    int y0 = 0; //at this y-coordinate is the first point
    int y1 = ui->graphicsView->height();
    QPointF p11 = ui->graphicsView->mapToScene((y0 - term)/slope, y0);
    QPointF p21 = ui->graphicsView->mapToScene((y1 - term)/slope, y1);

    MainWindow::drawLine(p11,p21);
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


void MainWindow::drawCoordinateSystem(Grid g)
{

    double x = g.getX();
    double y = g.getY();

    double w = ui->graphicsView->width();
    double h = ui->graphicsView->height();

    QPointF x1 = QPointF(ui->graphicsView->mapToScene(-1000, y));
    QPointF x2 = QPointF(ui->graphicsView->mapToScene(1000+w, y));
    QPointF y1 = QPointF(ui->graphicsView->mapToScene(x, -1000));
    QPointF y2 = QPointF(ui->graphicsView->mapToScene(x, 1000+h));

    QPen myPen = QPen(Qt::gray);
    myPen.setWidth(3);
    MainWindow::drawLine(x1,x2,myPen);
    MainWindow::drawLine(y1,y2,myPen);
}

MainWindow* MainWindow:: getInstance()
{
    return theWindow;
}

void MainWindow::drawScene()
{
    scene->addRect(scene->sceneRect());
}
void MainWindow::clearScene()
{
    scene->clear();
}

MainWindow *MainWindow::theWindow = nullptr;

MainWindow::~MainWindow()
{
    theWindow = nullptr;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->segment_chosen = true;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->circle_chosen = true;
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->graphicsView->inf_line_chosen = true;
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->graphicsView->point_chosen = true;
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->graphicsView->polygon_chosen = true;
    ui->graphicsView->n_polygon = 4;
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->graphicsView->polygon_chosen = true;
    ui->graphicsView->n_polygon = 3;
}

