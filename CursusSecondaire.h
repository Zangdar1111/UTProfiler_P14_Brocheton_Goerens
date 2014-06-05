#ifndef CURSUSSECONDAIRE_H
#define CURSUSSECONDAIRE_H

#include "includes.h"

//Class CursusSecondaire
class CursusSecondaire : public Cursus
{
    //Attributs Privés
    QStringList* TabListeUV; //Tableau de Listes d'UVs à valider
    unsigned int* NbUVsAValider; //Tableau d'entiers contenant le nombre d'UVs à valider pour chaque liste
    unsigned int tailleTab; //Taille des tableaux
    bool Filiere; //Vaut true si le Cursus Secondaire est une filière

public :
    //Constructeur
    CursusSecondaire(QString code, QString titre, QString resp, bool fil)
        :Cursus(code, titre, resp), TabListeUV(new QStringList[0]), NbUVsAValider(new unsigned int[0]), tailleTab(0),Filiere(fil){}


    //Accesseurs

    QStringList getList(unsigned int i) const {return TabListeUV[i];}
    unsigned int getNbUVAValiderfromList(unsigned int i) const {return NbUVsAValider[i];}
    unsigned int getTailleTab() const {return tailleTab;}
    bool isPrincipal() const {return false;}
    bool isSecondaire() const {return true;}
    bool isWhat1() const {return Filiere;}
    bool isWhat2() const {return !Filiere;}

    //Mutateur
    void setNbUVsforList(unsigned int nb, unsigned int i);

    int creerList(unsigned int nb); //Créé une liste d'UV
    void addUVtoList(QString code, unsigned int i); //Ajoute une UV à une liste d'UVs

    //Teste l'éxistance d'une liste
    bool existList(unsigned int i) const{
        if(tailleTab<i) return false;
        return true;
    }

    //Edition d'un Cursus Secondaire
    void editCursusSecondaire(QString titre, QString resp, bool fil){
        editCursus(titre, resp);
        Filiere=fil;
    }

    //Supprime une liste complète
    void removeList(unsigned int i){
        if(existList(i)){
            TabListeUV[i].clear();
            delete(&TabListeUV[i]);
            tailleTab--;
        }
        else
            cout<<"Erreur : Liste inexistante\n";
    }

    //Retire une UV de la liste
    void removeUVFromList(QString uv, unsigned int i){
        if(existList(i))
            TabListeUV[i].removeOne(uv);
        else
            cout<<"Erreur : Liste inexistante\n";
    }

    //Destructeur
    ~CursusSecondaire(){}

    //A supprimer par la suite

    void afficher() const;
};

#endif // CURSUSSECONDAIRE_H
