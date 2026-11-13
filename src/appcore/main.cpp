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

            item->setData(i+j, Qt::EditRole);
            item->setData(QString("Item - i:%1 , j:%2").arg(i).arg(j), Qt::DisplayRole);
            item->setData(QString("(%1, %2)").arg(i).arg(j), Qt::ToolTipRole);
            item->setData(QColor(
                (i + j) * 25,
                (3 * i) * 20,
                (7 * j) * 8
            ), Qt::DecorationRole);

            //item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            list.push_back(item);
        }
        model.appendRow(list);
    }






//        for(size_t i = 0; i < 4; ++i)
//        {
//            QList<QStandardItem*> list;
//            for(size_t j = 0; j < 5; ++j)
//            {
//                QStandardItem* item = new QStandardItem;
//                item->setData(QString("Item - i:{%1} , j:{%2}").arg(i).arg(j),Qt::DisplayRole);
//                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
//                list.push_back(item);
//            }
//            model.appendRow(list);
//        }


    QTreeView w;
    w.setModel(&model);
    w.resize(800,600);
    w.show();




	app.exec();
}
