#ifndef VIDAS_H
#define VIDAS_H
#include "objecitem.h"
#include <QGraphicsView>


class vidas: public ObjecItem
{
public:
    vidas(int x, int y,int w,int h,int vx, int vy,QGraphicsItem *parent=nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget=0) override;
};

#endif // VIDAS_H
