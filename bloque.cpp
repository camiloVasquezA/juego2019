#include "bloque.h"
#include <QPainter>

bloque::bloque(int x, int y,int w, int h, int vx, int vy,QString color1,QString color2,QGraphicsItem *parent)
:ObjecItem (x,y,w,h,vx,vy,parent)
{
    color=color1;
    colorR=color2;
    line1=new QGraphicsLineItem(x+w+1,y,x+w+1,y+h);
    line2=new QGraphicsLineItem(x-1,y,x-1,y+h);

}



void bloque::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPixmap pixmap;
    if(cam_color==true){
        pixmap.load(color);
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());}
    else {
        pixmap.load(colorR);
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }

}
