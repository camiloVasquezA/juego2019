#include "mainwindow_juego.h"
#include "ui_mainwindow_juego.h"
#include <QGraphicsView>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include<string.h>
#include "niveles.h"
#include <QDebug>
#include "mainwindow.h"
using namespace std;
void MainWindow_juego::verificar()
{
    if(mArkanoid->getscena()->getvidas()==0){
        music->stop();
        QMessageBox::information(this,"Arkanoid","Fin del juego");
        mArkanoid->getscena()->setvidas(3);

        niveles *n=new niveles(nom1,punt);


        n->show();
        this->close();
    }


    if(mArkanoid->getscena()->nbloq==0 && mArkanoid->getscena()->puntaje!=0){
music->stop();
        QMessageBox::information(this,"Arkanoid","FELICIDADES");

        mArkanoid->getscena()->setvidas(3);
        t= mArkanoid->getscena()->puntaje;
       mArkanoid->getscena()->puntaje=0;
       punt+=t;


       niveles *n=(new niveles(nom1,t));


         n->show();
         this->close();
    }




    if(mArkanoid->getscena2()->getvidas()==0){
music->stop();
        QMessageBox::information(this,"Arkanoid","Felicidades");
        mArkanoid->getscena2()->setvidas(3);
        t=punt;
        niveles *n=new niveles(nom1,t);
        n->show();
        this->close();

    }
    if(mArkanoid->getscena2()->nbloq==0 && mArkanoid->getscena2()->puntaje==380){
       music->stop();
        QMessageBox::information(this,"Arkanoid","Fin del juego");
        mArkanoid->getscena2()->setvidas(3);
        t= mArkanoid->getscena2()->puntaje;
       mArkanoid->getscena2()->puntaje=0;
       t+=punt;

       niveles *n=(new niveles(nom1,t));
       n->show();
        this->close();

    }

    if(mArkanoid->getscena3()->getvidas()==0){
       music->stop();
       QMessageBox::information(this,"Arkanoid","Fin del juego");
       mArkanoid->getscena3()->setvidas(3);
       t=punt;
       niveles *n=new niveles(nom1,t);
       n->show();
       this->close();

    }

    if(mArkanoid->getscena3()->nbloq==0 && mArkanoid->getscena3()->puntaje==480){
       music->stop();
        QMessageBox::information(this,"Arkanoid","Fin del juego");
        t= mArkanoid->getscena3()->puntaje;
        mArkanoid->getscena3()->setvidas(3);
        mArkanoid->getscena3()->puntaje=0;
        t+=punt;
        niveles *n=new niveles(nom1,t);
        n->show();
        this->close();

    }

    if(mArkanoid->getscena4()->getvidas()==0){
        music->stop();
        QMessageBox::information(this,"Arkanoid","Fin del juego");

        mArkanoid->getscena4()->setvidas(3);
        t=punt;
        niveles *n=new niveles(nom1,t);
        n->show();
        this->close();

    }
    if(mArkanoid->getscena4()->nbloq==0&& mArkanoid->getscena4()->puntaje==340){
        music->stop();
        QMessageBox::information(this,"Arkanoid","Fin del juego");
        t= mArkanoid->getscena4()->puntaje;
        mArkanoid->getscena4()->setvidas(3);
        mArkanoid->getscena4()->puntaje=0;
        t+=punt;
        niveles *n=new niveles(nom1,t);
        n->show();
        this->close();

    }
    if(mArkanoid->getmulti()->getvidas()==0){
        music->stop();
        QMessageBox::information(this,"Arkanoid","Fin del juego");

        mArkanoid->getmulti()->setvidas(3);
        t+=punt;
        MainWindow *j=new MainWindow();
         j->show();
        this->close();
    }
    if(mArkanoid->getmulti()->getvidas()==0&& mArkanoid->getmulti()->puntaje==200){
        music->stop();
        QMessageBox::information(this,"Arkanoid","Felicidades");

        mArkanoid->getmulti()->setvidas(3);
        t+=punt;
       MainWindow *j=new MainWindow();
        j->show();
        this->close();
    }
}


MainWindow_juego::MainWindow_juego(QString nombre,int pun,int niv,QString puerto,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_juego)
{
    music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/juegoTheme.mp3"));
    music->setVolume(50);




    nom1=nombre;
    ui->setupUi(this);
    punt=pun;
    nivel=niv;
    puert=puerto;
    music->play();
    mArkanoid=new Arkanoid(nivel,ui->graphicsView,this);
    setCentralWidget(ui->graphicsView);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/nuevofondo.png")));
    timer=new QTimer();
   connect(timer,SIGNAL(timeout()),this,SLOT(verificar()));
    timer->start(50);
    timer_control=new QTimer();
    control=new QSerialPort(this);
    connect(timer_control,SIGNAL(timeout()),this,SLOT(Joy()));


    control->setPortName(puerto);
    //timer_control->start(100);
    if(control->open(QIODevice::ReadWrite)){
        //Ahora el puerto seria está abierto
        if(!control->setBaudRate(QSerialPort::Baud9600)) //Configurar la tasa de baudios
            qDebug()<<control->errorString();

        if(!control->setDataBits(QSerialPort::Data8))
            qDebug()<<control->errorString();

        if(!control->setParity(QSerialPort::NoParity))
            qDebug()<<control->errorString();

        if(!control->setStopBits(QSerialPort::OneStop))
            qDebug()<<control->errorString();

        if(!control->setFlowControl(QSerialPort::NoFlowControl))
            qDebug()<<control->errorString();
            timer_control->start(20);
    }
    else{
        qDebug()<<"Serial COM6 not opened. Error: "<<control->errorString();
    }
}

