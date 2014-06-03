#ifndef CURSUSMANAGER_H
#define CURSUSMANAGER_H

#include "includes.h"

class CursusManager : public Singleton<CursusManager>
{
friend class Singleton<CursusManager>;
    map<QString, Cursus*> TabCursus;
    CursusManager(){}
public:
    Cursus* getCursus(QString c);
    void load();
    void save();
    void addCursusPrincipal(QString code, QString t, QString r, int tot, int cs, int tm, int cstm, int tsh, int sp, bool br);
    void addCursusSecondaire(QString code, QString t, QString r, bool fil);
    int addListToCursusSecondaire(QString code, int nb);
    void addUVtoListFormCursusSecondaire(QString code, QString uv, int i);
    void afficherCursus(QString c);
    void deleteCursus(QString c);
    QStringList listerCursus();
    //void check_integrity();
};


#endif // CURSUSMANAGER_H
