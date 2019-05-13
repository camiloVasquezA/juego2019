#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <dialog.h>
#include<mainwindow_juego.h>
#include<QMediaPlayer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool getini();

    QMediaPlayer *inicio=new QMediaPlayer();

private slots:




    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_RegistrarUsuariopushButton_clicked();



    void on_multi_clicked();

private:
    Ui::MainWindow *ui;





};

#endif // MAINWINDOW_H
