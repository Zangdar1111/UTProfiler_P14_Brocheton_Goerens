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

    bool operator ==(InscriptionFuture insc) const{
        if(TabUVs.size()!=insc.getListUV().size())
            return false;

        for(int i=0; i<TabUVs.size(); i++){
            if(insc.getListUV().at(i)!=TabUVs.at(i))
                return false;
        }
        return true;
    }

    bool operator !=(InscriptionFuture insc) const{
        return !operator ==(insc);
    }

};


#endif // INSCRIPTIONFUTURE_H
