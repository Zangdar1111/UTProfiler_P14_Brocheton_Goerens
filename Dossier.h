#ifndef DOSSIER_H
#define DOSSIER_H

#include "includes.h"

class Dossier{
    QString Login;
    QString Nom_Prenom;
    unsigned int Niveau_langue;
    QString Cursus_Prepa;
    QString Cursus_Branche;
    QString Cursus_Filiere;
    QStringList Cursus_Mineur;
    //Inscription* Inscription;
    //Solution* Solution;
public:
    Dossier(QString login, QString nom_pre, unsigned int langue):Login(login), Nom_Prenom(nom_pre), Niveau_langue(langue){}
    void editDossier(QString nom_pre, unsigned int langue){
        Nom_Prenom=nom_pre;
        Niveau_langue=langue;
    }
    void setPrepa(QString prepa) {Cursus_Prepa=prepa;}
    void setBranche(QString branche) {Cursus_Branche=branche;}
    void setFiliere(QString filiere) {Cursus_Filiere=filiere;}
    void addMineur(QString mineur){ Cursus_Mineur.append(mineur);}

    QString getNomPrenom() const {return Nom_Prenom;}
    unsigned int getNiveauLangue() const {return Niveau_langue;}
    QString getPrepa() const {return Cursus_Prepa;}
    QString getBranche() const {return Cursus_Branche;}
    QString getFiliere() const {return Cursus_Filiere;}
    QStringList getMineur() const {return Cursus_Mineur;}

};


#endif // DOSSIER_H
