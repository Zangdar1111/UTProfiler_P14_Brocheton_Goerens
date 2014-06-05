#ifndef CURSUSPRINCIPAL_H
#define CURSUSPRINCIPAL_H

#include "includes.h"

//Classe CursusPrincipal
class CursusPrincipal : public Cursus
{
    //Attributs privés
    unsigned int Credits_Total; //Nombre de crédits total à valider
    unsigned int Credits_CS; //Nombre de crédits CS à valider
    unsigned int Credits_TM; //Nombre de crédits TM à valider
    unsigned int Credits_CSTM; //Nombre de crédits CS + TM à valider
    unsigned int Credits_TSH; //Nombre de crédits TSH à valider
    unsigned int Credits_SP; //Nombre de crédits SP à valider
    bool Branche; //Vaut True si le Cursus est une Branche, vaut false sinon

public :
    //Constructeur
    CursusPrincipal(QString code, QString titre, QString resp, unsigned int tot, unsigned int cs, unsigned int tm, unsigned int cstm, unsigned int tsh, unsigned int sp, bool br)
        :Cursus(code, titre, resp), Credits_Total(tot), Credits_CS(cs), Credits_TM(tm), Credits_CSTM(cstm), Credits_TSH(tsh),
          Credits_SP(sp), Branche(br){}

    //Accesseurs
    unsigned int getCreditsTotal() const {return Credits_Total;}
    unsigned int getCreditsCS() const {return Credits_CS;}
    unsigned int getCreditsTM() const {return Credits_TM;}
    unsigned int getCreditsCSTM() const {return Credits_CSTM;}
    unsigned int getCreditsTSH() const {return Credits_TSH;}
    unsigned int getCreditsSP() const {return Credits_SP;}
    bool isPrincipal() const {return true;}
    bool isSecondaire() const {return false;}
    bool isWhat1() const {return !Branche;}
    bool isWhat2() const {return Branche;}

    //Mutateurs
    void setCreditsTotal(unsigned int c) {Credits_Total=c;}
    void setCreditsCS(unsigned int c) {Credits_CS=c;}
    void setCreditsTM(unsigned int c) {Credits_TM=c;}
    void setCreditsCSTM(unsigned int c) {Credits_CSTM=c;}
    void setCreditsTSH(unsigned int c) {Credits_TSH=c;}
    void setCreditsSP(unsigned int c) {Credits_SP=c;}

    //Edition d'un CursusPrincipal
    void editCursusPrincipal(QString titre, QString resp, unsigned int tot, unsigned int cs, unsigned int tm, unsigned int cstm, unsigned int tsh, unsigned int sp, bool br){
        editCursus(titre, resp);
        Credits_Total=tot;
        Credits_CS=cs;
        Credits_TM=tm;
        Credits_CSTM=cstm;
        Credits_TSH=tsh;
        Credits_SP=sp;
        Branche=br;
    }

    //Destructeur
    ~CursusPrincipal(){}

    //A supprimer
    void afficher() const;
};

#endif // CURSUSPRINCIPAL_H
