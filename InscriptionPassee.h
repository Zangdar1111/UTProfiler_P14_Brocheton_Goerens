#ifndef INSCRIPTIONPASSEE_H
#define INSCRIPTIONPASSEE_H

#include "includes.h"

class InscriptionPassee : public Inscription{
    Note* Resultat;
public:
    InscriptionPassee(Semestre s, QString cp):Inscription(s, cp){}
    InscriptionPassee(Semestre s, QString* uvs, QString cp, unsigned int t, Note* res):Inscription(s, uvs, cp, t){
        for(unsigned int i=0; i<getTailleTab(); i++){
            Resultat[i]=res[i];
        }
    }

    //Au choix...
    Note* getResultat() const {return Resultat;}
    Note getResultat(unsigned int i) const {
        if(existUV(i))
            return Resultat[i];
        else
            cout<<"Erreur : L'UV demandée n'existe pas (index out of range)\n";
    }

    void setResultat(unsigned int i, Note res){
        if(existUV(i))
            Resultat[i]=res;
        else
            cout<<"Erreur : L'UV demandée n'existe pas (index out of range)\n";
    }


    unsigned int getNbCreditsCS() const {
        unsigned int res=0;
        UVManager* UVManage = UVManager::getInstance();
        for (unsigned int i=0; i<getTailleTab(); i++)
            if(isValidee(i))
                res+=UVManage->getNbCreditsCategorie(getListUV()[i], CS);
        return res;
    }

    unsigned int getNbCreditsTM() const {
        unsigned int res=0;
        UVManager* UVManage = UVManager::getInstance();
        for (unsigned int i=0; i<getTailleTab(); i++)
            if(isValidee(i))
                res+=UVManage->getNbCreditsCategorie(getListUV()[i], TM);
        return res;
    }

    unsigned int getNbCreditsTSH() const {
        unsigned int res=0;
        UVManager* UVManage = UVManager::getInstance();
        for (unsigned int i=0; i<getTailleTab(); i++)
            if(isValidee(i))
                res+=UVManage->getNbCreditsCategorie(getListUV()[i], TSH);
        return res;
    }

    unsigned int getNbCreditsSP() const {
        unsigned int res=0;
        UVManager* UVManage = UVManager::getInstance();
        for (unsigned int i=0; i<getTailleTab(); i++)
            if(isValidee(i))
                res+=UVManage->getNbCreditsCategorie(getListUV()[i], SP);
        return res;
    }

    unsigned int getNbCreditsTot() const {
        unsigned int res=0;
        UVManager* UVManage = UVManager::getInstance();
        for (unsigned int i=0; i<getTailleTab(); i++)
            if(isValidee(i))
                res+=UVManage->getNbTotCredits(getListUV()[i]);
        return res;
    }

    //Retourne true si l'UV est validée, false sinon
    bool isValidee(unsigned int i) const{
        if(existUV(i)){
            if(Resultat[i]!=FX&&Resultat[i]!=F&&Resultat[i]!=RES&&Resultat[i]!=ABS&&Resultat[i]!=EC)
                return true;
        }
        return false;
    }

    ~InscriptionPassee(){}
};


#endif // INSCRIPTIONPASSEE_H
