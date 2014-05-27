#include "includes.h"

UVManager *UVManager::instance=NULL;


/* Permet d'ajouter ou de mettre à jour une UV à l'UVManager
 * Arguments : Code de l'UV (chaine de caractères)
 *              Titre de l'UV (chaine de caractères)
 *              Demi UV (booléen)
 */
void UVManager::addUV(QString c, QString t, bool p, bool a, bool d){
    if (TabUV.find(c)!=TabUV.end()){
        lastUV=getUV(c);
        lastUV->editUV(t, p, a, d);
    }
    else{
        UV* uv = new UV(c, t, p, a, d);
        TabUV.insert(make_pair(c,*uv));
        lastUV=uv;
    }
}

/* Permet d'ajouter une catégorie à une UV par le UVManager
 * Arguments : le code de l'UV (chaine de caractères)
 *              la catégorie à ajouter (Catégorie)
 *              le nombre de crédits apportés à cette catégorie (int)
 */
void UVManager::addUVCategorie(QString c, Categorie cat, int cre){
    if(lastUV!=NULL){
        if(c==lastUV->getCode())
            lastUV->ajouterCategorie(cat, cre);
        else{
            lastUV=getUV(c);
            if(lastUV!=NULL)
                lastUV->ajouterCategorie(cat, cre);
        }
    }
    else{
        lastUV=getUV(c);
        if(lastUV!=NULL)
            lastUV->ajouterCategorie(cat, cre);
    }
}

//Afficher une UV via le UVManager en ligne de commande (a supprimer par la suite)
void UVManager::afficherUV(QString c){
    if(lastUV!=NULL){
        if(c==lastUV->getCode()){
            lastUV->afficherUV();
        }
        else{
            lastUV=getUV(c);
            if(lastUV!=NULL){
                lastUV->afficherUV();
            }
        }
    }
    else{
        lastUV=getUV(c);
        if(lastUV!=NULL){
            lastUV->afficherUV();
        }
    }
}

/* Permet d'accéder à une UV existante
 * Argument : Code de l'UV (chaine de caracères)
 * Retour : Un pointeur sur l'objet UV recherché si l'UV est trouvé
 *          Le pointeur NULL si l'UV n'est pas trouvée
 */
UV* UVManager::getUV (QString c){
    map<QString, UV>::iterator it=TabUV.find(c);
    if (it!=TabUV.end()){
        return &(it->second);
    }
    else return NULL;
}

/* Permet de supprimer une UV de l'UVManager
 * Argument : Le code de l'UV (chaine de caractères)
 */
void UVManager::deleteUV(QString c)
{
    TabUV.erase(c);
}

/*
void UVManager::check_integrity()
{
    ifstream fichier("./data/uv.txt", ios::app);  // on ouvre le fichier en écriture seule
    if(fichier)  // si l'ouverture a réussi
    {
        int stop=0;
        QString contenu,code="DEBUT FICHIER";
        while(getline(fichier, contenu))
        {
            if (contenu!= "#"){stop=1;cout<<"Erreur: Fichier Corrompu. Verifiez a partir de l'UV "<<code<<"."<<endl; break;}
            cout<<contenu<<endl;
            getline(fichier,code);cout<<code<<endl;
            for (unsigned int i=0;i<8;i++)
            {
                getline(fichier,contenu);cout<<contenu<<endl;
                if (contenu=="#")
                {
                    stop=1;
                    break;
                }
            }
            if (stop==1) {cout<<"Erreur: Fichier Corrompu. Verifiez a partir de l'UV "<<code<<"."<<endl; break;}
        }
        if (stop==0) {cout<<"Aucuns Problemes !";}
        fichier.close();
    }
    else
    cout << "Check_Integrity: Impossible d'ouvrir le fichier !" << endl;
}

void UVManager::load()
{
    ifstream fichier("./data/uv.xml", ios::in);  // on ouvre le fichier en lecture
        if(fichier)  // si l'ouverture a réussi
        {
            // ON CREE UNE BOUCLE QUI VA PARCOURIR LE FICHIER
            QString separateur,code,titre,saison,Tab_Categorie,Credits_Categorie,Nb_Categorie,Tab_Cursus,Nb_Cursus,DemiUV;
            while(getline(fichier, separateur))
            {

            // ON RECUPERE LES INFORMATIONS
            // ON CREE UNE UV AVEC LES INFORMATIONS RECUPEREE
            // ON AJOUTE L'UV DANS UVManager
            }
            fichier.close();  // on ferme le fichier
        }
        else
        cout << "Load: Impossible d'ouvrir le fichier !" << endl;
}
*/
