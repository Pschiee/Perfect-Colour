/*! \mainpage This is the perfect colour software documentation. Contained here are all of the methods and classes used in the project.
 *  
 
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();

    return a.exec();
}
