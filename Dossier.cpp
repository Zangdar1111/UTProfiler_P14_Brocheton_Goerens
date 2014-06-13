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

//Vérifie si la liste 'liste' est complétée dans le dossier.
// nb : nombre d'UVs devant avoir été validée
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

/* ******Solutions******** */

void Dossier::proposerSolution(QStringList TriUVs){
    QStringList listeUVsPresentes = getListeUvs(); //récupère la liste des UVs validées dans le dossier
    Solution* sol = new Solution();
    ListeSolutions.append(*sol);

    cout<<"****Début de la recherche de Solution ****\n";
    if(!PrepaValide()){
        cout<<"---Complement de la Prepa\n---";
        proposerSolutionPrepa(sol, ListeSolutions.indexOf(*sol), &listeUVsPresentes, TriUVs);
        cout<<"affichage solution, apres complement prepa :\n";
        sol->afficher();
    }
   /* if(!BrancheValide()){

        if(!FiliereValide()){
            proposerSolutionFiliere(sol, ListeSolutions.indexOf(*sol));
        }
        proposerSolutionBranche(sol, ListeSolutions.indexOf(*sol), &listeUVsPresentes, TriUVs);
    }
    if(estSolutionValide(ListeSolutions.indexOf(*sol)))
        cout<<"solution valide !\n";
    else cout<<"solution non valide !\n";
*/
}

void Dossier::proposerSolutionPrepa(Solution* sol, int index, QStringList* listeUVsPresentes, QStringList TriUVs){
    Semestre* SemCourant = getSemestreCourant(); //Récupère le semestre courant
    bool complCS = true, complTM=true, complTSH=true, complSP=true;
    bool impossible=false;

    InscriptionFuture* proposition;
    unsigned int nbTotUVs; //Nombre Total d'UVs ajotuées dans la proposition - Ne doit pas excéder 7
    unsigned int nbTotCre; //Nombre Total de Crédits ajoutés dans la proposition - Ne doit pas excéder 35

    while(!PrepaSolutionValide(sol)&&!impossible){
        cout<<"##BOUCLE WHILE prepa non valide et non impossible de trouver une proposition\n";
        proposition = new InscriptionFuture(SemCourant, getPrepa());
        nbTotUVs=0;
        nbTotCre=0;

        cout<<"*****Complement des CS*****\n";
        complCS=completeCat(CS, proposition, getPrepa(), listeUVsPresentes, &nbTotUVs, &nbTotCre, TriUVs);
        cout<<"*****Complement des TM*****\n";
        complTM=completeCat(TM, proposition, getPrepa(), listeUVsPresentes, &nbTotUVs, &nbTotCre, TriUVs);
        cout<<"*****Complement des TSH*****\n";
        complTSH=completeCat(TSH, proposition, getPrepa(), listeUVsPresentes, &nbTotUVs, &nbTotCre, TriUVs);
        cout<<"*****Complement des SP*****\n";
        complSP=completeCat(SP, proposition, getPrepa(), listeUVsPresentes, &nbTotUVs, &nbTotCre, TriUVs);

        if(complCS&&complTM&&complTSH&&complSP){
            cout<<"ERR : IMPOSSIBLE DE TROUVER UNE SOLUTION\n";
            impossible=true;
        }
        sol->addPrevision(*proposition);
        cout<<"Nombre de previsions dans la solution : "<<sol->getListePrevisions().size()<<"\n";
        cout<<"affichage solution1\n";
        sol->afficher();
    }
}

