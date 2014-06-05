#include "includes.h"

Dossier* DossierManager::getDossier(QString login){
    map<QString, Dossier*>::iterator it=TabDossier.find(login);
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

