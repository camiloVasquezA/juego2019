#ifndef USUARIO_H
#define USUARIO_H
#include <QString>

class Usuario
{
public:
    Usuario(int id=-1, const QString &nombre="",const QString &contra="");
    int id() const{return  mid;}
    int getnivel(){return Nivel;}
    QString getnombre() const{return Mnombre;}
    QString getcontra() const{return  Mcontra;}
    void sid(int ide){mid=ide;}
    void setnivel(int niv){Nivel=niv;}
    void nombre(const QString &nombre){Mnombre=nombre;}
    void contra(const QString &contra){Mcontra=contra;}
private:
    QString Mnombre;
    QString Mcontra;
    int mid;
    int Nivel;

};

#endif // USUARIO_H
