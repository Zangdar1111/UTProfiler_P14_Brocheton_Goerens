#ifndef DOSSIER_H
#define DOSSIER_H

#include "includes.h"

class Dossier{
    QString Login;
    QString Nom_Prenom;
    unsigned int Niveau_langue;
    QString Cursus_Prepa;
    QString Cursus_Branche;
    QString Cursus_Filiere;
    QStringList Cursus_Mineur;
    Semestre* SemestreCourant;
    QList<InscriptionPassee> ListeParcours;
    QList<Solution> ListeSolutions;
public:
    Dossier(QString login, QString nom_pre, unsigned int langue, Semestre* sem):Login(login), Nom_Prenom(nom_pre), Niveau_langue(langue), SemestreCourant(sem){}
    void editDossier(QString nom_pre, unsigned int langue, Semestre* sem){
        Nom_Prenom=nom_pre;
        Niveau_langue=langue;
        SemestreCourant = sem;
    }
    void setPrepa(QString prepa) {Cursus_Prepa=prepa;}
    void setBranche(QString branche) {Cursus_Branche=branche;}
    void setFiliere(QString filiere) {Cursus_Filiere=filiere;}
    void addMineur(QString mineur){ Cursus_Mineur.append(mineur);}
    void setSemestreCourant(Semestre* sem) {SemestreCourant=sem;}
    void addParcours(InscriptionPassee& pass) {ListeParcours.append(pass);}
    void addParcours(const InscriptionPassee& pass) {ListeParcours.append(pass);}
    void addSolution(Solution& sol) {ListeSolutions.append(sol);}
    void addSolution(const Solution& sol) {ListeSolutions.append(sol);}

    void deleteAllParcours() {ListeParcours.clear();}
    void deleteAllSolutions() {ListeSolutions.clear();}

    QString getNomPrenom() const {return Nom_Prenom;}
    unsigned int getNiveauLangue() const {return Niveau_langue;}
    QString getPrepa() const {return Cursus_Prepa;}
    QString getBranche() const {return Cursus_Branche;}
    QString getFiliere() const {return Cursus_Filiere;}
    QStringList getMineur() const {return Cursus_Mineur;}
    Semestre* getSemestreCourant() const {return SemestreCourant;}
    QList<InscriptionPassee> getListeParcours() const {return ListeParcours;}
    QList<Solution> getListeSolutions() const {return ListeSolutions;}
    QStringList getListeUvs() const;

    bool PrepaValide() const;
    bool BrancheValide() const;
    bool FiliereValide() const;
    bool MineurValide(unsigned int numMineur) const;

    unsigned int getNbCreditsCat(Categorie cat, QString cursus) const;
    unsigned int getNbCreditsCS(QString cursus) const;
    unsigned int getNbCreditsTM(QString cursus) const;
    unsigned int getNbCreditsCSTM(QString cursus) const;
    unsigned int getNbCreditsTSH(QString cursus) const;
    unsigned int getNbCreditsSP(QString cursus) const;
    unsigned int getNbCreditsTot(QString cursus) const;

    bool estListeUVsCompletee(QStringList liste, unsigned int nb) const;

    bool NiveauLangueValide() const;
    bool estDiplome() const;

    void proposerSolution();
    void proposerSolutionPrepa();

    void completeCat(Categorie cat, InscriptionFuture* proposition, QString cursus, QStringList* listeUVsPresentes);

    void deleteSolution_fichier(int index);
    void saveSolution_fichier();

    bool estSolutionValide(int i) const;
    bool PrepaSolutionValide(int i) const;

};


#endif // DOSSIER_H
