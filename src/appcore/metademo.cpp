#include "metademo.h"

#include <QApplication>
#include <QDebug>
#include <QMetaObject>
#include <QPushButton>
#include <QMetaProperty>

#include "mymetaobj.h"

void SWP_DEMO_META::demoMetaObject()
{
    QPushButton btn;                          // 栈上就够，别 new
    const QMetaObject *metaPtr = btn.metaObject();
    const QMetaObject &metaObj = QPushButton::staticMetaObject;

    qDebug() << "== QMetaObject ==";
    qDebug() << "className :" << metaPtr->className();
    qDebug() << "className :" << metaObj.className();
    qDebug() << "metaType  :" << metaPtr->metaType();          // QMetaType 的 id
    qDebug() << "superClass:" << metaPtr->superClass()->className();
    qDebug() << "inherits  :" << metaPtr->inherits(metaPtr->superClass());

    // 顺手把整条继承链和所有属性/方法列出来，学习时特别有用
    for (const QMetaObject *m = metaPtr; m; m = m->superClass()) {
        qDebug() << "  chain:" << m->className();
    }
}

void SWP_DEMO_META::demoProperty()
{
    qDebug() << "== Q_PROPERTY ==";
    MyMetaObj obj;

    obj.setProperty("recycle", QStringLiteral("gun"));   // Qt6: void

    const QString v = obj.property("recycle").toString();
    if (!v.isEmpty())
        qDebug() << QStringLiteral("[INFO]: Recycle item : %1").arg(v);
    else
        qDebug() << QStringLiteral("[WARNING]: Can't recycle item");

    // 遍历全部属性：学元对象必看
    const QMetaObject *mo = obj.metaObject();
    for (int i = 0; i < mo->propertyCount(); ++i) {
        QMetaProperty p = mo->property(i);
        qDebug() << "  prop:" << p.name() << "writable:" << p.isWritable();
    }
}

void SWP_DEMO_META::demoInvoke()
{
    qDebug() << "== invokeMethod ==";
    MyMetaObj obj;

    // 字符串版：运行期查找，写错只返回 false
    bool ok = QMetaObject::invokeMethod(&obj, "testCall");
    qDebug() << "testCall ->" << ok;

    ok = QMetaObject::invokeMethod(&obj, "testCallParam1",
                                   Q_ARG(QString, QStringLiteral("lulu")));
    qDebug() << "testCallParam1 ->" << ok;

    // Qt6 模板版（若 testCallParam1 是 public 且签名已知）：编译期检查，推荐
    // QMetaObject::invokeMethod(&obj, &MyMetaObj::testCallParam1,
    //                           Qt::DirectConnection, QStringLiteral("lulu"));
}

void SWP_DEMO_META::runAllDemos()
{
    demoMetaObject();
    demoProperty();
    demoInvoke();
}
