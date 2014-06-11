#include "includes.h"

bool Dossier::PrepaValide() const{
    CursusManager* CursusManage = CursusManager::getInstance();

    if(CursusManage->getNbCreditsCSAValider(getPrepa())>getNbCreditsCS(getPrepa()))
        return false;
    if(CursusManage->getNbCreditsTMAValider(getPrepa())>getNbCreditsTM(getPrepa()))
        return false;
    if(CursusManage->getNbCreditsCSTMAValider(getPrepa())>getNbCreditsCSTM(getPrepa()))
        return false;
    if(CursusManage->getNbCreditsTSHAValider(getPrepa())>getNbCreditsTSH(getPrepa()))
        return false;
    if(CursusManage->getNbCreditsSPAValider(getPrepa())>getNbCreditsSP(getPrepa()))
        return false;
    if(CursusManage->getNbCreditsTotAValider(getPrepa())>getNbCreditsTot(getPrepa()))
        return false;
    return true;
}

bool Dossier::BrancheValide() const{
    cout<<"Validation de la Branche";
    CursusManager* CursusManage = CursusManager::getInstance();

    if(CursusManage->getNbCreditsCSAValider(getBranche())>getNbCreditsCS(getBranche()))
        return false;
    if(CursusManage->getNbCreditsTMAValider(getBranche())>getNbCreditsTM(getBranche()))
        return false;
    if(CursusManage->getNbCreditsCSTMAValider(getBranche())>getNbCreditsCSTM(getBranche()))
        return false;
    if(CursusManage->getNbCreditsTSHAValider(getBranche())>getNbCreditsTSH(getBranche()))
        return false;
    if(CursusManage->getNbCreditsSPAValider(getBranche())>getNbCreditsSP(getBranche()))
        return false;
    if(CursusManage->getNbCreditsTotAValider(getBranche())>getNbCreditsTot(getBranche()))
        return false;
    if(!FiliereValide())
        return false;
    return true;
}

bool Dossier::FiliereValide() const{
    cout<<"Validation de la Filiere\n";


    CursusManager* CursusManage = CursusManager::getInstance();
    for(unsigned int i=0; i<CursusManage->getTailleTabFromCursusSecondaire(getFiliere()); i++){
        if(!estListeUVsCompletee(CursusManage->getListFromCursusSecondaire(getFiliere(), i),
                                 CursusManage->getNbUVsAValiderFromCursusSecondaire(getFiliere(), i)))
            return true;
    }

    return false;
}

bool Dossier::MineurValide(unsigned int numMineur) const{
    CursusManager* CursusManage = CursusManager::getInstance();
    for(unsigned int i=0; i<CursusManage->getTailleTabFromCursusSecondaire(getMineur().at(numMineur)); i++){
        if(!estListeUVsCompletee(CursusManage->getListFromCursusSecondaire(getMineur().at(numMineur), i),
                                 CursusManage->getNbUVsAValiderFromCursusSecondaire(getMineur().at(numMineur), i)))
            return true;
    }
    return false;
}

unsigned int Dossier::getNbCreditsCS(QString cursus) const {
    unsigned int res=0;
    //Parcours la liste des inscriptions passees
    for(int i=0; i<(getListeParcours().size()); i++){
        if(getListeParcours()[i].getCursusPrincipal()==cursus)
            res+=getListeParcours()[i].getNbCreditsCS(cursus);
    }
    return res;
}

unsigned int Dossier::getNbCreditsTM(QString cursus) const {
    unsigned int res=0;
    for(int i=0; i<(getListeParcours().size()); i++){
        if(getListeParcours()[i].getCursusPrincipal()==cursus)
            res+=getListeParcours()[i].getNbCreditsTM(cursus);
    }
    return res;
}

unsigned int Dossier::getNbCreditsCSTM(QString cursus) const {
    unsigned int res=0;
    for(int i=0; i<(getListeParcours().size()); i++){
        if(getListeParcours()[i].getCursusPrincipal()==cursus)
            res+=getListeParcours()[i].getNbCreditsTM(cursus) + getListeParcours()[i].getNbCreditsCS(cursus);
    }
    return res;
}

unsigned int Dossier::getNbCreditsTSH(QString cursus) const {
    unsigned int res=0;
    for(int i=0; i<(getListeParcours().size()); i++){
        if(getListeParcours()[i].getCursusPrincipal()==cursus)
            res+=getListeParcours()[i].getNbCreditsTSH(cursus);
    }
    return res;
}

unsigned int Dossier::getNbCreditsSP(QString cursus) const {
    unsigned int res=0;
    for(int i=0; i<(getListeParcours().size()); i++){
        if(getListeParcours()[i].getCursusPrincipal()==cursus)
            res+=getListeParcours()[i].getNbCreditsSP(cursus);
    }
    return res;
}

unsigned int Dossier::getNbCreditsTot(QString cursus) const {
    unsigned int res=0;
    for(int i=0; i<(getListeParcours().size()); i++){
        if(getListeParcours()[i].getCursusPrincipal()==cursus)
            res+=getListeParcours()[i].getNbCreditsTot(cursus);
    }
    return res;
}

bool Dossier::estListeUVsCompletee(QStringList liste, unsigned int nb) const{
    for(int i=0; i<(getListeParcours().size()); i++){
        for(unsigned int j=0; j<getListeParcours()[i].getTailleTab(); j++){
            if(liste.contains(getListeParcours()[i].getListUV()[j]))
                nb--;
        }
    }
    if(nb<=0)
        return true;
    return false;
}

bool Dossier::NiveauLangueValide() const{
    if(getNiveauLangue()>3)
        return true;
    return false;
}

bool Dossier::estDiplome() const{
    if(PrepaValide()&&BrancheValide()&&NiveauLangueValide())
        return true;
    return false;
}
