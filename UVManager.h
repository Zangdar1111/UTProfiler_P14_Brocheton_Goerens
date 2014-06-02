#ifndef UVMANAGER_H_INCLUDED
#define UVMANAGER_H_INCLUDED

#include "includes.h"

class UVManager : public Singleton<UVManager>
{
friend class Singleton<UVManager>;
    map<QString, UV> TabUV;
    UVManager(){}
public:
    UV* getUV(QString c);
    //const UV& getUV(QString c) const;
    void load();
    void deleteUV_fichier(QString c);
    void addUV_fichier(QString c);
    void save();
    void addUV(QString code, QString t, bool p, bool a, bool d);
    void addUVCategorie(QString c, Categorie cat, int cre);
    void addUVCursus(QString c, QString cur);
    void afficherUV(QString c);
    void deleteUV(QString c);
    QStringList listerUV();
    int check_integrity();
};

#endif // UVMANAGER_H_INCLUDED
