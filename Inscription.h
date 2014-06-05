#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include "includes.h"

//Classe Abstraite
class Inscription{
    Semestre Sem;
    QString* TabUVs;
    QString CursusPpal;
    unsigned int tailleTab;
public:

    //NOTE : A préciser : de quelle fonctions avons nous besoin pour l'interface graphique ?
    Inscription(Semestre s, QString cp):Sem(s), CursusPpal(cp), tailleTab(0){}
    Inscription(Semestre s, QString* uvs, QString cp, unsigned int t): Sem(s), CursusPpal(cp), tailleTab(t){
        TabUVs=new QString[tailleTab];
        for(unsigned int i=0;i<tailleTab;i++)
            TabUVs[i]=uvs[i];
    }

    void editInscription(Semestre s, QString cp) {
        Sem=s;
        CursusPpal=cp;
    }

    Semestre getSemestre() const {return Sem;}
    QString* getListUV() const {return TabUVs;}
    QString getCursusPrincipal() const {return CursusPpal;}
    unsigned int getTailleTab() const {return tailleTab;}

   // void addUV(QString code) {TabUVs.append(code);}

    virtual ~Inscription()=0;
};


#endif // INSCRIPTION_H
