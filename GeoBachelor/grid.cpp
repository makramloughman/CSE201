#include "grid.h"
#include "mainwindow.h"
#include <QResizeEvent>
#include <QWidget>
#include <QDebug>

Grid::Grid(double x, double y)
{
    this->x_p = x;
    this->y_p = y;
    this->unit = 50;
}

Grid::Grid(double x, double y, double unit)
{
    this->x_p = x;
    this->y_p = y;
    this->unit = unit;
}

Grid::Grid()
{
    this->x_p = 0;
    this->y_p = 0;
}

void Grid::draw()
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    QPen myPen1 = QPen(Qt::lightGray);
    myPen1.setWidth(0.5);

    double w = mainW->getWidth_View();
    double h = mainW->getHeight_View();

    // Add the vertical lines first
    for (int x=x_p+unit; x<=mainW->getWidth_View()+unit; x+=unit)
    {
        QPointF p1 = QPointF(mainW -> mapToMyScene(x,0));
        QPointF p2 = QPointF(mainW -> mapToMyScene(x,h));
        mainW->drawLine(p1,p2,myPen1);
    }

    // Add the vertical lines first (for x<x_p)

    for (double x = x_p-unit; x >= -1*unit ; x-=unit)
    {
        QPointF p1 = QPointF(mainW -> mapToMyScene(x,0));
        QPointF p2 = QPointF(mainW -> mapToMyScene(x,h));
        mainW->drawLine(p1,p2,myPen1);
    }

    // Now add the horizontal lines for y>=y_p
    for (double y = y_p; y< h + unit; y+=unit)
    {
        QPointF p1= QPointF(mainW -> mapToMyScene(0,y));
        QPointF p2= QPointF(mainW -> mapToMyScene(mainW->getWidth_View()+50,y));
        mainW->drawLine(p1,p2,myPen1);
    }

    // Now add the horizontal lines for y<y_p
    for (double y = y_p-unit; y>= -1*unit; y-=unit)
    {
        QPointF p1= QPointF(mainW -> mapToMyScene(0,y));
        QPointF p2= QPointF(mainW -> mapToMyScene(w,y));
        mainW->drawLine(p1,p2,myPen1);
    }

    double x = this->getX();
    double y = this->getY();

    QPointF x1 = QPointF(mainW->mapToMyScene(std::min(0.0,x_p), y));
    QPointF x2 = QPointF(mainW->mapToMyScene(std::max(w,x_p), y));
    QPointF y1 = QPointF(mainW->mapToMyScene(x, std::min(y_p,0.0)));
    QPointF y2 = QPointF(mainW->mapToMyScene(x, std::max(h,y_p)));

    QPen myPen = QPen(Qt::gray);
    myPen.setWidth(3);
    mainW->drawLine(x1,x2,myPen);
    mainW->drawLine(y1,y2,myPen);
}

double Grid::getX()
{
    return this->x_p;
}

double Grid::getY()
{
    return this->y_p;
}

void Grid::set_BackColor(QBrush b)
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    mainW -> setBackGroundColor_View(b);
}


void Grid::set_xaxis_label()
{
    MainWindow* mainW = MainWindow::getInstance();

    double w = mainW->getWidth_View();
    QPointF f = mainW->mapToMyScene(w-50,getY()+10);
    QGraphicsTextItem* text=mainW->scene->addText("X");
    text->setPos(f.x(), f.y());
 }

void Grid::set_yaxis_label(){
    MainWindow* mainW = MainWindow::getInstance();
    QPointF f = mainW->mapToMyScene(getX()-30,10);
    QGraphicsTextItem* text=mainW->scene->addText("Y");
    text->setPos(f.x(), f.y());
}

void Grid::move_grid(double dx, double dy){
    MainWindow* mainW = MainWindow::getInstance();
    this-> x_p+=dx;
    this -> y_p+=dy;
    mainW->clearScene();
    draw();
    set_xaxis_label();
    set_yaxis_label();
    obj.move_refresh(dx,dy);
}

void Grid::move_grid(QPointF to)
{
    move_grid(to.x()-x_p,to.y()-y_p);
}

