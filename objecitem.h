#ifndef OBJECITEM_H
#define OBJECITEM_H
#include <QGraphicsItem>


class ObjecItem: public QGraphicsItem
{
public:
    ObjecItem(int x,int y, int w,int h,int vx, int vy, QGraphicsItem *parent=nullptr);
    void  setx(int x){
        mx=x;}
    void sety(int y){my=y;}
    void setw(int w){mw=w;}
    void seth(int h){mh=h;}
    void setvx(int vx){mvx=vx;}
    int getx() const{return mx;}
    void setvy(int vy){mvy=vy;}
    int gety()const{return mx;}
    int getw()const{return mw;}
    int geth()const{return mh;}
    int getvx()const {return mvx;}
    int getvy() const {return mvy;}
    virtual void move();

protected:

 QRectF boundingRect() const override;

  int mx, my, mw,mh,mvx,mvy;


};

#endif // OBJECITEM_H
