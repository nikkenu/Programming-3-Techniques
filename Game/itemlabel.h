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

/**
 * @brief The GameGraphicsView is a subclass
 * from QLabel. This helps a lot, when
 * doing drag & drops. Also we can set label
 * settings in here, so we don't need to do them
 * for every label by one.
 */

class ItemLabel : public QLabel
{
public:
    /**
     * @brief Constructor of ItemLabel.
     * @param Item enum ex. "WORKER".
     */

    ItemLabel(StaticStorage::Items item, QWidget *parent = 0);

    ~ItemLabel();

    /**
     * @brief If label is clicked and dragged
     * it saves label information for drop event.
     * @param Event that has happened.
     */
    void mousePressEvent(QMouseEvent *ev);

private:
    StaticStorage::Items m_item;
    QDrag* m_drag;
};

}


#endif // ITEMLABEL_H
