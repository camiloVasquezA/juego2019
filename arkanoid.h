#ifndef ARKANOID_H
#define ARKANOID_H
#include "my_scena.h"
#include "my_scena2.h"
#include "my_scena3.h"
#include "my_scena4.h"
#include "multijugador.h"
#include <QObject>
#include<QMediaPlayer>


class my_scena;
class my_scena2;
class my_scena3;
class my_scena4;
class multijugador;
class QGraphicsView;

class Arkanoid: public QObject
{
public:

    Arkanoid(int nivel,QGraphicsView *graphicsV, QObject *parent=nullptr);
    void starGame();
    void stopGame();
    bool getperdio(){return perdio;}

  my_scena* getscena(){

      return  mScene;
}

  my_scena2* getscena2(){

      return  mScene2;
}

  my_scena3* getscena3(){

      return  mScene3;
}

  my_scena4* getscena4(){

      return  mScene4;
}
  multijugador* getmulti(){
      return multi;
  }

  void setnivel(int niv){
      nivel=niv;
  }


private:
//    my_scena *mScene;
    int vidas=3;
    int nivel;
    bool perdio=false;
    my_scena *mScene;
    my_scena2 *mScene2;
    my_scena3 *mScene3;
    my_scena4 *mScene4;
    multijugador *multi;



};

#endif // ARKANOID_H
