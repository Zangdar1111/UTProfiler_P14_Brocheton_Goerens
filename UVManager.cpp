#include "includes.h"

/* Permet d'ajouter ou de mettre à jour une UV à l'UVManager
 * Arguments : Code de l'UV (chaine de caractères)
 *              Titre de l'UV (chaine de caractères)
 *              Demi UV (booléen)
 */
void UVManager::addUV(QString c, QString t, bool p, bool a, bool d){
    UV* findUV=getUV(c);
    if(findUV!=NULL)
            findUV->editUV(t, p, a, d);
    else{
        UV* uv = new UV(c, t, p, a, d);
        TabUV.insert(make_pair(c,*uv));
    }
}

/* Permet d'ajouter une catégorie à une UV par le UVManager
 * Arguments : le code de l'UV (chaine de caractères)
 *              la catégorie à ajouter (Catégorie)
 *              le nombre de crédits apportés à cette catégorie (int)
 */
void UVManager::addUVCategorie(QString c, Categorie cat, int cre){
    UV* findUV=getUV(c);
    if(findUV!=NULL){
        findUV->ajouterCategorie(cat, cre);
    }
}

//Afficher une UV via le UVManager en ligne de commande (a supprimer par la suite)
void UVManager::afficherUV(QString c){
    UV* findUV=getUV(c);
    if(findUV!=NULL){
        findUV->afficherUV();
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


/* Permet d'ajouter un Cursus à une UV par le UVManager
 * Arguments : le code de l'UV (chaine de caractères)
 *              la code du Cursus à ajouter (chaine de caractères)
 */
void UVManager::addUVCursus(QString c, QString cur){
    UV* findUV=getUV(c);
    if(findUV!=NULL){
        findUV->ajouterCursus(cur);
    }
}

int UVManager::check_integrity()
{
    unsigned int i;
    QFile fichier("../UTProfiler_P14_Brocheton_Goerens/data/uv.txt");
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))  // si l'ouverture a réussi
    {
        QString test;
        QTextStream flux(&fichier);
        while(!flux.atEnd())
        {
            test = flux.readLine();
            for (i=0;i<6;i++)
            {
                test = flux.readLine();
                if (test=="#")
                    return 1;
            }
            test = flux.readLine();
            if (test!="#")
                return 1;
        }
    }
    else
    {
        return 2;
    }
    return 0;
}

void UVManager::load()
{
    int i;
    QFile fichier("../UTProfiler_P14_Brocheton_Goerens/data/uv.txt");
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))  // si l'ouverture a réussi
    {
        QTextStream flux(&fichier);
        while(! flux.atEnd())
        {
            QString code = flux.readLine();
            QString titre= flux.readLine();
            QString saison = flux.readLine();
            QStringList tsaison = saison.split(",");

            QString Tab_Categorie = flux.readLine();
            QStringList tTab_Categorie = Tab_Categorie.split(",");
            int taille_cat=tTab_Categorie.size();

            QString Credits_Categorie = flux.readLine();
            QStringList tCredits_Categorie = Credits_Categorie.split(",");

            QString Tab_Cursus = flux.readLine();
            QStringList tTab_Cursus = Tab_Cursus.split(",");

            QString DemiUV = flux.readLine();
            QString separateur = flux.readLine();

            addUV(code,titre,tsaison.at(0).toInt(),tsaison.at(1).toInt(),DemiUV.toInt());
            for(i=0;i<taille_cat;i++)
                addUVCategorie(code,(Categorie)tTab_Categorie.at(i).toInt(),tCredits_Categorie.at(i).toInt());
        }
    }
}
