#include "includes.h"

UV::UV(string c, string t, bool d) : Code(c), Titre(t), Tab_Categorie(new Categorie[0]),
    Credits_Categorie(new int[0]), Nb_Categorie(0), Tab_Cursus(new Cursus[0]), Nb_Cursus(0), DemiUV(d){}


void UV::editUV(string c, string t, Saison s1, Saison s2, Categorie* tab_cat, int* cre_cat, int nb_cat, Cursus* tab_curs, int nb_curs, bool d)
{
    int i;
    Code=c;
    Titre=t;
    saison[0]=s1;
    saison[1]=s2;
    Tab_Categorie=tab_cat;
    Credits_Categorie=cre_cat;
    Nb_Categorie=nb_cat;
    Tab_Cursus=tab_curs;
    Nb_Cursus=nb_curs;
    DemiUV=d;

}

void UV::afficherUV(){
    cout<<"Code : "<<Code<<"\nTitre : "<<Titre<<"\n";
    for(unsigned int i=0; i<Nb_Categorie; i++){
        cout<<"Categorie n°"<<i<<" : "<<Tab_Categorie[i]<<" - "<<Credits_Categorie[i]<<" crédits\n";
    }
     for(unsigned int i=0; i<Nb_Cursus; i++){
        cout<<"Cursus n°"<<i<<" : "<<Tab_Cursus[i].getCode()<<"\n";
    }
    cout<<"Demi UV : "<<DemiUV<<"\n";
}

void UV::ajouterCategorie(Categorie c, int n){
    if (Nb_Categorie==0){
        //Cas de la première catégorie
        //Création d'un tableau de une case et ajout de la catégorie
        Tab_Categorie=new Categorie[1];
        Tab_Categorie[0]=c;

        Credits_Categorie=new int[1];
        Credits_Categorie[0]=n;

        Nb_Categorie++;
    }
    else{
        //Extension du tableau des catégories
        Categorie* newCatTab= new Categorie[Nb_Categorie+1];
        memcpy(newCatTab, Tab_Categorie, sizeof(Categorie) *Nb_Categorie);
        Categorie* oldCatTab=Tab_Categorie;
        Tab_Categorie=newCatTab;

        //Extension du tableau des Crédits
        int* newIntTab= new int[Nb_Categorie+1];
        memcpy(newIntTab, Credits_Categorie, sizeof(int) *Nb_Categorie);
        int* oldIntTab=Credits_Categorie;
        Credits_Categorie=newIntTab;

        Nb_Categorie++;

        delete[] oldCatTab;
        delete[] oldIntTab;

        //Ajout de la nouvelle catégorie et du nombre de crédits associés
        Tab_Categorie[Nb_Categorie-1]=c;
        Credits_Categorie[Nb_Categorie-1]=n;
    }
}

void UV::ajouterCursus(Cursus &c){
    if (Nb_Cursus==0){
        //Cas du premier Cursus
        //Création d'un tableau de une case et ajout du Cursus
        Tab_Cursus=new Cursus[1];
        Tab_Cursus[0]=c;

        Nb_Cursus++;
    }
    else{
        //Extension du tableau des Cursus
        Cursus* newCurTab= new Cursus[Nb_Cursus+1];
        memcpy(newCurTab, Tab_Cursus, sizeof(Cursus) *Nb_Cursus);
        Cursus* oldCurTab=Tab_Cursus;
        Tab_Cursus=newCurTab;

        Nb_Cursus++;

        delete[] oldCurTab;

        //Ajout du nouveau Cursus
        Tab_Cursus[Nb_Cursus-1]=c;
    }


}

