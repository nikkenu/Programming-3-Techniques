#include "playerqlineedit.h"

namespace Student {

PlayerQLineEdit::PlayerQLineEdit()
{
    setDisabled(false);
}

void PlayerQLineEdit::keyPressEvent(QKeyEvent *ev)
{
    if(m_whiteSpace.exactMatch(text()))
    {
        QPalette palette;
        palette.setColor(QPalette::Base, Qt::red);
        setPalette(palette);
        m_acceptName = false;
    }
    else
    {
        QPalette palette;
        palette.setColor(QPalette::Base, Qt::green);
        setPalette(palette);
        m_acceptName = true;
    }
    QLineEdit::keyPressEvent(ev);
}

bool PlayerQLineEdit::isAccepted()
{
    if(m_acceptName)
    {
        return true;
    }
    else
    {
        return false;
    }
}

}


