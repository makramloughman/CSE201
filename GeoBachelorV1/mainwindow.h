#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QToolButton>
#include <QDebug>
#include "dropdowntoolbutton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void Point();
    void PointInRegion();
    void Intersection();
    void MidPoint();

private:
    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
    void createToolBars();
    void createToolButtons();

    QAction* PointAction;
    QAction* PointInRegionAction;
    QAction* IntersectAction;
    QAction* MidPointAction;
    QMenu* PointMenu;
    DropDownToolButton* PointButton;
};

#endif // MAINWINDOW_H
