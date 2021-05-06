/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *hex;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *info;
    QVBoxLayout *playerInfo;
    QHBoxLayout *pInfoName;
    QLabel *player1;
    QLabel *player2;
    QHBoxLayout *pInfoColor;
    QLabel *player1Life;
    QLabel *player2Life;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *nextMove;
    QLabel *label;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *action;
    QPushButton *confirm;
    QPushButton *unselect;
    QPushButton *rules;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *pos1;
    QLabel *itemTextPos1;
    QLabel *itemPos1;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *pos2;
    QLabel *itemTextPos2;
    QLabel *itemPos2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1158, 773);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 981, 561));
        hex = new QHBoxLayout(horizontalLayoutWidget);
        hex->setObjectName(QString::fromUtf8("hex"));
        hex->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 580, 981, 141));
        info = new QVBoxLayout(verticalLayoutWidget);
        info->setObjectName(QString::fromUtf8("info"));
        info->setContentsMargins(0, 0, 0, 0);
        playerInfo = new QVBoxLayout();
        playerInfo->setObjectName(QString::fromUtf8("playerInfo"));
        pInfoName = new QHBoxLayout();
        pInfoName->setObjectName(QString::fromUtf8("pInfoName"));
        player1 = new QLabel(verticalLayoutWidget);
        player1->setObjectName(QString::fromUtf8("player1"));
        player1->setAlignment(Qt::AlignCenter);

        pInfoName->addWidget(player1);

        player2 = new QLabel(verticalLayoutWidget);
        player2->setObjectName(QString::fromUtf8("player2"));
        player2->setAlignment(Qt::AlignCenter);

        pInfoName->addWidget(player2);


        playerInfo->addLayout(pInfoName);

        pInfoColor = new QHBoxLayout();
        pInfoColor->setObjectName(QString::fromUtf8("pInfoColor"));
        player1Life = new QLabel(verticalLayoutWidget);
        player1Life->setObjectName(QString::fromUtf8("player1Life"));
        player1Life->setAlignment(Qt::AlignCenter);

        pInfoColor->addWidget(player1Life);

        player2Life = new QLabel(verticalLayoutWidget);
        player2Life->setObjectName(QString::fromUtf8("player2Life"));
        player2Life->setAlignment(Qt::AlignCenter);

        pInfoColor->addWidget(player2Life);


        playerInfo->addLayout(pInfoColor);


        info->addLayout(playerInfo);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        info->addItem(verticalSpacer);

        nextMove = new QVBoxLayout();
        nextMove->setObjectName(QString::fromUtf8("nextMove"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        nextMove->addWidget(label);


        info->addLayout(nextMove);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(1010, 320, 121, 251));
        action = new QVBoxLayout(verticalLayoutWidget_2);
        action->setObjectName(QString::fromUtf8("action"));
        action->setContentsMargins(0, 0, 0, 0);
        confirm = new QPushButton(verticalLayoutWidget_2);
        confirm->setObjectName(QString::fromUtf8("confirm"));

        action->addWidget(confirm);

        unselect = new QPushButton(verticalLayoutWidget_2);
        unselect->setObjectName(QString::fromUtf8("unselect"));

        action->addWidget(unselect);

        rules = new QPushButton(verticalLayoutWidget_2);
        rules->setObjectName(QString::fromUtf8("rules"));

        action->addWidget(rules);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(1000, 100, 141, 91));
        pos1 = new QVBoxLayout(verticalLayoutWidget_3);
        pos1->setObjectName(QString::fromUtf8("pos1"));
        pos1->setContentsMargins(0, 0, 0, 0);
        itemTextPos1 = new QLabel(verticalLayoutWidget_3);
        itemTextPos1->setObjectName(QString::fromUtf8("itemTextPos1"));
        itemTextPos1->setAlignment(Qt::AlignCenter);

        pos1->addWidget(itemTextPos1);

        itemPos1 = new QLabel(verticalLayoutWidget_3);
        itemPos1->setObjectName(QString::fromUtf8("itemPos1"));
        itemPos1->setAlignment(Qt::AlignCenter);

        pos1->addWidget(itemPos1);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(1000, 200, 141, 91));
        pos2 = new QVBoxLayout(verticalLayoutWidget_4);
        pos2->setObjectName(QString::fromUtf8("pos2"));
        pos2->setContentsMargins(0, 0, 0, 0);
        itemTextPos2 = new QLabel(verticalLayoutWidget_4);
        itemTextPos2->setObjectName(QString::fromUtf8("itemTextPos2"));
        itemTextPos2->setAlignment(Qt::AlignCenter);

        pos2->addWidget(itemTextPos2);

        itemPos2 = new QLabel(verticalLayoutWidget_4);
        itemPos2->setObjectName(QString::fromUtf8("itemPos2"));
        itemPos2->setAlignment(Qt::AlignCenter);

        pos2->addWidget(itemPos2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1158, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        player1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        player2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        player1Life->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        player2Life->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        confirm->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        unselect->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        rules->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        itemTextPos1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        itemPos1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        itemTextPos2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        itemPos2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
