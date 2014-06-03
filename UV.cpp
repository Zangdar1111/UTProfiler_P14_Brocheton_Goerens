#include "includes.h"

/* Permet d'éditer une UV existante
 * Arguments : Nouveau Titre de l'UV (chaine de caractères)
 *              Nouvelle valeur de DemiUV (booléen)
 */
void UV::editUV(QString t, bool p, bool a, bool d)
{
    Titre=t;
    presentPrintemps=p;
    presentAutomne=a;
    DemiUV=d;
}
/*
//Afficher une UV en ligne de commande (a supprimer par la suite)
void UV::afficherUV(){
    cout<<"###Affichage UV###\n";
    cout<<"Code : "<<Code.toStdString()<<"\nTitre : "<<Titre.toStdString()<<"\n";
    cout<<"Printemps : "<<presentPrintemps<<" - Automne : "<<presentAutomne<<"\n";
    for(unsigned int i=0; i<Nb_Categorie; i++){
        cout<<"Categorie n°"<<i+1<<" : "<<Tab_Categorie[i]<<" - "<<Credits_Categorie[i]<<" crédits\n";
    }

    CursusManager* CursusManage = CursusManager::getInstance(); //On récupère le CursusManager
    QStringList::const_iterator lit (Tab_Cursus.begin()), lend2(Tab_Cursus.end());
    for(;lit!=lend2;++lit){
        cout<<"Cursus n°"<<lit-Tab_Cursus.begin()+1<<" : "<<lit->toStdString() << '\n';
        CursusManage->afficherCursus(*lit); //Affichage détaillé des Cursus
    }
    cout<<"Demi UV : "<<DemiUV<<"\n";
    cout<<"######\n";
}*/


/* Permet d'ajouter un cursus à une UV
 * Argument : Code du Cursus (chaine de catactères)
 */
void UV::ajouterCursus(QString &c){
    if(Tab_Cursus.contains(c))
        cout<<"Cursus déjà présent !\n";
    else
        Tab_Cursus.append(c);

    /*
    if (Nb_Cursus==0){
        //Cas du premier Cursus
        //Création d'un tableau de une case et ajout du Cursus
        Tab_Cursus=new QString[1];
        Tab_Cursus[0]=c;

        //Incrémentation du nombre de Cursus
        Nb_Cursus++;
    }
    else{
        //On vérifie si le Cursus est déjà enregistré
        //int indice = hasCursus(c);
        int indice=-1;
        //Si le Cursus est déjà enregistré, on ne fait rien
        if(indice==-1){
            //Si le Cursus n'est pas encore enregistré
            //Extension du tableau des Cursus
            QString* newCurTab= new QString[Nb_Cursus+1];
            memcpy(newCurTab, Tab_Cursus, sizeof(QString) *Nb_Cursus);
            QString* oldCurTab=Tab_Cursus;
            Tab_Cursus=newCurTab;

            //Incrémentation du nombre de Cursus
            Nb_Cursus++;

            delete[] oldCurTab;

            //Ajout du nouveau Cursus
            Tab_Cursus[Nb_Cursus-1]=c;
        }
    }
    */
}



/* Permet de tester si un cursus est déjà enregistré pour cette UV
 * Argument : Le code du Cursus recherché (chaine de caractères)
 * Retour : l'indice (int) du Cursus dans le tableau si le Cursus est trouvé
 *          -1 si le Cursus n'est pas trouvé
 */
/*
int UV::hasCursus(const QString& cur) const{
    for(unsigned int i=0; i<Nb_Cursus; i++){
        if(cur==Tab_Cursus[i])
            return i;
    }
    return -1;
}
*/
