#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid {
//private functions below represent the default initialisation of the grid
private:
    //x_p and y_p represent the coordinates of the center of the grid
    //with respect to the coordinate system of the gris that is set by default.
    double x_p;
    double y_p;

public:

    //we should have a function that allows the user to use diffrent types of grids
    //as he was styling his own sheet

    std::vector<int> current_items;
    Grid(double x, double y);
    Grid();
    void draw(double scale);
    double getX();
    double getY();
};

#endif // GRID_H
