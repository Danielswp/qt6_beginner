#include "tperson.h"
#include <QDebug>

TPerson::TPerson(QString aName, QObject *parent)
    : QObject{parent}
{
    m_name = aName;
}

TPerson::~TPerson()
{
    qDebug() << "TPerson has been deleted!";
}

int TPerson::age()
{
    return m_age;
}

void TPerson::setAge(int value)
{
    if( m_age != value)
    {
        m_age = value;
        emit ageChanged(m_age);
    }
}

void TPerson::incAge()
{
    m_age++;
    emit ageChanged(m_age);
}


