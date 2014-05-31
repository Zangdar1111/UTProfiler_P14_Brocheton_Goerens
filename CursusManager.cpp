#include "includes.h"

/* Permet d'ajouter ou de mettre à jour un Cursus eu CursusManager
 * Arguments : Code du Cursus (chaine de caractères)
 *              Titre du Cursus (chaine de caractères)
 *              Responsable du Cursus (chaine de caractère)
 */
void CursusManager::addCursus(QString c, QString t, QString r){
    Cursus* findCursus=getCursus(c);
    if(findCursus!=NULL){
        findCursus->editCursus(t, r);
    }
    else{
        Cursus* new_cur = new Cursus(c, t, r);
        TabCursus.insert(make_pair(c,*new_cur));
    }
}

/* Permet d'accéder à un Cursus existant
 * Argument : Code du Cursus (chaine de caractères)
 * Retour : Un pointeur sur l'objet Cursus recherché si le Cursus est trouvé
 *          Le pointeur NULL si le Cursus n'est pas trouvé
 */
Cursus* CursusManager::getCursus(QString c){
    map<QString, Cursus>::iterator it=TabCursus.find(c);
    if (it!=TabCursus.end()){
        return &(it->second);
    }
    else return NULL;
}

//Afficher une UV via le UVManager en ligne de commande (a supprimer par la suite)
void CursusManager::afficherCursus(QString c){
    Cursus* findCursus=getCursus(c);
    if(findCursus!=NULL){
        findCursus->afficherCursus();
    }
}

/* Permet de supprimer un Cursus du CursusManager
 * Argument : Le code du Cursus (chaine de caractères)
 */
void CursusManager::deleteCursus(QString c){
    TabCursus.erase(c);
    //Que se passe t il se l'on demande de supprimer un Cursus qui n'existe pas ?
}