void Grid::refresh_grid()
{
    move_grid(0,0);
}

void Grid::zoom(double coef)
{
    this->unit = this->unit*coef;
}

/*

    t=QTransform();
    //the color of the font should be initialized to white

    void Grid::initialize_fontcolor()
    {
        ui->myGraphicsView->setScene(myScene);
        ui->myGraphicsView->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
        //->replot
    }
    // the argument represent the norm of the unit vector
    //maximum value for x

}

    void Grid::draw()
{
   MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have

    double x = this->getX();
    double y = this->getY();

    double w = mainW->getWidth_View();
    double h = mainW->getHeight_View();

    QPointF x1 = QPointF(mainW->mapToMyScene(-1000, y));
    QPointF x2 = QPointF(mainW->mapToMyScene(1000+w, y));
    QPointF y1 = QPointF(mainW->mapToMyScene(x, -1000));
    QPointF y2 = QPointF(mainW->mapToMyScene(x, 1000+h));

    QPen myPen = QPen(Qt::gray);
    myPen.setWidth(3);
    mainW->drawLine(x1,x2,myPen);
    mainW->drawLine(y1,y2,myPen);
}

void Grid::set_yaxis_label(){
    QGraphicsTextItem *text = scene->addText();
    text->setPos(x_p-50, 50);
}
void Grid::set_xaxis_label(){
    double w = ui->graphicsView->width();
    double h = ui->graphicsView->height();
    text->setPos(width-50, y_p+50);

public:

    // translate the center or translate the whole coordinate system so that
    //a specified point become the center

void Grid::Draw_grid(){
    // Add the vertical lines first
    for (int x=0; x<=1100; x+=50)
        Qpoint p1(x,0);
        Qpoint p2(x,1100);
    mainW->drawInfiniteLine(p1,p2)

    // Now add the horizontal lines,
    for (int y=0; y<=500; y+=50)
        Qpoint p1(0,y);
        Qpoint p2(1100,y);
        mainW->drawInfiniteLine(p1,p2)

    // Fit the view in the scene's bounding rect
    ui->view->fitInView(scene->itemsVBoundingRect());









    void translate(int percentage);
    void change_center_view();

    //user should be able to hide and show coordinate axis
    //WE NEED TO DEFINE PUBLIC ATTRIBUTES QGRAPHICSITEM_X QGRAPHICSITEM_Y in the main window
    void hide_x_axis();
    void show_x_axis();
    void hide_y_axis();
    void show_y_axis();

    //allows the user the rotate the coordinate system
    void Grid::right_rotation(double angle_of_rotation)
    {


    void left_rotation(double angle_of_rotation);

    //zoom on a specific zome of the grid
    //we still need to see how to define the achpr where we click
    void Grid::zoom_in(int percentage)
    {
        t.scale(int percentage,int percentage);
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        view->setTransform(t);
    }
    void Grid::zoom_out(int percentage)
    {
        t.scale(int -percentage,int -percentage);
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        view->setTransform(t);

    }



    //the user should be able to rescale the axis
    //user should also be able to rename the axis
    void rescale_axis(double new_scale);
    void rename_axis();

    //the user should be able to write a legend for the figures he draws
    void legend_box();

    //checkbox tool is to hide several objects
    void checkboxtool();
    //user should able to lable everything on his fugures and modify them
    void create_labels();
    void modify_labels();
    void delete_labels();

    //(advanced fuction) we should have the visibility status of some chosen objects depend
    //on certain conditions fixed by the user
    void conditional_visibility();
    void hide_object();
    void reshow_object();

    //user should be able to change the opacity of objects
    void opacity();

    //create layers in order to determine which object to select when users clicks on
    //multiple objects at the same time
    void create_layers();
    void hide_layer(int layer_number);
    void show_layer(int layer_number);
    //create helpers so that when thw users puts the mouse on a toolbox
    //a small text box appears describing breifly the funtion of the toolbox
    void tips():]

    //user should be able to take a snapshot of the grid
    void snapshot();

    // user should be able to undo and redo
    void undo();
    void redo();

    //the user should be able to clear the grid as he pleases
    void clear_sheet();
};
*/
