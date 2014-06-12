#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include "includes.h"

//Classe Abstraite
class Inscription{
    Semestre* Sem;
    QString CursusPpal;
protected :
    QStringList TabUVs;
    unsigned int tailleTab;
public:

    //NOTE : A préciser : de quelle fonctions avons nous besoin pour l'interface graphique ?
    Inscription(Semestre* s, QString cp):Sem(s), CursusPpal(cp), tailleTab(0){}
    Inscription(Semestre* s, QStringList uvs, QString cp, unsigned int t): Sem(s), CursusPpal(cp), TabUVs(uvs), tailleTab(t){}

    void editInscription(Semestre* s, QString cp) {
        Sem=s;
        CursusPpal=cp;
    }

    virtual void addUV(QString uv)=0;

    Semestre* getSemestre() const {return Sem;}
    QStringList getListUV() const {return TabUVs;}
    QString getCursusPrincipal() const {return CursusPpal;}
    unsigned int getTailleTab() const {return tailleTab;}

    unsigned int getNbCreditsCatMax(Categorie cat) const{
        unsigned int res=0;
        UVManager* UVManage = UVManager::getInstance();
        for (unsigned int i=0; i<tailleTab; i++) res+=UVManage->getNbCreditsCategorie(TabUVs.at(i), cat);
        return res;
    }

    //Récupère le nombre de crédits CS pouvant être validés au maximum
    unsigned int getNbCreditsCSMax() const{
        unsigned int res=0;
        UVManager* UVManage = UVManager::getInstance();
        for (unsigned int i=0; i<tailleTab; i++) res+=UVManage->getNbCreditsCategorie(TabUVs.at(i), CS);
        return res;
    }

    //Récupère le nombre de crédits TM pouvant être validés au maximum
    unsigned int getNbCreditsTMMax() const{
        unsigned int res=0;
        UVManager* UVManage = UVManager::getInstance();
        for (unsigned int i=0; i<tailleTab; i++) res+=UVManage->getNbCreditsCategorie(TabUVs.at(i), TM);
        return res;
    }

    //Récupère le nombre de crédits TSH pouvant être validés au maximum
    unsigned int getNbCreditsTSHMax() const{
        unsigned int res=0;
        UVManager* UVManage = UVManager::getInstance();
        for (unsigned int i=0; i<tailleTab; i++) res+=UVManage->getNbCreditsCategorie(TabUVs.at(i), TSH);
        return res;
    }

    //Récupère le nombre de crédits SP pouvant être validés au maximum
    unsigned int getNbCreditsSPMax() const{
        unsigned int res=0;
        UVManager* UVManage = UVManager::getInstance();
        for (unsigned int i=0; i<tailleTab; i++) res+=UVManage->getNbCreditsCategorie(TabUVs.at(i), SP);
        return res;
    }

    //Récupère le nombre de crédits Total pouvant être validés au maximum
    unsigned int getNbCreditsTotMax() const{
        unsigned int res=0;
        UVManager* UVManage = UVManager::getInstance();
        for (unsigned int i=0; i<tailleTab; i++) res+=UVManage->getNbTotCredits(TabUVs.at(i));
        return res;
    }

    //Test si l'index fourni est bien dans le tableau d'UVs
    bool existUV(unsigned int i) const{
        if(i>getTailleTab())
            return false;
        return true;
    }

    virtual ~Inscription(){}
};


#endif // INSCRIPTION_H
