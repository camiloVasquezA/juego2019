#ifndef MULTIJUGADOR_H
#define MULTIJUGADOR_H
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QPainter>
#include<QPixmap>
#include "objecitem.h"
#include "vidas.h"
#include "bloque.h"
#include <vector>



class Timer;
class Ball_Item;
class Platafor_Item;
class vidas;
class bloque;


class multijugador: public QGraphicsScene
{
public:
    multijugador(QObject *parent=nullptr);
    void startScene();
    void stopScene();
    void setvidas(int v){ vida=v;}
    int getvidas(){ return vida;}
    Platafor_Item* getplataform(){return mplataform;}
    bool choqueBloque();
    int puntaje=0;
    int nbloques=20;
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);






private:
    Timer *mtimer;
    Ball_Item *mball;
    Platafor_Item *mplataform;
    Platafor_Item *mplataform2;
    void createObjects();
    void confingureObjects();
    void conectObjects();
    void updateScene();
    void  checkoCollisions();
    void collisionsWhitbloque();
    void collinsWhitLine1();
     void collinsWhitLine2();


    int vida=3;
    QGraphicsLineItem *l1;
    QGraphicsLineItem *l2;
    vidas *vida1;
    vidas *vida2;
    vidas *vida3;
    QList <bloque*> bloques;
    bloque *bloqu1;
   bool choque=false;

};


#endif
