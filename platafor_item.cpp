#include "platafor_item.h"
#include <QPainter>
#include "global_defines.h"
#include "d_util.h"


Platafor_Item::Platafor_Item(int x, int y, int w, int h, int vx, int vy, QGraphicsItem *parent)
    :ObjecItem (x,y,w,h,vx,vy,parent)
{

}

void Platafor_Item::move(int key)
{
    if(mx>0 &&key==Qt::Key_Left){
         mvx=-D_Util::abs(mvx);
         ObjecItem::move();
    }
    else if(mx<XSIZE-WPLATAFORM &&key==Qt::Key_Right){
          mvx=+D_Util::abs(mvx);
        ObjecItem::move();
    }
}


void Platafor_Item::move2(int key){
    if(mx>0 &&key==Qt::Key_Z){
         mvx=-D_Util::abs(mvx);
         ObjecItem::move();
    }
    else if(mx<XSIZE-WPLATAFORM &&key==Qt::Key_C){
          mvx=+D_Util::abs(mvx);
        ObjecItem::move();
    }
}

void Platafor_Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{   QPixmap pixmap;
    pixmap.load(":/base.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
//    painter->drawRect(mx,my,mw,mh);
}

