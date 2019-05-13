#include "my_scena4.h"
#include "global_defines.h"
#include "timer.h"
#include <QKeyEvent>
#include "ball_item.h"
#include "platafor_item.h"
#include "d_util.h"
#include <QGraphicsLineItem>
#include <QMessageBox>
#include <QString>
#include <QPixmap>
#include "vidas.h"
#include<QMediaPlayer>
#define MILISECONDS 10



my_scena4::my_scena4(QObject *parent)
    :QGraphicsScene (0.0,0.0,XSIZE,YSIZE,parent)
{
    createObjects();
    confingureObjects();
    conectObjects();



    uribe=new QMediaPlayer();
    uribe->setMedia(QUrl("qrc:/U.mp3"));
    uribe->setVolume(100);


    base=new QMediaPlayer();
    base->setMedia(QUrl("qrc:/Rebote pelota 2D-[AudioTrimmer.com].mp3"));
    base->setVolume(30);


    choques=new QMediaPlayer();
    choques->setMedia(QUrl("qrc:/GOLPE DE BATE BASEBALL.mp3"));
    choques->setVolume(20);

}

void my_scena4::startScene()
{
    mtimer->start();
    timer1->mov(1);
    timer1->start();
}

void my_scena4::stopScene()
{
    mtimer->terminate();
}

void my_scena4::keyPressEvent(QKeyEvent *event)
{
    mplataform->move(event->key());
}

void my_scena4::keyReleaseEvent(QKeyEvent *event)
{
    event->accept();
}

void my_scena4::createObjects()
{
    timer1=new Timer(5, this);
    mtimer=new Timer(MILISECONDS, this);
    QString amarillo(":/amarillo.png");
    QString amarilloq(":/amarillo.png");
    QString morado(":/verde.png");
    QString moradoq(":/verde.png");
    QString azul(":/azul.png");
    QString azulq(":/azul.png");
    QString rojo(":/rojo.png");
    QString verde(":/morado.png");
    QString urib(":/Sin_titulo-1.png");
    mtimer=new Timer(MILISECONDS, this);
    mball=new Ball_Item(XBALL,YBALL,WBALL,HBALL,5,5);
    mplataform=new Platafor_Item(XPLATAFORM,575,WPLATAFORM,HPLATAFORM, VXPLATAFORM,VYPLATAFORM);
    l1=new QGraphicsLineItem(0,614,1000,614);
    vida1=new vidas(20,615,30,40,0,0);
    vida2=new vidas(75,615,30,40,0,0);
    vida3=new vidas(130,615,30,40,0,0);
    int xb=68,yb=50,wb=80,hb=36;
   uribeprin =new bloque(10,400,66,84,0,0,urib,urib);
   uribe1=new bloque(160,95,45,57,0,0,urib,urib);
   uribe2=new bloque(320,95,45,57,0,0,urib,urib);
   uribe3=new bloque(480,95,45,57,0,0,urib,urib);
   uribe4=new bloque(640,95,45,57,0,0,urib,urib);
   uribe5=new bloque(800,95,45,57,0,0,urib,urib);
for (int i=0 ;i<11;i++){
            bloques.append(new bloque(xb,yb,wb,hb,0,0,amarilloq,amarillo));
            xb=xb+80;
            //xb=xb+80;
  }

yb=yb+37;
xb=68;
for (int i=0 ;i<6;i++){
            bloques.append(new bloque(xb,yb,wb,hb,0,0,amarilloq,amarillo));
            xb=xb+80;
            xb=xb+80;
  }

yb=yb+37;
xb=68;
for (int i=0 ;i<6;i++){
            bloques.append(new bloque(xb,yb,wb,hb,0,0,azul,azul));
            xb=xb+80;
            xb=xb+80;
  }
yb=yb+37;
xb=68;

for (int i=0 ;i<11;i++){
            bloques.append(new bloque(xb,yb,wb,hb,0,0,rojo,rojo));
            xb=xb+80;
            //xb=xb+80;
  }
}

