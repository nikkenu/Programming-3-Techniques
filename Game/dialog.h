#ifndef DIALOG_H
#define DIALOG_H


#include "lore.h"
#include <QDialog>
#include <QLineEdit>
#include "playerqlineedit.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

signals:
    void playerNameSignal(QStringList list);

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    void accept();
    void reject();
    void addNewPlayer();
    void lore();

    int m_playerCount = 2;
    QStringList m_playerList;
    Student::PlayerQLineEdit* m_lineOne;
    Student::PlayerQLineEdit* m_lineTwo;
    Student::PlayerQLineEdit* m_lineThree;
    Student::PlayerQLineEdit* m_lineFour;
};

#endif // DIALOG_H
