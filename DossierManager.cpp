#include "includes.h"

Dossier* DossierManager::getDossier(QString login) const{
    map<QString, Dossier*>::const_iterator it=TabDossier.find(login);
    if (it!=TabDossier.end()){
        return (it->second);
    }
    else return NULL;
}

void DossierManager::addDossier(QString login, QString nom_pre, unsigned int langue, Semestre* sem){
    Dossier* findDossier=getDossier(login);
    if(findDossier==NULL){
        Dossier* new_dos = new Dossier(login, nom_pre, langue, sem);
        TabDossier.insert(make_pair(login, new_dos));
    }
    else
        findDossier->editDossier(nom_pre,langue, sem);
}

void DossierManager::deleteDossier(QString login){
    Dossier* findDossier=getDossier(login);
    if(findDossier!=NULL){
        TabDossier.erase(login);
        delete(findDossier);
    }
}

void DossierManager::setPrepa(QString login, QString prepa){
    CursusManager* CursusManage = CursusManager::getInstance();
    Dossier* findDossier=getDossier(login);
    CursusPrincipal* findCursus= dynamic_cast<CursusPrincipal*>(CursusManage->getCursus(prepa));
    if(findDossier!=NULL&&findCursus!=NULL){
        if(findCursus->isWhat1())
            findDossier->setPrepa(prepa);
        else
            cout<<"Erreur : Ce Cursus n est pas une prepa\n";
    }
    else
        cout<<"Erreur : Dossier ou Cursus Inexistant\n";
}


void DossierManager::setSemestreCourant(QString login, Semestre* sem){
    Dossier* findDossier=getDossier(login);
    if(findDossier==NULL){
        cout<<"Erreur: Dossier non trouvé";
    }
    else
        findDossier->setSemestreCourant(sem);
}

void DossierManager::setBranche(QString login, QString branche){
    CursusManager* CursusManage = CursusManager::getInstance();
    Dossier* findDossier=getDossier(login);
    CursusPrincipal* findCursus= dynamic_cast<CursusPrincipal*>(CursusManage->getCursus(branche));
    if(findDossier!=NULL&&findCursus!=NULL){
        if(findCursus->isWhat2())
            findDossier->setBranche(branche);
        else
            cout<<"Erreur : Ce Cursus n est pas une branche\n";
    }
    else
        cout<<"Erreur : Dosser ou Cursus Inexistant\n";
}

void DossierManager::setFiliere(QString login, QString filiere){
    CursusManager* CursusManage = CursusManager::getInstance();
    Dossier* findDossier=getDossier(login);
    CursusSecondaire* findCursus= dynamic_cast<CursusSecondaire*>(CursusManage->getCursus(filiere));
    if(findDossier!=NULL&&findCursus!=NULL){
        if(findCursus->isWhat1())
            findDossier->setFiliere(filiere);
        else
            cout<<"Erreur : Ce cursus n est pas une filiere\n";
    }
    else
        cout<<"Erreur : Dosser ou Cursus Inexistant\n";
}

void DossierManager::addMineur(QString login, QString mineur){
    CursusManager* CursusManage = CursusManager::getInstance();
    Dossier* findDossier=getDossier(login);
    CursusSecondaire* findCursus= dynamic_cast<CursusSecondaire*>(CursusManage->getCursus(mineur));
    if(findDossier!=NULL&&findCursus!=NULL){
        if(findCursus->isWhat2())
            findDossier->addMineur(mineur);
        else
            cout<<"Erreur : Ce cursus n est pas un mineur\n";
    }
    else
        cout<<"Erreur : Dosser ou Cursus Inexistant\n";
}

QString DossierManager::getNomPrenom(QString login) const{
    Dossier* findDossier=getDossier(login);
    if(findDossier!=NULL)
        return findDossier->getNomPrenom();
    else
        return QString::null;
}

unsigned int DossierManager::getNiveauLangue(QString login) const{
    Dossier* findDossier=getDossier(login);
    if(findDossier!=NULL)
        return findDossier->getNiveauLangue();
    else
        return 0;
}

QString DossierManager::getPrepa(QString login) const{
    Dossier* findDossier=getDossier(login);
    if(findDossier!=NULL)
        return findDossier->getPrepa();
    else
        return QString::null;
}

QString DossierManager::getBranche(QString login) const{
    Dossier* findDossier=getDossier(login);
    if(findDossier!=NULL)
        return findDossier->getBranche();
    else
        return QString::null;
}

QString DossierManager::getFiliere(QString login) const{
    Dossier* findDossier=getDossier(login);
    if(findDossier!=NULL)
        return findDossier->getFiliere();
    else
        return QString::null;
}

QStringList DossierManager::getMineur(QString login) const{
    Dossier* findDossier=getDossier(login);
    if(findDossier!=NULL)
        return findDossier->getMineur();
    else
        return QStringList();
}

