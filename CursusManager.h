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
    void addCursusPrincipal(QString code, QString t, QString r, int tot, int cs, int tm, int cstm, int tsh, int sp, bool br); //Permet d'ajouter un Cursus Principal
    void addCursusSecondaire(QString code, QString t, QString r, bool fil); //Permet d'ajouter un Cursus Secondaire
    int addListToCursusSecondaire(QString code, int nb); //Permet d'ajouter une liste d'UV à un Cursus Secondaire
    void addUVtoListFormCursusSecondaire(QString code, QString uv, int i);//Permet d'ajouter une UV à une liste d'un Cursus Secondaire
    void deleteCursus(QString c); //Permet de supprimer un Cursus
    QStringList listerCursus();//Liste tous les Cursus
    //void check_integrity();

    //A supprimer par la suite
    void afficherCursus(QString c);
};


#endif // CURSUSMANAGER_H
