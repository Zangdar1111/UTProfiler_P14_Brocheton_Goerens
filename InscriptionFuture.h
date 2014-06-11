#ifndef INSCRIPTIONFUTURE_H
#define INSCRIPTIONFUTURE_H

#include "includes.h"

class InscriptionFuture : public Inscription{
public :
    InscriptionFuture(Semestre* s, QString cp):Inscription(s, cp){}
    InscriptionFuture(Semestre* s, QStringList uvs, QString cp, unsigned int t):Inscription(s, uvs, cp, t){}

    ~InscriptionFuture(){}

    void addUV(QString uv){
        TabUVs.append(uv);
        tailleTab++;
    }
};


#endif // INSCRIPTIONFUTURE_H
