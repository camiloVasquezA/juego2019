#ifndef TIMER_H
#define TIMER_H
#include <QThread>

class Timer: public QThread
{
    Q_OBJECT
public:
    Timer(int miliseconds,QObject *parent=nullptr);
    void mov(int a){
        movi=a;
    }
signals:
    void timeOut();
protected:
    void run() override;
private:
    int mMiliseconds;

   int movi=0;
};

#endif // TIMER_H
