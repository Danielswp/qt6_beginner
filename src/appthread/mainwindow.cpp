#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_workerThread = new QThread(this);
    m_worker = new Worker();

    m_worker->moveToThread(m_workerThread);

    connect(this, SIGNAL(startWork(int)), m_worker, SLOT(doWork(int)));
    //connect(this, SIGNAL(requestCancel()), m_worker, SLOT(cancel()), Qt::DirectConnection);
    connect(this, SIGNAL(requestCancel()), m_worker, SLOT(cancel()));

    connect(m_worker, &Worker::progressChanged, this, [this](int current, int total){
        ui->progressBar->setMaximum(total);
        ui->progressBar->setValue(current);
    });

    connect(m_worker, &Worker::finished, this, [this](const QString str){
        qDebug() << "[INFO]Task finish:!" << str;
        ui->pushButton->setEnabled(true);
    });

    connect(ui->pushButton, &QPushButton::clicked, this, [this]{
        ui->pushButton->setEnabled(false);
        emit startWork(50);
    });
    connect(ui->pushButton_2, &QPushButton::clicked, this, [this]{ emit requestCancel(); });
    m_workerThread->start();
}

MainWindow::~MainWindow()
{
    m_workerThread->quit();
    m_workerThread->wait();
    delete m_worker;
    delete ui;
}
