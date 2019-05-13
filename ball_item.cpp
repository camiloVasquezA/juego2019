#include "ball_item.h"
#include  <QPainter>
#include "global_defines.h"
#include <QGraphicsItem>


Ball_Item::Ball_Item(int x, int y, int w, int h, int vx, int vy, QGraphicsItem *parent)
    :ObjecItem (x,y,w,h,vx,vy,parent)
{

}

void Ball_Item::move()
{   if(mx<0||mx>(XSIZE-WBALL)){
        mvx=-mvx;

    }
    else if(my<0||my>(YSIZE-HBALL)){
        mvy=-mvy;

    }
    ObjecItem::move();

}

void Ball_Item::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget* )
{
    QPixmap pixmap;
    pixmap.load(":/bola.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    //    painter->drawEllipse(mx,my,mw,mh);
}

