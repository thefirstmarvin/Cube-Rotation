#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGLFormat format;
    format.setVersion(4,0);
    format.setProfile(QGLFormat::CoreProfile);

    MainView *glView = new MainView (format);
    setView(glView);
    QVBoxLayout *mainLayout = new QVBoxLayout(ui->OpenGL);
    mainLayout->addWidget(glView);
}

void MainWindow::setView(MainView* view)
{
    this->view = view;
}

void MainWindow::defaultPosition()
{
    view->defaultPosition();
}

void MainWindow::viewPosition()
{
    // Stores floats of eye inputs in an array
    eye[0] = ui->eyeX->value();
    eye[1] = ui->eyeY->value();
    eye[2] = ui->eyeZ->value();

    // Stores floats of position inputs in an array
    position[0] = ui->positionX->value();
    position[1] = ui->positionY->value();
    position[2] = ui->positionZ->value();

    // Change view to prescribed position
    view->viewPosition(eye, position);
    std::cout<< eye[0] << eye[1] << eye[2] << std::endl;
}

void MainWindow::setLine()
{
    // Store floats of line start in an array
    b[0] = ui->bX->value();
    b[1] = ui->bY->value();
    b[2] = ui->bZ->value();

    // Store floats of line end in an array
    d[0] = ui->dX->value();
    d[1] = ui->dY->value();
    d[2] = ui->dZ->value();

    // Store float of u
    u = ui->u->value();

    // Setup the line as prescribed by the user
    view->setLine(b, u, d);
    view->updateGL();
}

void MainWindow::lineRotation()
{
    // Store float of the angle
    viewangle = ui->angle->value();

    // Rotate Line around b+ud at an angle of viewangle
    view->rotateView (b, u, d, viewangle);
}

void MainWindow::updatePosition()
{
    // Update the line before rotating the cube by updating the GL
    view->updateGL();
}

MainWindow::~MainWindow()
{
    delete ui;
}
