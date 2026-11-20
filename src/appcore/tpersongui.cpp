#include "tpersongui.h"
#include "ui_tpersongui.h"
#include <QMetaProperty>

TPersonGUI::TPersonGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TPersonGUI)
{
    ui->setupUi(this);

    boy = new TPerson("Sword", this);
    boy->setProperty("score", 90);
    boy->setProperty("age", 16);
    boy->setProperty("sex", "Boy");
    connect(boy, &TPerson::ageChanged, this, &TPersonGUI::do_ageChanged);

    girl = new TPerson("Apple", this);
    girl->setProperty("score", 80);
    girl->setProperty("age", 13);
    girl->setProperty("sex", "Girl");
    connect(girl, &TPerson::ageChanged, this, &TPersonGUI::do_ageChanged);

    ui->spinBox->setProperty("isBoy", true);
    ui->spinBox_2->setProperty("isBoy", false);
    connect(ui->spinBox, &QSpinBox::valueChanged, this, &TPersonGUI::do_spinChanged);
    connect(ui->spinBox_2, &QSpinBox::valueChanged, this, &TPersonGUI::do_spinChanged);
    connect(ui->pushButton, &QPushButton::clicked, this, [&](){ on_btnGrow_clicked(ui->spinBox); });
    connect(ui->pushButton_3, &QPushButton::clicked, this, [&](){ on_btnGrow_clicked(ui->spinBox_2); });
    connect(ui->pushButton_4, &QPushButton::clicked,this, &TPersonGUI::on_btnClear_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &TPersonGUI::on_btnClassInfo_clicked);

    ui->spinBox->setValue(boy->property("age").toInt());
    ui->spinBox_2->setValue(girl->property("age").toInt());


}

TPersonGUI::~TPersonGUI()
{
    delete ui;
}

void TPersonGUI::do_ageChanged(int value)
{
    TPerson *person = qobject_cast<TPerson *>(sender());
    QString hisName = person->property("name").toString();
    QString hisScore = person->property("score").toString();
    QString hisSex = person->property("sex").toString();
    int hisAge = person->property("age").toInt();

    QString str = QString("{\"Name\":\"%1\",\"Sex\":\"%2\",\"score\":%3,\"age\":%4}")
            .arg(hisName)
            .arg(hisSex)
            .arg(hisScore)
            .arg(hisAge);

    ui->textEdit->append(str);
}

void TPersonGUI::do_spinChanged(int arg1)
{
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(sender());
    if  (spinBox->property("isBoy").toBool())
        boy->setAge(arg1);
    else
        girl->setAge(arg1);
}

void TPersonGUI::on_btnGrow_clicked(QSpinBox* box)
{
    box->setValue(box->value()+1);
}

void TPersonGUI::on_btnClassInfo_clicked()
{
    if(!boy)return;

    const QMetaObject *metaObject = boy->metaObject();
    QString className =  metaObject->className();
    ui->textEdit->append(QString(20,'-'));
    ui->textEdit->append(QString("Meta Object ClassName: %1").arg(className));
    for(size_t i = metaObject->propertyOffset(); i != metaObject->propertyCount(); ++i)
    {
        QMetaProperty metaProp = metaObject->property(i);
        QString metaPropName = metaProp.name();
        QString metaPropValue = boy->property(metaProp.name()).toString();
        ui->textEdit->append(QString("Meta Object Property { name : %1, value : %2 }").arg(metaPropName).arg(metaPropValue));
    }
    for(size_t i = metaObject->classInfoOffset(); i!= metaObject->classInfoCount(); ++i)
    {
        QMetaClassInfo classInfo = metaObject->classInfo(i);
        ui->textEdit->append(QString("Meta Object ClassInfo { name : %1, value : %2 }").arg(classInfo.name()).arg(classInfo.value()));
    }
    ui->textEdit->append(QString(20,'-'));
}

void TPersonGUI::on_btnClear_clicked()
{
    ui->textEdit->clear();
}
