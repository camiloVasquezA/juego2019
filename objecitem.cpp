#include "objecitem.h"



ObjecItem::ObjecItem(int x, int y, int w, int h, int vx, int vy, QGraphicsItem *parent)
    :QGraphicsItem (parent)
{
    mx=x;
    my=y;
    mw=w;
    mh=h;
    mvx=vx;
    mvy=vy;
}

void ObjecItem::move()
{
    mx+=mvx;
    my+=mvy;
}

QRectF ObjecItem::boundingRect() const
{
    return QRectF(mx,my,mw,mh);
}
