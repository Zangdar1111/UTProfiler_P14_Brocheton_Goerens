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
    //UVManager(const UVManager& m){}
    static UVManager* instance;
    UV* lastUV=NULL;
public:
    static UVManager* getInstance(){
        if(instance==NULL)
            instance = new UVManager();
        return instance;
    }
    static void kill() {
        if(instance!=NULL){
            delete instance;
            instance=NULL;
        }
    }
    UV* getUV(QString c);
    //const UV& getUV(QString c) const;
    void load();
    void save();
    void addUV(QString code, QString t, bool p, bool a, bool d);
    void addUVCategorie(QString c, Categorie cat, int cre);
    void afficherUV(QString c);
    void deleteUV(QString c);
    int check_integrity();
};

#endif // UVMANAGER_H_INCLUDED
