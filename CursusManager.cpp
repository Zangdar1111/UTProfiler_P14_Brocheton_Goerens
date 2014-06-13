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

unsigned int CursusManager::getNbCreditsCatAValider(QString c, Categorie cat){
    CursusPrincipal* findCursus= dynamic_cast<CursusPrincipal*>(getCursus(c));
    if(findCursus!=NULL)
        return findCursus->getCreditsCat(cat);
    else return 0;
}

unsigned int CursusManager::getNbCreditsCSAValider(QString c){
    CursusPrincipal* findCursus= dynamic_cast<CursusPrincipal*>(getCursus(c));
    if(findCursus!=NULL)
        return findCursus->getCreditsCS();
    else return 0;
}

unsigned int CursusManager::getNbCreditsTMAValider(QString c){
    CursusPrincipal* findCursus= dynamic_cast<CursusPrincipal*>(getCursus(c));
    if(findCursus!=NULL){
        return findCursus->getCreditsTM();
    }
    else return 0;
}

unsigned int CursusManager::getNbCreditsCSTMAValider(QString c){
    CursusPrincipal* findCursus= dynamic_cast<CursusPrincipal*>(getCursus(c));
    if(findCursus!=NULL){
        return findCursus->getCreditsCSTM();
    }
    else return 0;
}

unsigned int CursusManager::getNbCreditsTSHAValider(QString c){
    CursusPrincipal* findCursus= dynamic_cast<CursusPrincipal*>(getCursus(c));
    if(findCursus!=NULL){
        return findCursus->getCreditsTSH();
    }
    else return 0;
}

unsigned int CursusManager::getNbCreditsSPAValider(QString c){
    CursusPrincipal* findCursus= dynamic_cast<CursusPrincipal*>(getCursus(c));
    if(findCursus!=NULL){
        return findCursus->getCreditsSP();
    }
    else return 0;
}

unsigned int CursusManager::getNbCreditsTotAValider(QString c){
    CursusPrincipal* findCursus= dynamic_cast<CursusPrincipal*>(getCursus(c));
    if(findCursus!=NULL){
        return findCursus->getCreditsTotal();
    }
    else return 0;
}

QStringList CursusManager::getListFromCursusSecondaire(QString c, unsigned int i){
    CursusSecondaire* findCursus= dynamic_cast<CursusSecondaire*>(getCursus(c));
    if(findCursus!=NULL){
        return (findCursus->getList(i));
    }
    else return QStringList();
}

unsigned int CursusManager::getTailleTabFromCursusSecondaire(QString c){
    CursusSecondaire* findCursus= dynamic_cast<CursusSecondaire*>(getCursus(c));
    if(findCursus!=NULL){
        return findCursus->getTailleTab();
    }
    else return 0;
}

int CursusManager::getNbUVsAValiderFromCursusSecondaire(QString c, unsigned int i){
    CursusSecondaire* findCursus= dynamic_cast<CursusSecondaire*>(getCursus(c));
    if(findCursus!=NULL){
        return findCursus->getNbUVAValiderfromList(i);
    }
    else return -1;
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
/*
bool CursusManager::isPrepa(QString c) const{
    CursusPrincipal* findCursus= dynamic_cast<CursusPrincipal*>(getCursus(c));
    if(findCursus!=NULL){
        return findCursus->isWhat1();
    }
    else return false;
}

bool CursusManager::isBranche(QString c) const{
    CursusPrincipal* findCursus= dynamic_cast<CursusPrincipal*>(getCursus(c));
    if(findCursus!=NULL){
        return findCursus->isWhat2();
    }
    else return false;
}
*/

/*
QString CursusManager::getUVfromCursus(QString code, QStringList listeUVs) const{
    CursusSecondaire* findCursus= dynamic_cast<CursusSecondaire*>(getCursus(code));
    unsigned int i=0;
    if(findCursus!=NULL){
        while(i<findCursus->getTailleTab()&&!trouve){

            i++;
        }
    } else {
        cout<<"Cursus introuvable\n";
    }
}*/


int CursusManager::check_integrity()
{
  unsigned int NbLigne=4;
  QFile fichier("../UTProfiler_P14_Brocheton_Goerens/data/cursus.txt");
  if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))  // si l'ouverture a réussi
  {
      QString test;
      QTextStream flux(&fichier);
      if (flux.readLine()!="#Principal#") return 1;
      while(!flux.atEnd())
      {
          test = flux.readLine();
          if (test=="#Secondaire#")
          {
              NbLigne=5;
              test=flux.readLine();
              if(flux.atEnd())
                  return 0;
          }
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
        QString code;
        QTextStream flux(&fichier);
        flux.readLine();
        while(!flux.atEnd())
        {
            code = flux.readLine();
            if ((code=="#Secondaire#") || (secondaire==true))
            {

                secondaire=true;
                if (code=="#Secondaire#") code = flux.readLine();
                if(flux.atEnd()) break;
                QString titre= flux.readLine();
                QString resp = flux.readLine();

                QString ensembleuv = flux.readLine();

                QStringList tabuv = ensembleuv.split(";");

                QStringList listeuv[tabuv.size()];

                for(int i=0;i<tabuv.size();i++)
                {
                  listeuv[i]=tabuv.at(i).split(",");
                }
                QString listeval = flux.readLine();
                QStringList tabavalider = listeval.split(",");

                QString filiere = flux.readLine();

                addCursusSecondaire(code,titre,resp,filiere.toInt());


                for (int i=0;i<tabuv.size();i++)
                {
                    addListToCursusSecondaire(code,tabavalider.at(i).toInt());
                    for (int j=0;j<listeuv[i].size();j++)
                        addUVtoListFromCursusSecondaire(code,listeuv[i].at(j),i);
                }
            }
            else
            {
            QString titre= flux.readLine();
            QString resp = flux.readLine();

            QString credits = flux.readLine();
            QStringList tc = credits.split(",");

            QString branche = flux.readLine();

            addCursusPrincipal(code,titre,resp,tc.at(0).toInt(),tc.at(1).toInt(),tc.at(2).toInt(),tc.at(3).toInt(),tc.at(4).toInt(),tc.at(5).toInt(),branche.toInt());
            }
            flux.readLine();
        }

    }
}

