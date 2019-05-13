#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::Dialog)
  , mAdmi(-1,"","")
{
    ui->setupUi(this);
    ui->ContralineEdit->setEchoMode(QLineEdit::Password);
    ui->RepetirContlineEdit->setEchoMode(QLineEdit::Password);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    mAdmi.sid(1);
    mAdmi.nombre(ui->UserrlineEdit->text());
    mAdmi.contra(ui->ContralineEdit->text());
    if(mAdmi.getcontra()!=ui->RepetirContlineEdit->text()){
        QMessageBox::critical(this,"Error","Las contraseñas deben ser iguales");
        return;
    }
    accept();


}

void Dialog::on_buttonBox_rejected()
{
    reject();
}
