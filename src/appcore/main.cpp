#include <QApplication>
#include <QDebug>
#include <QListWidget>
#include <QStandardItemModel>
#include <QTreeView>
#include <QList>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

    QStandardItemModel model;



    for(size_t i = 0; i < 4; ++i)
    {
        QList<QStandardItem*> list;
        for(size_t j = 0; j < 5; ++j)
        {
            QStandardItem* item = new QStandardItem;
            item->setData(QString("Item - {%1} , {%2}").arg(i).arg(j),Qt::DisplayRole);
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            list.push_back(item);
        }
        model.appendRow(list);
    }


    QTreeView w;
    w.setModel(&model);
    w.show();



    QPushButton btn("打开模态对话框");
    btn.show();

    QObject::connect(&btn, &QPushButton::clicked, [&]() {
        QDialog dlg(&btn);                 // 父窗口传进去
        dlg.setWindowTitle("模态对话框");
        dlg.setModal(true);                // exec() 其实默认就是模态，可省略

        QLabel label("这是一个模态弹窗");
        QPushButton ok("确定");
        QVBoxLayout layout(&dlg);
        layout.addWidget(&label);
        layout.addWidget(&ok);

        QObject::connect(&ok, &QPushButton::clicked, &dlg, &QDialog::accept);

        int ret = dlg.exec();              // ← 阻塞，后面的代码不执行
        if (ret == QDialog::Accepted)
            qDebug("用户点了确定");
    });



	app.exec();
}
