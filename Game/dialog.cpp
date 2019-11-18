#include "dialog.h"
#include "ui_dialog.h"
#include <QDesktopServices>
#include <QUrl>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->closeButton, &QPushButton::clicked,
            this, &Dialog::reject);

    connect(ui->playButton, &QPushButton::clicked,
            this, &Dialog::accept);

    connect(ui->loreButton, &QPushButton::clicked,
            this, &Dialog::lore);
    ui->amountSpinBox->setMaximum(4);
    ui->amountSpinBox->setMinimum(1);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::accept()
{
    int numberOfPlayers = ui->amountSpinBox->value();
    emit this->playerAmountSignal(numberOfPlayers);
    this->done(1);
}

void Dialog::reject()
{
    this->done(0);
}

void Dialog::lore()
{
    Lore lore;
    lore.setWindowTitle("The lore of Pirkanmaa");
    lore.exec();
}

