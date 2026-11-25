#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

class Worker;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void startWork(int totalSteps);
    void requestCancel();

private:
    Ui::MainWindow *ui;

    QThread *m_workerThread = nullptr;
    Worker *m_worker = nullptr;
};

#endif // MAINWINDOW_H
