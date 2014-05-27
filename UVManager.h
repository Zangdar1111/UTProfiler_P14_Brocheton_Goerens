#ifndef UVMANAGER_H_INCLUDED
#define UVMANAGER_H_INCLUDED

#include "includes.h"

template<typename T> class Singleton
 {
   public:
     static T& Instance()
     {
         static T theSingleInstance; // suppose que T a un constructeur par défaut
         return theSingleInstance;
     }
 };

class UVManager : public Singleton<UVManager>
{
friend class Singleton<UVManager>;
    map<string, UV> TabUV;
    UV* lastUV=NULL;
    UVManager(){}
    //UVManager(const UVManager& m){}
    static UVManager* instance;
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

    UV *getUV(string c);
    //const UV& getUV(string c) const;
    void load();
    void save();
    void addUV(string code, string t, bool d);
    void addUVCategorie(string c, Categorie cat, int cre);
    void afficherUV(string c);

    void deleteUV(string code);
};

#endif // UVMANAGER_H_INCLUDED
