#include "niveles.h"
#include "ui_niveles.h"
#include"mainwindow_juego.h"
#include "QString"
#include<QMainWindow>
#include <QMovie>
#include <iostream>
#include <QFile>
#include <stdlib.h>
#include <map>
#include <string>
#include <vector>
#include <QTextStream>
#include <QDebug>

using namespace std;

niveles::niveles( QString nombre,int pun,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::niveles)
{
   puntajeG+=pun;

   inicio2->setMedia(QUrl("qrc:/8 Bit Universe.mp3"));
   inicio2->setVolume(15);
   ui->setupUi(this);

name=nombre;
 //puerto=ui->lineEdit->text();

 QSize size(151,91);
 QMovie *mov=new QMovie(":/jostick.gif");
 inicio2->play();
ui->lcdNumber->display(puntajeG);
 mov->setScaledSize(size);
 ui->label_2->setMovie(mov);


 if(puntajeG<=520){
     map<QString,vector<QString>> basedatos;
     map<QString,vector<QString>>::iterator itera;
     QFile base(("base.txt"));
     QString strin;
     base.open(QIODevice::ReadOnly | QIODevice::Text);

     if (puntajeG==520){
         niv=1;

     }



     strin=base.readAll();
     base.flush();
     base.close();
     int longi=strin.size();
     QString auxi;
     QString usuario=name;
     for(int i=0;i<longi;i++){
         if(strin[i]!=',' && strin[i]!=' ')
             auxi+=strin[i];
         else if(strin[i]==','){
             basedatos[name].push_back(auxi);

             auxi="";

         }
         else if(strin[i]==' '){
             name+=1;
         }

     }
     for(itera=basedatos.begin();itera!=basedatos.end();itera++){
         for(int i=0;i<itera->second.size();i++) {
            basedatos[usuario][2]= QString::number(niv);
            basedatos[usuario][3]=QString::number(puntajeG);

         }
     }

     base.open(QIODevice::WriteOnly | QIODevice::Text);

      map<QString,vector<QString>>::iterator iter;
     QTextStream usuari(&base);


      for(iter=basedatos.begin();iter!=basedatos.end();iter++){
          for(int i=0;i<basedatos[usuario].size();i++){

              usuari<<iter->second[i]<<",";

          }

             usuari<<" ";
      }

      base.flush();
      base.close();}

 //2//
 if(puntajeG>=520&&puntajeG<=900){
     map<QString,vector<QString>> basedatos;
     map<QString,vector<QString>>::iterator itera;
     QFile base(("base.txt"));
     QString strin;
     base.open(QIODevice::ReadOnly | QIODevice::Text);
     if (puntajeG==900){
         niv=2;

     }
     strin=base.readAll();
     base.flush();
     base.close();
     int longi=strin.size();
     QString auxi;
     QString usuario=name;
     for(int i=0;i<longi;i++){
         if(strin[i]!=',' && strin[i]!=' ')
             auxi+=strin[i];
         else if(strin[i]==','){
             basedatos[name].push_back(auxi);

             auxi="";

         }
         else if(strin[i]==' '){
             name+=1;
         }

     }
     for(itera=basedatos.begin();itera!=basedatos.end();itera++){
         for(int i=0;i<itera->second.size();i++) {
            basedatos[usuario][2]= QString::number(niv);
            basedatos[usuario][3]=QString::number(puntajeG);

         }
     }

     base.open(QIODevice::WriteOnly | QIODevice::Text);

      map<QString,vector<QString>>::iterator iter;
     QTextStream usuari(&base);


      for(iter=basedatos.begin();iter!=basedatos.end();iter++){
          for(int i=0;i<basedatos[usuario].size();i++){

              usuari<<iter->second[i]<<",";

          }

             usuari<<" ";
      }

      base.flush();
      base.close();}

 //3//
 if(puntajeG>=900&&puntajeG<=1380){
     map<QString,vector<QString>> basedatos;
     map<QString,vector<QString>>::iterator itera;
     QFile base(("base.txt"));
     QString strin;
     base.open(QIODevice::ReadOnly | QIODevice::Text);
     if (puntajeG==1380){
         niv=3;

     }
     strin=base.readAll();
     base.flush();
     base.close();
     int longi=strin.size();
     QString auxi;
     QString usuario=name;
     for(int i=0;i<longi;i++){
         if(strin[i]!=',' && strin[i]!=' ')
             auxi+=strin[i];
         else if(strin[i]==','){
             basedatos[name].push_back(auxi);

             auxi="";

         }
         else if(strin[i]==' '){
             name+=1;
         }

     }
     for(itera=basedatos.begin();itera!=basedatos.end();itera++){
         for(int i=0;i<itera->second.size();i++) {
            basedatos[usuario][2]= QString::number(niv);
            basedatos[usuario][3]=QString::number(puntajeG);

         }
     }

     base.open(QIODevice::WriteOnly | QIODevice::Text);

      map<QString,vector<QString>>::iterator iter;
     QTextStream usuari(&base);


      for(iter=basedatos.begin();iter!=basedatos.end();iter++){
          for(int i=0;i<basedatos[usuario].size();i++){

              usuari<<iter->second[i]<<",";

          }

             usuari<<" ";
      }

      base.flush();
      base.close();}
 //4//
 if(puntajeG>=1380&&puntajeG<=1720){
     map<QString,vector<QString>> basedatos;
     map<QString,vector<QString>>::iterator itera;
     QFile base(("base.txt"));
     QString strin;
     base.open(QIODevice::ReadOnly | QIODevice::Text);
     if (puntajeG==1720){
         niv=3;

     }
     strin=base.readAll();
     base.flush();
     base.close();
     int longi=strin.size();
     QString auxi;
     QString usuario=name;
     for(int i=0;i<longi;i++){
         if(strin[i]!=',' && strin[i]!=' ')
             auxi+=strin[i];
         else if(strin[i]==','){
             basedatos[name].push_back(auxi);

             auxi="";

         }
         else if(strin[i]==' '){
             name+=1;
         }

     }
     for(itera=basedatos.begin();itera!=basedatos.end();itera++){
         for(int i=0;i<itera->second.size();i++) {
            basedatos[usuario][2]= QString::number(niv);
            basedatos[usuario][3]=QString::number(puntajeG);

         }
     }

     base.open(QIODevice::WriteOnly | QIODevice::Text);

      map<QString,vector<QString>>::iterator iter;
     QTextStream usuari(&base);


      for(iter=basedatos.begin();iter!=basedatos.end();iter++){
          for(int i=0;i<basedatos[usuario].size();i++){

              usuari<<iter->second[i]<<",";

          }

             usuari<<" ";
      }

      base.flush();
      base.close();}




 mov->start();


}

