#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include "DuCrypt.h"
#include <QString>
#include <QMessageBox>
#include "mainwindow_juego.h"
#include "niveles.h"
#include <iostream>
#include <QFile>
#include <stdlib.h>
#include <map>
#include <string>
#include <vector>
#include <QTextStream>
#include <QDebug>
#include<QMediaPlayer>

using namespace std;




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    inicio->setMedia(QUrl("qrc:/Himno Colombiano 8 Bits.mp3"));
    inicio->setVolume(50);
    ui->setupUi(this);
    ui->contralineEdit_2->setEchoMode(QLineEdit::Password);

    inicio->play();




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_buttonBox_accepted()
{

//    bool esusuario=true;
//    int cant;


//    QSqlQuery q;
//         Usuario u(-1,ui->UsuariolineEdit->text(),ui->contralineEdit_2->text());

//            q.exec(QString("SELECT count(*) FROM usuario WHERE nombre LIKE '%1' AND "
//                           "contrasenya LIKE '%2'").arg((u.getnombre())).arg( (u.getcontra())));
//            q.next();
//           cant=q.value(0).toInt();
//           if(cant==0){
//               QMessageBox::warning(this,"Aviso","Usuario o contraseña incorrectos");
//               return;




//        }

    map<QString,vector<QString>> basedatos;
    map<QString,vector<QString>>::iterator itera;
    QFile base(("base.txt"));
    QString strin;
    base.open(QIODevice::ReadOnly | QIODevice::Text);


    strin=base.readAll();
    base.flush();
    base.close();
    int longi=strin.size();
    QString auxi;
    QString auxi2="usuario0";
    for(int i=0;i<longi;i++){
        if(strin[i]!=',' && strin[i]!=' ')
            auxi+=strin[i];
        else if(strin[i]==','){
            basedatos[auxi2].push_back(auxi);




            auxi="";

        }
        else if(strin[i]==' '){
            auxi2+=1;
        }

    }
    bool usuari=false, contrase=false;
    Usuario u(-1,ui->UsuariolineEdit->text(),ui->contralineEdit_2->text());
    QString nom;
    int punt;
    for(itera=basedatos.begin();itera!=basedatos.end();itera++){
        for(int i=0;i<itera->second.size();i++) {

            if(u.getnombre()==itera->second[i]){
                usuari=true;
                nom=itera->second[i];
                punt=itera->second[i+3].toInt();

            }
            else if(u.getcontra()==itera->second[i]&&u.getnombre()==itera->second[i-1])
                contrase=true;

        }
    }




    if(usuari==true &&contrase==true){

        niveles *n=new niveles(nom,punt);
        inicio->stop();
        n->show();
        this->close();
    }
    else{
        QMessageBox::warning(this,"Aviso","Usuario o contraseña incorrectos");

    }









   }




void MainWindow::on_buttonBox_rejected()
{
        close();
}

void MainWindow::on_RegistrarUsuariopushButton_clicked()
{

    Dialog d(this);
    if( d.exec()==QDialog::Rejected){
        return;
    }


QFile base(("base.txt"));
base.open(QIODevice::ReadWrite | QIODevice::Append);
  auto admi =  d.getAdmi();
 map<const QString,vector< QString>> basededatos;
 basededatos[admi.getnombre()].push_back(admi.getnombre());
 basededatos[admi.getnombre()].push_back(admi.getcontra());
 basededatos[admi.getnombre()].push_back("0");
  basededatos[admi.getnombre()].push_back("0");
 map<QString,vector<QString>>::iterator iter;




QTextStream usuari(&base);


 for(iter=basededatos.begin();iter!=basededatos.end();iter++){
     for(int i=0;i<basededatos[admi.getnombre()].size();i++){

         usuari<<iter->second[i]<<",";





     }

        usuari<<" ";
 }

 base.flush();
 base.close();





//  QSqlQuery q;
//  q.exec(QString("INSERT INTO usuario (nombre, contrasenya) VALUES ('%1','%2')")
//         .arg((admi.getnombre()))
//         .arg((admi.getcontra())));



}


void MainWindow::on_multi_clicked()
{
    MainWindow_juego *j=new MainWindow_juego("hola",1,4,"hola");
    j->show();
    this->close();
}
