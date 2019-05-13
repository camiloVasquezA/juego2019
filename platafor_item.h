#ifndef PLATAFOR_ITEM_H
#define PLATAFOR_ITEM_H
#include "objecitem.h"

class Platafor_Item: public ObjecItem
{
public:
    Platafor_Item(int x,int y,int w,int h, int vx,int vy,QGraphicsItem *parent=nullptr);
    void move(int key);
    void move2(int key);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget=0) override;


};

#endif // PLATAFOR_ITEM_H
