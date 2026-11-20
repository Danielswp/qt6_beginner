#include <QApplication>
#include <QDebug>


#include <QtGlobal>
#include <QtMath>
#include <QObject>

#include "metademo.h"


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

    SWP_DEMO_META::runAllDemos();



	app.exec();
}
