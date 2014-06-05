#ifndef CURSUS_H_INCLUDED
#define CURSUS_H_INCLUDED

#include "includes.h"

//Class abstraite Cursus
class Cursus{
    //Attribtuts Public
    QString Code; //Code du Cursus
    QString Titre; //Titre Complet du Cursus
    QString Responsable; //Nom du Responsable
protected :
    //A supprimer par la suite
    void afficherCursus() const{
        cout<<"***Affichage Cursus***\nCode : "<<Code.toStdString()
           <<"\nTitre : "<<Titre.toStdString()
          <<"\nResponsable : "<<Responsable.toStdString()<<"\n";
    }
public:
    //Constructeurs
    Cursus(QString c,QString t, QString r):Code(c),Titre(t),Responsable(r){}
    Cursus() {}

    //Accesseurs
    QString getCode() const {return this->Code;}
    QString getTitre() const {return this->Titre;}
    QString getResp() const {return this->Responsable;}

    //Permet l'édition d'un Cursus
    void editCursus(QString t, QString r){
        Titre=t;
        Responsable=r;
    }

    //Fonctions virtuelles pures
    virtual bool isPrincipal()=0;
    virtual bool isSecondaire()=0;
    virtual bool isWhat1()=0;
    virtual bool isWhat2()=0;
    virtual void afficher()=0;
    virtual ~Cursus(){}

};

#endif // CURSUS_H_INCLUDED
