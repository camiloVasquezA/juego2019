#ifndef MY_SCENA3_H
#define MY_SCENA3_H
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
#include "platafor_item.h"
#include<QMediaPlayer>

class Timer;
class Ball_Item;
class Platafor_Item;
class vidas;
class bloque;


class my_scena3: public QGraphicsScene
{
public:

     QMediaPlayer *duque;
     QMediaPlayer *base;
     QMediaPlayer *choques;
    my_scena3(QObject *parent=nullptr);
    void startScene();
    void stopScene();
    void setvidas(int v){ vida=v;}
    int getvidas(){ return vida;}
    Platafor_Item* getplataform(){return mplataform;}
   bool choqueBloque();
    int puntaje=0;
    int nbloq=48;
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);






private:
    Timer *mtimer;
    Ball_Item *mball;
    Platafor_Item *mplataform;
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
    vidas *vida1;
    vidas *vida2;
    vidas *vida3;
    QList <bloque*> bloques;
    bloque *bloqu1;
    bloque *marrano;
    bloque *marrano1;
   bool choque=false;

};


#endif // MY_SCENA_H
