#include "containerdemo.h"
#include <QDebug>

#include <QList>
#include <QStack>
#include <QQueue>

#include <QSet>
#include <QMap>
#include <QMultiMap>

#include <QVariant>
#include <QRandomGenerator>
#include <QDateTime>

void SWP_DEMO_CONTAINER::runAllDemos()
{
    demoSequenceContainer();
    demoAssociativeContainer();
    demoBasicConatiner();
}

void SWP_DEMO_CONTAINER::demoSequenceContainer()
{
    QList<int> list;
    list << 10 << 22;
    qDebug() << list;

    // QList 的两个子类 QStack 和 QQueue
    QStack<int> stack;      // FILO
    stack << 7 << 8 << 9;
    stack.push(10);
    stack.pop();
    stack.pop();
    qDebug() << stack;

    QQueue<int> queue;      // FIFO
    queue << 11 << 22 << 33;
    queue.enqueue(88);
    queue.dequeue();
    qDebug() << queue;

}

void SWP_DEMO_CONTAINER::demoAssociativeContainer()
{
    // 无序，查找，插入/删除 O(1), 哈希表
    QSet<QString> set;
    set << "rg35xx" << "NS2" << "NDS" << "PS5";
    qDebug() << QString("Device list : NS2 => %1").arg(set.contains("NS2"));
    qDebug() << QString("Device list : GBA => %1").arg(set.contains("GBA"));

    // key ：value
    // 有序，查找，插入/删除 O(nlogn), 红黑树
    QMap<QString, int> map;
    map.insert("rg35xx", 300);
    map.insert("NS2", 2000);
    map.insert("NDS", 500);
    map.insert("PS5", 5000);
    qDebug() << map;

    // key ：value1; key ：value2; key ：value3; ...
    QMultiMap<QString, QString> multi_map;
    multi_map.insert("NS2", "Super Mario World");
    multi_map.insert("NS2", "The Legend of Zelda: A Link to the Past");
    multi_map.insert("NS2", "Dragon Quest V / VI");
    multi_map.insert("NS2", "Pocket Monsters Red / Green");
    auto [begin, end] = multi_map.equal_range("NS2");
    for(auto it = begin; it != end; ++it)
    {
        qDebug () << QString("[%1]  %2").arg(it.key()).arg(it.value());
    }

    // 无序，查找，插入/删除 O(1), 哈希表
    QHash<QString, QString> hash;
    hash.insert("Windows 10 Professional (Pro)", "W269N-WFGWX-YVC9B-4J6C9-T83GX");
    hash.insert("Windows 10 Home", "TX9XD-98N7V-6WMQ6-BX7FG-H8Q99");
    hash.insert("Windows 10 Enterprise", "NPPR9-FWDCX-D2C8J-H872K-2YT43");
    hash.insert("Windows 10 Education", "NW6C2-QMPVW-D7KKK-3GKT6-VCFB2");
    for(auto it = hash.begin(); it != hash.end(); ++it)
    {
        qDebug() << QString("[%1]  %2").arg(it.key()).arg(it.value());
    }
}

namespace Item {
    enum Option {
        Mask_1 = 0x00000001,
        Mask_2 = 0x00000010,
        Mask_3 = 0x00000100,
        Mask_4 = 0x00001000,
        Mask_5 = 0x00010000,
        Mask_6 = 0x00100000,
        Mask_7 = 0x01000000,
        Mask_8 = 0x10000000,
    };
    Q_DECLARE_FLAGS(Options, Option)
}
Q_DECLARE_OPERATORS_FOR_FLAGS(Item::Options)


void SWP_DEMO_CONTAINER::demoBasicConatiner()
{
    QVariant var("445");
    qDebug() << QString("%1, %2, %3").arg(var.toInt()).arg(var.toBool()).arg(var.toString());


    Item::Options o = Item::Mask_2 | Item::Mask_4 | Item::Mask_5;
    qDebug() << o;


    int n = QRandomGenerator::global()->bounded(1, 101);
    qDebug() << n;
    qDebug() << QString(20,'-');

    quint32 seed = QDateTime::currentMSecsSinceEpoch();
    QRandomGenerator rng(seed);
    qDebug() << rng.bounded(1, 101);   // 每次运行都不一样
    qDebug() << QString(20,'-');

    QRandomGenerator rng_fixed(12345);       // 固定种子
    for (int i = 0; i < 5; ++i)
        qDebug() << rng_fixed.bounded(1, 101);
    qDebug() << QString(20,'-');
}
