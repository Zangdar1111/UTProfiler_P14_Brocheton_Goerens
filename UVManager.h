#ifndef UVMANAGER_H_INCLUDED
#define UVMANAGER_H_INCLUDED

#include "includes.h"


template<typename T> class Singleton
 {
   public:
     static T& Instance()
     {
         static T theSingleInstance; // suppose que T a un constructeur par d�faut
         return theSingleInstance;
     }
 };

class UVManager : public Singleton<UVManager>
{
friend class Singleton<UVManager>;
    map<QString, UV> TabUV;
    UVManager(){}
public:
    UV* getUV(QString c);
    //const UV& getUV(QString c) const;
    void load();
    void save();
    void addUV(QString code, QString t, bool p, bool a, bool d);
    void addUVCategorie(QString c, Categorie cat, int cre);
    void addUVCursus(QString c, QString cur);
    void afficherUV(QString c);
    void deleteUV(QString c);
    int check_integrity();
};

#endif // UVMANAGER_H_INCLUDED
