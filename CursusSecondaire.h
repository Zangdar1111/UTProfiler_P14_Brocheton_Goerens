#ifndef CURSUSSECONDAIRE_H
#define CURSUSSECONDAIRE_H

#include "includes.h"

class CursusSecondaire : public Cursus
{
    QStringList* TabListeUV;
    int* NbUVsAValider;
    unsigned int tailleTab;
    bool Filiere;
public :
    CursusSecondaire(QString code, QString titre, QString resp, bool fil)
        :Cursus(code, titre, resp), TabListeUV(new QStringList[0]), NbUVsAValider(new int[0]), tailleTab(0),Filiere(fil){}
    QStringList getList(unsigned int i) const {return TabListeUV[i];}
    int getNbUVAValiderfromList(unsigned int i) const {return NbUVsAValider[i];}
    int getTailleTab() const {return tailleTab;}
    bool isFiliere() const {return Filiere;}
    bool isMineur() const {return !Filiere;}

    void addUVtoList(QString code, int i);
    void setNbUVsforList(int nb, int i);
    int creerList(int nb);
    bool existList(unsigned int i) const{
        if(tailleTab<i) return false;
        return true;
    }

    void afficher() const;
    ~CursusSecondaire(){}
};

#endif // CURSUSSECONDAIRE_H
