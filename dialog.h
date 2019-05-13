#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "administrador.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    Administrador getAdmi() const {return mAdmi;}

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;
    Administrador  mAdmi;
};

#endif // DIALOG_H
