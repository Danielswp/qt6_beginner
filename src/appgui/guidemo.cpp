#include "guidemo.h"

#include <QDir>
#include <QFile>
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
#include <QTextBrowser>
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

#include <md4c-html.h>

QString markdownToHtml(const QString& md)
{
    std::string html;
    const QByteArray utf8 = md.toUtf8();

    md_html(utf8.constData(), (MD_SIZE)utf8.size(),
            [](const MD_CHAR* chunk, MD_SIZE size, void* ud) {
                static_cast<std::string*>(ud)->append(chunk, size);
            },
            &html,
            MD_DIALECT_GITHUB | MD_FLAG_NOHTML,  // NOHTML 防 XSS
            0);

    return QString::fromStdString(html);
}

void SWP_DEMO_GUI::runAllDemos()
{
    // demoCommonGUIButton();
    // demoCommonGUIInput();
    demo_3rdparty_md4c();
}

void SWP_DEMO_GUI::demoCommonGUIButton()
{
    QWidget *window = new QWidget();
    window->setFixedSize(400, 120);

    // QPushButton
    QPushButton *btn_pushButton = new QPushButton("PushButton", window);
    btn_pushButton->move(10, 10);
    QObject::connect(btn_pushButton, &QPushButton::clicked, [window]() { qDebug() << "PushButton clicked"; });

    // QCommanLinkButton
    QCommandLinkButton *btn_linkButton = new QCommandLinkButton("CommandButton", "Create a new project", window);
    btn_linkButton->setDescription("write here...");
    btn_linkButton->resize(140, 50);
    btn_linkButton->move(5, 35);

    // QToolButton
    QToolButton *btn_toolButton = new QToolButton(window);
    btn_toolButton->setIcon(QIcon("://images/avatar_bot_child.svg"));
    btn_toolButton->setText("toolBtn");
    btn_toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn_toolButton->setPopupMode(QToolButton::DelayedPopup);
    btn_toolButton->setAutoRaise(true);
    btn_toolButton->move(145, 10);
    QObject::connect(btn_toolButton, &QToolButton::clicked, [] { qDebug() << "ToolButton clicked"; });

    // QRadioButton
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

    // QCheckBox
    QCheckBox *btn_chkBox = new QCheckBox("light on/off", window);
    btn_chkBox->setChecked(true);
    btn_chkBox->move(310, 35);
    QObject::connect(btn_chkBox, &QCheckBox::toggled, [](bool checked){
       qDebug() << QString("Checked id : %1.").arg(checked);
    });

    // QDialogButtonBox
    QDialogButtonBox *btn_dialogBtnBox =
                new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, window);
    QObject::connect(btn_dialogBtnBox, &QDialogButtonBox::accepted, []{ qDebug() << "QDialogButtonBox accepted"; });
    QObject::connect(btn_dialogBtnBox, &QDialogButtonBox::rejected, []{ qDebug() << "QDialogButtonBox rejected"; });
    btn_dialogBtnBox->move(100,85);


    window->show();
}

void SWP_DEMO_GUI::demoCommonGUIInput()
{
    QWidget *window = new QWidget();
    window->setFixedSize(800, 600);

    // QComboBox
    QComboBox *combo = new QComboBox(window);
    combo->addItem("Option 1");
    combo->addItem("Option 2");
    combo->addItem("Option 3");
    combo->move(10, 10);
    QObject::connect(combo, QOverload<int>::of(&QComboBox::currentIndexChanged),
                     [](int index){ qDebug() << QString("QComboBox Index : %1").arg(index); });

    // QFontComboBox
    QFontComboBox *fontComboBox = new QFontComboBox(window);
    fontComboBox->setEditable(false);
    fontComboBox->move(110, 10);
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);
    fontComboBox->setWritingSystem(QFontDatabase::SimplifiedChinese);
    QLabel* label = new QLabel("测试test", window);
    label->move(270,15);
    QObject::connect(fontComboBox, &QFontComboBox::currentFontChanged, label, &QLabel::setFont);

    // QLineEdit
    QLineEdit *lineEdit = new QLineEdit(window);
    lineEdit->move(10, 60);
    QObject::connect(lineEdit, &QLineEdit::textChanged, [](const QString & str){
       qDebug() << QString("[Input]%1").arg(str);
    });

    // QFrame
    QFrame *frame = new QFrame(window);
    frame->setFrameShape(QFrame::Box);
    frame->setStyleSheet("border:1px solid #ccc; border-radius:6px;");
    frame->move(150, 60);

    // QTextEdit
    QTextEdit *textEdit = new QTextEdit(window);
    textEdit->resize(150,100);
    textEdit->move(250, 60);

    // QPlainTextEdit
    QPlainTextEdit *plainTextEdit = new QPlainTextEdit(window);
    //plainTextEdit->

    window->show();
}

void SWP_DEMO_GUI::demo_3rdparty_md4c()
{
    QString path = QDir::current().filePath("../../src/appgui/test.md");
    qDebug () << QString("[File]%1").arg(path);
    QFile file( path );
    QString str;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        str = file.readAll();
        qDebug() << str;
        file.close();
    }

    QString htmlstr = markdownToHtml(str);

    // QTextEdit *w = new QTextEdit();
    QTextBrowser *w = new QTextBrowser();
    w->resize(800, 600);
    w->setHtml(htmlstr);
    w->show();



    qDebug() << htmlstr;

}
