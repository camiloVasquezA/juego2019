#include "multijugador.h"
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
#define MILISECONDS 10



multijugador::multijugador(QObject *parent)
    :QGraphicsScene (0.0,0.0,XSIZE,YSIZE,parent)
{
    createObjects();
    confingureObjects();
    conectObjects();


}

void multijugador::startScene()
{
    mtimer->start();
}

void multijugador::stopScene()
{
    mtimer->terminate();
}

void multijugador::keyPressEvent(QKeyEvent *event)
{
    mplataform->move(event->key());
    mplataform2->move2(event->key());
}

void multijugador::keyReleaseEvent(QKeyEvent *event)
{
    event->accept();
}



void multijugador::createObjects()
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
    QString fiscal(":/morado.png");
    mtimer=new Timer(MILISECONDS, this);
    mball=new Ball_Item(XBALL,YBALL,WBALL,HBALL,VXBALL,VYBALL);
    mplataform=new Platafor_Item(XPLATAFORM,575,WPLATAFORM,HPLATAFORM, VXPLATAFORM,VYPLATAFORM);
    mplataform2=new Platafor_Item(XPLATAFORM,20,WPLATAFORM,HPLATAFORM, VXPLATAFORM,VYPLATAFORM);
    l1=new QGraphicsLineItem(0,614,1000,614);
    l2=new QGraphicsLineItem(0,0,1000,0);
    vida1=new vidas(20,615,30,40,0,0);
    vida2=new vidas(75,615,30,40,0,0);
    vida3=new vidas(130,615,30,40,0,0);
    int xb=100,yb=174,wb=80,hb=36;

    for(int i=0;i<5;i++){
            bloques.append(new bloque(xb,yb,wb,hb,0,0,amarilloq,amarillo));

            yb=yb+37;
         }
yb=174;
xb=xb+160;

for(int i=0;i<5;i++){
        bloques.append(new bloque(xb,yb,wb,hb,0,0,amarilloq,amarillo));

        yb=yb+37;
     }

yb=174;
xb=xb+400;
for(int i=0;i<5;i++){
        bloques.append(new bloque(xb,yb,wb,hb,0,0,azul,azul));

        yb=yb+37;
     }

yb=174;
xb=xb+160;
for(int i=0;i<5;i++){
        bloques.append(new bloque(xb,yb,wb,hb,0,0,azul,azul));

        yb=yb+37;
     }


}







void multijugador::confingureObjects()
{   addItem(mball);
    addItem(mplataform);
    addItem(mplataform2);
    addItem(l1);
    addItem(vida1);
    addItem(vida2);
    addItem(vida3);

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

void multijugador::conectObjects()
{
    connect(mtimer,&Timer::timeOut,this,&multijugador::updateScene);
}

void multijugador::updateScene()
{
    mball->move();
    if(mball->collidesWithItem(mplataform)){
       collisionsWhitbloque();



    }
    else if(mball->collidesWithItem(mplataform2)){
        collisionsWhitbloque();
    }
    else if(mball->collidesWithItem(l1) || mball->collidesWithItem(l2)){
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
        mplataform2->setx(XPLATAFORM);
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
            nbloques-=1;




        }
     else if(mball->collidesWithItem(bloques.at(i)->getlin1())){
             collinsWhitLine1();
             bloques.at(i)->setcambio(true);
             removeItem(bloques.at(i));
             removeItem(bloques.at(i)->getlin1());
             removeItem(bloques.at(i)->getlin2());
             bloques.removeAt(i);



    }
        else if(mball->collidesWithItem(bloques.at(i)->getlin2())){
            collinsWhitLine2();
            bloques.at(i)->setcambio(true);
            removeItem(bloques.at(i));
            removeItem(bloques.at(i)->getlin1());
            removeItem(bloques.at(i)->getlin2());
            bloques.removeAt(i);








       }



        }


 update();

}

void multijugador::checkoCollisions()
{
    int bvx=mball->getvx();
    int bvy=mball->getvy();
   const int pvx=mplataform->getvx();
  const  int pvy=mplataform->getvy();

    if(bvx>0&&bvy>0&&pvx>0&&pvy==0){
       bvx=D_Util::abs(bvx);
       bvy=-D_Util::abs(bvy);
    }

    else if(bvx<0&&bvy>0&&pvx>0&&pvy==0){
        bvx=-D_Util::abs(bvx);
        bvy=-D_Util::abs(bvy);

    }
    else if (bvx>0&&bvy>0&&pvx<0&&pvy==0) {
        bvx=D_Util::abs(bvx);
        bvy=-D_Util::abs(bvy)-0.5;

    }
    else if(bvx<0&&bvy>0&&pvx<0&&pvy==0){

       bvx=-D_Util::abs(bvx);
       bvy=-D_Util::abs(bvy)-0.5;
    }
    else if(bvx<0&&bvy<0&&pvx<0&&pvy==0){

       bvx=D_Util::abs(bvx);
       bvy=D_Util::abs(bvy)-0.5;
    }
    else if(bvx>0&&bvy<0&&pvx<0&&pvy==0){

       bvx=D_Util::abs(bvx);
       bvy=D_Util::abs(bvy)-0.5;
    }
    else if(bvx<0&&bvy<0&&pvx>0&&pvy==0){

       bvx=D_Util::abs(bvx);
       bvy=D_Util::abs(bvy)-0.5;
    }
    else if(bvx>0&&bvy<0&&pvx>0&&pvy==0){

       bvx=D_Util::abs(bvx);
       bvy=D_Util::abs(bvy)-0.5;
    }


    mball->setvx(bvx);
    mball->setvy(bvy);
}

void multijugador::collisionsWhitbloque()
{
    int bvx=mball->getvx();
    int bvy=mball->getvy();

    if(bvx>0&&bvy>0){
       bvx=D_Util::abs(bvx);
       bvy=-D_Util::abs(bvy);
    }

    else if(bvx<0&&bvy>0){
        bvx=-D_Util::abs(bvx);
        bvy=-D_Util::abs(bvy);

    }
    else if (bvx>0&&bvy<0) {
        bvx=D_Util::abs(bvx);
        bvy=D_Util::abs(bvy);


    }
    else if(bvx<0&&bvy<0){

       bvx=-D_Util::abs(bvx);
       bvy=D_Util::abs(bvy);
    }
  mball->setvx(bvx);
  mball->setvy(bvy);
    }

void multijugador::collinsWhitLine1(){

 int bvx=mball->getvx();
 int bvy=mball->getvy();
 if(bvx<0 && bvy<0){
     bvx=D_Util::abs(bvx);
     bvy=-D_Util::abs(bvy);

 }
 else if(bvx<0 && bvy>0){
     bvx=D_Util::abs(bvx);
     bvy=D_Util::abs(bvy);
 }

 mball->setvx(bvx);
 mball->setvy(bvy);


}

void multijugador::collinsWhitLine2()
{

    int bvx=mball->getvx();
    int bvy=mball->getvy();
    if(bvx>0 && bvy<0){
        bvx=-D_Util::abs(bvx);
        bvy=-D_Util::abs(bvy);

    }
    else if(bvx>0 && bvy>0){
        bvx=-D_Util::abs(bvx);
        bvy=D_Util::abs(bvy);
    }

    mball->setvx(bvx);
    mball->setvy(bvy);

}

bool multijugador::choqueBloque()
{   choque=true;
    bool choq=choque;
    choque=false;
    return  choq;

}

