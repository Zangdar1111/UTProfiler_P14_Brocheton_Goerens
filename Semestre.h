#ifndef SEMESTRE_H
#define SEMESTRE_H

#include "includes.h"
#include <limits.h>

class Semestre{
    Saison S;
    unsigned int Annee;
public :
    Semestre(Saison sai, unsigned int ann):S(sai), Annee(ann){}
    Semestre(const Semestre& sem){S=sem.getSaison(); Annee=sem.getAnnee();}
    Saison getSaison() const {return S;}
    unsigned int getAnnee() const {return Annee;}
    //QString getSemestre() const {return S+Annee;}

    //Incrémentation
    void incrementer(){
        if(getSaison()==Automne){
            S=Printemps;
            Annee++;
        }
        else
            S=Automne;
    }

    void afficher(){
        if(getSaison()==Automne)
            cout<<"A"<<getAnnee();
        else
            cout<<"P"<<getAnnee();
    }
};

#endif // SEMESTRE_H
