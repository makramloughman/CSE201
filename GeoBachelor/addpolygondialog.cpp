#include "mainwindow.h"
#include "addpolygondialog.h"

AddPolygonDialog::AddPolygonDialog(QWidget *parent) :
    QDialog(parent)
{
    label = new QLabel("Number of sides: ");
    text_box = new QLineEdit();
    label->setBuddy(text_box);

    enter_button = new QPushButton("Enter");
    enter_button->setDefault(true);
    quit_button = new QPushButton("Exit without changes");

    connect(quit_button,SIGNAL(clicked()),this,SLOT(close()));
    connect(enter_button,SIGNAL(clicked()),this,SLOT(process_input()));

    QHBoxLayout* main_layout = new QHBoxLayout();
    QVBoxLayout* left_l = new QVBoxLayout();
    QVBoxLayout* right_l = new QVBoxLayout();

    left_l->addWidget(label);
    right_l->addWidget(text_box);
    left_l->addWidget(enter_button);
    right_l->addWidget(quit_button);

    main_layout->addLayout(left_l);
    main_layout->addLayout(right_l);
    setLayout(main_layout);

    MainWindow* mainW = MainWindow::getInstance();
    connect(this, SIGNAL(Polygon(int)),mainW,SLOT(Polygon(int)));

    setWindowTitle("Create a Polygon");
    setFixedHeight(sizeHint().height());
}

void AddPolygonDialog::process_input()
{
    double n = text_box->text().toDouble();
    emit Polygon(n);
    close();
}

AddPolygonDialog::~AddPolygonDialog()
{
    delete label;
    delete text_box;
    delete enter_button;
    delete quit_button;
}