void my_scena4::confingureObjects()
{    addItem(mball);
     addItem(mplataform);
     addItem(l1);
     addItem(vida1);
     addItem(vida2);
     addItem(vida3);
     addItem(uribe1);
     addItem(uribe2);
     addItem(uribe3);
     addItem(uribe4);
     addItem(uribe5);
     addItem(uribeprin);

     addItem(bloques.last());
     addItem(bloques.last()->getlin1());
     addItem(bloques.last()->getlin2());
     for(int i=0;i<bloques.length();i++){
         addItem( bloques.at(i));
         addItem(bloques.at(i)->getlin1());
         addItem(bloques.at(i)->getlin2());
     }


     addRect(0.0,0.0,XSIZE,YSIZE,QPen(QColor(Qt::blue)));
 }

 void my_scena4::conectObjects()
 {
     ruta=calcularut();

     m_index=0;
     connect(mtimer,&Timer::timeOut,this,&my_scena4::updateScene);
     connect(timer1,&Timer::timeOut,[&]() {
         if(m_index==ruta.size()-1){
             m_index=0;
         }

        const double x=ruta.at(m_index).x();
        const double y=ruta.at(m_index).y();
        uribeprin->setx(x);
        uribeprin->sety(y);

        update();
        ++m_index;

    });
 }

 void my_scena4::updateScene()
 {

     mball->move();
     if(mball->collidesWithItem(mplataform)){
         checkoCollisions();



     }
     else if(mball->collidesWithItem(l1)){
         mtimer->terminate();

         vida-=1;
         if(vida==2)
             removeItem(vida3);
         else if(vida==1)
             removeItem(vida2);
         else if(vida==0)
             removeItem(vida1);



         mball->setx(XSIZE/2);
         mball->sety(YSIZE/2);
         mplataform->setx(XPLATAFORM);
     }
     for(int i=0; i<bloques.length();i++){
         if(bloques.at(i)->collidesWithItem(mball)){
             collisionsWhitbloque();
             bloques.at(i)->setcambio(true);


             removeItem(bloques.at(i));
             removeItem(bloques.at(i)->getlin1());
             removeItem(bloques.at(i)->getlin2());
             bloques.removeAt(i);
             puntaje+=10;
             nbloq-=1;



         }
      else if(mball->collidesWithItem(bloques.at(i)->getlin1())){
              collinsWhitLine1();
              bloques.at(i)->setcambio(true);
              removeItem(bloques.at(i));
              removeItem(bloques.at(i)->getlin1());
              removeItem(bloques.at(i)->getlin2());
              bloques.removeAt(i);
              puntaje+=10;
              nbloq-=1;



     }
         else if(mball->collidesWithItem(bloques.at(i)->getlin2())){
             collinsWhitLine2();
             bloques.at(i)->setcambio(true);
             removeItem(bloques.at(i));
             removeItem(bloques.at(i)->getlin1());
             removeItem(bloques.at(i)->getlin2());
             bloques.removeAt(i);
             puntaje+=10;
             nbloq-=1;








        }



         }

     if(mball->collidesWithItem(uribeprin)||mball->collidesWithItem(uribe1)||mball->collidesWithItem(uribe2)||mball->collidesWithItem(uribe3)||mball->collidesWithItem(uribe4)||mball->collidesWithItem(uribe5)){
           collisionsWhitbloque();
           removeItem(uribeprin->getlin1());
           removeItem(uribeprin->getlin2());
           uribe->play();
       }
 //      else if(mball->collidesWithItem(marrano->getlin1())){
 //          collinsWhitLine1();
 //          removeItem(marrano->getlin1());
 //          removeItem(marrano->getlin2());
 //          duque->play();
 //      }
 //      else if(mball->collidesWithItem(marrano->getlin2())){
 //          collinsWhitLine2();
 //          removeItem(marrano->getlin1());
 //          removeItem(marrano->getlin2());
 //          duque->play();
 //      }


  update();

 }

 void my_scena4::checkoCollisions()
 {

     int bvx=mball->getvx();
     int bvy=mball->getvy();
    const int pvx=mplataform->getvx();
   const  int pvy=mplataform->getvy();

     if(bvx>0&&bvy>0&&pvx>0&&pvy==0){
        bvx=D_Util::abs(bvx);
        bvy=-D_Util::abs(bvy);
        base->play();
     }

     else if(bvx<0&&bvy>0&&pvx>0&&pvy==0){
         bvx=-D_Util::abs(bvx);
         bvy=-D_Util::abs(bvy);
         base->play();
     }
     else if (bvx>0&&bvy>0&&pvx<0&&pvy==0) {
         bvx=D_Util::abs(bvx);
         bvy=-D_Util::abs(bvy)-0.5;
         base->play();

     }
     else if(bvx<0&&bvy>0&&pvx<0&&pvy==0){

        bvx=-D_Util::abs(bvx);
        bvy=-D_Util::abs(bvy)-0.5;
        base->play();
     }

     mball->setvx(bvx);
     mball->setvy(bvy);
 }

 void my_scena4::collisionsWhitbloque()
 {
     int bvx=mball->getvx();
     int bvy=mball->getvy();

     if(bvx>0&&bvy>0){
        bvx=D_Util::abs(bvx);
        bvy=-D_Util::abs(bvy);
        choques->play();
     }

     else if(bvx<0&&bvy>0){
         bvx=-D_Util::abs(bvx);
         bvy=-D_Util::abs(bvy);
         choques->play();

     }
     else if (bvx>0&&bvy<0) {
         bvx=D_Util::abs(bvx);
         bvy=D_Util::abs(bvy);
         choques->play();


     }
     else if(bvx<0&&bvy<0){

        bvx=-D_Util::abs(bvx);
        bvy=D_Util::abs(bvy);
        choques->play();
     }
   mball->setvx(bvx);
   mball->setvy(bvy);
     }

 void my_scena4::collinsWhitLine1(){

  int bvx=mball->getvx();
  int bvy=mball->getvy();
  if(bvx<0 && bvy<0){
      bvx=D_Util::abs(bvx);
      bvy=-D_Util::abs(bvy);
      choques->play();
  }
  else if(bvx<0 && bvy>0){
      bvx=D_Util::abs(bvx);
      bvy=D_Util::abs(bvy);
      choques->play();
  }

  mball->setvx(bvx);
  mball->setvy(bvy);


 }

 void my_scena4::collinsWhitLine2()
 {

     int bvx=mball->getvx();
     int bvy=mball->getvy();
     if(bvx>0 && bvy<0){
         bvx=-D_Util::abs(bvx);
         bvy=-D_Util::abs(bvy);
         choques->play();

     }
     else if(bvx>0 && bvy>0){
         bvx=-D_Util::abs(bvx);
         bvy=D_Util::abs(bvy);
          choques->play();
     }

     mball->setvx(bvx);
     mball->setvy(bvy);

 }

 bool my_scena4::choqueBloque()
 {   choque=true;
     bool choq=choque;
     choque=false;
     return  choq;

 }



 QVector<QPointF> my_scena4::calcularut() const
 {
     QVector<QPointF> rut;
       for(double x=-10; x<=XSIZE;x+=0.5){


           double h=XSIZE/2+400;
           double k=500+100;
           double p=-400;
           double y=0;

           y=(sin(x/50)*30)+300;

          rut <<QPointF(x,y);
       }

       return rut;
 }