void DossierManager::addParcours(QString login, InscriptionPassee& pass){
    Dossier* findDossier=getDossier(login);
    if(findDossier!=NULL)
        findDossier->addParcours(pass);
}

void DossierManager::addSolution(QString login, Solution& sol){
    Dossier* findDossier=getDossier(login);
    if(findDossier!=NULL)
        findDossier->addSolution(sol);
}

QList<InscriptionPassee> DossierManager::getAllParcours(QString login) const{
    Dossier* findDossier=getDossier(login);
    if(findDossier!=NULL)
        return findDossier->getListeParcours();
    else
        return QList<InscriptionPassee>();
}

QList<Solution> DossierManager::getAllSolutions(QString login) const{
    Dossier* findDossier=getDossier(login);
    if(findDossier!=NULL)
        return findDossier->getListeSolutions();
    else
        return QList<Solution>();
}

bool DossierManager::estDiplome(QString login) const{
    Dossier* findDossier=getDossier(login);
    if(findDossier!=NULL)
        return findDossier->estDiplome();
    else
        return false;
}

void DossierManager::proposerSolution(QString login){
    Dossier* findDossier=getDossier(login);
    if(findDossier!=NULL)
        //cout<<"coucou";
        return findDossier->proposerSolution();
}

QStringList DossierManager::listerDossier()
{
    QStringList list;
    for(map<QString, Dossier*>::iterator it=TabDossier.begin() ; it!=TabDossier.end() ; ++it)
    {
        list.append(it->first); // accede à la clé
    }
    return list;
}

void DossierManager::load()
{
    QFile liste_dossier("../UTProfiler_P14_Brocheton_Goerens/data/dossier/liste.txt");
    if(liste_dossier.open(QIODevice::ReadOnly | QIODevice::Text))  // si l'ouverture a réussi
    {
        QTextStream flux_liste(&liste_dossier);
        QStringList liste_login;
        while(! flux_liste.atEnd())
        {
            liste_login.append(flux_liste.readLine());
        }
        for(int ili=0;ili<liste_login.size();ili++)
        {
            cout<<liste_login.size();
            cout<<liste_login.at(ili).toStdString();
            QFile dossier("../UTProfiler_P14_Brocheton_Goerens/data/dossier/"+liste_login.at(ili)+".txt");
            if(dossier.open(QIODevice::ReadOnly | QIODevice::Text))  // si l'ouverture a réussi
            {
                QTextStream flux(&dossier);
                QString login = flux.readLine();
                QString NomPrenom = flux.readLine();
                int anglais = flux.readLine().toInt();
                QString Prepa = flux.readLine();
                cout<<Prepa.toStdString();
                QString Branche = flux.readLine();
                QString Filiere = flux.readLine();
                QString Mineurs = flux.readLine();
                QStringList liste_mineur = Mineurs.split(",");
                QString sem1 = flux.readLine();
                QStringList sem2 = sem1.split(",");
                Saison saiso=Printemps;
                if(sem2.at(0)=="Automne")
                    saiso=Automne;
                Semestre* currentsemestre = new Semestre(saiso,sem2.at(1).toInt());
                addDossier(login,NomPrenom,anglais,currentsemestre);
                setPrepa(login,Prepa);
                setBranche(login,Branche);
                setFiliere(login,Filiere);
                for (int i=0;i<liste_mineur.size();i++)
                    addMineur(login,liste_mineur.at(i));

                while(! flux.atEnd())
                {
                    flux.readLine();
                    QString semest = flux.readLine();
                    QStringList semestre = semest.split(",");
                    Saison sais=Printemps;
                    if(semestre.at(0)=="Automne")
                        sais=Automne;
                    unsigned int annee = semestre.at(1).toInt();
                    Semestre* sem = new Semestre(sais,annee);
                    QString cursus = flux.readLine();
                    InscriptionPassee IP = InscriptionPassee(sem,cursus);
                    QString uvs = flux.readLine();
                    QStringList uvs_liste = uvs.split(",");
                    QString notes = flux.readLine();
                    QStringList notes_liste = notes.split(",");
                    for(int i=0;i<uvs_liste.size();i++)
                    {
                        Note nott = QStringtoNote(notes_liste.at(i));
                        IP.addUVwithNote(uvs_liste.at(i),nott);
                    }
                    addParcours(login,IP);
                }
            }
            QFile solution("../UTProfiler_P14_Brocheton_Goerens/data/dossier/"+liste_login.at(ili)+"_solutions.txt");
            if(solution.open(QIODevice::ReadOnly | QIODevice::Text))  // si l'ouverture a réussi
            {
                int indexsolution=2;
                QTextStream flux_sol(&solution);
                while(! flux_sol.atEnd())
                {
                    Solution sol = Solution();
                    bool ajouter=false;
                    if(indexsolution==2) flux_sol.readLine();
                    while(flux_sol.readLine()!="#Solution#" && !flux_sol.atEnd())
                    {
                        ajouter=true;
                        QString semest = flux_sol.readLine();cout<<"Semestre:"<<semest.toStdString()<<endl;
                        QStringList semestre = semest.split(",");
                        Saison sais=Printemps;
                        if(semestre.at(0)=="Automne")
                            sais=Automne;
                        unsigned int annee = semestre.at(1).toInt();
                        Semestre* sem = new Semestre(sais,annee);
                        QString cursus = flux_sol.readLine();cout<<"Cursus:"<<cursus.toStdString()<<endl;
                        QString uvs = flux_sol.readLine();cout<<"Uvs:"<<uvs.toStdString()<<endl;
                        QStringList uvs_liste = uvs.split(",");
                        InscriptionFuture IF = InscriptionFuture(sem,uvs_liste,cursus,uvs_liste.size());
                        sol.addPrevision(IF);
                    }
                    if(ajouter)
                        addSolution(liste_login.at(ili),sol);
                    indexsolution++;
                    ajouter=false;
                }
            }
        }
    }
}



