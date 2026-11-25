#include "worker.h"
#include <QThread>
#include <QElapsedTimer>

Worker::Worker(QObject *parent)
    : QObject{parent}
{

}

void Worker::doWork(int totalSteps)
{
    QElapsedTimer timer;
    timer.start();
    m_working = true;

    // op : long time work
    for(int i = 0; i < totalSteps; ++i)
    {
        if (!m_working)
        {
            emit finished("[INFO]Task has been canceled");
            return;
        }
        QThread::msleep(100);  // 1s
        emit progressChanged(i+1, totalSteps);
    }
}

void Worker::cancel()
{
    m_working = false;
}

