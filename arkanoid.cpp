#include "arkanoid.h"
#include "my_scena.h"
#include "my_scena2.h"
#include "my_scena3.h"
#include "my_scena4.h"
#include <QGraphicsView>
#include <QMessageBox>

Arkanoid::Arkanoid(int niv,QGraphicsView *graphicsV, QObject *parent)
    :QObject (parent)
{


    mScene=new my_scena(this);
    mScene2=new my_scena2(this);
    mScene3=new my_scena3(this);
    mScene4=new my_scena4(this);
    multi=new multijugador(this);
    nivel=niv;

    if(nivel==0){
    graphicsV->setScene(mScene);


    }
    if(nivel==1){
        graphicsV->setScene(mScene2);

    }
    if(nivel==2){
    graphicsV->setScene(mScene3);

    }
    if(nivel==3){
        graphicsV->setScene(mScene4);

    }
    if(nivel==4){

        graphicsV->setScene(multi);
    }


}

void Arkanoid::starGame()
{

    if (nivel==0){
   mScene->startScene( );
    }

    if (nivel==1){
   mScene2->startScene( );
    }

    if (nivel==2){
   mScene3->startScene( );
    }

    if (nivel==3){
   mScene4->startScene( );
    }


    if (nivel==4){
   multi->startScene( );
    }


}

void Arkanoid::stopGame()
{
    mScene->stopScene();
}
