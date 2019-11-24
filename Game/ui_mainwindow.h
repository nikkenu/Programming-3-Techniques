/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *roundLabel;
    QLabel *playerTurnLabel;
    QFrame *line;
    QLabel *resourcesTitle;
    QFormLayout *formLayout;
    QLCDNumber *moneyLCDNumber;
    QLabel *moneyTitle;
    QLCDNumber *foodLCDNumber;
    QLabel *foodTitle;
    QLCDNumber *woodLCDNumber;
    QLabel *woodTitle;
    QLCDNumber *stoneLCDNumber;
    QLabel *stoneTitle;
    QLCDNumber *oreLCDNumber;
    QLabel *oreTitle;
    QFrame *line_2;
    QLabel *workerManagementTitle;
    QGridLayout *gridLayout_2;
    QPushButton *assignPushButton;
    QPushButton *freePushButton;
    QFrame *line_3;
    QLabel *buildTitle;
    QVBoxLayout *verticalLayout_5;
    QFrame *line_4;
    QPushButton *endTurnPushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(750, 520);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(750, 520));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(222, 0));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        roundLabel = new QLabel(widget);
        roundLabel->setObjectName(QString::fromUtf8("roundLabel"));
        roundLabel->setMinimumSize(QSize(0, 15));
        roundLabel->setMaximumSize(QSize(16777215, 15));
        roundLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(roundLabel);

        playerTurnLabel = new QLabel(widget);
        playerTurnLabel->setObjectName(QString::fromUtf8("playerTurnLabel"));
        playerTurnLabel->setMinimumSize(QSize(0, 15));
        playerTurnLabel->setMaximumSize(QSize(16777215, 15));
        playerTurnLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(playerTurnLabel);

        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMaximumSize(QSize(16777215, 2));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        resourcesTitle = new QLabel(widget);
        resourcesTitle->setObjectName(QString::fromUtf8("resourcesTitle"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(resourcesTitle->sizePolicy().hasHeightForWidth());
        resourcesTitle->setSizePolicy(sizePolicy3);
        resourcesTitle->setMinimumSize(QSize(0, 15));
        resourcesTitle->setMaximumSize(QSize(16777215, 15));
        resourcesTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(resourcesTitle);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        formLayout->setHorizontalSpacing(6);
        formLayout->setVerticalSpacing(5);
        formLayout->setContentsMargins(-1, 0, -1, 0);
        moneyLCDNumber = new QLCDNumber(widget);
        moneyLCDNumber->setObjectName(QString::fromUtf8("moneyLCDNumber"));
        sizePolicy1.setHeightForWidth(moneyLCDNumber->sizePolicy().hasHeightForWidth());
        moneyLCDNumber->setSizePolicy(sizePolicy1);
        moneyLCDNumber->setMinimumSize(QSize(0, 20));
        moneyLCDNumber->setMaximumSize(QSize(16777215, 5355));
        moneyLCDNumber->setMouseTracking(false);
        moneyLCDNumber->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(0, QFormLayout::LabelRole, moneyLCDNumber);

        moneyTitle = new QLabel(widget);
        moneyTitle->setObjectName(QString::fromUtf8("moneyTitle"));
        sizePolicy1.setHeightForWidth(moneyTitle->sizePolicy().hasHeightForWidth());
        moneyTitle->setSizePolicy(sizePolicy1);
        moneyTitle->setMinimumSize(QSize(0, 20));
        moneyTitle->setMaximumSize(QSize(16777215, 5355));

        formLayout->setWidget(0, QFormLayout::FieldRole, moneyTitle);

        foodLCDNumber = new QLCDNumber(widget);
        foodLCDNumber->setObjectName(QString::fromUtf8("foodLCDNumber"));
        sizePolicy1.setHeightForWidth(foodLCDNumber->sizePolicy().hasHeightForWidth());
        foodLCDNumber->setSizePolicy(sizePolicy1);
        foodLCDNumber->setMinimumSize(QSize(0, 20));
        foodLCDNumber->setMaximumSize(QSize(16777215, 5355));
        foodLCDNumber->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(1, QFormLayout::LabelRole, foodLCDNumber);

        foodTitle = new QLabel(widget);
        foodTitle->setObjectName(QString::fromUtf8("foodTitle"));
        sizePolicy1.setHeightForWidth(foodTitle->sizePolicy().hasHeightForWidth());
        foodTitle->setSizePolicy(sizePolicy1);
        foodTitle->setMinimumSize(QSize(0, 20));
        foodTitle->setMaximumSize(QSize(16777215, 5355));

        formLayout->setWidget(1, QFormLayout::FieldRole, foodTitle);

        woodLCDNumber = new QLCDNumber(widget);
        woodLCDNumber->setObjectName(QString::fromUtf8("woodLCDNumber"));
        sizePolicy1.setHeightForWidth(woodLCDNumber->sizePolicy().hasHeightForWidth());
        woodLCDNumber->setSizePolicy(sizePolicy1);
        woodLCDNumber->setMinimumSize(QSize(0, 20));
        woodLCDNumber->setMaximumSize(QSize(16777215, 5355));
        woodLCDNumber->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(2, QFormLayout::LabelRole, woodLCDNumber);

        woodTitle = new QLabel(widget);
        woodTitle->setObjectName(QString::fromUtf8("woodTitle"));
        sizePolicy1.setHeightForWidth(woodTitle->sizePolicy().hasHeightForWidth());
        woodTitle->setSizePolicy(sizePolicy1);
        woodTitle->setMinimumSize(QSize(0, 20));
        woodTitle->setMaximumSize(QSize(16777215, 5355));

        formLayout->setWidget(2, QFormLayout::FieldRole, woodTitle);

        stoneLCDNumber = new QLCDNumber(widget);
        stoneLCDNumber->setObjectName(QString::fromUtf8("stoneLCDNumber"));
        sizePolicy1.setHeightForWidth(stoneLCDNumber->sizePolicy().hasHeightForWidth());
        stoneLCDNumber->setSizePolicy(sizePolicy1);
        stoneLCDNumber->setMinimumSize(QSize(0, 20));
        stoneLCDNumber->setMaximumSize(QSize(16777215, 5355));
        stoneLCDNumber->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(3, QFormLayout::LabelRole, stoneLCDNumber);

        stoneTitle = new QLabel(widget);
        stoneTitle->setObjectName(QString::fromUtf8("stoneTitle"));
        sizePolicy1.setHeightForWidth(stoneTitle->sizePolicy().hasHeightForWidth());
        stoneTitle->setSizePolicy(sizePolicy1);
        stoneTitle->setMinimumSize(QSize(0, 20));
        stoneTitle->setMaximumSize(QSize(16777215, 5355));

        formLayout->setWidget(3, QFormLayout::FieldRole, stoneTitle);

        oreLCDNumber = new QLCDNumber(widget);
        oreLCDNumber->setObjectName(QString::fromUtf8("oreLCDNumber"));
        sizePolicy1.setHeightForWidth(oreLCDNumber->sizePolicy().hasHeightForWidth());
        oreLCDNumber->setSizePolicy(sizePolicy1);
        oreLCDNumber->setMinimumSize(QSize(0, 20));
        oreLCDNumber->setMaximumSize(QSize(16777215, 5355));
        oreLCDNumber->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(4, QFormLayout::LabelRole, oreLCDNumber);

        oreTitle = new QLabel(widget);
        oreTitle->setObjectName(QString::fromUtf8("oreTitle"));
        sizePolicy1.setHeightForWidth(oreTitle->sizePolicy().hasHeightForWidth());
        oreTitle->setSizePolicy(sizePolicy1);
        oreTitle->setMinimumSize(QSize(0, 20));
        oreTitle->setMaximumSize(QSize(16777215, 5355));

        formLayout->setWidget(4, QFormLayout::FieldRole, oreTitle);


        verticalLayout_4->addLayout(formLayout);

        line_2 = new QFrame(widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        sizePolicy3.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy3);
        line_2->setMaximumSize(QSize(16777215, 2));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        workerManagementTitle = new QLabel(widget);
        workerManagementTitle->setObjectName(QString::fromUtf8("workerManagementTitle"));
        sizePolicy3.setHeightForWidth(workerManagementTitle->sizePolicy().hasHeightForWidth());
        workerManagementTitle->setSizePolicy(sizePolicy3);
        workerManagementTitle->setMinimumSize(QSize(0, 15));
        workerManagementTitle->setMaximumSize(QSize(16777215, 15));
        workerManagementTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(workerManagementTitle);


        verticalLayout_3->addLayout(verticalLayout_4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        assignPushButton = new QPushButton(widget);
        assignPushButton->setObjectName(QString::fromUtf8("assignPushButton"));
        assignPushButton->setMinimumSize(QSize(0, 20));
        assignPushButton->setMaximumSize(QSize(16777215, 20));

        gridLayout_2->addWidget(assignPushButton, 0, 0, 1, 1);

        freePushButton = new QPushButton(widget);
        freePushButton->setObjectName(QString::fromUtf8("freePushButton"));
        freePushButton->setMinimumSize(QSize(0, 20));
        freePushButton->setMaximumSize(QSize(16777215, 20));

        gridLayout_2->addWidget(freePushButton, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        line_3 = new QFrame(widget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setAutoFillBackground(false);
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_3);

        buildTitle = new QLabel(widget);
        buildTitle->setObjectName(QString::fromUtf8("buildTitle"));
        buildTitle->setMinimumSize(QSize(0, 15));
        buildTitle->setMaximumSize(QSize(16777215, 15));
        buildTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(buildTitle);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));

        verticalLayout_3->addLayout(verticalLayout_5);

        line_4 = new QFrame(widget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_4);

        endTurnPushButton = new QPushButton(widget);
        endTurnPushButton->setObjectName(QString::fromUtf8("endTurnPushButton"));
        endTurnPushButton->setMinimumSize(QSize(0, 25));
        endTurnPushButton->setMaximumSize(QSize(16777215, 25));

        verticalLayout_3->addWidget(endTurnPushButton);


        verticalLayout_2->addWidget(widget);


        horizontalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        roundLabel->setText(QApplication::translate("MainWindow", "Round 1", nullptr));
        playerTurnLabel->setText(QApplication::translate("MainWindow", "Turn : Player 1", nullptr));
        resourcesTitle->setText(QApplication::translate("MainWindow", "Resources", nullptr));
        moneyTitle->setText(QApplication::translate("MainWindow", "Money", nullptr));
        foodTitle->setText(QApplication::translate("MainWindow", "Food", nullptr));
        woodTitle->setText(QApplication::translate("MainWindow", "Wood", nullptr));
        stoneTitle->setText(QApplication::translate("MainWindow", "Stone", nullptr));
        oreTitle->setText(QApplication::translate("MainWindow", "Ore", nullptr));
        workerManagementTitle->setText(QApplication::translate("MainWindow", "Worker Management", nullptr));
        assignPushButton->setText(QApplication::translate("MainWindow", "Assign", nullptr));
        freePushButton->setText(QApplication::translate("MainWindow", "Free", nullptr));
        buildTitle->setText(QApplication::translate("MainWindow", "Build", nullptr));
        endTurnPushButton->setText(QApplication::translate("MainWindow", "End Turn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
