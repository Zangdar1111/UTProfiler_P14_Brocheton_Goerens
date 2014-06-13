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
    else
    {
        UV* uv = new UV(c, t, p, a, d);
        TabUV.insert(make_pair(c,*uv));
    }
}

/* Permet d'ajouter une catégorie à une UV par le UVManager
 * Arguments : le code de l'UV (chaine de caractères)
 *              la catégorie à ajouter (Catégorie)
 *              le nombre de crédits apportés à cette catégorie (int)
 */
void UVManager::editUVCategorie(QString c, Categorie cat, int cre){
    UV* findUV=getUV(c);
    if(findUV!=NULL){
        findUV->addCreditsCat(cat, cre);
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

QStringList UVManager::getTabCursus(QString c){
    UV* findUV=getUV(c);
    if(findUV!=NULL)
        return findUV->getTab_Cursus();
    else return QStringList();
}

unsigned int UVManager::getNbCreditsCategorie(QString c, Categorie cat){
    UV* findUV=getUV(c);
    if(findUV!=NULL)
        return findUV->getCreditsCat(cat);
    return 0;
}

unsigned int UVManager::getNbTotCredits(QString c){
    UV* findUV=getUV(c);
    if(findUV!=NULL)
        return findUV->getCreditsCat(CS)+
                 findUV->getCreditsCat(TM)+
                 findUV->getCreditsCat(TSH)+
                 findUV->getCreditsCat(SP);
    else return 0;
}

bool UVManager::hasCursus(QString c, QString cursus){
    UV* findUV=getUV(c);
    if(findUV!=NULL)
        if(findUV->getTab_Cursus().contains(cursus))
            return true;
    cout<<"ne fait pas partie du bon Cursus\n";
    return false;
}


/* Permet de supprimer une UV de l'UVManager
 * Argument : Le code de l'UV (chaine de caractères)
 */
void UVManager::deleteUV(QString c)
{
    TabUV.erase(c);
}


/* Permet de lister toutes les UV chargées dans l'application
 * Argument: aucuns
 * Retourne une QStringList contenant le code de chaque UV
 * */
QStringList UVManager::listerUV()
{
    QStringList list;
    for(map<QString, UV>::iterator it=TabUV.begin() ; it!=TabUV.end() ; ++it)
    {
        list.append(it->first); // accede à la clé
    }
    return list;
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

QString UVManager::getUVfromCatCursus(Categorie cat, QString cursus, QStringList* listeUVsPresentes, QStringList TriUVs){
    cout<<"...Recherche d'Uvs... Critere : cat="<<cat<<"; cursus="<<cursus.toStdString()<<"\n";
    UV* findUV;
    for(int i=0; i<TriUVs.size(); i++){
        findUV=getUV(TriUVs.at(i));
        cout<<"test de l'UV "<<findUV->getCode().toStdString()<<", donne "<<findUV->getCreditsCat(cat)<<" credits dans cette categorie; hasCategorie renvoie : "<<findUV->hasCategorie(cat)<<"; dejà présent dans la liste renvoie : "<<listeUVsPresentes->contains(TriUVs.at(i))<<"\n";
        if(hasCursus(TriUVs.at(i), cursus)&&!listeUVsPresentes->contains(TriUVs.at(i))&&findUV->hasCategorie(cat)){
            cout<<"UV "<<findUV->getCode().toStdString()<<" OK !\n";
            return TriUVs.at(i); //Retourne le code de l'UV
        }
    }
    cout<<"Aucune UV trouvée...\n";
    return QString::null; //Si aucune UV ne correspond, on renvoie NULL
}

/* Permet de retirer tous les Cursus d'une UV par le UVManager
 * Arguments : le code de l'UV (chaine de caractères)
 */
void UVManager::removeAllUVCursus(QString c)
{
    UV* findUV=getUV(c);
    if(findUV!=NULL){
        findUV->deleteAllCursus();
    }
}

int UVManager::check_integrity()
{
    QFile fichier("../UTProfiler_P14_Brocheton_Goerens/data/uv.txt");
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))  // si l'ouverture a réussi
    {
        QString test;
        QTextStream flux(&fichier);
        while(!flux.atEnd())
        {
            test = flux.readLine();
            for (unsigned int i=0;i<5;i++)
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

            QString Credits_Categorie = flux.readLine();
            QStringList tCredits_Categorie = Credits_Categorie.split(",");

            QString Tab_Cursus = flux.readLine();
            QStringList tTab_Cursus = Tab_Cursus.split(",");

            QString DemiUV = flux.readLine();
            QString separateur = flux.readLine();

            addUV(code,titre,tsaison.at(0).toInt(),tsaison.at(1).toInt(),DemiUV.toInt());
            editUVCategorie(code,CS,tCredits_Categorie.at(0).toInt());
            editUVCategorie(code,TM,tCredits_Categorie.at(1).toInt());
            editUVCategorie(code,TSH,tCredits_Categorie.at(2).toInt());
            editUVCategorie(code,SP,tCredits_Categorie.at(3).toInt());
            if(tTab_Cursus.at(0)!="")
            {
            for(int i=0;i<tTab_Cursus.size();i++)
                addUVCursus(code,tTab_Cursus.at(i));
            }
        }
    }
}

void UVManager::deleteUV_fichier(QString c)
{

    QFile fichier("../UTProfiler_P14_Brocheton_Goerens/data/uv.txt");
    if(fichier.open(QIODevice::ReadWrite | QIODevice::Text))  // si l'ouverture a réussi
    {
        QTextStream flux(&fichier);
        QStringList tout;
        while(! flux.atEnd())
        {
            tout.append(flux.readLine());
        }
        int ind=tout.indexOf(c);
        for (unsigned int i=0;i<7;i++)
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

void UVManager::addUV_fichier(QString c)
{
    int ind;
    UV* uv = getUV(c);
    QFile fichier("../UTProfiler_P14_Brocheton_Goerens/data/uv.txt");
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
            for (unsigned int i=0;i<7;i++)
            {
                 tout.removeAt(ind);
            }
        }
        else
        {
            ind=tout.size();
        }

        tout.insert(ind,"#");
        tout.insert(ind,QString::number(uv->getDemiUV()));
        QString cursus;
        QStringList tabCursus = getTabCursus(uv->getCode());
            for(int i=0;i<tabCursus.size();i++)
            {
                if (i==tabCursus.size()-1)
                    cursus+=tabCursus.at(i);
                else
                    cursus+=tabCursus.at(i)+",";
            }
        tout.insert(ind,cursus);


        tout.insert(ind,QString::number(uv->getCreditsCat(CS))+","+QString::number(uv->getCreditsCat(TM))+","+QString::number(uv->getCreditsCat(TSH))+","+QString::number(uv->getCreditsCat(SP)));
        tout.insert(ind,QString::number(uv->getPresentPrintemps())+","+QString::number(uv->getPresentAutomne()));
        tout.insert(ind,uv->getTitre());
        tout.insert(ind,uv->getCode());

        fichier.resize(0);
        for(QList<QString>::iterator it=tout.begin() ; it!=tout.end() ; ++it)
        {
            flux<<*it<<"\n";
        }
    }
}
