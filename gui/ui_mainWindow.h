/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QGroupBox *intrinsicBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *mass2Edit;
    QLabel *label_3;
    QLineEdit *mass1Edit;
    QLineEdit *eccEdit;
    QLabel *label_4;
    QLabel *label;
    QWidget *widget_2;
    QLineEdit *smaEdit;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *plotTitle;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QCustomPlot *customPlot;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(675, 450);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        intrinsicBox = new QGroupBox(centralwidget);
        intrinsicBox->setObjectName(QString::fromUtf8("intrinsicBox"));
        gridLayout = new QGridLayout(intrinsicBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(intrinsicBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        mass2Edit = new QLineEdit(intrinsicBox);
        mass2Edit->setObjectName(QString::fromUtf8("mass2Edit"));
        mass2Edit->setMaximumSize(QSize(75, 16777215));

        gridLayout->addWidget(mass2Edit, 1, 1, 1, 1);

        label_3 = new QLabel(intrinsicBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        mass1Edit = new QLineEdit(intrinsicBox);
        mass1Edit->setObjectName(QString::fromUtf8("mass1Edit"));
        mass1Edit->setMaximumSize(QSize(75, 16777215));

        gridLayout->addWidget(mass1Edit, 0, 1, 1, 1);

        eccEdit = new QLineEdit(intrinsicBox);
        eccEdit->setObjectName(QString::fromUtf8("eccEdit"));
        eccEdit->setMaximumSize(QSize(75, 16777215));

        gridLayout->addWidget(eccEdit, 2, 1, 1, 1);

        label_4 = new QLabel(intrinsicBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label = new QLabel(intrinsicBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        widget_2 = new QWidget(intrinsicBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        gridLayout->addWidget(widget_2, 4, 0, 1, 1);

        smaEdit = new QLineEdit(intrinsicBox);
        smaEdit->setObjectName(QString::fromUtf8("smaEdit"));
        smaEdit->setMaximumSize(QSize(75, 16777215));

        gridLayout->addWidget(smaEdit, 3, 1, 1, 1);


        verticalLayout->addWidget(intrinsicBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        plotTitle = new QLabel(centralwidget);
        plotTitle->setObjectName(QString::fromUtf8("plotTitle"));
        plotTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(plotTitle);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(450, 350));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        customPlot = new QCustomPlot(frame);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));

        horizontalLayout_2->addWidget(customPlot);

        smaEdit->raise();
        customPlot->raise();

        verticalLayout_3->addWidget(frame);


        horizontalLayout->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 675, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Binary Explorer", 0, QApplication::UnicodeUTF8));
        intrinsicBox->setTitle(QApplication::translate("MainWindow", "Intrinsic Binary Info", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Mass 2:", 0, QApplication::UnicodeUTF8));
        mass2Edit->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Eccentricity:", 0, QApplication::UnicodeUTF8));
        mass1Edit->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        eccEdit->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Semi-Major Axis:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Mass 1:", 0, QApplication::UnicodeUTF8));
        smaEdit->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        plotTitle->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:xx-large; font-weight:600; font-style:italic; color:#ff0000;\">Orbit Plot</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