void CursusManager::deleteCursus_fichier(QString c)
{
    unsigned int taille = 6;
    if (getCursus(c)->isSecondaire()) taille++;
    QFile fichier("../UTProfiler_P14_Brocheton_Goerens/data/cursus.txt");
    if(fichier.open(QIODevice::ReadWrite | QIODevice::Text))  // si l'ouverture a réussi
    {
        QTextStream flux(&fichier);
        QStringList tout;
        while(! flux.atEnd())
        {
            tout.append(flux.readLine());
        }
        int ind=tout.indexOf(c);
        for (unsigned int i=0;i<taille;i++)
        {
             tout.removeAt(ind);
        }
        fichier.resize(0);
        for(QList<QString>::iterator it=tout.begin() ; it!=tout.end() ; ++it)
        {
            flux<<*it<<"\n";
        }
    }
}

void CursusManager::addCursus_fichier(QString c)
{
    int ind;
    unsigned int taille = 6;
    if (getCursus(c)->isSecondaire()) taille++;
    Cursus* curs = getCursus(c);
    QFile fichier("../UTProfiler_P14_Brocheton_Goerens/data/cursus.txt");
    if(fichier.open(QIODevice::ReadWrite | QIODevice::Text))  // si l'ouverture a réussi
    {
        QTextStream flux(&fichier);
        QStringList tout;
        while(! flux.atEnd())
        {
            tout.append(flux.readLine());
        }
        if (tout.contains(c))
        {
            ind=tout.indexOf(c);
            for (unsigned int i=0;i<taille;i++)
            {
                 tout.removeAt(ind);
            }
        }
        else
        {
            if(curs->isPrincipal())
                ind=tout.indexOf("#Secondaire#");
            else
                ind=tout.size();
        }
        cout<<tout.indexOf("#Secondaire#")<<endl;
        cout<<tout.indexOf("SRI")<<endl;
        tout.insert(ind,"#");
        if (getCursus(c)->isPrincipal())
        {
            CursusPrincipal* curs1 = dynamic_cast<CursusPrincipal*>(curs);
            tout.insert(ind,QString::number(curs1->isWhat2()));
            tout.insert(ind,QString::number(curs1->getCreditsTotal())+","+
                        QString::number(curs1->getCreditsCS())+","+
                        QString::number(curs1->getCreditsTM())+","+
                        QString::number(curs1->getCreditsCSTM())+","+
                        QString::number(curs1->getCreditsTSH())+","+
                        QString::number(curs1->getCreditsSP()));
        }
        else
        {
            CursusSecondaire* curs2 = dynamic_cast<CursusSecondaire*>(curs);
            curs2->afficher();
            unsigned int ttab = curs2->getTailleTab();
            QString nbuv,uvs;
            QStringList listeuv;
            for (unsigned int i=0;i<ttab;i++)
            {
                 nbuv+=QString::number(curs2->getNbUVAValiderfromList(i));
                 if (i<ttab-1)
                     nbuv+=",";

                 listeuv=curs2->getList(i);
                 for (int j=0;j<listeuv.size();j++)
                 {
                     uvs+=listeuv.at(j);
                     if (j<listeuv.size()-1)
                         uvs+=",";
                     else
                     {
                         if(i<ttab-1)
                            uvs+=";";
                     }
                 }
            }

            tout.insert(ind,QString::number(curs2->isWhat1()));
            tout.insert(ind,nbuv);
            tout.insert(ind,uvs);
        }
        tout.insert(ind,curs->getResp());
        tout.insert(ind,curs->getTitre());
        tout.insert(ind,curs->getCode());

        fichier.resize(0);
        for(QList<QString>::iterator it=tout.begin() ; it!=tout.end() ; ++it)
        {
            flux<<*it<<"\n";
        }
    }
}
