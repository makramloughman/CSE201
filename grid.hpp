#include <iostream>
class Grid {
//private functions below represent the default initialisation of the grid
private:
    //x_p and y_p represent the coordinates of the center of the grid 
    //with respect to the coordinate system of the gris that is set by default.
    double x_p;
    double y_p;
    X_p=1
    y_p=1
    
    //the color of the font should be initialized to white
    void initialize_fontcolor();

    // the argument represent the norm of the unit vector
    //maximum value for x
    void draw_x_axis(double scale);
    void set_max_x(int max_x);;
    void set_xaxis_label()

    // the argument represent the norm of the unit vector
    //maximum value for y
    void draw_y_axis(double scale);
    void set_max_y(int max_y);
    vois set_yaxos_label();

    // function that initialises pointer tools
    void coordinates_pointers();
    // current state
    int current_objects[10]




public:
    
    //we should have a function that allows the user to use diffrent types of grids
    //as he was styling his own sheet
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
    void tips():]

    //user should be able to take a snapshot of the grid
    void snapshot();

    // user should be able to undo and redo
    void undo()
    void redo()

    //the user should be able to clear the grid as he pleases
    void clear_sheet();
};