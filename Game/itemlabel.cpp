#include "itemlabel.h"

namespace Student {


ItemLabel::ItemLabel(StaticStorage::Items item, QWidget *parent):
    QLabel(parent)
{
    m_item = item;
    setPixmap(StaticStorage::getInstance().getItemPixmap(m_item));
    setToolTip(StaticStorage::getInstance().getItemName(m_item));
    setMaximumSize(50,50);
    setScaledContents(true);
    setFrameStyle(1);
}

void ItemLabel::mousePressEvent(QMouseEvent *ev)
{

    if(ev->button() == Qt::LeftButton){
        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(StaticStorage::getInstance().getItemName(m_item));
        QPixmap pixmap(*this->pixmap());

        drag->setMimeData(mimeData);
        drag->setPixmap(pixmap.scaled(50,50,Qt::KeepAspectRatio));
        drag->exec(Qt::CopyAction);
    }

}

}
