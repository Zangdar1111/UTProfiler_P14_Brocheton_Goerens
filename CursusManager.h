#ifndef CURSUSMANAGER_H
#define CURSUSMANAGER_H

class CursusManager : public Singleton<CursusManager>
{
friend class Singleton<CursusManager>;
    map<QString, Cursus> TabCursus;
    CursusManager(){}
public:
    Cursus* getCursus(QString c);
    void load();
    void save();
    void addCursus(QString code, QString t, QString r);
    void afficherCursus(QString c);
    void deleteCursus(QString c);
    //void check_integrity();
};


#endif // CURSUSMANAGER_H
