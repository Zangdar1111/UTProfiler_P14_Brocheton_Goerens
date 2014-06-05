#ifndef CURSUSPRINCIPAL_H
#define CURSUSPRINCIPAL_H

#include "includes.h"

//Classe CursusPrincipal
class CursusPrincipal : public Cursus
{
    //Attributs privés
    int Credits_Total; //Nombre de crédits total à valider
    int Credits_CS; //Nombre de crédits CS à valider
    int Credits_TM; //Nombre de crédits TM à valider
    int Credits_CSTM; //Nombre de crédits CS + TM à valider
    int Credits_TSH; //Nombre de crédits TSH à valider
    int Credits_SP; //Nombre de crédits SP à valider
    bool Branche; //Vaut True si le Cursus est une Branche, vaut false sinon

public :
    //Constructeur
    CursusPrincipal(QString code, QString titre, QString resp, int tot, int cs, int tm, int cstm, int tsh, int sp, bool br)
        :Cursus(code, titre, resp), Credits_Total(tot), Credits_CS(cs), Credits_TM(tm), Credits_CSTM(cstm), Credits_TSH(tsh),
          Credits_SP(sp), Branche(br){}

    //Accesseurs
    int getCreditsTotal() const {return Credits_Total;}
    int getCreditsCS() const {return Credits_CS;}
    int getCreditsTM() const {return Credits_TM;}
    int getCreditsCSTM() const {return Credits_CSTM;}
    int getCreditsTSH() const {return Credits_TSH;}
    int getCreditsSP() const {return Credits_SP;}
    bool isPrincipal() {return true;}
    bool isSecondaire() {return false;}
    bool isWhat1() {return !Branche;}
    bool isWhat2() {return Branche;}

    //Mutateurs
    void setCreditsTotal(int c) {Credits_Total=c;}
    void setCreditsCS(int c) {Credits_CS=c;}
    void setCreditsTM(int c) {Credits_TM=c;}
    void setCreditsCSTM(int c) {Credits_CSTM=c;}
    void setCreditsTSH(int c) {Credits_TSH=c;}
    void setCreditsSP(int c) {Credits_SP=c;}

    //Destructeur
    ~CursusPrincipal(){}

    //A supprimer
    void afficher();
};

#endif // CURSUSPRINCIPAL_H
