#ifndef CURSUSSECONDAIRE_H
#define CURSUSSECONDAIRE_H

#include "includes.h"

//Class CursusSecondaire
class CursusSecondaire : public Cursus
{
    //Attributs Privés
    QStringList* TabListeUV; //Tableau de Listes d'UVs à valider
    int* NbUVsAValider; //Tableau d'entiers contenant le nombre d'UVs à valider pour chaque liste
    unsigned int tailleTab; //Taille des tableaux
    bool Filiere; //Vaut true si le Cursus Secondaire est une filière

public :
    //Constructeur
    CursusSecondaire(QString code, QString titre, QString resp, bool fil)
        :Cursus(code, titre, resp), TabListeUV(new QStringList[0]), NbUVsAValider(new int[0]), tailleTab(0),Filiere(fil){}
    QStringList getList(unsigned int i) const {return TabListeUV[i];}

    //Accesseurs
    int getNbUVAValiderfromList(unsigned int i) const {return NbUVsAValider[i];}
    int getTailleTab() const {return tailleTab;}
    bool isPrincipal(){return false;}
    bool isSecondaire(){return true;}
    bool isWhat1(){return Filiere;}
    bool isWhat2(){return !Filiere;}

    //Mutateur
    void setNbUVsforList(int nb, int i);

    int creerList(int nb); //Créer une liste d'UV
    void addUVtoList(QString code, int i); //Ajoute une UV à une liste d'UVs

    //Teste l'éxistance d'une liste
    bool existList(unsigned int i) const{
        if(tailleTab<i) return false;
        return true;
    }

    //Destructeur
    ~CursusSecondaire(){}

    //A supprimer par la suite
    void afficher();
};

#endif // CURSUSSECONDAIRE_H
