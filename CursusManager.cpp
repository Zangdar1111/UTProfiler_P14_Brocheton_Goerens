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
void CursusManager::addCursusPrincipal(QString c, QString t, QString r, unsigned int tot, unsigned int cs, unsigned int tm, unsigned int cstm, unsigned int tsh, unsigned int sp, bool br){
    Cursus* findCursus=getCursus(c);
    if(findCursus==NULL){
        Cursus* new_cur = new CursusPrincipal(c, t, r, tot, cs, tm, cstm, tsh, sp, br);
        TabCursus.insert(make_pair(c,new_cur));
    } else
        dynamic_cast<CursusPrincipal*>(findCursus)->editCursusPrincipal(t, r, tot, cs, tm, cstm, tsh, sp, br);
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
    } else
        dynamic_cast<CursusSecondaire*>(findCursus)->editCursusSecondaire(t, r, fil);
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

/* Permet d'ajouter une liste d'UV à un CursusSecondaire
 * Arguments : le code du Cursus (chaine de caractères)
 *              le nombre d'UVs à valider dans cette liste (int)
 * Retourne l'indice de la chaine créée, ou -1 si le Cursus n'éxiste pas
 */
int CursusManager::addListToCursusSecondaire(QString c, unsigned int nb){
    CursusSecondaire* findCursus= dynamic_cast<CursusSecondaire*>(getCursus(c));
    int indice_liste=-1;
    if(findCursus!=NULL){
        indice_liste=findCursus->creerList(nb);
    } else {
        cout<<"Cursus introuvable\n";
    }
    return indice_liste;
}

/* Permet d'ajouter une UV à une liste d'UVs dans un CursusSecondaire
 * Arguments : le code du Cursus (chaine de caractères)
 *              le code de l'UV (chaine de caractères)
 *              l'indice de la liste à modifier (int)
 */
void CursusManager::addUVtoListFromCursusSecondaire(QString c, QString uv, unsigned int i){
    CursusSecondaire* findCursus= dynamic_cast<CursusSecondaire*>(getCursus(c));
    if(findCursus!=NULL){
        findCursus->addUVtoList(uv, i);
    } else {
        cout<<"Cursus introuvable\n";
    }
}

/* Permet de lister tous les Cursus chargés dans l'application
 * Argument: aucuns
 * Retourne une QStringList contenant le code de chaque Cursus
 * */
QStringList CursusManager::listerCursus()
{
    QStringList list;
    for(map<QString, Cursus*>::iterator it=TabCursus.begin() ; it!=TabCursus.end() ; ++it)
    {
        list.append(it->first); // accede à la clé
    }
    return list;
}

void CursusManager::removeListFromCursusSecondaire(QString code, unsigned int i){
    CursusSecondaire* findCursus= dynamic_cast<CursusSecondaire*>(getCursus(code));
    if(findCursus!=NULL){
        findCursus->removeList(i);
    } else {
        cout<<"Cursus introuvable\n";
    }
}

void CursusManager::removeUVfromListofCursusSecondaire(QString code, QString uv, unsigned int i){
    CursusSecondaire* findCursus= dynamic_cast<CursusSecondaire*>(getCursus(code));
    if(findCursus!=NULL){
        findCursus->removeUVFromList(uv, i);
    } else {
        cout<<"Cursus introuvable\n";
    }
}

void CursusManager::editNbUVsforListOfCursusSecondaire(QString code, unsigned int nb, unsigned int i){
    CursusSecondaire* findCursus= dynamic_cast<CursusSecondaire*>(getCursus(code));
    if(findCursus!=NULL){
        findCursus->setNbUVsforList(nb, i);
    } else {
        cout<<"Cursus introuvable\n";
    }
}

int CursusManager::check_integrity()
{
  int NbLigne=4;
  QFile fichier("../UTProfiler_P14_Brocheton_Goerens/data/cursus.txt");
  if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))  // si l'ouverture a réussi
  {
      QString test;
      QTextStream flux(&fichier);
      if (flux.readLine()!="#Principal#") return 1;
      while(!flux.atEnd())
      {
          test = flux.readLine();
          if (test=="#Secondaire#") NbLigne=7;
              for (unsigned int i=0;i<NbLigne;i++)
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

void CursusManager::load()
{
    bool secondaire=false;
    QFile fichier("../UTProfiler_P14_Brocheton_Goerens/data/cursus.txt");
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))  // si l'ouverture a réussi
    {
        QTextStream flux(&fichier);
        flux.readLine();
        while(! flux.atEnd())
        {
            QString code = flux.readLine();
            if ((code=="#Secondaire#") || (secondaire==true))
            {
                secondaire=true;
                if (code=="#Secondaire#") QString code = flux.readLine();
                QString titre= flux.readLine();
                QString resp = flux.readLine();

                QString ensembleuv = flux.readLine();
                QStringList tabuv = ensembleuv.split(";");
                QStringList listeuv[tabuv.size()];
                for(unsigned int i=0;i<tabuv.size();i++)
                {
                  listeuv[i]=tabuv.at(i).split(",");
                }

                QString listeval = flux.readLine();
                QStringList tabavalider = listeval.split(",");

                QString taille = flux.readLine();
                QString filiere = flux.readLine();

                addCursusSecondaire(code,titre,resp,filiere.toInt());
                for (unsigned int i=0;i<tabuv.size();i++)
                {
                  addListToCursusSecondaire(code,tabavalider.at(i).toInt());

                }
            }
            QString titre= flux.readLine();
            QString resp = flux.readLine();

            QString credits = flux.readLine();
            QStringList tc = credits.split(",");

            QString branche = flux.readLine();

            addCursusPrincipal(code,titre,resp,tc.at(0).toInt(),tc.at(1).toInt(),tc.at(2).toInt(),tc.at(3).toInt(),tc.at(4).toInt(),tc.at(5).toInt(),branche.toInt());
        }
    }
}

