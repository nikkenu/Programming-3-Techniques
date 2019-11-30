#include "itemlabel.h"

namespace Student {


ItemLabel::ItemLabel(StaticStorage::Items item, QWidget *parent):
    QLabel(parent),
    m_item(item)
{
    setPixmap(StaticStorage::getInstance().getItemPixmap(m_item));
    setToolTip(StaticStorage::getInstance().getItemName(m_item));
    setMaximumSize(50,50);
    setScaledContents(true);
    setFrameStyle(1);
}

ItemLabel::~ItemLabel()
{
    delete m_drag;
}

void ItemLabel::mousePressEvent(QMouseEvent *ev)
{

    if(ev->button() == Qt::LeftButton){
        m_drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;

        mimeData->setText(StaticStorage::getInstance().getItemName(m_item));
        QPixmap pixmap(*this->pixmap());

        m_drag->setMimeData(mimeData);
        m_drag->setPixmap(pixmap.scaled(50,50,Qt::KeepAspectRatio));
        m_drag->exec();
    }

}

}
