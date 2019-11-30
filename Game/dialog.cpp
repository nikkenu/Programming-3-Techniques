#include "dialog.h"
#include "ui_dialog.h"
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>

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

    connect(ui->addNewPlayerButton, &QPushButton::clicked,
            this, &Dialog::addNewPlayer);

    QLabel* labelOne = new QLabel(QString("Player 1: "));
    m_lineOne = new Student::PlayerQLineEdit();
    ui->formLayout->addRow(labelOne, m_lineOne);

    QLabel* labelTwo = new QLabel(QString("Player 2: "));
    m_lineTwo = new Student::PlayerQLineEdit();
    ui->formLayout->addRow(labelTwo, m_lineTwo);

}

Dialog::~Dialog()
{
    delete ui;
    delete m_lineOne;
    delete m_lineTwo;
    delete m_lineThree;
    delete m_lineFour;
}

void Dialog::accept()
{

    if (m_lineOne->text().isEmpty() && m_lineTwo->text().isEmpty())
    {
        ui->infoLabel->setText("You must have at least two players!");
        return;
    }
    else
    {
        if(!m_lineOne->isAccepted() || !m_lineTwo->isAccepted())
        {
            ui->infoLabel->setText("Fix line, it has invisible characters only");
            return;
        }

        if(m_playerCount == 3)
        {
            if(!m_lineThree->isAccepted())
            {
                ui->infoLabel->setText("Fix line, it has invisible characters only");
                return;
            }
        }
        else if(m_playerCount == 4)
        {
            if(!m_lineThree->isAccepted() || !m_lineFour->isAccepted())
            {
                ui->infoLabel->setText("Fix line, it has invisible characters only");
                return;
            }
        }
        else
        {

        }

        m_playerList.push_back(m_lineOne->text());
        m_playerList.push_back(m_lineTwo->text());

        if(m_playerCount == 4)
        {
            m_playerList.push_back(m_lineThree->text());
            m_playerList.push_back(m_lineFour->text());
        }
        else if(m_playerCount == 3)
        {
            m_playerList.push_back(m_lineThree->text());
        }

        emit this->playerNameSignal(m_playerList);
        this->done(1);
    }

}

void Dialog::reject()
{
    this->done(0);
}

void Dialog::addNewPlayer()
{
    m_playerCount += 1;
    if(m_playerCount == 3)
    {
        QLabel* labelThree = new QLabel(QString("Player " + QString::number(m_playerCount) + " :"));
        m_lineThree = new Student::PlayerQLineEdit();
        ui->formLayout->addRow(labelThree, m_lineThree);
    }
    else if(m_playerCount == 4)
    {
        QLabel* labelFour = new QLabel(QString("Player " + QString::number(m_playerCount) + " :"));
        m_lineFour = new Student::PlayerQLineEdit();
        ui->formLayout->addRow(labelFour, m_lineFour);
    }
    else
    {
        ui->infoLabel->setText("You already have max amount of players!");
    }
}

void Dialog::lore()
{
    Lore lore;
    lore.setWindowTitle("The lore of Pirkanmaa");
    lore.exec();
}

