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
};


#endif // CURSUS_H_INCLUDED
