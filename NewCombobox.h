#ifndef NEWCOMBOBOX_H
#define NEWCOMBOBOX_H

#include <QComboBox>
#include <QMouseEvent>

class NewCombobox : public QComboBox
{
    Q_OBJECT
public:
    explicit NewCombobox(QWidget *paraent = 0);
    ~NewCombobox();

protected:
    virtual void mousePressEvent(QMouseEvent *event);
signals:
    void clicked();
};

#endif // NEWCOMBOBOX_H
