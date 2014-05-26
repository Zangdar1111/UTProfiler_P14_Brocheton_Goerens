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
    for(int i=0; i<Nb_Categorie; i++){
        cout<<"Categorie n°"<<i<<" : "<<Tab_Categorie[i]<<" - "<<Credits_Categorie[i]<<" crédits\n";
    }
  /*  for(int i=0; i<Nb_Cursus; i++){
        cout<<"Cursus n°"<<i<<" : "<<Tab_Cursus[i]<<"\n";
    }*/
    cout<<"Demi UV : "<<DemiUV<<"\n";
}

void UV::ajouterCategorie(Categorie c, int n){
    if (Nb_Categorie==0){
        Tab_Categorie=new Categorie[1];
        Tab_Categorie[0]=c;
        cout<<"Ajout cat : "<<c<<"\n";

        Credits_Categorie=new int[1];
        Credits_Categorie[0]=n;

        Nb_Categorie++;
    }
    else{
        //étendre le Tableau


    }
}
