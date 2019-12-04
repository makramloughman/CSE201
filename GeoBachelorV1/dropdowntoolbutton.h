#ifndef DROPDOWNTOOLBUTTON_H
#define DROPDOWNTOOLBUTTON_H

#include <QToolButton>
#include <QDebug>

class DropDownToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit DropDownToolButton(QWidget *parent = 0);
};

#endif // DROPDOWNTOOLBUTTON_H
