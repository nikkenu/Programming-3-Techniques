/********************************************************************************
** Form generated from reading UI file 'lore.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LORE_H
#define UI_LORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Lore
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *loreLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *gotItButton;

    void setupUi(QDialog *Lore)
    {
        if (Lore->objectName().isEmpty())
            Lore->setObjectName(QString::fromUtf8("Lore"));
        Lore->resize(400, 300);
        verticalLayout = new QVBoxLayout(Lore);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        loreLabel = new QLabel(Lore);
        loreLabel->setObjectName(QString::fromUtf8("loreLabel"));
        loreLabel->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(loreLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gotItButton = new QPushButton(Lore);
        gotItButton->setObjectName(QString::fromUtf8("gotItButton"));

        horizontalLayout->addWidget(gotItButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Lore);

        QMetaObject::connectSlotsByName(Lore);
    } // setupUi

    void retranslateUi(QDialog *Lore)
    {
        Lore->setWindowTitle(QApplication::translate("Lore", "Dialog", nullptr));
        loreLabel->setText(QString());
        gotItButton->setText(QApplication::translate("Lore", "Got it", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lore: public Ui_Lore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LORE_H