MainWindow_juego::~MainWindow_juego()
{
    delete ui;

}



void MainWindow_juego::on_actionQuitar_triggered()
{
    mArkanoid->stopGame();
    close();
}

void MainWindow_juego::on_actionIniciar_juego_triggered()
{
     mArkanoid->starGame();
}



void MainWindow_juego::Joy(){
        char data;
        int l = 0;
        bool flag=true;

           if(control->waitForReadyRead(100)){

                //Data was returned
                l = control->read(&data,1);
                switch (data) {

                case '0':
                   mArkanoid->getscena()->getplataform()->setx(mArkanoid->getscena()->getplataform()->getx()-(mArkanoid->getscena()->getplataform()->getvx())*2.0);
                   mArkanoid->getscena2()->getplataform()->setx(mArkanoid->getscena2()->getplataform()->getx()-(mArkanoid->getscena()->getplataform()->getvx())*2.0);
                   mArkanoid->getscena3()->getplataform()->setx(mArkanoid->getscena3()->getplataform()->getx()-(mArkanoid->getscena()->getplataform()->getvx())*2.0);
                   mArkanoid->getscena4()->getplataform()->setx(mArkanoid->getscena4()->getplataform()->getx()-(mArkanoid->getscena()->getplataform()->getvx())*2.0);

                    break;
                case '1':
                   mArkanoid->getscena()->getplataform()->setx(mArkanoid->getscena()->getplataform()->getx()-(mArkanoid->getscena()->getplataform()->getvx())*1.3);
                   mArkanoid->getscena2()->getplataform()->setx(mArkanoid->getscena2()->getplataform()->getx()-(mArkanoid->getscena()->getplataform()->getvx())*1.3);
                   mArkanoid->getscena3()->getplataform()->setx(mArkanoid->getscena3()->getplataform()->getx()-(mArkanoid->getscena()->getplataform()->getvx())*1.3);
                   mArkanoid->getscena4()->getplataform()->setx(mArkanoid->getscena4()->getplataform()->getx()-(mArkanoid->getscena()->getplataform()->getvx())*1.3);

                    break;
                case '2':
                   mArkanoid->getscena()->getplataform()->setx(mArkanoid->getscena()->getplataform()->getx()-(mArkanoid->getscena()->getplataform()->getvx()));
                   mArkanoid->getscena2()->getplataform()->setx(mArkanoid->getscena2()->getplataform()->getx()-(mArkanoid->getscena()->getplataform()->getvx()));
                   mArkanoid->getscena3()->getplataform()->setx(mArkanoid->getscena3()->getplataform()->getx()-(mArkanoid->getscena()->getplataform()->getvx()));
                   mArkanoid->getscena4()->getplataform()->setx(mArkanoid->getscena4()->getplataform()->getx()-(mArkanoid->getscena()->getplataform()->getvx()));
                    break;
                case '3':
                   mArkanoid->getscena()->getplataform()->setx(mArkanoid->getscena()->getplataform()->getx()+(mArkanoid->getscena()->getplataform()->getvx()));
                   mArkanoid->getscena2()->getplataform()->setx(mArkanoid->getscena2()->getplataform()->getx()+(mArkanoid->getscena()->getplataform()->getvx()));
                   mArkanoid->getscena3()->getplataform()->setx(mArkanoid->getscena3()->getplataform()->getx()+(mArkanoid->getscena()->getplataform()->getvx()));
                   mArkanoid->getscena4()->getplataform()->setx(mArkanoid->getscena4()->getplataform()->getx()+(mArkanoid->getscena()->getplataform()->getvx()));
                    break;
                case '4':
                  mArkanoid->getscena()->getplataform()->setx(mArkanoid->getscena()->getplataform()->getx()+(mArkanoid->getscena()->getplataform()->getvx())*1.3);
                  mArkanoid->getscena2()->getplataform()->setx(mArkanoid->getscena2()->getplataform()->getx()+(mArkanoid->getscena()->getplataform()->getvx())*1.3);
                  mArkanoid->getscena3()->getplataform()->setx(mArkanoid->getscena3()->getplataform()->getx()+(mArkanoid->getscena()->getplataform()->getvx())*1.3);
                  mArkanoid->getscena4()->getplataform()->setx(mArkanoid->getscena4()->getplataform()->getx()+(mArkanoid->getscena()->getplataform()->getvx())*1.3);

                    break;
                case 'X':
                    mArkanoid->getscena()->getplataform()->setx(mArkanoid->getscena()->getplataform()->getx()+(mArkanoid->getscena()->getplataform()->getvx())*2.0);
                    mArkanoid->getscena2()->getplataform()->setx(mArkanoid->getscena2()->getplataform()->getx()+(mArkanoid->getscena()->getplataform()->getvx())*2.0);
                    mArkanoid->getscena3()->getplataform()->setx(mArkanoid->getscena3()->getplataform()->getx()+(mArkanoid->getscena()->getplataform()->getvx())*2.0);
                    mArkanoid->getscena4()->getplataform()->setx(mArkanoid->getscena4()->getplataform()->getx()+(mArkanoid->getscena()->getplataform()->getvx())*2.0);
                    break;
                    break;

                case 'N':
                    flag=false;
                    break;
                default:
                    flag=false;
                    break;
                }

                qDebug()<<"Response: "<<data;
                flag=false;

            }else{
                //No data
                qDebug()<<"Time out";
          }
        //}
        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        //control->close();

}




