#include <QApplication>
#include <QDebug>
#include <QThread>
#include <QElapsedTimer>
#include "mainwindow.h"


int main(int argc, char** argv)
{
    QApplication a(argc, argv);

//    qDebug() << "Test";

    MainWindow w;
    w.show();


    return a.exec();
}
