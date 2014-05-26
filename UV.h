#ifndef UV_H_INCLUDED
#define UV_H_INCLUDED

#include "includes.h"

class UV
{
private:
    string Code;
    string Titre;
    Saison saison[];
    Categorie* Tab_Categorie;
    int* Credits_Categorie;
    int Nb_Categorie;
    Cursus* Tab_Cursus;
    int Nb_Cursus;
    bool DemiUV;

public:
    UV(string c, string t, bool d);
    void editUV(string c, string t, Saison s1, Saison s2, Categorie* tab_cat, int* cre_cat, int nb_cat, Cursus* tab_curs, int nb_curs, bool d);
    string getCode(){return this->Code;}
    string getTitre(){return this->Titre;}
    Saison* getSaison(){return this->saison;}
    Categorie* getTab_Categorie(){return this->Tab_Categorie;}
    int* getCredits_Categorie(){return this->Credits_Categorie;}
    int getNb_Categorie(){return this->Nb_Categorie;}
    Cursus* getTab_Cursus(){return this->Tab_Cursus;}
    int getNb_Cursus(){return this->Nb_Cursus;}
    bool getDemiUV(){return this->DemiUV;}
    ~UV();

    void afficherUV();
    void ajouterCategorie(Categorie c, int n); //Ajouter une catégorie et le nombre de crédits
};

#endif
