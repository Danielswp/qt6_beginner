#ifndef TPERSONGUI_H
#define TPERSONGUI_H

#include <QWidget>
#include <QSpinBox>

#include "tperson.h"

namespace Ui {
class TPersonGUI;
}

class TPersonGUI : public QWidget
{
    Q_OBJECT

public:
    explicit TPersonGUI(QWidget *parent = nullptr);
    ~TPersonGUI();

private slots:
    void do_ageChanged(int value);
    void do_spinChanged(int arg1);

    void on_btnGrow_clicked(QSpinBox* box);
    void on_btnClassInfo_clicked();
    void on_btnClear_clicked();

private:
    Ui::TPersonGUI *ui;

    TPerson *boy;
    TPerson *girl;
};

#endif // TPERSONGUI_H
