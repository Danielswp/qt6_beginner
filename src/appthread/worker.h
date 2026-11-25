
#ifndef WORKER_H
#define WORKER_H


#include <QObject>


class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

public slots:
    void doWork(int totalSteps);
    void cancel();

signals:
    void progressChanged(int current, int total);
    void finished(const QString &result);

private:
    std::atomic<bool> m_working = false;

};

#endif // WORKER_H
