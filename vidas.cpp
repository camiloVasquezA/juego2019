#include "vidas.h"
#include <QPixmap>



vidas::vidas(int x, int y, int w, int h, int vx, int vy, QGraphicsItem *parent)
    :ObjecItem (x,y,w,h,vx,vy,parent)
{

}

void vidas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/vida.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
