# CSE201 - GeoBachelor

[Website](https://makramloughman.github.io/CSE201/)

## Getting Started

This is the project for the class of CSE201.
 
The GeoBachelor is a remake of GeoGebra.

### Prerequisites

- QT 5.9.5 or newer

>**Note**: The program was tested on Ubuntu 18.04 with QT 5.9.5

### Installation

```
git clone https://github.com/makramloughman/CSE201.git
```
Open the project in QT creator, build it and run it.

### Screenshot

![Preview](/GeoBachelor/images/bx21.png)

![Preview](/GeoBachelor/images/bx21(2).png)

### Instructions

There are 4 main blocks: the **toolbar**, the **grid**, the **text-display**, and the **command line**.

The **toolbar** contains the buttons required to draw mathematical figures. To draw an object, one must click on the desired button and complete the necessay action on the gird. After this, the clicked button is automatically deselected, and one can only move the grid and zoom in / out. To draw another (even if the same) mathematical object, one must click again the desired button. This stops unintentional objects of being created on the grid when clicking on it. A detailed list of all possible actions from the toolbar is given below:

* **Move:** only allows user to move the grid
* **Select:** only selects objects in the grid 
    1. Select two points for line, segment, midpoint, perpendicular bisector, or reflect about point
    2. Select three points for triangle, circle, or angle bisector
    3. Select one point and one line for perpendicular line, parallel line, reflect about line
    4. Select two lines for intersection
    5. Select one point and one line for tangent
    6. Select triangle for triangle related functions (inscribed circle, etc)
    7. Select random object on grid for intersection
    8. Select any object on grid for deletion
* **Line:** Place two points on the grid *(can also be created with selection of points)*
* **Segment:** Place two points on the grid *(can also be created with selection of points)*
* **Ray:** Place two points on the grid *(can also be created with selection of points)*
* **Perpendicular Line:** *selection of point and line required*
* **Parallel Line:** *selection of point and line required*
* **Perpendicular Bisector:** *selection of two points required*
* **Angle Bisector:** *selection of three points required*
* **Tangent:** *selection of point and circle required*
* **Polygon:** *(a box shows up and asks for the number of sides n)* Place *n+1* points on the grid
* **Triangle:** Place three points on the grid *(can also be created with selection of points)*
* **Inscribed Circle:** *(a triangle must be selected)*
* **Circumscribed Circle:** *(a triangle must be selected)*
* **Orthocenter:** *(a triangle must be selected)*
* **Center of Gravity:** *(a triangle must be selected)*
* **Circle with Center through Point:** Place center then point through which the circle passes *(can also be created with selection of points)*
* **Circle with Center and Radius:** Place center and point of the radius
* **Ellipse:** Place three points *(works only for points aligned and parallel to the x axis; if they are not then they will be projected to the parallel to the x axis going through the first point placed; if impossible points with these conditions are given, then nothing happens)* 
* **Reflect about Line:** *selection of point and line required*
* **Delete:** *selection of object(s) required*
* **Clear:** Clear the grid

The **grid** can be moved in any direction by dragging it and can be zoomed in / out using ctrl + scroll.

The **text-display** contains the objects currently on the grid. One can select and delete an object in this list by clicking on it and pressing on the backspace or delete button.

The **command line** allows one to create objects not necessarly available or possible from the toolbar. A detailed list of arguments is given below:

* **Point:** point(x,y)
* **Triangle:** triangle((x1,y1),(x2,y2),(x3,y3))
* **Regular Polygon:** rpoly((cx,yx),(x1,y1),n) *(where (cx,cy) are the coordinates of the center, (x1,y1) are the coordinates of a point on the polygon, n is the number of sides)*
* **Function:** any mathemetical function *(must be written linearly like on an old casio calculator)*
    * *exapmle:* exp(-(1/x)+cos(x))
    * *example:* log(x)+sin(x)

## Authors

- Bogdan Raonic, bogdanraonic, team leader
- Milica Bozanic, milicabozanic, ide leader
- Makram Loughman, makramloughman, git leader
- Gautier Alassaire, gautieralassaire, treasurer 
- Aya Hankir, ayahankir
- Meryem Bennani, merybeni
- Farah El-Euch, faraheleuch
- Naya Khalil, naya-khalil
- Kaylynn Pellicer, kaylynnn

## License

This project is for educational purposes only. Icons form the official GeoGebra application were used in the design. Under no right this software may be distributed.
