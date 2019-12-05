#include "grid.h"
#include <mainwindow.h>

Grid::Grid(double x, double y)
{
    this->x_p = x;
    this->y_p = y;
}

Grid::Grid()
{
    this->x_p = 0;
    this->y_p = 0;
}

void Grid::draw(double scale)
{
    MainWindow* mainW = MainWindow::getInstance(); //One and only one MainWindow that we have
    mainW->drawCoordinateSystem(*this);
}

double Grid::getX()
{
    return this->x_p;
}

double Grid::getY()
{
    return this->y_p;
}


