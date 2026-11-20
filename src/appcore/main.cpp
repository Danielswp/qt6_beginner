#include "metademo.h"
#include "containerdemo.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

    //SWP_DEMO_META::runAllDemos();
    SWP_DEMO_CONTAINER::runAllDemos();



	app.exec();
}
