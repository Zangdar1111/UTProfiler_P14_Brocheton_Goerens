#ifndef CURSUSPRINCIPAL_H
#define CURSUSPRINCIPAL_H

#include "includes.h"

class CursusPrincipal : public Cursus
{
    int Credits_Total;
    int Credits_CS;
    int Credits_TM;
    int Credits_CSTM;
    int Credits_TSH;
    int Credits_SP;
    bool Branche;
public :
    CursusPrincipal(QString code, QString titre, QString resp, int tot, int cs, int tm, int cstm, int tsh, int sp, bool br)
        :Cursus(code, titre, resp), Credits_Total(tot), Credits_CS(cs), Credits_TM(tm), Credits_CSTM(cstm), Credits_TSH(tsh),
          Credits_SP(sp), Branche(br){}
    int getCreditsTotal() const {return Credits_Total;}
    int getCreditsCS() const {return Credits_CS;}
    int getCreditsTM() const {return Credits_TM;}
    int getCreditsCSTM() const {return Credits_CSTM;}
    int getCreditsTSH() const {return Credits_TSH;}
    int getCreditsSP() const {return Credits_SP;}
    bool isBranche() const {return Branche;}
    bool isPrepa() const {return !Branche;}

    void setCreditsTotal(int c) {Credits_Total=c;}
    void setCreditsCS(int c) {Credits_CS=c;}
    void setCreditsTM(int c) {Credits_TM=c;}
    void setCreditsCSTM(int c) {Credits_CSTM=c;}
    void setCreditsTSH(int c) {Credits_TSH=c;}
    void setCreditsSP(int c) {Credits_SP=c;}

    void afficher() const;
    ~CursusPrincipal(){}
};

#endif // CURSUSPRINCIPAL_H
