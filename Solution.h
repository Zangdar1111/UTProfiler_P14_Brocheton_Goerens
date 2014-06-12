#ifndef SOLUTION_H
#define SOLUTION_H

#include "includes.h"

class Solution{
    QList<InscriptionFuture> ListePrevisions;

public :
    Solution(){}

    void addPrevision(InscriptionFuture pre){
        ListePrevisions.append(pre);
    }

    QList<InscriptionFuture> getListePrevisions() const {return ListePrevisions;}

    ~Solution(){
        ListePrevisions.clear();
    }

    unsigned int getNbCreditsCat(Categorie cat, QString cursus) const {
        unsigned int nbCredits=0;
        for(int i=0; i<ListePrevisions.size(); i++){
            if(getListePrevisions().at(i).getCursusPrincipal()==cursus)
                nbCredits+=getListePrevisions().at(i).getNbCreditsCatMax(cat);
        }

        return nbCredits;
    }

    bool operator ==(Solution sol){
        if(ListePrevisions.size()!=sol.getListePrevisions().size())
            return false;
        for(int i=0; i<ListePrevisions.size(); i++){
            if(ListePrevisions.at(i)!=sol.getListePrevisions().at(i))
                return false;
        }
        return true;
    }
};

#endif // SOLUTION_H
