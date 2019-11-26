#ifndef LORE_H
#define LORE_H

#include "staticstorage.h"

#include <QDialog>
#include <QUrl>
#include <QLabel>

namespace Ui {
class Lore;
}

/**
 * @brief Tis dialog is opened when user clicks the loreButton on
 * the initial dialog. It contanins of photo of the lore and has
 * a button where this dialog can be closed
 * @see Class Dialog's lore method.
 */
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
