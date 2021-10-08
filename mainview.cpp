#include "scenebasic.h"
#include "mainview.h"

#include "glutils.h"
#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;


MainView::MainView(const QGLFormat & format, QWidget *parent) : QGLWidget(format, parent)
{
    // This tells the widget to accept keyboard focus when the widget is clicked.
    this->setFocusPolicy(Qt::ClickFocus);

    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(timerUpdate()) );
    timer->start(50);

    this->setMinimumSize(800,600);

}

void MainView::initializeGL()
{

    //////////////// PLUG IN SCENE HERE /////////////////
    scene = new SceneBasic();
    ////////////////////////////////////////////////////

    GLenum err = glewInit();
    if( GLEW_OK != err )
    {
        cout <<"Error initializing GLEW: " << glewGetErrorString(err) << endl;
    }
   // GLUtils::checkForOpenGLError(__FILE__,__LINE__);
     GLUtils::checkForOpenGLError();

    QGLFormat format = this->format();
    printf("QGLFormat reports profile: ");
    if( format.profile() == QGLFormat::CompatibilityProfile )
        printf("compatability.\n");
    else if( format.profile() == QGLFormat::CoreProfile )
        printf("core.\n");
    else
        printf("none.\n");

    GLUtils::dumpGLInfo();

    glClearColor(0.0f,0.0f,0.0f,1.0f);

    scene->initScene();
}

void MainView::paintGL()
{
    GLUtils::checkForOpenGLError();
    scene->render();
}

void MainView::resizeGL(int w, int h )
{
    scene->resize(w,h);
}

void MainView::toggleAnimation()
{
    if( timer->isActive() )
        timer->stop();
    else
        timer->start();
}


void MainView::defaultPosition()
{
    scene->defaultPosition();
    updateGL();
}

void MainView::setLine(float b[], float u, float d[])
{
    scene->setLine(b, u, d);
    updateGL();
}

void MainView::viewPosition(float A[], float B[])
{
    scene->viewPosition(A, B);
    updateGL();
}

void MainView::rotateView(float b[], float u, float d [], float viewangle)
{
    scene->rotateView(b, u, d, viewangle);
    updateGL();
}

void MainView::timerUpdate()
{
    scene->update();
    updateGL();
}