void Dossier::proposerSolutionBranche(Solution* sol, int index, QStringList* listeUVsPresentes, QStringList TriUVs){
    Semestre* SemCourant = getSemestreCourant();

    unsigned int nbTotUVs; //Nombre Total d'UVs ajotuées dans cette proposition - Ne doit pas excéder 7
    unsigned int nbTotCre; //Nombre Total de Crédits ajoutés dans cette proposition - Ne doit pas excéder 35

    InscriptionFuture* proposition = new InscriptionFuture(SemCourant, getBranche());

    while(!BrancheSolutionValide(index)){
        proposition = new InscriptionFuture(SemCourant, getPrepa());
        nbTotUVs=0;
        nbTotCre=0;

        completeCat(CS, proposition, getBranche(), listeUVsPresentes, &nbTotUVs, &nbTotCre, TriUVs);
        completeCat(TM, proposition, getBranche(), listeUVsPresentes, &nbTotUVs, &nbTotCre, TriUVs);
        completeCat(TSH, proposition, getBranche(), listeUVsPresentes, &nbTotUVs, &nbTotCre, TriUVs);
        completeCat(SP, proposition, getBranche(), listeUVsPresentes, &nbTotUVs, &nbTotCre, TriUVs);

        sol->addPrevision(*proposition);
    }
}

bool Dossier::completeCat(Categorie cat, InscriptionFuture* proposition, QString cursus,
                          QStringList* listeUVsPresentes, unsigned int* nbTotUVs, unsigned int* nbTotCre,
                          QStringList TriUVs){
    CursusManager* CursusManage = CursusManager::getInstance();
    UVManager* UVManage = UVManager::getInstance();
    bool impossible=false;

    unsigned int nbUVsAjoutees=0;
    unsigned int nbCreAjoutees=0;
    unsigned int nbCredCatAValider = CursusManage->getNbCreditsCatAValider(cursus, cat);

    while((getNbCreditsCat(cat, cursus)+nbCreAjoutees<nbCredCatAValider)&&!impossible&&nbUVsAjoutees<2&&((*nbTotUVs)+nbUVsAjoutees<7)){
        cout<<"##BOUCLE WHILE : Recherche d'UVs##\n";
        QString uv = UVManage->getUVfromCatCursus(cat, cursus, listeUVsPresentes, TriUVs);
        if(uv==QString::null){
            impossible=true;
            cout<<"Recherche d'UVs a retourner NULL : impossible\n";
        } else {
            if((*nbTotCre)+nbCreAjoutees+UVManage->getNbCreditsCategorie(uv,cat)>35){
                cout<<"Nombre de Crédits pour ce semestre trop élevé, annulation de l'ajout de l'UV\n";
                impossible=true;
            } else {
            cout<<"UV Trouvee : "<<uv.toStdString()<<"\n";
            //Ajouter l'UV à la proposition
            proposition->addUV(uv);

            cout<<"Ajout de "<<UVManage->getNbCreditsCategorie(uv,cat)<<"credits "<<cat<<"\n";
            //Incrémenter le nombre d'UVs ajoutées et le nombre de crédits validés
            nbUVsAjoutees++;
            nbCreAjoutees+=UVManage->getNbCreditsCategorie(uv,cat);
            }
        }
    }
    (*nbTotUVs)+=nbUVsAjoutees;
    (*nbTotCre)+=nbCreAjoutees;

    cout<<"**Fin d'ajout des credits "<<cat<<" : "<<nbCreAjoutees<<" ajoutes, "<<(*nbTotCre)<<" credits au total, "<< nbCredCatAValider<<" credits a valider\n";
    return impossible;
}

bool Dossier::estSolutionValide(int i) const{
    if(i<0)
        cout<<"Erreur : Solution inexistante !";
    else{
        //if(PrepaSolutionValide(i)&&BrancheSolutionValide(i)&&NiveauLangueValide())
    /*    if(!PrepaSolutionValide(i)){
            cout<<"Prepa Solution NON VALIDE\n";
            return false;
        }
        if(!BrancheSolutionValide(i)){
            cout<<"Branche Solution NON VALIDE\n";
            return false;
        }
        */
    }
    return true;
}