niveles::~niveles()
{
    delete ui;
}

void niveles::on_nivel1_clicked()
{

    if(niv==0||niv==1||niv==2||niv==3){
        niv_tem=0;
    MainWindow_juego *j=new MainWindow_juego(name,puntajeG,niv_tem,puerto);
    inicio2->stop();
    j->show();
    this->close();
}
    else {
        QMessageBox::information(this,"Arkanoid","TODAVIA NO");
    }
}

void niveles::on_nivel2_clicked()
{
    if(niv==1||niv==2||niv==3){
        niv_tem=1;
    MainWindow_juego *j=new MainWindow_juego(name,puntajeG,niv_tem,puerto);
    inicio2->stop();
    j->show();
    this->close();}

}

void niveles::on_nivel3_clicked()
{

    if(niv==2||niv==3){
        niv_tem=2;
MainWindow_juego *j=new MainWindow_juego(name,puntajeG,niv_tem,puerto);
    inicio2->stop();
    j->show();
    this->close();}


}

void niveles::on_nivel4_clicked()
{
   if(niv==3){
       niv_tem=3;
    MainWindow_juego *j=new MainWindow_juego(name,puntajeG,niv_tem,puerto);
    inicio2->stop();
    j->show();
    this->close();}
}


void niveles::on_pushButton_5_clicked()
{
    puerto=ui->lineEdit->text();
    ui->lineEdit->clear();
}


void  niveles ::sumapuntaje(int t){
    puntajeG+=t;
    //QMessageBox::information(this,"Arkanoid","Fin del juego");
}
int  niveles::getpuntaje(){
    return puntajeG;
}

void niveles::setnivel(int u)
{
    niv=u;
}

