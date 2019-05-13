#ifndef MAINWINDOW_JUEGO_H
#define MAINWINDOW_JUEGO_H
#include "arkanoid.h"
#include <QMainWindow>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include<QString>
#include<QMediaPlayer>
namespace Ui {
class MainWindow_juego;

}
class Arkanoid;

class MainWindow_juego : public QMainWindow
{

    Q_OBJECT

public slots:
     void verificar();


public:
      QMediaPlayer *music=new QMediaPlayer();
 int t;
    explicit MainWindow_juego(QString nombre,int,int,QString puerto,QWidget *parent = nullptr);
     QSerialPort *control;
     QTimer *timer_control;
     QString puert;
    ~MainWindow_juego();

private slots:

    void on_actionQuitar_triggered();

    void on_actionIniciar_juego_triggered();

    void Joy();




private:
    Ui::MainWindow_juego *ui;
    Arkanoid *mArkanoid;
    QTimer *timer;
    int nivel;
    int punt=0;
    QString nom1;
};

#endif // MAINWINDOW_JUEGO_H
