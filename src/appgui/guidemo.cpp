#include "guidemo.h"

#include <QDebug>
#include <QLabel>
#include <QWidget>

#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QAbstractButton>
#include <QPushButton>
#include <QToolButton>
#include <QRadioButton>
#include <QButtonGroup>
#include <QCheckBox>
#include <QCommandLinkButton>
#include <QDialogButtonBox>

#include <QComboBox>
#include <QFontComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTimeEdit>
#include <QDial>
#include <QScrollBar>
#include <QSlider>
#include <QKeySequence>



void SWP_DEMO_GUI::runAllDemos()
{
    // demoCommonGUIButton();
    demoCommonGUIInput();
}

void SWP_DEMO_GUI::demoCommonGUIButton()
{
    QWidget *window = new QWidget();
    window->setFixedSize(400, 120);

    QPushButton *btn_pushButton = new QPushButton("PushButton", window);
    btn_pushButton->move(10, 15);
    QObject::connect(btn_pushButton, &QPushButton::clicked, [window]() { qDebug() << "PushButton clicked"; });

    QToolButton *btn_toolButton = new QToolButton(window);
    btn_toolButton->setIcon(QIcon("://images/avatar_bot_child.svg"));
    btn_toolButton->setText("toolBtn");
    btn_toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn_toolButton->setPopupMode(QToolButton::DelayedPopup);
    btn_toolButton->setAutoRaise(true);
    btn_toolButton->move(110, 10);
    QObject::connect(btn_toolButton, &QToolButton::clicked, [] { qDebug() << "ToolButton clicked"; });

    QButtonGroup *btn_radioButtonGroup = new QButtonGroup(window);
    QRadioButton *btn_radioButton1 = new QRadioButton("man", window);
    QRadioButton *btn_radioButton2 = new QRadioButton("female", window);
    btn_radioButtonGroup->addButton(btn_radioButton1, 0);
    btn_radioButtonGroup->addButton(btn_radioButton2, 1);
    btn_radioButton1->move(210, 10);
    btn_radioButton2->move(210, 30);
    btn_radioButton1->setChecked(true);
    QObject::connect(btn_radioButtonGroup, &QButtonGroup::idClicked, [](int id){
       qDebug() << QString("Clicked id : %1.").arg(id);
    });

    QCheckBox *btn_chkBox = new QCheckBox("light on/off", window);
    btn_chkBox->setChecked(true);
    btn_chkBox->move(310, 35);
    QObject::connect(btn_chkBox, &QCheckBox::toggled, [](bool checked){
       qDebug() << QString("Checked id : %1.").arg(checked);
    });

    QDialogButtonBox *btn_dialogBtnBox =
                new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, window);
    QObject::connect(btn_dialogBtnBox, &QDialogButtonBox::accepted, []{ qDebug() << "QDialogButtonBox accepted"; });
    QObject::connect(btn_dialogBtnBox, &QDialogButtonBox::rejected, []{ qDebug() << "QDialogButtonBox rejected"; });
    btn_dialogBtnBox->move(100,80);


    window->show();
}

void SWP_DEMO_GUI::demoCommonGUIInput()
{
    QWidget *window = new QWidget();
    window->setFixedSize(800, 600);

    QComboBox *combo = new QComboBox(window);
    combo->addItem("Option 1");
    combo->addItem("Option 2");
    combo->addItem("Option 3");
    combo->move(10, 10);
    QObject::connect(combo, QOverload<int>::of(&QComboBox::currentIndexChanged),
                     [](int index){ qDebug() << QString("QComboBox Index : %1").arg(index); });

    QFontComboBox *fontComboBox = new QFontComboBox(window);
    fontComboBox->setEditable(false);
    fontComboBox->move(110, 10);
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);
    fontComboBox->setWritingSystem(QFontDatabase::SimplifiedChinese);
    QLabel* label = new QLabel("测试test", window);
    label->move(270,15);
    QObject::connect(fontComboBox, &QFontComboBox::currentFontChanged, label, &QLabel::setFont);

    QLineEdit *lineEdit = new QLineEdit(window);
    lineEdit->move(10, 60);
    QObject::connect(lineEdit, &QLineEdit::textChanged, [](const QString & str){
       qDebug() << QString("[Input]%1").arg(str);
    });

    QFrame *frame = new QFrame(window);
    frame->setFrameShape(QFrame::Box);
    frame->setStyleSheet("border:1px solid #ccc; border-radius:6px;");
    //frame->setGeometry(110, 60, 100, 50);
    frame->move(150, 60);

    window->show();
}
