#include <QApplication>
#include <QDebug>
#include <QtGlobal>
#include <QPushButton>

#include "mymetaobj.h"



int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

    QPushButton *btn = new QPushButton();
    const QMetaObject *metaPtr = btn->metaObject();
    const QMetaObject metaObj = btn->staticMetaObject;


    qDebug() << metaPtr->className();
    qDebug() << metaObj.className();

    qDebug() << QString(10,'=');
    qDebug() << metaPtr->metaType();
    qDebug() << metaPtr->superClass()->className();
    qDebug() << metaPtr->inherits(metaPtr->superClass());

    qDebug() << QString(10,'=');

    MyMetaObj obj;
    bool ok = obj.setProperty("recycle","gun");

    if (ok)
        qDebug() << QString("[INFO]: Recycle item : %1").arg(obj.property("recycle").toString());
    else
        qDebug() << QString("[WARNING]: Can't recycle item : %1").arg(obj.property("recycle").toString());

    QMetaObject::invokeMethod(&obj, "testCall");
    QMetaObject::invokeMethod(&obj, "testCallParam1", Q_ARG(QString, "lulu"));

	app.exec();
}
