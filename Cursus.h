#ifndef CURSUS_H_INCLUDED
#define CURSUS_H_INCLUDED

#include "includes.h"

class Cursus
{
    string Code;
    string Titre;
    string Responsable;
public:
    Cursus() {}
    Cursus(string c,string t, string r):Code(c),Titre(t),Responsable(r){}
    string getCode(){return this->Code;}
    string getTitre(){return this->Titre;}
    string getResp(){return this->Responsable;}
};


#endif // CURSUS_H_INCLUDED
