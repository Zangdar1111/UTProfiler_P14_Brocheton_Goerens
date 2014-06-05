#ifndef DOSSIER_H
#define DOSSIER_H

#include "includes.h"

class Dossier{
    QString login;
    QString Nom_Prenom;
    unsigned int Niveau_langue;
    CursusPrincipal* Cursus_P1;
    CursusPrincipal* Cursus_P2;
    CursusSecondaire* Cursus_F;
    QList<CursusSecondaire*> Cursus_M;
    //Inscription* Inscription;
    //Solution* Solution;
public:
    Dossier(QString login, QString nom_pre, unsigned int langue):login(login), Nom_Prenom(nom_pre), Niveau_langue(langue){}
    void editDossier(QString nom_pre, unsigned int langue){
        Nom_Prenom=nom_pre;
        Niveau_langue=langue;
    }

};


#endif // DOSSIER_H
