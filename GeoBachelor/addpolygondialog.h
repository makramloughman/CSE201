#ifndef ADDPOLYGONDIALOG_H
#define ADDPOLYGONDIALOG_H

#pragma once
#include <iostream>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

class AddPolygonDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddPolygonDialog(QWidget *parent = 0);
    ~AddPolygonDialog();

signals:
    void Polygon(int n);

public slots:
    void process_input();

private:
    QLabel* label;
    QLineEdit* text_box;
    QPushButton* enter_button;
    QPushButton* quit_button;

};

#endif // ADDPOLYGONDIALOG_H
