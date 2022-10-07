#include "NewCombobox.h"

NewCombobox::NewCombobox(QWidget *parent) : QComboBox(parent)
{

}

NewCombobox::~NewCombobox()
{

}

void NewCombobox::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked();
    }
    QComboBox::mousePressEvent(event);
}
