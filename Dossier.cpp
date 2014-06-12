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

unsigned int Dossier::getNbCreditsCat(Categorie cat, QString cursus) const {
    unsigned int res=0;
    for(int i=0; i<(getListeParcours().size()); i++){
        if(getListeParcours()[i].getCursusPrincipal()==cursus)
            res+=getListeParcours()[i].getNbCreditsCat(cat, cursus);
    }
    return res;
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

QStringList Dossier::getListeUvs() const{
    QStringList ListeUVs;
    for(int i=0; i<(getListeParcours().size()); i++){
        for(unsigned int j=0; j<getListeParcours()[i].getTailleTab(); j++){
            cout<<"uv : "<<getListeParcours()[i].getListUV()[j].toStdString()<<"\n";
            ListeUVs.append(getListeParcours()[i].getListUV()[j]);
        }
    }
    return ListeUVs;
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

void Dossier::proposerSolution(){
    if(!PrepaValide()){
        proposerSolutionPrepa();
    }
}

void Dossier::proposerSolutionPrepa(){

//  CursusManager* CursusManage = CursusManager::getInstance();
    QStringList listeUVsPresentes = getListeUvs();
    Semestre* SemCourant = getSemestreCourant();
    Solution* solutionPrepa = new Solution();

    /*
    unsigned int nbTotUVs=0; //Nombre Total d'UVs ajotuées au dossier
    unsigned int nbTotCre=0; //Nombre Total de Crédits ajoutés
*/

    InscriptionFuture* proposition = new InscriptionFuture(SemCourant, getPrepa());
    completeCat(CS, proposition, getPrepa(), &listeUVsPresentes);
    completeCat(TM, proposition, getPrepa(), &listeUVsPresentes);
    completeCat(TSH, proposition, getPrepa(), &listeUVsPresentes);
    completeCat(SP, proposition, getPrepa(), &listeUVsPresentes);

    if(proposition->getListUV().contains("XX01"))
        cout<<"yes\n";
    else cout<<"no\n";

    solutionPrepa->addPrevision(*proposition);
    ListeSolutions.append(*solutionPrepa);
    estSolutionValide(ListeSolutions.indexOf(*solutionPrepa));
}

void Dossier::completeCat(Categorie cat, InscriptionFuture* proposition, QString cursus, QStringList* listeUVsPresentes){
    CursusManager* CursusManage = CursusManager::getInstance();
    UVManager* UVManage = UVManager::getInstance();
    bool impossible=false;

    unsigned int nbUVsAjoutees=0;
    unsigned int nbCredCatTheo = getNbCreditsCat(cat, cursus);
    unsigned int nbCredCatAValider = CursusManage->getNbCreditsCatAValider(cursus, cat);

    while(nbCredCatTheo<nbCredCatAValider&&!impossible&&nbUVsAjoutees<2){
        cout<<"Recherche d'UVs\n";
        QString uv = UVManage->getUVfromCatCursus(cat, cursus, *listeUVsPresentes);
        if(uv==QString::null){
            impossible=true;
            cout<<"impossible\n";
        } else {
            cout<<"uv trouvee : "<<uv.toStdString()<<"\n";

            //Ajouter l'UV à la proposition et à la liste des UVs présentes
            proposition->addUV(uv);
            listeUVsPresentes->append("XX01");

            //Incrémenter le nombre d'UVs ajoutées et le nombre de crédits validés
            nbUVsAjoutees++;
            nbCredCatTheo+=UVManage->getNbCreditsCategorie(uv,cat);

            cout<<"Cred a valider : "<<nbCredCatAValider<<"\n";
            cout<<"new cred theo : "<<nbCredCatTheo<<"\n";
            //Ajouter le nb de crédits
            //GO ON
        }
    }
}

bool Dossier::estSolutionValide(int i) const{
    if(i<0)
        cout<<"Erreur : Solution inexistante !";
    else
        //if(PrepaSolutionValide(i)&&BrancheSolutionValide(i)&&NiveauLangueValide())
        if(PrepaSolutionValide(i))
            return true;

    return false;
}

bool Dossier::PrepaSolutionValide(int i) const{
    CursusManager* CursusManage = CursusManager::getInstance();

    if(CursusManage->getNbCreditsCSAValider(getPrepa())>getNbCreditsCS(getPrepa())+getListeSolutions().at(i).getNbCreditsCat(CS, getPrepa()))
        return false;
    if(CursusManage->getNbCreditsTMAValider(getPrepa())>getNbCreditsTM(getPrepa())+getListeSolutions().at(i).getNbCreditsCat(TM, getPrepa()))
        return false;
    if(CursusManage->getNbCreditsCSTMAValider(getPrepa())>getNbCreditsCSTM(getPrepa())+getListeSolutions().at(i).getNbCreditsCat(CS, getPrepa()))
        return false;
    if(CursusManage->getNbCreditsTSHAValider(getPrepa())>getNbCreditsTSH(getPrepa())+getListeSolutions().at(i).getNbCreditsCat(TSH, getPrepa()))
        return false;
    if(CursusManage->getNbCreditsSPAValider(getPrepa())>getNbCreditsSP(getPrepa())+getListeSolutions().at(i).getNbCreditsCat(SP, getPrepa()))
        return false;
    if(CursusManage->getNbCreditsTotAValider(getPrepa())>getNbCreditsTot(getPrepa())+getListeSolutions().at(i).getNbCreditsCat(CS, getPrepa()))
        return false;
    return true;
}
