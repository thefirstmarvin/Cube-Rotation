/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *OpenGL;
    QPushButton *ViewPosition;
    QPushButton *LineRotatioin;
    QPushButton *DefaultPosition;
    QDoubleSpinBox *angle;
    QDoubleSpinBox *u;
    QPushButton *updatePosition;
    QLabel *label;
    QLabel *label_15;
    QLabel *label_16;
    QGroupBox *groupBox_2;
    QDoubleSpinBox *eyeX;
    QLabel *label_7;
    QDoubleSpinBox *eyeY;
    QLabel *label_4;
    QDoubleSpinBox *eyeZ;
    QLabel *label_8;
    QGroupBox *groupBox;
    QDoubleSpinBox *positionX;
    QLabel *label_3;
    QDoubleSpinBox *positionY;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *positionZ;
    QGroupBox *groupBox_3;
    QLabel *label_9;
    QDoubleSpinBox *bX;
    QLabel *label_11;
    QDoubleSpinBox *bY;
    QLabel *label_10;
    QDoubleSpinBox *bZ;
    QGroupBox *groupBox_4;
    QLabel *label_12;
    QDoubleSpinBox *dX;
    QDoubleSpinBox *dY;
    QDoubleSpinBox *dZ;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1143, 702);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        OpenGL = new QWidget(centralWidget);
        OpenGL->setObjectName(QString::fromUtf8("OpenGL"));
        OpenGL->setGeometry(QRect(30, 0, 821, 641));
        ViewPosition = new QPushButton(centralWidget);
        ViewPosition->setObjectName(QString::fromUtf8("ViewPosition"));
        ViewPosition->setGeometry(QRect(1030, 190, 75, 23));
        LineRotatioin = new QPushButton(centralWidget);
        LineRotatioin->setObjectName(QString::fromUtf8("LineRotatioin"));
        LineRotatioin->setGeometry(QRect(990, 480, 111, 31));
        DefaultPosition = new QPushButton(centralWidget);
        DefaultPosition->setObjectName(QString::fromUtf8("DefaultPosition"));
        DefaultPosition->setGeometry(QRect(860, 570, 241, 41));
        angle = new QDoubleSpinBox(centralWidget);
        angle->setObjectName(QString::fromUtf8("angle"));
        angle->setGeometry(QRect(950, 430, 62, 22));
        u = new QDoubleSpinBox(centralWidget);
        u->setObjectName(QString::fromUtf8("u"));
        u->setGeometry(QRect(870, 430, 62, 22));
        updatePosition = new QPushButton(centralWidget);
        updatePosition->setObjectName(QString::fromUtf8("updatePosition"));
        updatePosition->setGeometry(QRect(1040, 420, 61, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(870, 60, 91, 16));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(940, 410, 47, 13));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(870, 410, 47, 13));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(860, 30, 241, 71));
        eyeX = new QDoubleSpinBox(groupBox_2);
        eyeX->setObjectName(QString::fromUtf8("eyeX"));
        eyeX->setGeometry(QRect(10, 40, 62, 22));
        eyeX->setMinimum(-15.000000000000000);
        eyeX->setValue(0.000000000000000);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 20, 47, 13));
        eyeY = new QDoubleSpinBox(groupBox_2);
        eyeY->setObjectName(QString::fromUtf8("eyeY"));
        eyeY->setGeometry(QRect(90, 40, 62, 22));
        eyeY->setMinimum(-14.000000000000000);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 20, 47, 13));
        eyeZ = new QDoubleSpinBox(groupBox_2);
        eyeZ->setObjectName(QString::fromUtf8("eyeZ"));
        eyeZ->setGeometry(QRect(170, 40, 62, 22));
        eyeZ->setMinimum(-16.000000000000000);
        eyeZ->setValue(0.000000000000000);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(170, 20, 47, 13));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(860, 110, 241, 71));
        positionX = new QDoubleSpinBox(groupBox);
        positionX->setObjectName(QString::fromUtf8("positionX"));
        positionX->setGeometry(QRect(10, 40, 62, 22));
        positionX->setMinimum(-20.000000000000000);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 47, 13));
        positionY = new QDoubleSpinBox(groupBox);
        positionY->setObjectName(QString::fromUtf8("positionY"));
        positionY->setGeometry(QRect(90, 40, 62, 22));
        positionY->setMinimum(-16.000000000000000);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 20, 47, 13));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(170, 20, 47, 13));
        positionZ = new QDoubleSpinBox(groupBox);
        positionZ->setObjectName(QString::fromUtf8("positionZ"));
        positionZ->setGeometry(QRect(170, 40, 62, 22));
        positionZ->setMinimum(-13.000000000000000);
        positionZ->setValue(0.000000000000000);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(860, 250, 241, 71));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 20, 47, 13));
        bX = new QDoubleSpinBox(groupBox_3);
        bX->setObjectName(QString::fromUtf8("bX"));
        bX->setGeometry(QRect(10, 40, 62, 22));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(80, 20, 47, 13));
        bY = new QDoubleSpinBox(groupBox_3);
        bY->setObjectName(QString::fromUtf8("bY"));
        bY->setGeometry(QRect(90, 40, 62, 22));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(170, 20, 47, 13));
        bZ = new QDoubleSpinBox(groupBox_3);
        bZ->setObjectName(QString::fromUtf8("bZ"));
        bZ->setGeometry(QRect(170, 40, 62, 22));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(860, 330, 241, 71));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 20, 47, 13));
        dX = new QDoubleSpinBox(groupBox_4);
        dX->setObjectName(QString::fromUtf8("dX"));
        dX->setGeometry(QRect(10, 40, 62, 22));
        dY = new QDoubleSpinBox(groupBox_4);
        dY->setObjectName(QString::fromUtf8("dY"));
        dY->setGeometry(QRect(90, 40, 62, 22));
        dZ = new QDoubleSpinBox(groupBox_4);
        dZ->setObjectName(QString::fromUtf8("dZ"));
        dZ->setGeometry(QRect(170, 40, 62, 22));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(90, 20, 47, 13));
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(170, 20, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(860, 610, 251, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1143, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(eyeX, SIGNAL(valueChanged(double)), MainWindow, SLOT(update()));
        QObject::connect(eyeY, SIGNAL(valueChanged(double)), MainWindow, SLOT(update()));
        QObject::connect(eyeZ, SIGNAL(valueChanged(double)), MainWindow, SLOT(update()));
        QObject::connect(positionX, SIGNAL(valueChanged(double)), MainWindow, SLOT(update()));
        QObject::connect(positionY, SIGNAL(valueChanged(double)), MainWindow, SLOT(update()));
        QObject::connect(positionZ, SIGNAL(valueChanged(double)), MainWindow, SLOT(update()));
        QObject::connect(ViewPosition, SIGNAL(pressed()), MainWindow, SLOT(viewPosition()));
        QObject::connect(dX, SIGNAL(valueChanged(double)), MainWindow, SLOT(update()));
        QObject::connect(dY, SIGNAL(valueChanged(double)), MainWindow, SLOT(update()));
        QObject::connect(dZ, SIGNAL(valueChanged(double)), MainWindow, SLOT(update()));
        QObject::connect(angle, SIGNAL(valueChanged(double)), MainWindow, SLOT(update()));
        QObject::connect(LineRotatioin, SIGNAL(pressed()), MainWindow, SLOT(lineRotation()));
        QObject::connect(DefaultPosition, SIGNAL(pressed()), MainWindow, SLOT(defaultPosition()));
        QObject::connect(updatePosition, SIGNAL(clicked()), MainWindow, SLOT(setLine()));
        QObject::connect(bZ, SIGNAL(valueChanged(double)), MainWindow, SLOT(update()));
        QObject::connect(bY, SIGNAL(valueChanged(double)), MainWindow, SLOT(update()));
        QObject::connect(bX, SIGNAL(valueChanged(double)), MainWindow, SLOT(update()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ViewPosition->setText(QCoreApplication::translate("MainWindow", "View Position", nullptr));
        LineRotatioin->setText(QCoreApplication::translate("MainWindow", "Line Rotate", nullptr));
        DefaultPosition->setText(QCoreApplication::translate("MainWindow", "Reset View", nullptr));
        updatePosition->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        label->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "angle", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "u", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Eye Coordinates", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "eye.X", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "eye.Y", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "eye.Z", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Point Coordinates", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "point.X", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "point.Y", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "point.Z", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Line Start Coordinates", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "b.X", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "b.Y", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "b.Z", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Line End Coordinates", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "d.X", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "d.Y", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "d.Z", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Ensure you update the line before you rotate it", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
