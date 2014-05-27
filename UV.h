#ifndef UV_H_INCLUDED
#define UV_H_INCLUDED

#include "includes.h"

class UV
{
private:
    QString Code;
    QString Titre;
    Saison saison[];
    Categorie* Tab_Categorie;
    int* Credits_Categorie;
    unsigned int Nb_Categorie;
    Cursus* Tab_Cursus;
    unsigned int Nb_Cursus;
    bool DemiUV;

public:
    UV(QString c, QString t, bool d);
    UV();
    void editUV(QString c, QString t, bool d);
    QString getCode() const {return this->Code;}
    QString getTitre() const {return this->Titre;}
    Saison* getSaison() {return this->saison;}
    Categorie* getTab_Categorie() const {return this->Tab_Categorie;}
    int* getCredits_Categorie() const {return this->Credits_Categorie;}
    int getNb_Categorie() const {return this->Nb_Categorie;}
    Cursus* getTab_Cursus() const {return this->Tab_Cursus;}
    int getNb_Cursus() const {return this->Nb_Cursus;}
    bool getDemiUV() const {return this->DemiUV;}
    //~UV();

    void afficherUV();
    void ajouterCategorie(Categorie c, int n); //Ajouter une catégorie et le nombre de crédits
    void ajouterCursus(Cursus &c); //Ajouter un Cursus
    //UV* operator=(UV& src); //Opérateur de recopie pour le MAP
    Categorie& getCategorie(unsigned int i) const {return Tab_Categorie[i];}
    unsigned int getCreditsCat(unsigned int i) const {return Credits_Categorie[i];}
    Cursus& getCursus(unsigned int i) const {return Tab_Cursus[i];}

};

#endif