void DossierManager::deleteDossier_fichier(QString login)
{
    QFile liste_dossier("../UTProfiler_P14_Brocheton_Goerens/data/dossier/liste.txt");
    if(liste_dossier.open(QIODevice::ReadWrite | QIODevice::Text))  // si l'ouverture a réussi
    {
        QTextStream flux(&liste_dossier);
        QStringList tout;
        while(! flux.atEnd())
        {
            tout.append(flux.readLine());
        }
        int ind=tout.indexOf(login);
        tout.removeAt(ind);
        liste_dossier.resize(0);
        for(QList<QString>::iterator it=tout.begin() ; it!=tout.end() ; ++it)
        {
            flux<<*it<<"\n";
        }
        int i=1;
        QFile dossier("../UTProfiler_P14_Brocheton_Goerens/data/dossier/"+login+".txt");
        dossier.remove();

        //QFile dossier1("../UTProfiler_P14_Brocheton_Goerens/data/dossier/"+login+"_solutions.txt");
        //dossier1.remove("../UTProfiler_P14_Brocheton_Goerens/data/dossier/"+login+"_solutions.txt");
    }
}

void DossierManager::addDossier_fichier(QString login)
{
    QFile liste_dossier("../UTProfiler_P14_Brocheton_Goerens/data/dossier/liste.txt");
    if(liste_dossier.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream flux(&liste_dossier);
        QStringList tout;
        while(! flux.atEnd())
        {
            tout.append(flux.readLine());
        }
        if(!tout.contains(login))
            flux<<login<<"\n";
    }

    Dossier* doss = getDossier(login);

    QFile dossier1("../UTProfiler_P14_Brocheton_Goerens/data/dossier/"+login+"_solutions.txt");
    if(dossier1.open(QIODevice::ReadWrite | QIODevice::Append))
        dossier1.resize(0);
    else
        cout<<"Dossier Solutions Introuvable !";

    QFile fichier("../UTProfiler_P14_Brocheton_Goerens/data/dossier/"+login+".txt");
    if(fichier.open(QIODevice::ReadWrite | QIODevice::Text))  // si l'ouverture a réussi
    {
        fichier.resize(0);
        QTextStream flux(&fichier);
        flux<<login<<"\n";
        flux<<doss->getNomPrenom()<<"\n";
        flux<<doss->getNiveauLangue()<<"\n";
        flux<<doss->getPrepa()<<"\n";
        flux<<doss->getBranche()<<"\n";
        flux<<doss->getFiliere()<<"\n";
        QStringList mineurs = doss->getMineur();
        for (int i=0;i<mineurs.size();i++)
        {
            flux<<mineurs.at(i);
            if(i<mineurs.size()-1)
                flux<<",";
        }
        flux<<"\n";
        QString saiso = "Automne";
        if (doss->getSemestreCourant()->getSaison()==Printemps)
            saiso = "Printemps";
        flux<<saiso<<","<<doss->getSemestreCourant()->getAnnee()<<"\n";
        QList<InscriptionPassee> ins = doss->getListeParcours();
        for(QList<InscriptionPassee>::iterator it=ins.begin() ; it!=ins.end() ; ++it)
        {
            flux<<"#"<<"\n";
            QString saisone = "Automne";
            if (it->getSemestre()->getSaison()==Printemps)
                saisone = "Printemps";
            flux<<saisone<<","<<it->getSemestre()->getAnnee()<<"\n";
            flux<<it->getCursusPrincipal()<<"\n";
            QStringList uvs = it->getListUV();
            for (int i=0;i<uvs.size();i++)
            {
                flux<<uvs.at(i);
                if(i<uvs.size()-1)
                    flux<<",";
            }
            flux<<"\n";
            Note* notes = it->getResultat();
            for (int i=0;i<uvs.size();i++)
            {
                flux<<NotetoQString(notes[i]);
                if(i<uvs.size()-1)
                    flux<<",";
            }
            flux<<"\n";
        }
    }
}
