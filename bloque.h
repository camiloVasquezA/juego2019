#ifndef BLOQUE_H
#define BLOQUE_H
#include "objecitem.h"
#include <QString>
#include <QGraphicsLineItem>


class bloque :public ObjecItem
{
public:
    bloque  (int x, int y,int w,int h,int vx, int vy,QString color1,QString color2,QGraphicsItem *parent=nullptr);
    QGraphicsLineItem* getlin1(){return line1;}
    QGraphicsLineItem* getlin2(){return line2;}

    void setcambio(bool cambio){cam_color=cambio;}

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget=0) override;
private:
    QString color;
    QString colorR;
    bool cam_color=false;

    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;
};

#endif // BLOQUE_H
