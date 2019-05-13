#include "mainwindow.h"
#include "mainwindow_juego.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#define DRIVER "QSQLITE"
#define NOMBRE_BASE_DATOS "./data.db"

int creaBaseDedatos(){

    if(!QSqlDatabase::isDriverAvailable(DRIVER)){
        qDebug()<<"Driver no existe";
        return -1;
    }

    auto db=QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName( NOMBRE_BASE_DATOS);
    if(!db.open()){
        qDebug()<<db.lastError();
        return -2;
    }
    return 0;
}
void  configuraBaseDatos(){
    QSqlQuery q;
    q.exec("CREATE TABLE IF NOT EXISTS usuario (id INTEGER PRIMARY KEY NOT NULL,"
           "nombre TEXT NOT NULL, contrasenya TEXT NOT NULL, nivel INTEGER NOT NULL)");


}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    const int resultado=creaBaseDedatos();
    if(resultado<0){
        return  resultado;
    }
    configuraBaseDatos();
    a.setStyle("fusion");
    MainWindow w;


    w.show();


    return a.exec();

}
