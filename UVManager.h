#ifndef UVMANAGER_H_INCLUDED
#define UVMANAGER_H_INCLUDED

#include "includes.h"

//Class UVManager - Classe responsable du cycle de Vie des objets UV
class UVManager : public Singleton<UVManager>{
friend class Singleton<UVManager>;
    //Attribut
    map<QString, UV> TabUV; //Map associant une UV à une chaine de caractères (son code)

    UVManager(){} //Constructeur privé - UVManager est un singleton

public:
    UV* getUV(QString c); //Permet d'accéder à une UV de la Map
    QStringList getTabCursus(QString c);
    unsigned int getNbCreditsCategorie(QString c, Categorie cat);
    unsigned int getNbTotCredits(QString c);
    void load(); //Charge les UVs depuis un fichier
    void deleteUV_fichier(QString c); //Supprime une UV du fichier de sauvegarde
    void addUV_fichier(QString c); //Ajoute une UV au fichier de sauvegarde
    void addUV(QString code, QString t, bool p, bool a, bool d); //Ajoute une UV dans la Map
    void editUVCategorie(QString c, Categorie cat, int cre); //Edite les crédits d'une UV
    void addUVCursus(QString c, QString cur); //Ajoute un Cursus à une UV
    void removeAllUVCursus(QString c); //Enlève tous les Cursus d'une UV
    void deleteUV(QString c); //Supprime une UV
    QStringList listerUV(); // Permet de lister toutes les UV chargées dans l'application
    int check_integrity(); //Vérifie l'intégrité du fichier de sauvegarde
    bool hasCursus(QString c, QString cursus);

    QString getUVfromCatCursus(Categorie cat, QString cursus,
                               QStringList* listeUVsPresentes, QStringList TriUVs);
};

#endif // UVMANAGER_H_INCLUDED
