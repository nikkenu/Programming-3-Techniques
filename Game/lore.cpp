#include "lore.h"
#include "ui_lore.h"


Lore::Lore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lore)
{
    ui->setupUi(this);
    connect(ui->gotItButton, &QPushButton::clicked,
            this, &Lore::accept);


    ui->loreLabel->setPixmap(Student::StaticStorage::getInstance().getEpiclorePixmap());
    ui->loreLabel->setScaledContents(true);
    ui->loreLabel->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );


}

Lore::~Lore()
{
    delete ui;
}

void Lore::accept()
{
    this->done(1);
}
