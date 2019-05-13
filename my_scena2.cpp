#include "my_scena2.h"
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
#include<qmath.h>
#define MILISECONDS 10



my_scena2::my_scena2(QObject *parent)
    :QGraphicsScene (0.0,0.0,XSIZE,YSIZE,parent)
{
    createObjects();
    confingureObjects();
    conectObjects();




    nestor=new QMediaPlayer();
    nestor->setMedia(QUrl("qrc:/coima.mp3"));
    nestor->setVolume(100);


    base=new QMediaPlayer();
    base->setMedia(QUrl("qrc:/Rebote pelota 2D-[AudioTrimmer.com].mp3"));
    base->setVolume(30);


    choques=new QMediaPlayer();
    choques->setMedia(QUrl("qrc:/GOLPE DE BATE BASEBALL.mp3"));
    choques->setVolume(20);

}

void my_scena2::startScene()
{
    mtimer->start();
    timer1->mov(1);
    timer1->start();
}

void my_scena2::stopScene()
{
    mtimer->terminate();
    timer1->terminate();
}

void my_scena2::keyPressEvent(QKeyEvent *event)
{
    mplataform->move(event->key());
}

void my_scena2::keyReleaseEvent(QKeyEvent *event)
{
    event->accept();
}

void my_scena2::createObjects()
{
    mtimer=new Timer(MILISECONDS, this);
    timer1=new Timer(12, this);
    QString amarillo(":/amarillo.png");
    QString amarilloq(":/amarillo.png");
    QString morado(":/verde.png");
    QString moradoq(":/verde.png");
    QString azul(":/azul.png");
    QString azulq(":/azul.png");
    QString rojo(":/rojo.png");
    QString verde(":/morado.png");
    QString fiscal(":/1-juego (2).png");
    mtimer=new Timer(MILISECONDS, this);
    mball=new Ball_Item(XBALL,YBALL,WBALL,HBALL,VXBALL,VYBALL);
    mplataform=new Platafor_Item(XPLATAFORM,575,WPLATAFORM,HPLATAFORM, VXPLATAFORM,VYPLATAFORM);
    l1=new QGraphicsLineItem(0,614,1000,614);
    vida1=new vidas(20,615,30,40,0,0);
    vida2=new vidas(75,615,30,40,0,0);
    vida3=new vidas(130,615,30,40,0,0);

    int xb=100,yb=100,wb=80,hb=36;
libre =new bloque(10,500,66,66,0,0,fiscal,fiscal);
    for(int i=0;i<7;i++){
            bloques.append(new bloque(xb,yb,wb,hb,0,0,amarilloq,amarillo));

            yb=yb+37;
         }
yb=100;
xb=xb+160;

for(int i=0;i<7;i++){
        bloques.append(new bloque(xb,yb,wb,hb,0,0,amarilloq,amarillo));

        yb=yb+37;
     }

yb=100;
xb=xb+400;
for(int i=0;i<7;i++){
        bloques.append(new bloque(xb,yb,wb,hb,0,0,azul,azul));

        yb=yb+37;
     }

yb=100;
xb=xb+160;
for(int i=0;i<7;i++){
        bloques.append(new bloque(xb,yb,wb,hb,0,0,azul,azul));

        yb=yb+37;
     }
yb=50;
xb=100;

for(int i=0;i<10;i++){
        bloques.append(new bloque(xb,yb,wb,hb,0,0,rojo,rojo));

        xb=xb+80;
     }
}




void my_scena2::confingureObjects()
{   addItem(mball);
    addItem(mplataform);
    addItem(l1);
    addItem(vida1);
    addItem(vida2);
    addItem(vida3);
    addItem(libre);
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

void my_scena2::conectObjects()
{

    ruta=calcularut();
      //addPolygon(QPolygonF(ruta));
    m_index=0;
    connect(mtimer,&Timer::timeOut,this,&my_scena2::updateScene);
    connect(timer1,&Timer::timeOut,[&]() {
        if(m_index==ruta.size()-1){
            m_index=0;
        }

       const double x=ruta.at(m_index).x();
       const double y=ruta.at(m_index).y();
       libre->setx(x);
       libre->sety(y);

       update();
       ++m_index;

   });
}

void my_scena2::updateScene()
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
            nbloq-=1;
            puntaje+=10;




        }
     else if(mball->collidesWithItem(bloques.at(i)->getlin1())){
             collinsWhitLine1();
             bloques.at(i)->setcambio(true);
             removeItem(bloques.at(i));
             removeItem(bloques.at(i)->getlin1());
             removeItem(bloques.at(i)->getlin2());
             bloques.removeAt(i);
             nbloq-=1;
             puntaje+=10;





    }
        else if(mball->collidesWithItem(bloques.at(i)->getlin2())){
            collinsWhitLine2();
            bloques.at(i)->setcambio(true);
            removeItem(bloques.at(i));
            removeItem(bloques.at(i)->getlin1());
            removeItem(bloques.at(i)->getlin2());
            bloques.removeAt(i);
            nbloq-=1;
            puntaje+=10;










       }



        }

    if(mball->collidesWithItem(libre)){
          collisionsWhitbloque();
          removeItem(libre->getlin1());
          removeItem(libre->getlin2());
          nestor->play();
      }
      else if(mball->collidesWithItem(libre->getlin1())){
          collinsWhitLine1();
          removeItem(libre->getlin1());
          removeItem(libre->getlin2());
          nestor->play();
      }
      else if(mball->collidesWithItem(libre->getlin2())){
          collinsWhitLine2();
          removeItem(libre->getlin1());
          removeItem(libre->getlin2());
          nestor->play();
      }
 update();

}

void my_scena2::checkoCollisions()
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

void my_scena2::collisionsWhitbloque()
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

void my_scena2::collinsWhitLine1(){

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

void my_scena2::collinsWhitLine2()
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

bool my_scena2::choqueBloque()
{   choque=true;
    bool choq=choque;
    choque=false;
    return  choq;

}

QVector<QPointF> my_scena2::calcularut() const
{
    QVector<QPointF> rut;
      for(double x=230; x<=XSIZE-230;x+=0.5){
  //       const double h=XSIZE/2;
  //       const double k=YSIZE;
  //       const double p=10.0;

          double h=XSIZE/2;
          double k=200;
          double p=-50;
          double y=0;
            y=-qPow(x-h,2.0)/(4*p)+k;
//          y=(sin(x/5)*50)+400;

         rut <<QPointF(x,y);
      }

      return rut;
}
