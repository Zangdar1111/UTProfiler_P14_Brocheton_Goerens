#ifndef INSCRIPTIONPASSEE_H
#define INSCRIPTIONPASSEE_H

#include "includes.h"

class InscriptionPassee : public Inscription{
    Note* Resultat;
public:
    InscriptionPassee(Semestre s, QString cp):Inscription(s, cp){}
    InscriptionPassee(Semestre s, QString* uvs, QString cp, unsigned int t, Note* res):Inscription(s, uvs, cp, t){
        for(unsigned int i=0; i<getTailleTab(); i++){
            Resultat[i]=res[i];
        }
    }

    //Au choix...
    Note* getResultat() const {return Resultat;}
    Note getResultat(unsigned int i) const {
        if(existUV(i))
            return Resultat[i];
        else
            cout<<"Erreur : L'UV demandée n'existe pas (index out of range)\n";
    }

    void setResultat(unsigned int i, Note res){
        if(existUV(i))
            Resultat[i]=res;
        else
            cout<<"Erreur : L'UV demandée n'existe pas (index out of range)\n";
    }

};


#endif // INSCRIPTIONPASSEE_H
