/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGridLayout *tiles;
    QGridLayout *controls;
    QWidget *gridWidget;
    QGridLayout *gridLayout_2;
    QPushButton *turn;
    QPushButton *up;
    QPushButton *down;
    QPushButton *downleft;
    QPushButton *right;
    QPushButton *upright;
    QPushButton *upleft;
    QPushButton *downright;
    QPushButton *left;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName("horizontalLayout");
        tiles = new QGridLayout();
        tiles->setSpacing(0);
        tiles->setObjectName("tiles");
        tiles->setSizeConstraint(QLayout::SetFixedSize);

        horizontalLayout->addLayout(tiles);

        controls = new QGridLayout();
        controls->setObjectName("controls");
        controls->setSizeConstraint(QLayout::SetFixedSize);
        controls->setContentsMargins(-1, 150, 0, 250);
        gridWidget = new QWidget(centralwidget);
        gridWidget->setObjectName("gridWidget");
        gridWidget->setMaximumSize(QSize(633, 16777215));
        gridWidget->setCursor(QCursor(Qt::CursorShape::BlankCursor));
        gridWidget->setStyleSheet(QString::fromUtf8("border-image: none;"));
        gridLayout_2 = new QGridLayout(gridWidget);
        gridLayout_2->setSpacing(4);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_2->setContentsMargins(-1, -1, -1, 9);
        turn = new QPushButton(gridWidget);
        turn->setObjectName("turn");
        turn->setEnabled(true);
        turn->setMinimumSize(QSize(45, 45));
        turn->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        turn->setStyleSheet(QString::fromUtf8("border-image: url(:/textures/arrows/arrow_skip.png);"));

        gridLayout_2->addWidget(turn, 1, 1, 1, 1);

        up = new QPushButton(gridWidget);
        up->setObjectName("up");
        up->setEnabled(true);
        up->setMinimumSize(QSize(45, 45));
        up->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        up->setStyleSheet(QString::fromUtf8("border-image: url(:/textures/arrows/arrow_up.png);"));

        gridLayout_2->addWidget(up, 0, 1, 1, 1);

        down = new QPushButton(gridWidget);
        down->setObjectName("down");
        down->setEnabled(true);
        down->setMinimumSize(QSize(45, 45));
        down->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        down->setStyleSheet(QString::fromUtf8("border-image: url(:/textures/arrows/arrow_down.png);"));

        gridLayout_2->addWidget(down, 2, 1, 1, 1);

        downleft = new QPushButton(gridWidget);
        downleft->setObjectName("downleft");
        downleft->setEnabled(true);
        downleft->setMinimumSize(QSize(45, 45));
        downleft->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        downleft->setStyleSheet(QString::fromUtf8("border-image: url(:/textures/arrows/arrow_down_left.png);"));

        gridLayout_2->addWidget(downleft, 2, 0, 1, 1);

        right = new QPushButton(gridWidget);
        right->setObjectName("right");
        right->setEnabled(true);
        right->setMinimumSize(QSize(45, 45));
        right->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        right->setStyleSheet(QString::fromUtf8("border-image: url(:/textures/arrows/arrow_right.png);"));

        gridLayout_2->addWidget(right, 1, 2, 1, 1);

        upright = new QPushButton(gridWidget);
        upright->setObjectName("upright");
        upright->setEnabled(true);
        upright->setMinimumSize(QSize(45, 45));
        upright->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        upright->setStyleSheet(QString::fromUtf8("border-image: url(:/textures/arrows/arrow_up_right.png);"));

        gridLayout_2->addWidget(upright, 0, 2, 1, 1);

        upleft = new QPushButton(gridWidget);
        upleft->setObjectName("upleft");
        upleft->setEnabled(true);
        upleft->setMinimumSize(QSize(45, 45));
        upleft->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        upleft->setStyleSheet(QString::fromUtf8("border-image: url(:/textures/arrows/arrow_up_left.png);"));

        gridLayout_2->addWidget(upleft, 0, 0, 1, 1);

        downright = new QPushButton(gridWidget);
        downright->setObjectName("downright");
        downright->setEnabled(true);
        downright->setMinimumSize(QSize(45, 45));
        downright->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        downright->setStyleSheet(QString::fromUtf8("border-image: url(:/textures/arrows/arrow_down_right.png);"));

        gridLayout_2->addWidget(downright, 2, 2, 1, 1);

        left = new QPushButton(gridWidget);
        left->setObjectName("left");
        left->setEnabled(true);
        left->setMinimumSize(QSize(45, 45));
        left->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        left->setStyleSheet(QString::fromUtf8("border-image: url(:/textures/arrows/arrow_left.png);"));

        gridLayout_2->addWidget(left, 1, 0, 1, 1);


        controls->addWidget(gridWidget, 0, 0, 1, 1);


        horizontalLayout->addLayout(controls);

        horizontalLayout->setStretch(0, 6);
        horizontalLayout->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        turn->setText(QString());
        up->setText(QString());
        down->setText(QString());
        downleft->setText(QString());
        right->setText(QString());
        upright->setText(QString());
        upleft->setText(QString());
        downright->setText(QString());
        left->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
