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


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::accept()
{
    if (ui->p1Name->text().isEmpty() && ui->p2Name->text().isEmpty() &&
        ui->p3Name->text().isEmpty() && ui->p4Name->text().isEmpty())
    {
        ui->infoLabel->setText("You must have at least one player!");
    }
    else
    {
        emit this->playerNameSignal(ui->p1Name->text(), ui->p2Name->text(),
                                    ui->p3Name->text(), ui->p4Name->text());
        this->done(1);
    }

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

