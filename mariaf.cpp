#include "mariaf.h"
#include <QPainter>

MariaF::MariaF(int x, int y,int w, int h, int vx, int vy,QString color1,QString color2,QGraphicsItem *parent)
:ObjecItem (x,y,w,h,vx,vy,parent)
{
    color=color1;
    colorR=color2;

}

void MariaF::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
