#ifndef ITEMLABEL_H
#define ITEMLABEL_H

#include "gamescene.h"
#include "staticstorage.h"
#include <QGraphicsScene>
#include <QLabel>
#include <QString>
#include <QMimeData>
#include <QMouseEvent>
#include <QDebug>
#include <QDrag>

namespace Student {

class ItemLabel : public QLabel
{
public:
    ItemLabel(StaticStorage::Items item, QWidget *parent = 0);

    void mousePressEvent(QMouseEvent *ev);

private:
    StaticStorage::Items m_item;
};

}


#endif // ITEMLABEL_H
