#ifndef PLAYERQLINEEDIT_H
#define PLAYERQLINEEDIT_H

#include <QLineEdit>
#include <QDebug>

namespace Student {

class PlayerQLineEdit : public QLineEdit
{
public:
    PlayerQLineEdit();

    void keyPressEvent(QKeyEvent *ev);

    bool isAccepted();
private:
    QRegExp m_whiteSpace {QStringLiteral("\\s*")};
    bool m_acceptName = false;
};


}



#endif // PLAYERQLINEEDIT_H
