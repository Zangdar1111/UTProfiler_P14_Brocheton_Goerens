#ifndef DOSSIERMANAGER_H
#define DOSSIERMANAGER_H

#include "includes.h"

//Class DossierManager - Classe responsable du cycle de Vie des objets Dossier
class DossierManager : public Singleton<DossierManager>{
friend class Singleton<DossierManager>;
    //Attribut
    map<QString, Dossier*> TabDossier; //Map associant un Dossier à une chaine de caractères (son login)

    DossierManager(){} //Constructeur privé - DossierManager est un singleton

public:
    Dossier* getDossier(QString login) const; //Permet d'accéder à un Dossier de la Map
    void addDossier(QString login, QString nom_pre, unsigned int langue, Semestre *sem); //Ajoute un Dossier dans la Map
    void deleteDossier(QString login); //Supprime un Dossier
    void setPrepa(QString login, QString prepa);
    void setBranche(QString login, QString branche);
    void setFiliere(QString login, QString filiere);
    void addMineur(QString login, QString mineur);
    void setSemestreCourant(QString login, Semestre* sem);
    QString getNomPrenom(QString login) const;
    unsigned int getNiveauLangue(QString login) const;
    QString getPrepa(QString login) const;
    QString getBranche(QString login) const;
    QString getFiliere(QString login) const;
    QStringList getMineur(QString login) const;

    void addParcours(QString login, InscriptionPassee &pass);
    void addSolution(QString login, Solution& sol);
    QList<InscriptionPassee> getAllParcours(QString login) const;
    QList<Solution> getAllSolutions(QString login) const;

    bool estDiplome(QString login) const;
    Solution* proposerSolution(QString login, QStringList TriUVs);

    QStringList listerDossier(); // Permet de lister toutes les Dossier chargées dans l'application

    void load(); //Charge les Dossiers depuis un fichier
    void deleteDossier_fichier(QString login); //Supprime une Dossier du fichier de saDossieregarde
    void addDossier_fichier(QString login); //Ajoute une Dossier au fichier de saDossieregarde

    void afficherSolutions(QString login) const;


};


#endif // DOSSIERMANAGER_H
