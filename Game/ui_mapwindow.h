/********************************************************************************
** Form generated from reading UI file 'mapwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWINDOW_H
#define UI_MAPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
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
    QGridLayout *workerManagementGrid;
    QLabel *workerLabel;
    QLabel *farmerLabel;
    QLabel *minerLabel;
    QGridLayout *gridLayout_2;
    QPushButton *assignPushButton;
    QPushButton *freePushButton;
    QFrame *line_3;
    QLabel *buildTitle;
    QGridLayout *buildGrid;
    QLabel *farmLabel;
    QLabel *outpostLabel;
    QLabel *hqLabel;
    QLabel *mineLabel;
    QLabel *oilrigLabel;
    QFrame *line_4;
    QPushButton *endTurnPushButton;

    void setupUi(QMainWindow *MapWindow)
    {
        if (MapWindow->objectName().isEmpty())
            MapWindow->setObjectName(QString::fromUtf8("MapWindow"));
        MapWindow->resize(750, 520);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MapWindow->sizePolicy().hasHeightForWidth());
        MapWindow->setSizePolicy(sizePolicy);
        MapWindow->setMinimumSize(QSize(750, 520));
        centralwidget = new QWidget(MapWindow);
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
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(500, 500));
        graphicsView->setFrameShape(QFrame::NoFrame);

        verticalLayout->addWidget(graphicsView);


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

        workerManagementGrid = new QGridLayout();
        workerManagementGrid->setObjectName(QString::fromUtf8("workerManagementGrid"));
        workerLabel = new QLabel(widget);
        workerLabel->setObjectName(QString::fromUtf8("workerLabel"));
        sizePolicy.setHeightForWidth(workerLabel->sizePolicy().hasHeightForWidth());
        workerLabel->setSizePolicy(sizePolicy);
        workerLabel->setMinimumSize(QSize(50, 50));
        workerLabel->setMaximumSize(QSize(50, 50));
        workerLabel->setCursor(QCursor(Qt::ArrowCursor));
        workerLabel->setFrameShape(QFrame::Box);
        workerLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/images/worker.png")));
        workerLabel->setScaledContents(true);

        workerManagementGrid->addWidget(workerLabel, 0, 0, 1, 1);

        farmerLabel = new QLabel(widget);
        farmerLabel->setObjectName(QString::fromUtf8("farmerLabel"));
        sizePolicy.setHeightForWidth(farmerLabel->sizePolicy().hasHeightForWidth());
        farmerLabel->setSizePolicy(sizePolicy);
        farmerLabel->setMinimumSize(QSize(50, 50));
        farmerLabel->setMaximumSize(QSize(50, 50));
        farmerLabel->setCursor(QCursor(Qt::ArrowCursor));
        farmerLabel->setFrameShape(QFrame::Box);
        farmerLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/images/farmer.png")));
        farmerLabel->setScaledContents(true);

        workerManagementGrid->addWidget(farmerLabel, 0, 1, 1, 1);

        minerLabel = new QLabel(widget);
        minerLabel->setObjectName(QString::fromUtf8("minerLabel"));
        sizePolicy.setHeightForWidth(minerLabel->sizePolicy().hasHeightForWidth());
        minerLabel->setSizePolicy(sizePolicy);
        minerLabel->setMinimumSize(QSize(50, 50));
        minerLabel->setMaximumSize(QSize(50, 50));
        minerLabel->setCursor(QCursor(Qt::ArrowCursor));
        minerLabel->setFrameShape(QFrame::Box);
        minerLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/images/miner.png")));
        minerLabel->setScaledContents(true);

        workerManagementGrid->addWidget(minerLabel, 0, 2, 1, 1);


        verticalLayout_4->addLayout(workerManagementGrid);


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

        buildGrid = new QGridLayout();
        buildGrid->setObjectName(QString::fromUtf8("buildGrid"));
        farmLabel = new QLabel(widget);
        farmLabel->setObjectName(QString::fromUtf8("farmLabel"));
        sizePolicy.setHeightForWidth(farmLabel->sizePolicy().hasHeightForWidth());
        farmLabel->setSizePolicy(sizePolicy);
        farmLabel->setMinimumSize(QSize(50, 50));
        farmLabel->setMaximumSize(QSize(50, 50));
        farmLabel->setFrameShape(QFrame::Box);
        farmLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/images/scarecrow.png")));
        farmLabel->setScaledContents(true);
        farmLabel->setAlignment(Qt::AlignCenter);

        buildGrid->addWidget(farmLabel, 0, 2, 1, 1);

        outpostLabel = new QLabel(widget);
        outpostLabel->setObjectName(QString::fromUtf8("outpostLabel"));
        sizePolicy.setHeightForWidth(outpostLabel->sizePolicy().hasHeightForWidth());
        outpostLabel->setSizePolicy(sizePolicy);
        outpostLabel->setMinimumSize(QSize(50, 50));
        outpostLabel->setMaximumSize(QSize(50, 50));
        outpostLabel->setFrameShape(QFrame::Box);
        outpostLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/images/lighthouse.png")));
        outpostLabel->setScaledContents(true);
        outpostLabel->setAlignment(Qt::AlignCenter);

        buildGrid->addWidget(outpostLabel, 0, 1, 1, 1);

        hqLabel = new QLabel(widget);
        hqLabel->setObjectName(QString::fromUtf8("hqLabel"));
        sizePolicy.setHeightForWidth(hqLabel->sizePolicy().hasHeightForWidth());
        hqLabel->setSizePolicy(sizePolicy);
        hqLabel->setMinimumSize(QSize(50, 50));
        hqLabel->setMaximumSize(QSize(50, 50));
        hqLabel->setAutoFillBackground(false);
        hqLabel->setFrameShape(QFrame::Box);
        hqLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/images/headquarter.png")));
        hqLabel->setScaledContents(true);
        hqLabel->setAlignment(Qt::AlignCenter);

        buildGrid->addWidget(hqLabel, 0, 0, 1, 1);

        mineLabel = new QLabel(widget);
        mineLabel->setObjectName(QString::fromUtf8("mineLabel"));
        sizePolicy.setHeightForWidth(mineLabel->sizePolicy().hasHeightForWidth());
        mineLabel->setSizePolicy(sizePolicy);
        mineLabel->setMinimumSize(QSize(50, 50));
        mineLabel->setMaximumSize(QSize(50, 50));
        mineLabel->setFrameShape(QFrame::Box);
        mineLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/images/data.png")));
        mineLabel->setScaledContents(true);
        mineLabel->setAlignment(Qt::AlignCenter);

        buildGrid->addWidget(mineLabel, 1, 0, 1, 1);

        oilrigLabel = new QLabel(widget);
        oilrigLabel->setObjectName(QString::fromUtf8("oilrigLabel"));
        sizePolicy.setHeightForWidth(oilrigLabel->sizePolicy().hasHeightForWidth());
        oilrigLabel->setSizePolicy(sizePolicy);
        oilrigLabel->setMinimumSize(QSize(50, 50));
        oilrigLabel->setMaximumSize(QSize(50, 50));
        oilrigLabel->setFrameShape(QFrame::Box);
        oilrigLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/images/oilrig.png")));
        oilrigLabel->setScaledContents(true);
        oilrigLabel->setAlignment(Qt::AlignCenter);

        buildGrid->addWidget(oilrigLabel, 1, 1, 1, 1);


        verticalLayout_3->addLayout(buildGrid);

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

        MapWindow->setCentralWidget(centralwidget);

        retranslateUi(MapWindow);

        QMetaObject::connectSlotsByName(MapWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MapWindow)
    {
        MapWindow->setWindowTitle(QApplication::translate("MapWindow", "MainWindow", nullptr));
        graphicsView->setStyleSheet(QApplication::translate("MapWindow", "0", nullptr));
        roundLabel->setText(QApplication::translate("MapWindow", "Round 1", nullptr));
        playerTurnLabel->setText(QApplication::translate("MapWindow", "Turn : Player 1", nullptr));
        resourcesTitle->setText(QApplication::translate("MapWindow", "Resources", nullptr));
        moneyTitle->setText(QApplication::translate("MapWindow", "Money", nullptr));
        foodTitle->setText(QApplication::translate("MapWindow", "Food", nullptr));
        woodTitle->setText(QApplication::translate("MapWindow", "Wood", nullptr));
        stoneTitle->setText(QApplication::translate("MapWindow", "Stone", nullptr));
        oreTitle->setText(QApplication::translate("MapWindow", "Ore", nullptr));
        workerManagementTitle->setText(QApplication::translate("MapWindow", "Worker Management", nullptr));
#ifndef QT_NO_TOOLTIP
        workerLabel->setToolTip(QApplication::translate("MapWindow", "worker", nullptr));
#endif // QT_NO_TOOLTIP
        workerLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        farmerLabel->setToolTip(QApplication::translate("MapWindow", "farmer", nullptr));
#endif // QT_NO_TOOLTIP
        farmerLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        minerLabel->setToolTip(QApplication::translate("MapWindow", "miner", nullptr));
#endif // QT_NO_TOOLTIP
        minerLabel->setText(QString());
        assignPushButton->setText(QApplication::translate("MapWindow", "Assign", nullptr));
        freePushButton->setText(QApplication::translate("MapWindow", "Free", nullptr));
        buildTitle->setText(QApplication::translate("MapWindow", "Build", nullptr));
#ifndef QT_NO_TOOLTIP
        farmLabel->setToolTip(QApplication::translate("MapWindow", "farm", nullptr));
#endif // QT_NO_TOOLTIP
        farmLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        outpostLabel->setToolTip(QApplication::translate("MapWindow", "outpost", nullptr));
#endif // QT_NO_TOOLTIP
        outpostLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        hqLabel->setToolTip(QApplication::translate("MapWindow", "headquarter", nullptr));
#endif // QT_NO_TOOLTIP
        hqLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        mineLabel->setToolTip(QApplication::translate("MapWindow", "mine", nullptr));
#endif // QT_NO_TOOLTIP
        mineLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        oilrigLabel->setToolTip(QApplication::translate("MapWindow", "oilrig", nullptr));
#endif // QT_NO_TOOLTIP
        oilrigLabel->setText(QString());
        endTurnPushButton->setText(QApplication::translate("MapWindow", "End Turn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapWindow: public Ui_MapWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWINDOW_H
