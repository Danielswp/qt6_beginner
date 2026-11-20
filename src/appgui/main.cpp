//#include "widget.h"

#include "guidemo.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SWP_DEMO_GUI::runAllDemos();

    return a.exec();
}
