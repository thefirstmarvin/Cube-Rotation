#include "C:/glew-2.1.0/include/GL/glew.h"
#include <QApplication>
#include <QMainWindow>

#include "mainview.h"
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *window = new MainWindow();

    window->show();
    return app.exec();
}
