#ifndef GRID_H
#define GRID_H
#include <vector>
#include <iostream>
#include <QPalette>
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <vector>
#include <QGraphicsScene>
#include <cmath>
#include <QGraphicsTextItem>
#include "mathobject.h"
#include "point.hpp"
#include "container.h"
#include <QResizeEvent>
#pragma once

class Grid {
private:
    //x_p and y_p represent the coordinates of the center of the grid
    //with respect to the coordinate system of the gris that is set by default.
    double x_p;
    double y_p;

public:
    //we should have a function that allows the user to use diffrent types of grids
    //as he was styling his own sheet

    Grid(double x, double y);
    Grid(double x, double y,double unit);
    Grid();
    void draw();
    double getX();
    double getY();
    void set_BackColor(QBrush b);
    double unit; //number of pixels correspondig to 1 natural unit (in our grid)

    Container obj; //all the current objects
    void set_xaxis_label();
    void set_yaxis_label();
    void move_grid(double dx, double dy);
    void move_grid(QPointF to);
    void refresh_grid();

    void zoom(double coef);
};

#endif // GRID_H

/*
class Grid {
//private functions below represent the default initialisation of the grid
private:
    //x_p and y_p represent the coordinates of the center of the grid
    //with respect to the coordinate system of the gris that is set by default.
    double x_p;
    double y_p;


    //the color of the font should be initialized to white
    void initialize_fontcolor();

    // the argument represent the norm of the unit vector
    //maximum value for x
    void draw_coordinate_system();
    void set_xaxis_label();

    // the argument represent the norm of the unit vector
    //maximum value for y
    void set_yaxis_label();

    // function that initialises pointer tools
    void coordinates_pointers();




public:
    std::vector<Item> current_items;
    Grid(int x,int y);
    Grid();
    Grid(double x, double y);
    double getX();
    double getY();



    //we should have a function that allows the user to use diffrent types of grids
    //as he was styling his own sheet
    void Draw_grid();
    void style_grid();
    void change_font_color();
    void change_grid_color();
    void hide_grid();


    // translate the center or translate the whole coordinate system so that
    //a specified point become the center
    void translate(int percentage);
    void change_center_view();

    //user should be able to hide and show coordinate axis
    void hide_x_axis();
    void show_x_axis();
    void hide_y_axis();
    void show_y_axis();

    //allows the user the rotate the coordinate system
    void right_rotation(double angle_of_rotation);
    void left_rotation(double angle_of_rotation);

    //zoom on a specific zome of the grid
    void zoom_in(int percentage);
    void zoom_out(int percentage);

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
    void tips();

    //user should be able to take a snapshot of the grid
    void snapshot();

    // user should be able to undo and redo
    void undo();
    void redo();

    //the user should be able to clear the grid as he pleases
    void clear_sheet();
};
*/
