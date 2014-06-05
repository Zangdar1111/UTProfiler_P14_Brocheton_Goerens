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
void UV::afficherUV() const{
    cout<<"###Affichage UV###\n";
    cout<<"Code : "<<Code.toStdString()<<"\nTitre : "<<Titre.toStdString()<<"\n";
    cout<<"Printemps : "<<presentPrintemps<<" - Automne : "<<presentAutomne<<"\n";

    cout<<"Info : Manque l'affichage de crédits\n";
    CursusManager* CursusManage = CursusManager::getInstance(); //On récupère le CursusManager
    QStringList::const_iterator lit (Tab_Cursus.begin()), lend2(Tab_Cursus.end());
    for(;lit!=lend2;++lit){
        cout<<"Cursus n°"<<lit-Tab_Cursus.begin()+1<<" : "<<lit->toStdString() << '\n';
        CursusManage->afficherCursus(*lit); //Affichage détaillé des Cursus
    }
    cout<<"Demi UV : "<<DemiUV<<"\n";
    cout<<"######\n";
}


/* Permet d'ajouter un cursus à une UV
 * Argument : Code du Cursus (chaine de catactères)
 */
void UV::ajouterCursus(QString &c){
    if(Tab_Cursus.contains(c))
        cout<<"Cursus déjà présent !\n";
    else
        Tab_Cursus.append(c);
}
