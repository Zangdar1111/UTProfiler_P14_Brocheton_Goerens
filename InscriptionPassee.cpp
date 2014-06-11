#include "includes.h"


void InscriptionPassee::setResultat(unsigned int i, Note res){
    if(existUV(i))
        Resultat[i]=res;
    else
        cout<<"Erreur : L'UV demandée n'existe pas (index out of range)\n";
}

/* Retourne le nombre de Crédits CS obtenus lors de ce semestre
 * Argument : (optionnel) code du Cursus - la fonction retourne alors le nombre de crédits CS obtenus spécifiques à ce Cursus
 */
unsigned int InscriptionPassee::getNbCreditsCS(QString cursus /*=QString::null*/) const {
    unsigned int res=0;
    UVManager* UVManage = UVManager::getInstance();

    if(cursus!=""){
        for (unsigned int i=0; i<getTailleTab(); i++)
            if(isValidee(i)&&UVManage->hasCursus(getListUV()[i],cursus))
                res+=UVManage->getNbCreditsCategorie(getListUV()[i], CS);
    }
    else {
        for (unsigned int i=0; i<getTailleTab(); i++)
            if(isValidee(i))
                res+=UVManage->getNbCreditsCategorie(getListUV()[i], CS);
    }
    return res;
}

unsigned int InscriptionPassee::getNbCreditsTM(QString cursus /*=QString::null*/) const {
    unsigned int res=0;
    UVManager* UVManage = UVManager::getInstance();

    if(cursus!=""){
        for (unsigned int i=0; i<getTailleTab(); i++)
            if(isValidee(i)&&UVManage->hasCursus(getListUV()[i],cursus))
                    res+=UVManage->getNbCreditsCategorie(getListUV()[i], TM);
    }
    else
        for (unsigned int i=0; i<getTailleTab(); i++)
            if(isValidee(i))
                res+=UVManage->getNbCreditsCategorie(getListUV()[i], TM);
    return res;
}

unsigned int InscriptionPassee::getNbCreditsTSH(QString cursus /*=QString::null*/) const {
    unsigned int res=0;
    UVManager* UVManage = UVManager::getInstance();

    if(cursus!=""){
        for (unsigned int i=0; i<getTailleTab(); i++)
            if(isValidee(i)&&UVManage->hasCursus(getListUV()[i],cursus))
                    res+=UVManage->getNbCreditsCategorie(getListUV()[i], TSH);
    }
    else
        for (unsigned int i=0; i<getTailleTab(); i++)
            if(isValidee(i))
                res+=UVManage->getNbCreditsCategorie(getListUV()[i], TSH);
    return res;
}

unsigned int InscriptionPassee::getNbCreditsSP(QString cursus /*=QString::null*/) const {
    unsigned int res=0;
    UVManager* UVManage = UVManager::getInstance();

    if(cursus!=""){
        for (unsigned int i=0; i<getTailleTab(); i++)
            if(isValidee(i)&&UVManage->hasCursus(getListUV()[i],cursus))
                    res+=UVManage->getNbCreditsCategorie(getListUV()[i], SP);
    }
    else
        for (unsigned int i=0; i<getTailleTab(); i++)
            if(isValidee(i))
                res+=UVManage->getNbCreditsCategorie(getListUV()[i], SP);
    return res;
}

unsigned int InscriptionPassee::getNbCreditsTot(QString cursus /*=""*/) const {
    unsigned int res=0;
    UVManager* UVManage = UVManager::getInstance();

    if(cursus!=""){
        for (unsigned int i=0; i<getTailleTab(); i++)
            if(isValidee(i)&&UVManage->hasCursus(getListUV()[i],cursus))
                    res+=UVManage->getNbTotCredits(getListUV()[i]);
    }
    else
        for (unsigned int i=0; i<getTailleTab(); i++)
            if(isValidee(i))
                res+=UVManage->getNbTotCredits(getListUV()[i]);
    return res;
}

//Retourne true si l'UV est validée, false sinon
bool InscriptionPassee::isValidee(unsigned int i) const{
    if(existUV(i)){
        if(Resultat[i]!=FX&&Resultat[i]!=F&&Resultat[i]!=RES&&Resultat[i]!=ABS&&Resultat[i]!=EC)
            return true;
    }
    return false;
}

void InscriptionPassee::addUV(QString uv){
    cout<<"Erreur : Il faut une note avec l UV. Utiliser 'addUVwithNote()'\n";
}


void InscriptionPassee::addUVwithNote(QString uv, Note res){
    if(TabUVs.contains(uv))
        cout<<"Erreur:UV deja dans le tableau";
    else
    {
        TabUVs.append(uv);
        if (tailleTab==0){
            //Cas de la première UV
            //Création d'un tableau de une case et ajout d'une QString
            Resultat=new Note[1];
            Resultat[0]=res;
            //Incrémentation de la taille du tableau
            tailleTab++;
        }
        else
        {
            Note* newRes= new Note[tailleTab+1];
            for(unsigned int i=0; i<tailleTab; i++){
                newRes[i]=Resultat[i];
            }
            Note* oldRes=Resultat;
            Resultat=newRes;
            Resultat[tailleTab]=res;
            tailleTab++;
            delete[] oldRes;
        }
    }
}


