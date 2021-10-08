#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mainview.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setView(MainView* view);



    ~MainWindow();

public slots:
    void defaultPosition();
    void viewPosition();
    void setLine();
    void lineRotation();
    void updatePosition();

private:
    Ui::MainWindow *ui;
    MainView* view;

    // Variables to hold eye coordinates
    float eyeAX;
    float eyeAY;
    float eyeAZ;

    // Variables to hold position coordinates
    float positionAX;
    float positionAY;
    float positionAZ;

    // Variable to hold u value
    float u;

    // Variable to hold rotation angle
    float viewangle;

    // Float arrays to hold floats
    float eye[3];
    float position[3];
    float b[3];
    float d[3];
};

#endif // MAINWINDOW_H
