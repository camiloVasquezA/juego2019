#ifndef BALL_ITEM_H
#define BALL_ITEM_H
#include "objecitem.h"

class Ball_Item: public ObjecItem
{
public:
    Ball_Item(int x, int y,int w,int h,int vx, int vy,QGraphicsItem *parent=nullptr);
    void move() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget=0) override;

};

#endif // BALL_ITEM_H
