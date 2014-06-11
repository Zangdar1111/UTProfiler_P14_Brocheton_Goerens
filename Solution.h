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

};

#endif // SOLUTION_H
