#ifndef DIALOG_H
#define DIALOG_H


#include "lore.h"
#include <QDialog>
#include <QLineEdit>
#include "playerqlineedit.h"

namespace Ui {
class Dialog;
}

/**
 * @brief The Dialog class is used to make a dialog where the amount
 * of players and their names are set.
 */

class Dialog : public QDialog
{
    Q_OBJECT

signals:

    /**
     * @brief playerNameSignal is used to send o send player names to Mainwindow
     * @see MainWidow's startGame-method
     * @param A list containing player names.
     */
    void playerNameSignal(QStringList list);

public:

    /**
     * @brief Consturctor
     * @param parent
     * @post Exception guarantee: No guarantee
     */
    explicit Dialog(QWidget *parent = 0);

    /**
      *@brief Deconstructor
      */
    ~Dialog();

private:

    Ui::Dialog *ui;

    /**
     * @brief Called when playButton is presses. Check if player names set are valid
     * (not empty or only spaces), if they're not it send a massege to the ui.
     * If nothing's wrong, it pushes player names to a vector, emits playerNameSignal and
     * closes the window.
     * @see playerNameSignal
     * @post Exception guarantee: Basic
     */
    void accept();

    /**
     * @brief Rejects the dialog.
     * @post Exception guarantee: No-throw
     */
    void reject();

    /**
     * @brief addNewPlayer is called when the addNewPlayerButton is pressed. It adds a new
     * QLineEdit to the screen (max: 4).
     * @post Exception guarantee: Basic
     */
    void addNewPlayer();

    /**
     * @brief Called when loreButton is pressed. Opens a new window with the lore in it.
     * @see Class Lore.
     * @post Exception guarantee: No-throw
     */
    void lore();

    int m_playerCount = 2;
    QStringList m_playerList;

    Student::PlayerQLineEdit* m_lineOne;
    Student::PlayerQLineEdit* m_lineTwo;
    Student::PlayerQLineEdit* m_lineThree;
    Student::PlayerQLineEdit* m_lineFour;
};

#endif // DIALOG_H
