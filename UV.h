#ifndef UV_H_INCLUDED
#define UV_H_INCLUDED

#include "includes.h"

class UV
{
private:
    QString Code;
    QString Titre;
    bool presentPrintemps;
    bool presentAutomne;
    Categorie* Tab_Categorie;
    int* Credits_Categorie;
    unsigned int Nb_Categorie;
    QStringList Tab_Cursus;
    unsigned int Nb_Cursus;
    bool DemiUV;

public:
    UV(QString c, QString t, bool p, bool a, bool d) : Code(c), Titre(t), presentPrintemps(p), presentAutomne(a), Tab_Categorie(new Categorie[0]),
        Credits_Categorie(new int[0]), Nb_Categorie(0), Nb_Cursus(0), DemiUV(d){}
    UV();
    void editUV(QString t, bool p, bool a, bool d);
    QString getCode() const {return this->Code;}
    QString getTitre() const {return this->Titre;}
    bool getPresentPrintemps () const {return presentPrintemps;}
    bool getPresentAutomne () const {return presentAutomne;}
    Categorie* getTab_Categorie() const {return this->Tab_Categorie;}
    int* getCredits_Categorie() const {return this->Credits_Categorie;}
    int getNb_Categorie() const {return this->Nb_Categorie;}
    QStringList getTab_Cursus() const {return this->Tab_Cursus;}
    int getNb_Cursus() const {return this->Nb_Cursus;}
    bool getDemiUV() const {return this->DemiUV;}
    //~UV();

    void afficherUV();
    void ajouterCategorie(Categorie c, int n); //Ajouter une catégorie et le nombre de crédits
    void ajouterCursus(QString &c); //Ajouter un Cursus
    //UV* operator=(UV& src); //Opérateur de recopie pour le MAP
    Categorie& getCategorie(unsigned int i) const {return Tab_Categorie[i];}
    unsigned int getCreditsCat(Categorie cat) const;
    QString getCursus(unsigned int i) const {return Tab_Cursus.value(i);}
    int hasCategorie(Categorie cat) const;
    int hasCursus(const QString &cur) const;
};

#endif
