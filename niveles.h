#ifndef NIVELES_H
#define NIVELES_H

#include <QMainWindow>
#include <QString>
#include<QMediaPlayer>

namespace Ui {
class niveles;
}

class niveles : public QMainWindow
{
    Q_OBJECT

public:
    QMediaPlayer *inicio2=new QMediaPlayer();


    explicit niveles(QString nombre, int pun,QWidget *parent = nullptr);


    QString puerto;
    ~niveles();
    void sumapuntaje(int t);
    int getpuntaje();
    void setnivel(int u);

private slots:
    void on_nivel1_clicked();

    void on_nivel2_clicked();

    void on_nivel3_clicked();

    void on_nivel4_clicked();

    void on_pushButton_5_clicked();




private:
    Ui::niveles *ui;
   int puntajeG=0;
   int niv=0;
   int niv_tem;
   QString name;
};

#endif // NIVELES_H
