#ifndef CURSUSMANAGER_H
#define CURSUSMANAGER_H

#include "includes.h"

//Class CursusManager - Classe responsable du cycle de Vie des objets Cursus
class CursusManager : public Singleton<CursusManager>
{
friend class Singleton<CursusManager>;
    map<QString, Cursus*> TabCursus; //Map associant une Cursus à une chaine de caractères (son code)

    CursusManager(){} //Constructeur privé - CursusManager est un singleton
public:
    Cursus* getCursus(QString c); //Permet d'accéder à un Cursus de la Map
    void load(); //Charge les Cursus depuis un fichier
    void save(); //Sauvegarde les Cursus dans un fichier
    void addCursusPrincipal(QString code, QString t, QString r, unsigned int tot, unsigned int cs, unsigned int tm, unsigned int cstm, unsigned int tsh, unsigned int sp, bool br); //Permet d'ajouter un Cursus Principal
    void addCursusSecondaire(QString code, QString t, QString r, bool fil); //Permet d'ajouter un Cursus Secondaire
    unsigned int addListToCursusSecondaire(QString code, unsigned int nb); //Permet d'ajouter une liste d'UV à un Cursus Secondaire
    void addUVtoListFromCursusSecondaire(QString code, QString uv, unsigned int i);//Permet d'ajouter une UV à une liste d'un Cursus Secondaire
    void removeListFromCursusSecondaire(QString code, unsigned int i);
    void removeUVfromListofCursusSecondaire(QString code, QString uv, unsigned int i);
    void editNbUVsforListOfCursusSecondaire(QString code, unsigned int nb, unsigned int i);
    void deleteCursus(QString c); //Permet de supprimer un Cursus
    QStringList listerCursus();//Liste tous les Cursus
    int check_integrity();
    void deleteCursus_fichier(QString c);
    void addCursus_fichier(QString c);

    //A supprimer par la suite
    void afficherCursus(QString c);
};

#endif // CURSUSMANAGER_H
