#include "includes.h"

UVManager *UVManager::instance=NULL;

void UVManager::addUV(QString c, QString t, bool d){
    if (TabUV.find(c)!=TabUV.end()){
        cout<<"Modifier UV\n";
        lastUV=getUV(c);
        lastUV->editUV(c,t,d);
    }
    else{
        UV* uv = new UV(c, t, d);
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

void UVManager::deleteUV(QString c)
{
    TabUV.erase(c);
}

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
