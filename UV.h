#ifndef UV_H_INCLUDED
#define UV_H_INCLUDED

#include "includes.h"

//Classe UV
class UV{
private:
    //Attributs Privés
    QString Code; //Code de l'UV
    QString Titre; //Titre complet de l'UV
    bool presentPrintemps; //Vaut True si l'UV est enseignée au semestre de Printemps
    bool presentAutomne; //Vaut True si l'UV est enseignée au semestre d'Automne
    int* Credits_Categorie; //Tableau de 4 entiers représentant les crédits donnés par l'UV dans chacune des catégories (CS, TM, TSH, SP)
    QStringList Tab_Cursus; //Liste des Cursus auxquels l'UV appartient
    unsigned int Nb_Cursus; //Nombre de Cursus dans la liste
    bool DemiUV; //Vaut True si l'UV est une demi-UV

public:
    //Constructeurs de la classe UV
    UV(QString c, QString t, bool p, bool a, bool d) : Code(c), Titre(t), presentPrintemps(p), presentAutomne(a),
        Credits_Categorie(new int[4]), Nb_Cursus(0), DemiUV(d)
    {
        for (int i=0;i<4;i++)
            Credits_Categorie[i]=0;
    }
    UV(); //Nécessaire pour le Map de l'UVManager
    //~UV();

    //Accesseurs
    QString getCode() const {return this->Code;}
    QString getTitre() const {return this->Titre;}
    bool getPresentPrintemps () const {return presentPrintemps;}
    bool getPresentAutomne () const {return presentAutomne;}
    unsigned int getCreditsCat(Categorie cat) const{return Credits_Categorie[cat];}
    QStringList getTab_Cursus() const {return this->Tab_Cursus;}
    int getNb_Cursus() const {return this->Nb_Cursus;}
    bool getDemiUV() const {return this->DemiUV;}
    bool hasCategorie(Categorie cat) const{
        if(Credits_Categorie[cat]>0) return true;
        return false;
    }

    void editUV(QString t, bool p, bool a, bool d); //Permet d'éditer une UV existante
    void ajouterCursus(QString &c); //Permet d'ajouter un Cursus à une UV
    void deleteAllCursus(); //Permet de supprimer tous les Cursus d'une UV
    void addCreditsCat(Categorie cat, int cred) {Credits_Categorie[cat]=cred;} //Ajouter des Crédits à une Catégorie
    QString getCursus(unsigned int i) const {return Tab_Cursus.value(i);} //Obtenir un Cursus de la liste des Cursus

    //A supprimer par la suite
    void afficherUV() const;
};

#endif
