#ifndef PLAYERQLINEEDIT_H
#define PLAYERQLINEEDIT_H

#include <QLineEdit>
#include <QDebug>

namespace Student {

/**
 * @brief The PlayerQLineEdit class is made to identify when user types
 * player names to initial dialog. It gives feedback whether the player
 * name set is valid.
 */
class PlayerQLineEdit : public QLineEdit
{
public:
    PlayerQLineEdit();

    /**
     * @brief Gives feedback to user whether the player name typed
     * is valid or not.
     * @param ev: The event when player starts typing.
     */
    void keyPressEvent(QKeyEvent *ev);

    /**
     * @brief  Checks if player name typed is valid.
     * @return True if valid, false if invalid.
     */
    bool isAccepted();
private:
    QRegExp m_whiteSpace {QStringLiteral("\\s*")};
    bool m_acceptName = false;
};


}



#endif // PLAYERQLINEEDIT_H