bool Dossier::PrepaSolutionValide(Solution* sol) const{
    CursusManager* CursusManage = CursusManager::getInstance();

    cout<<"Test Si la PrepapSolution est valide\n";
    cout<<"affichage solution3\n";
    sol->afficher();

    if(CursusManage->getNbCreditsCSAValider(getPrepa())>getNbCreditsCS(getPrepa())+sol->getNbCreditsCat(CS, getPrepa())){
        cout<<"Prepa non valide ! "<<CursusManage->getNbCreditsCSAValider(getPrepa())<<" credits CS à valider, "
              <<getNbCreditsCS(getPrepa())<<" credits CS deja presents dans le dossier, "
                <<sol->getNbCreditsCat(CS, getPrepa())<<" credits CS ajoutes par la solution\n";
        return false;
    }
    if(CursusManage->getNbCreditsTMAValider(getPrepa())>getNbCreditsTM(getPrepa())+sol->getNbCreditsCat(TM, getPrepa())){
        cout<<"Prepa non valide ! "<<CursusManage->getNbCreditsTMAValider(getPrepa())<<" credits TM à valider, "
              <<getNbCreditsTM(getPrepa())<<" credits TM deja presents dans le dossier, "
                <<sol->getNbCreditsCat(TM, getPrepa())<<" credits TM ajoutes par la solution\n";
        return false;
    }
    if(CursusManage->getNbCreditsCSTMAValider(getPrepa())>getNbCreditsCSTM(getPrepa())+sol->getNbCreditsCSTM(getPrepa())){
        cout<<"Prepa non valide ! "<<CursusManage->getNbCreditsCSTMAValider(getPrepa())<<" credits CS-TM à valider, "
              <<getNbCreditsCSTM(getPrepa())<<" credits CS-TM deja presents dans le dossier, "
                <<sol->getNbCreditsCSTM(getPrepa())<<" credits CS-TM ajoutes par la solution\n";
        return false;
    }
    if(CursusManage->getNbCreditsTSHAValider(getPrepa())>getNbCreditsTSH(getPrepa())+sol->getNbCreditsCat(TSH, getPrepa())){
        cout<<"Prepa non valide ! "<<CursusManage->getNbCreditsTSHAValider(getPrepa())<<" credits TSH à valider, "
              <<getNbCreditsTSH(getPrepa())<<" credits TSH deja presents dans le dossier, "
                <<sol->getNbCreditsCat(TSH, getPrepa())<<" credits TSH ajoutes par la solution\n";
        return false;
    }
    if(CursusManage->getNbCreditsSPAValider(getPrepa())>getNbCreditsSP(getPrepa())+sol->getNbCreditsCat(SP, getPrepa())){
        cout<<"Prepa non valide ! "<<CursusManage->getNbCreditsSPAValider(getPrepa())<<" credits SP à valider, "
              <<getNbCreditsSP(getPrepa())<<" credits SP deja presents dans le dossier, "
                <<sol->getNbCreditsCat(SP, getPrepa())<<" credits SP ajoutes par la solution\n";
        return false;
    }
    if(CursusManage->getNbCreditsTotAValider(getPrepa())>getNbCreditsTot(getPrepa())+sol->getNbCreditsTot(getPrepa())){
        cout<<"Prepa non valide ! "<<CursusManage->getNbCreditsTotAValider(getPrepa())<<" credits Tot à valider, "
              <<getNbCreditsTot(getPrepa())<<" credits Tot deja presents dans le dossier, "
                <<sol->getNbCreditsTot(getPrepa())<<" credits Tot ajoutes par la solution\n";
        return false;
    }
    cout<<"Prepa Valide !\n";
    return true;
}

bool Dossier::BrancheSolutionValide(int i) const{
    CursusManager* CursusManage = CursusManager::getInstance();

    if(CursusManage->getNbCreditsCSAValider(getBranche())>getNbCreditsCS(getBranche())+getListeSolutions().at(i).getNbCreditsCat(CS, getBranche()))
        return false;
    if(CursusManage->getNbCreditsTMAValider(getBranche())>getNbCreditsTM(getBranche())+getListeSolutions().at(i).getNbCreditsCat(TM, getBranche()))
        return false;
    if(CursusManage->getNbCreditsCSTMAValider(getBranche())>getNbCreditsCSTM(getBranche())+getListeSolutions().at(i).getNbCreditsCSTM(getBranche()))
        return false;
    if(CursusManage->getNbCreditsTSHAValider(getBranche())>getNbCreditsTSH(getBranche())+getListeSolutions().at(i).getNbCreditsCat(TSH, getBranche()))
        return false;
    if(CursusManage->getNbCreditsSPAValider(getBranche())>getNbCreditsSP(getBranche())+getListeSolutions().at(i).getNbCreditsCat(SP, getBranche()))
        return false;
    if(CursusManage->getNbCreditsTotAValider(getBranche())>getNbCreditsTot(getBranche())+getListeSolutions().at(i).getNbCreditsTot(getBranche()))
        return false;
    return true;
}

