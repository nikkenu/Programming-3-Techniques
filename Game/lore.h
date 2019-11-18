#ifndef LORE_H
#define LORE_H

#include "staticstorage.h"

#include <QDialog>
#include <QUrl>
#include <QLabel>

namespace Ui {
class Lore;
}

class Lore : public QDialog
{
    Q_OBJECT

public:
    explicit Lore(QWidget *parent = 0);
    ~Lore();

private:
    Ui::Lore *ui;
    void accept();
};

#endif // LORE_H
