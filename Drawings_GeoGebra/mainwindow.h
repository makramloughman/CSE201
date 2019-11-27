#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QDialog>
#include <QGraphicsScene>
#include <QTimer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT //Tells us that we use GUI

public:
    explicit MainWindow(QWidget *parent = 0); //constructor
    ~MainWindow(); //distractor
    void drawLine(QLineF l);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
};

#endif // MAINWINDOW_H
