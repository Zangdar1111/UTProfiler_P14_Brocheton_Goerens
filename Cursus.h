#ifndef CURSUS_H_INCLUDED
#define CURSUS_H_INCLUDED

#include "includes.h"

class Cursus
{
    QString Code;
    QString Titre;
    QString Responsable;
public:
    Cursus() {}
    Cursus(QString c,QString t, QString r):Code(c),Titre(t),Responsable(r){}
    QString getCode(){return this->Code;}
    QString getTitre(){return this->Titre;}
    QString getResp(){return this->Responsable;}
    void editCursus(QString t, QString r){
        Titre=t;
        Responsable=r;
    }
    void afficherCursus(){
        cout<<"Code : "<<Code.toStdString()<<"\nTitre : "<<Titre.toStdString()<<"\nResponsable : "<<Responsable.toStdString()<<"\n";
    }

};


#endif // CURSUS_H_INCLUDED
