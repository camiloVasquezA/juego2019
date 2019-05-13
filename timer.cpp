#include "timer.h"



Timer::Timer(int miliseconds, QObject *parent)
    :QThread (parent)
{
    mMiliseconds=miliseconds;
}

void Timer::run()
{
    while(true){
        if(movi==0){
            emit timeOut();
            QThread::msleep(mMiliseconds);
        }
        else{
            msleep(mMiliseconds);
            emit timeOut();

        }

    }
}
