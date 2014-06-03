#include "includes.h"

//Affichage d'un Cursus Secondaire dans la console (à retirer par la suite)
void CursusSecondaire::afficher() const{
    QStringList::const_iterator lit, lend;

    afficherCursus();
    cout<<"Cursus Secondaire\n";

    for(unsigned int i=0; i<tailleTab;i++){
        cout<<"Liste d'UV n°"<<i+1<<" : ";
        lit = TabListeUV[i].begin();
        lend = TabListeUV[i].end();

        for(;lit!=lend;++lit){
            cout<<lit->toStdString()<<", ";
        }

        cout<<NbUVsAValider[i]<<" Uvs à valider\n";
    }

    if(isFiliere()) cout<<getCode().toStdString()<<" est une filiere\n";
    if(isMineur()) cout<<getCode().toStdString()<<" est un mineur\n";
    cout<<"******\n";
}

/* Ajoute une UV à une liste d'UVs
 * Arguments : le code de l'UV à ajouter (string)
 *              l'indice de la liste dans le tableau des listes (int)
 */
void CursusSecondaire::addUVtoList(QString code, int i){
    if(i<0||i>=tailleTab){
        cout<<"Liste Inexistante pour ce Cursus\n";
    } else {
        if(TabListeUV[i].contains(code))
            cout<<"UV déjà présente dans la liste !\n";
        else
           TabListeUV[i].append(code);
    }
}

/* Sauvegarde le nombre d'UVs à valider dans une liste
 * Arguments : le nombre d'UVs à valider parmi celle de la liste (int)
 *              l'indice de la liste dans le tableau des listes (int)
 */
void CursusSecondaire::setNbUVsforList(int nb, int i){
    NbUVsAValider[i]=nb;
}

/* Créé une nouvelle liste d'UV vide
 * Argument : le nombre d'UVs à valider parmi celle de la liste (int)
 * Sortie : L'indice de la liste dans le tableau des listes
 */
int CursusSecondaire::creerList(int nb){
    if (tailleTab==0){
        //Cas de la première liste
        //Création d'un tableau de une case et ajout d'une QStringList
        TabListeUV=new QStringList[1];
        NbUVsAValider=new int[1];
        setNbUVsforList(nb, 0);
        //Incrémentation de la taille des tableaux
        tailleTab++;
    }
    else{
        //Extension du tableau des Listes d'UVs et du nombre d'UVs à valider
        QStringList* newListTab= new QStringList[tailleTab+1];
        int* newIntTab = new int[tailleTab+1];

        //Recopie de chaque liste d'UVs dans le nouveau tableau
        //QStringList définie un opérateur d'affectation (=)
        for(unsigned int i=0; i<tailleTab; i++)
            newListTab[i]=TabListeUV[i];

        memcpy(newIntTab, NbUVsAValider, sizeof(int)*tailleTab);

        QStringList* oldListTab=TabListeUV;
        TabListeUV=newListTab;

        //Incrémentation de la taille des tableaux
        tailleTab++;

        delete[] oldListTab;

        //Sauvegarde du nombre d'UVs à valider pour cette liste
        setNbUVsforList(nb,tailleTab-1);
    }
    return tailleTab-1;
}
