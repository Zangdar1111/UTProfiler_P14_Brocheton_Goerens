#ifndef INSCRIPTIONPASSEE_H
#define INSCRIPTIONPASSEE_H

#include "includes.h"

class InscriptionPassee : public Inscription{
    Note* Resultat;
public:
    InscriptionPassee(Semestre* s, QString cp):Inscription(s, cp){}
    InscriptionPassee(Semestre* s, QStringList uvs, QString cp, unsigned int t, Note* res):Inscription(s, uvs, cp, t){
        Resultat = new Note[getTailleTab()];
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

    void setResultat(unsigned int i, Note res);
    void addUV(QString uv);
    void addUVwithNote(QString uv, Note res);

    unsigned int getNbCreditsCS(QString cursus="") const;
    unsigned int getNbCreditsTM(QString cursus="") const;
    unsigned int getNbCreditsTSH(QString cursus="") const;
    unsigned int getNbCreditsSP(QString cursus="") const;
    unsigned int getNbCreditsTot(QString cursus="") const;

    //Retourne true si l'UV est validée, false sinon
    bool isValidee(unsigned int i) const;

    ~InscriptionPassee(){}
};


#endif // INSCRIPTIONPASSEE_H
