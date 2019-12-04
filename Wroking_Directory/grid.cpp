#include 'grid.hpp'
#include <iostream>
#include <QPalette>
class Grid{
private:
    double x_p;
    double y_p;
    x_p=1
    y_p=1
    //the color of the font should be initialized to white
    void initialize_fontcolor(){
        m_CustomPlot->setBackground(QBrush(QColor("#b3daff")));
        //->replot
    }
    // the argument represent the norm of the unit vector
    //maximum value for x
    void draw_x_axis(double scale);
    QGraphicsLineItem* ox = new QGraphicsLineItem(0,-width/2,0,width/2);

    void set_max_x(int max_x);
    const int MaxX  = std::ceil(width/zoom_factor);
    void set_xaxis_label();





























}