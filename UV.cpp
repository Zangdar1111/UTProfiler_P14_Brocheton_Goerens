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

//Afficher une UV en ligne de commande (a supprimer par la suite)
void UV::afficherUV(){
    cout<<"Code : "<<Code.toStdString()<<"\nTitre : "<<Titre.toStdString()<<"\n";
    cout<<"Printemps : "<<presentPrintemps<<" - Automne : "<<presentAutomne<<"\n";
    for(unsigned int i=0; i<Nb_Categorie; i++){
        cout<<"Categorie n°"<<i<<" : "<<Tab_Categorie[i]<<" - "<<Credits_Categorie[i]<<" crédits\n";
    }
     for(unsigned int i=0; i<Nb_Cursus; i++){
        cout<<"Cursus n°"<<i<<" : "<<Tab_Cursus[i].getCode().toStdString()<<"\n";
    }
    cout<<"Demi UV : "<<DemiUV<<"\n";
}

/* Permet d'ajouter une catégorie à une UV
 * Arguments : Catégorie à ajouter (Categorie)
 *              Nombres de crédits associés (int)
 */
void UV::ajouterCategorie(Categorie c, int n){
    if (Nb_Categorie==0){
        //Cas de la première catégorie
        //Création d'un tableau de une case et ajout de la catégorie
        Tab_Categorie=new Categorie[1];
        Tab_Categorie[0]=c;

        Credits_Categorie=new int[1];
        Credits_Categorie[0]=n;

        //Incrémentation du nombre de Catégorie
        Nb_Categorie++;
    }
    else{
        //On vérifie si la catégorie est déjà enregistrée
        int indice = hasCategorie(c);
        if(indice!=-1){
            //Mise à jour du nomre de crédits de la Catégorie
            Credits_Categorie[indice]=n;
        }
        else {
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

            //Incrémentation du nombre de Catégorie
            Nb_Categorie++;

            delete[] oldCatTab;
            delete[] oldIntTab;

            //Ajout de la nouvelle catégorie et du nombre de crédits associés
            Tab_Categorie[Nb_Categorie-1]=c;
            Credits_Categorie[Nb_Categorie-1]=n;
        }
    }
}

/* Permet d'ajouter un cursus à une UV
 * Argument : Référence vers le Cursus (&Cursus)
 */
void UV::ajouterCursus(Cursus &c){
    if (Nb_Cursus==0){
        //Cas du premier Cursus
        //Création d'un tableau de une case et ajout du Cursus
        Tab_Cursus=new Cursus[1];
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
            Cursus* newCurTab= new Cursus[Nb_Cursus+1];
            memcpy(newCurTab, Tab_Cursus, sizeof(Cursus) *Nb_Cursus);
            Cursus* oldCurTab=Tab_Cursus;
            Tab_Cursus=newCurTab;

            //Incrémentation du nombre de Cursus
            Nb_Cursus++;

            delete[] oldCurTab;

            //Ajout du nouveau Cursus
            Tab_Cursus[Nb_Cursus-1]=c;
        }
    }
}

/* Permet de tester si une catégorie est déjà enregistrée pour cette UV
 * Argument : La catégorie (Categorie)
 * Retour : l'indice (int) de la catégorie dans le tableau si la catégorie est trouvée
 *          -1 si la catégorie n'est pas trouvée
 */
int UV::hasCategorie(Categorie cat) const{
    for(unsigned int i=0; i<Nb_Categorie; i++){
        if(cat==Tab_Categorie[i])
            return i;
    }
    return -1;
}

/* Permet de tester si un cursus est déjà enregistré pour cette UV
 * Argument : Le Cursus (Cursus)
 * Retour : l'indice (int) du Cursus dans le tableau si le Cursus est trouvé
 *          -1 si le Cursus n'est pas trouvé
 */

/*
int UV::hasCursus(Cursus& cur) const{
    for(unsigned int i=0; i<Nb_Cursus; i++){
        if(cur==Tab_Cursus[i])
            return i;
    }
    return -1;
}
*/
