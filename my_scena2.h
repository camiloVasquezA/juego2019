#ifndef MY_SCENA2_H
#define MY_SCENA2_H
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


class my_scena2: public QGraphicsScene
{
public:

     QMediaPlayer *nestor;
     QMediaPlayer *base;
     QMediaPlayer *choques;
    my_scena2(QObject *parent=nullptr);
    void startScene();
    void stopScene();
    void setvidas(int v){ vida=v;}
    int getvidas(){ return vida;}
    Platafor_Item* getplataform(){return mplataform;}
    bool choqueBloque();
    int puntaje=0;
    int nbloq=38;
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);






private:
    Timer *mtimer;
    Timer *timer1;
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
   QVector<QPointF> calcularut()const;
   int m_index;
    int vida=3;
    QGraphicsLineItem *l1;
    vidas *vida1;
    vidas *vida2;
    vidas *vida3;
    QList <bloque*> bloques;
    bloque *bloqu1;
   bool choque=false;
   QVector<QPointF>ruta;
   bloque *libre;
};


#endif // MY_SCENA_H
