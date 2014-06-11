#include "includes.h"

Dossier* DossierManager::getDossier(QString login) const{
    map<QString, Dossier*>::const_iterator it=TabDossier.find(login);
    if (it!=TabDossier.end()){
        return (it->second);
    }
    else return NULL;
}

void DossierManager::addDossier(QString login, QString nom_pre, unsigned int langue){
    Dossier* findDossier=getDossier(login);
    if(findDossier==NULL){
        Dossier* new_dos = new Dossier(login, nom_pre, langue);
        TabDossier.insert(make_pair(login, new_dos));
    }
    else
        findDossier->editDossier(nom_pre,langue);
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
    /*
    QFile liste_dossier("../UTProfiler_P14_Brocheton_Goerens/data/dossier/liste.txt");
    if(liste_dossier.open(QIODevice::ReadOnly | QIODevice::Text))  // si l'ouverture a réussi
    {
        QTextStream flux_liste(&liste_dossier);
        QStringList liste_login;
        while(! flux_liste.atEnd())
        {
            liste_login.append(flux_liste.readLine());
        }
        for(int i=0;i<liste_login.size();i++)
        {
            QFile dossier("../UTProfiler_P14_Brocheton_Goerens/data/dossier/"+liste_login.at(i)+".txt");
            if(dossier.open(QIODevice::ReadOnly | QIODevice::Text))  // si l'ouverture a réussi
            {
                QTextStream flux(&liste_dossier);
                QString login = flux.readLine();
                QString NomPrenom = flux.readLine();
                int anglais = QString::number(flux.readLine());
                QString Prepa = flux.readLine();
                QString Branche = flux.readLine();
                QString Filiere = flux.readLine();
                QString Mineurs = flux.readLine();
                QStringList liste_mineur = Mineurs.split(",");

                addDossier(login,NomPrenom,anglais);
                setPrepa(login,Prepa);
                setBranche(login,Branche);
                setFiliere(login,Filiere);
                for (i=0;i<liste_mineur.size();i++)
                    addMineur(liste_mineur.at(i));

                while(! flux.atEnd())
                {
                    flux.readLine();
                    QString saison = flux.readLine();
                    if(saison=="Automne")
                        Saison sais=Automne;
                    else
                        Saison sais=Printemps;
                    unsigned int annee = flux.readLine.toInt()
                    Semestre sem = new Semestre(sais,annee);
                    QString cursus = flux.readLine();
                    InscriptionPassee IP = new InscriptionPassee(sem,cursus);
                    QString uvs = flux.readLine();
                    QStringList uvs_liste = uvs.split(",");
                    QString notes = flux.readLine();
                    QStringList notes_liste = notes.split(",");
                    for(int i=0;i<uvs_liste.size();i++)
                    {
                        IP.
                        IP.setResultat(i,notes_liste.at(i));
                    }
                }
            }
        }
    }*/
}




void DossierManager::deleteDossier_fichier(QString c)
{

}
