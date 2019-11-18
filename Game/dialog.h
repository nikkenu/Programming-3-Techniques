#ifndef DIALOG_H
#define DIALOG_H


#include "lore.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

signals:
    void playerNameSignal(QString name1, QString name2, QString name3, QString name4);

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    void accept();
    void reject();
    void lore();
};

#endif // DIALOG_H
