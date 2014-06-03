#include "includes.h"

/* Permet d'ajouter ou de mettre à jour un CursusPrincipal du CursusManager
 * Arguments : Code du Cursus (chaine de caractères)
 *              Titre du Cursus (chaine de caractères)
 *              Responsable du Cursus (chaine de caractère)
 *              Nombre total de crédits à valider (int)
 *              Nombre total de crédits CS à valider (int)
 *              Nombre total de crédits TM à valider (int)
 *              Nombre total de crédits CSTM à valider (int)
 *              Nombre total de crédits TSH à valider (int)
 *              Nombre total de crédits SP à valider (int)
 *              Valeure de vérité de branche (bool)
 */
void CursusManager::addCursusPrincipal(QString c, QString t, QString r, int tot, int cs, int tm, int cstm, int tsh, int sp, bool br){
    Cursus* findCursus=getCursus(c);
    if(findCursus==NULL){
        Cursus* new_cur = new CursusPrincipal(c, t, r, tot, cs, tm, cstm, tsh, sp, br);
        TabCursus.insert(make_pair(c,new_cur));
    } else {
        cout<<"Erreur : Cursus Déjà présent !\n\n";
    }
}

/* Permet d'ajouter ou de mettre à jour un CursusSecondaire du CursusManager
 * Arguments : Code du Cursus (chaine de caractères)
 *              Titre du Cursus (chaine de caractères)
 *              Responsable du Cursus (chaine de caractère)
 *              Valeure de vérité de filière (bool)
 */
void CursusManager::addCursusSecondaire(QString c, QString t, QString r, bool fil){
    Cursus* findCursus=getCursus(c);
    if(findCursus==NULL){
        Cursus* new_cur = new CursusSecondaire(c, t, r, fil);
        TabCursus.insert(make_pair(c,new_cur));
    } else {
        cout<<"Erreur : Cursus Déjà présent !\n\n";
    }
}

/* Permet d'accéder à un Cursus existant
 * Argument : Code du Cursus (chaine de caractères)
 * Retour : Un pointeur sur l'objet Cursus recherché si le Cursus est trouvé
 *          Le pointeur NULL si le Cursus n'est pas trouvé
 */
Cursus* CursusManager::getCursus(QString c){
    map<QString, Cursus*>::iterator it=TabCursus.find(c);
    if (it!=TabCursus.end()){
        return (it->second);
    }
    else return NULL;
}

//Afficher un Cursus via le CursusManager en ligne de commande (a supprimer par la suite)
void CursusManager::afficherCursus(QString c){
    Cursus* findCursus=getCursus(c);
    if(findCursus!=NULL){
        findCursus->afficher();
    }
}

/* Permet de supprimer un Cursus du CursusManager
 * Argument : Le code du Cursus (chaine de caractères)
 */
void CursusManager::deleteCursus(QString c){
    Cursus* findCursus=getCursus(c);
    if(findCursus!=NULL){
        TabCursus.erase(c);
        delete(findCursus);
    }
}

int CursusManager::addListToCursusSecondaire(QString c, int nb){
    CursusSecondaire* findCursus= dynamic_cast<CursusSecondaire*>(getCursus(c));
    int indice_liste=-1;
    if(findCursus!=NULL){
        indice_liste=findCursus->creerList(nb);
    } else {
        cout<<"Cursus introuvable\n";
    }
    return indice_liste;
}

void CursusManager::addUVtoListFormCursusSecondaire(QString c, QString uv, int i){
    CursusSecondaire* findCursus= dynamic_cast<CursusSecondaire*>(getCursus(c));
    if(findCursus!=NULL){
        findCursus->addUVtoList(uv, i);
    } else {
        cout<<"Cursus introuvable\n";
    }
}
