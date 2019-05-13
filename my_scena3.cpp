#include "my_scena3.h"
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



my_scena3::my_scena3(QObject *parent)
    :QGraphicsScene (0.0,0.0,XSIZE,YSIZE,parent)
{
    createObjects();
    confingureObjects();
    conectObjects();



    duque=new QMediaPlayer();
    duque->setMedia(QUrl("qrc:/marrano.mp3"));
    duque->setVolume(100);


    base=new QMediaPlayer();
    base->setMedia(QUrl("qrc:/Rebote pelota 2D-[AudioTrimmer.com].mp3"));
    base->setVolume(30);


    choques=new QMediaPlayer();
    choques->setMedia(QUrl("qrc:/GOLPE DE BATE BASEBALL.mp3"));
    choques->setVolume(20);
}

void my_scena3::startScene()
{
    mtimer->start();
}

void my_scena3::stopScene()
{
    mtimer->terminate();
}

void my_scena3::keyPressEvent(QKeyEvent *event)
{
    mplataform->move(event->key());
}

void my_scena3::keyReleaseEvent(QKeyEvent *event)
{
    event->accept();
}

void my_scena3::createObjects()
{
    mtimer=new Timer(MILISECONDS, this);
    QString amarillo(":/amarillo.png");
    QString amarilloq(":/amarillo.png");
    QString morado(":/verde.png");
    QString moradoq(":/verde.png");
    QString azul(":/azul.png");
    QString azulq(":/azul.png");
    QString rojo(":/rojo.png");
    QString verde(":/morado.png");
    QString duq(":/1-juego (1).png");
    mtimer=new Timer(MILISECONDS, this);
    mball=new Ball_Item(XBALL,YBALL,WBALL,HBALL,3.5,3.3);
    mplataform=new Platafor_Item(XPLATAFORM,575,WPLATAFORM,HPLATAFORM, VXPLATAFORM,VYPLATAFORM);
    l1=new QGraphicsLineItem(0,614,1000,614);
    vida1=new vidas(20,615,30,40,0,0);
    vida2=new vidas(75,615,30,40,0,0);
    vida3=new vidas(130,615,30,40,0,0);
    int xb=100,yb=50,wb=80,hb=36;

    marrano1=new bloque(470,210,66,66,0,0,duq,duq);

    yb=100;
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
yb=400;
xb=100;
for(int i=0;i<10;i++){
        bloques.append(new bloque(xb,yb,wb,hb,0,0,rojo,rojo));

        xb=xb+80;
     }

//    for (int i=1;i<=4; i++){
//           for(int j=1;j < i*2 ; j++ )
//              bloques.append(new bloque(xb,yb,wb,hb,0,0,amarilloq,amarillo));
//           xb=xb+82;
//           yb=yb+39;

//       }
//    xb=182;
//    yb=50;
//    for (int i=1;i<=4; i++){
//           for(int j=1;j < i*2 ; j++ )
//              bloques.append(new bloque(xb,yb,wb,hb,0,0,amarilloq,amarillo));
//           xb=xb+82;
//           yb=yb+39;

//       }
//    xb=262;
//    yb=52;
//    for (int i=1;i<=4; i++){
//           for(int j=1;j < i*2 ; j++ )
//              bloques.append(new bloque(xb,yb,wb,hb,0,0,morado,morado));
//           xb=xb+85;
//           yb=yb+39;

//       }
//    xb=342;
//    yb=52;
//    for (int i=1;i<=4; i++){
//           for(int j=1;j < i*2 ; j++ )
//              bloques.append(new bloque(xb,yb,wb,hb,0,0,morado,morado));
//           xb=xb+85;
//           yb=yb+39;

//       }
//    xb=420;
//    yb=52;
//    for (int i=1;i<=4; i++){
//           for(int j=1;j < i*2 ; j++ )
//              bloques.append(new bloque(xb,yb,wb,hb,0,0,verde,verde));
//           xb=xb+82;
//           yb=yb+39;

//       }
//    xb=502;
//    yb=52;
//    for (int i=1;i<=4; i++){
//           for(int j=1;j < i*2 ; j++ )
//              bloques.append(new bloque(xb,yb,wb,hb,0,0,verde,verde));
//           xb=xb+82;
//           yb=yb+39;

//       }
//    xb=582;
//    yb=52;
//    for (int i=1;i<=4; i++){
//           for(int j=1;j < i*2 ; j++ )
//              bloques.append(new bloque(xb,yb,wb,hb,0,0,rojo,rojo));
//           xb=xb+85;
//           yb=yb+39;

//       }
//    //////////////////////////////////////////////////////////////////
//    yb=270;
//    xb=100;
//    for(int i=0;i<3;i++){
//            bloques.append(new bloque(xb,yb,wb,hb,0,0,amarilloq,amarillo));

//            yb=yb+40;
//         }
//yb=270;
//xb=xb+180;

//for(int i=0;i<3;i++){
//        bloques.append(new bloque(xb,yb,wb,hb,0,0,morado,morado));

//        yb=yb+40;
//     }
//yb=270;
//xb=xb+180;

//for(int i=0;i<1;i++){
//        bloques.append(new bloque(xb,yb,wb,hb,0,0,rojo,rojo));

//        yb=yb+40;
//     }
//yb=270;
//xb=xb+180;

//for(int i=0;i<3;i++){
//        bloques.append(new bloque(xb,yb,wb,hb,0,0,morado,morado));

//        yb=yb+40;
//     }
//yb=270;
//xb=xb+180;

//for(int i=0;i<3;i++){
//        bloques.append(new bloque(xb,yb,wb,hb,0,0,amarillo,amarillo));

//        yb=yb+40;
//     }
}

void my_scena3::confingureObjects()

    {   addItem(mball);
        addItem(mplataform);
        addItem(l1);
        addItem(vida1);
        addItem(vida2);
        addItem(vida3);
        addItem(marrano1);

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

    void my_scena3::conectObjects()
    {


        connect(mtimer,&Timer::timeOut,this,&my_scena3::updateScene);

    }

    void my_scena3::updateScene()
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

        if(mball->collidesWithItem(marrano1)){
              collisionsWhitbloque();
              removeItem(marrano1->getlin1());
              removeItem(marrano1->getlin2());
              duque->play();
          }
          else if(mball->collidesWithItem(marrano1->getlin1())){
              collinsWhitLine1();
              removeItem(marrano1->getlin1());
              removeItem(marrano1->getlin2());
              duque->play();
          }
          else if(mball->collidesWithItem(marrano1->getlin2())){
              collinsWhitLine2();
              removeItem(marrano1->getlin1());
              removeItem(marrano1->getlin2());
              duque->play();
          }
     update();

    }

    void my_scena3::checkoCollisions()
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

    void my_scena3::collisionsWhitbloque()
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

    void my_scena3::collinsWhitLine1(){

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

    void my_scena3::collinsWhitLine2()
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

    bool my_scena3::choqueBloque()
    {   choque=true;
        bool choq=choque;
        choque=false;
        return  choq;

    }