bool Dossier::FiliereSolutionValide(const int i) const{
    CursusManager* CursusManage = CursusManager::getInstance();
    for(unsigned int j=0; j<CursusManage->getTailleTabFromCursusSecondaire(getFiliere()); j++){
        if(!estListeUVsSolutionCompletee(CursusManage->getListFromCursusSecondaire(getFiliere(), j),
                                 CursusManage->getNbUVsAValiderFromCursusSecondaire(getFiliere(), j), i))
            return true;
    }

    return false;
}

//Vérifie si la liste 'liste' est complétée dans la solution 'i'
// nb : nombre d'UVs devant avoir été validée
bool Dossier::estListeUVsSolutionCompletee(QStringList liste, unsigned int nb, const int i) const{
    for(int j=0; j<getListeSolutions().at(i).getListePrevisions().size(); j++){
        for(unsigned int k=0; k<getListeSolutions().at(i).getListePrevisions().at(j).getTailleTab();k++){
            if(liste.contains(getListeSolutions().at(i).getListePrevisions().at(j).getListUV().at(k)))
                nb--;
        }
    }

    if(nb<=0)
        return true;
    return false;
}

void Dossier::afficherSolutions() const{
    for(int i=0; i<getListeSolutions().size(); i++){
        getListeSolutions().at(i).afficher();
    }
}

void Dossier::proposerSolutionFiliere(Solution* sol, int index){
    QStringList listeUVsPresentes = getListeUvs();
    Semestre* SemCourant = getSemestreCourant();

    unsigned int nbTotUVs=0; //Nombre Total d'UVs ajotuées dans cette proposition - Ne doit pas excéder 7
    unsigned int nbTotCre=0; //Nombre Total de Crédits ajoutés dans cette proposition - Ne doit pas excéder 35


    while(!FiliereSolutionValide(index)){
        InscriptionFuture* proposition = new InscriptionFuture(SemCourant, getFiliere());
       /*
        completeCat(CS, proposition, getFiliere(), &listeUVsPresentes, &nbTotUVs, &nbTotCre);
        completeCat(TM, proposition, getFiliere(), &listeUVsPresentes, &nbTotUVs, &nbTotCre);
        completeCat(TSH, proposition, getFiliere(), &listeUVsPresentes, &nbTotUVs, &nbTotCre);
        completeCat(SP, proposition, getFiliere(), &listeUVsPresentes, &nbTotUVs, &nbTotCre);
        */
        sol->addPrevision(*proposition);
    }
}


void Dossier::deleteSolution_fichier(int index)
{
    cout<<"TEST";
    QFile fichier("../UTProfiler_P14_Brocheton_Goerens/data/dossier/"+Login+"_solutions.txt");
    if(fichier.open(QIODevice::ReadWrite | QIODevice::Text))  // si l'ouverture a réussi
    {
        int marqueur1=0,marqueur2=0,j=0;
        QTextStream flux(&fichier);
        QStringList tout;
        while(! flux.atEnd())
        {
            tout.append(flux.readLine());
        }
        for(int i=0;i<tout.size();i++)
        {
            if(tout.at(i)=="#Solution#")
            {
                if(j==index)
                   marqueur1=i;
                if(j==index+1)
                    marqueur2=i;
                j++;
            }
        }
        if(marqueur2==0)
            marqueur2=tout.size();
        for(int k=0;k<marqueur2-marqueur1;k++)
           tout.removeAt(marqueur1);
        fichier.resize(0);
        for(QList<QString>::iterator it=tout.begin() ; it!=tout.end() ; ++it)
        {
            flux<<*it<<"\n";
        }
    }
}
