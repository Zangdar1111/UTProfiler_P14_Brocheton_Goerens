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
    UVManager();
    UVManager(const UVManager& m){}
public:
    UV& getUV(string c);
    void load();
    void save();
    void addUV(string code, string t, ...);
    void deleteUV(string code);
};

#endif // UVMANAGER_H_INCLUDED
