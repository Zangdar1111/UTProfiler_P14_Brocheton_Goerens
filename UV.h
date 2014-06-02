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
    int* Credits_Categorie;
    QStringList Tab_Cursus;
    unsigned int Nb_Cursus;
    bool DemiUV;

public:
    UV(QString c, QString t, bool p, bool a, bool d) : Code(c), Titre(t), presentPrintemps(p), presentAutomne(a),
        Credits_Categorie(new int[4]), Nb_Cursus(0), DemiUV(d)
    {
        for (int i=0;i<4;i++)
            Credits_Categorie[i]=0;
    }
    UV();
    void editUV(QString t, bool p, bool a, bool d);
    QString getCode() const {return this->Code;}
    QString getTitre() const {return this->Titre;}
    bool getPresentPrintemps () const {return presentPrintemps;}
    bool getPresentAutomne () const {return presentAutomne;}
    unsigned int getCreditsCat(Categorie cat) const{return Credits_Categorie[cat];}
    QStringList getTab_Cursus() const {return this->Tab_Cursus;}
    int getNb_Cursus() const {return this->Nb_Cursus;}
    bool getDemiUV() const {return this->DemiUV;}
    //~UV();

    void ajouterCursus(QString &c); //Ajouter un Cursus
    //UV* operator=(UV& src); //Opérateur de recopie pour le MAP
    void addCreditsCat(Categorie cat, int cred) {Credits_Categorie[cat]=cred;}
    QString getCursus(unsigned int i) const {return Tab_Cursus.value(i);}
    int hasCursus(const QString &cur) const;
};

#endif
