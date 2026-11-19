#ifndef MYMETAOBJ_H
#define MYMETAOBJ_H

#include <QObject>
#include <QDebug>

class MyMetaObj : public QObject
{
    Q_OBJECT

    //Q_PROPERTY(QString recycle READ recycle WRITE setRecycle);
    Q_PROPERTY(QString recycle READ recycle);

public:
    explicit MyMetaObj(QObject *parent = nullptr);
    ~MyMetaObj();

    QString recycle()const { return m_recycle; };


    Q_INVOKABLE void testCall()const { qDebug() << QString("[%1] : testCall")
                                        .arg(metaObject()->className());};

    Q_INVOKABLE void testCallParam1(const QString& p)const { qDebug() << QString("[%1] : testCallParam1 - %2")
                                        .arg(metaObject()->className())
                                        .arg(p);};

private:
    QString m_recycle;
    void setRecycle(const QString& c) { m_recycle = c; };
};

#endif // MYMETAOBJ_H
