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
        cout<<"Dans getNbCreditsCat de Solution\n";
        unsigned int nbCredits=0;
        for(int i=0; i<ListePrevisions.size(); i++){
            cout<<"parcours de la liste des previsions\n";
            if(getListePrevisions().at(i).getCursusPrincipal()==cursus){
                cout<<"cursus egaux\n";
                nbCredits+=getListePrevisions().at(i).getNbCreditsCatMax(cat);
                cout<<"Valeur de nbCredits\n";
            }
        }
        cout<<"Valeur de retour nbCredits : "<<nbCredits<<"\n";
        return nbCredits;
    }

    unsigned int getNbCreditsCSTM(QString cursus) const {
        unsigned int nbCredits=0;
        for(int i=0; i<ListePrevisions.size(); i++){
            if(getListePrevisions().at(i).getCursusPrincipal()==cursus)
                nbCredits+=getListePrevisions().at(i).getNbCreditsCatMax(CS)+getListePrevisions().at(i).getNbCreditsCatMax(TM);
        }

        return nbCredits;
    }

    unsigned int getNbCreditsTot(QString cursus) const {
        unsigned int nbCredits=0;
        for(int i=0; i<ListePrevisions.size(); i++){
            if(getListePrevisions().at(i).getCursusPrincipal()==cursus)
                nbCredits+=getListePrevisions().at(i).getNbCreditsTotMax();
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

    void afficher() const{
        for(int i=0; i<getListePrevisions().size(); i++){
            getListePrevisions().at(i).getSemestre()->afficher();
            cout<<" : ";
            for(int j=0; j<getListePrevisions().at(i).getListUV().size(); j++){
                cout<<getListePrevisions().at(i).getListUV().at(j).toStdString()<<" - ";
            }
            cout<<"\n";
        }
    }
};

#endif // SOLUTION_H
