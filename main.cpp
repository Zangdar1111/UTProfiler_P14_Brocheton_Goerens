#include "mainwindow.h"
#include <QApplication>
#include "includes.h"

void test_dossier();
void fin();

UVManager* UVManage = UVManager::getInstance();
CursusManager* CursusManage = CursusManager::getInstance();
DossierManager* DossierManage = DossierManager::getInstance();

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QPixmap pixmap("../UTProfiler_P14_Brocheton_Goerens/splash.png");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
    splash.showMessage("Verification de l'intégrité des UV", Qt::AlignCenter, Qt::black);
    int code=UVManage->check_integrity();
    Sleep(500);
    if (code==2)
    {
        splash.clearMessage();
        splash.showMessage("ERREUR lors de l'ouverture du fichier UV", Qt::AlignCenter, Qt::black);
        Sleep(4000);
        return 1;
    }
    if (code==1)
    {
        splash.clearMessage();
        splash.showMessage("ERREUR: Fichier UV Corrompu", Qt::AlignCenter, Qt::black);
        Sleep(4000);
        return 1;
    }
    splash.showMessage("Verification de l'intégrité des Cursus", Qt::AlignCenter, Qt::black);
    code=CursusManage->check_integrity();
    Sleep(500);
    if (code==2)
    {
        splash.clearMessage();
        splash.showMessage("ERREUR lors de l'ouverture du fichier Cursus", Qt::AlignCenter, Qt::black);
        Sleep(4000);
        return 1;
    }
    if (code==1)
    {
        splash.clearMessage();
        splash.showMessage("ERREUR: Fichier Cursus Corrompu", Qt::AlignCenter, Qt::black);
        Sleep(4000);
        return 1;
    }
    splash.clearMessage();
    splash.showMessage("Chargement des UV", Qt::AlignCenter, Qt::black);
    UVManage->load();
    Sleep(500);
    splash.clearMessage();
    splash.showMessage("Chargement des Cursus", Qt::AlignCenter, Qt::black);
    CursusManage->load();
    Sleep(500);
    splash.clearMessage();
    splash.showMessage("Chargement des Dossiers", Qt::AlignCenter, Qt::black);
    DossierManage->load();
    Sleep(500);
    MainWindow w;
    w.show();

    splash.finish(&w);

    //test_dossier();

    //DossierManage->addDossier("tbrochet","Brocheton Thibault",3);
    //DossierManage->addDossier("mgoerens","Goerens Matthias",5);

    return a.exec();
    atexit(fin);
    return 0;
}

void fin()
{
    UVManager::kill();
    CursusManager::kill();
    DossierManager::kill();
}

void test_dossier(){

    //Création d'UVs
    cout<<"Creation des UVs\n";
    UVManage->addUV("LO20","BlablaLO20", true, false, false);
    UVManage->addUV("LO21","Programmation Objet", true, false, false);
    UVManage->addUV("LO22","blablaLO22", true, false, false);
    UVManage->addUV("LO23","Conduite de projet informatique", false, true, false);

    UVManage->addUV("NF16","BlablaNF16", true, false, false);
    UVManage->addUV("NF17","BlablaNF17", true, false, false);
    UVManage->addUV("NF18","BlablaNF18", true, false, false);
    UVManage->addUV("NF19","BlablaNF19", true, false, false);
    UVManage->addUV("NF21","BlablaNF21", true, false, false);
    UVManage->addUV("NF22","BlablaNF22", true, false, false);
    UVManage->addUV("NF23","BlablaNF23", true, false, false);

    UVManage->addUV("TN10","BlablaTN10", true, false, false);


    cout<<"Ajout de categorie aux UVs\n";
    //Ajout de catégorie à une UV
    UVManage->editUVCategorie("LO20",TM,6);
    UVManage->editUVCategorie("LO21",TM,6);
    UVManage->editUVCategorie("LO22",CS,6);
    UVManage->editUVCategorie("LO23",CS,6);
    UVManage->editUVCategorie("NF16",TSH,4);
    UVManage->editUVCategorie("NF17",TSH,4);
    UVManage->editUVCategorie("NF18",TSH,4);
    UVManage->editUVCategorie("NF19",TSH,4);
    UVManage->editUVCategorie("NF21",TM,6);
    UVManage->editUVCategorie("NF22",CS,6);
    UVManage->editUVCategorie("NF23",CS,6);
    UVManage->editUVCategorie("TN10",SP,30);

    cout<<"Creation des Cursus\n";
    //Exemple de Création d'un Cursus
    CursusManage->addCursusPrincipal("GI","Génie Informatique", "Philippe Trigano", 50, 6, 6, 12, 8, 30, true);
    CursusManage->addCursusPrincipal("TC","Tronc Commun", "Obi-Wan Kenobi", 20, 6, 6, 12, 8, 0, false);
    CursusManage->addCursusSecondaire("SRI", "Systèmes et Réseaux Informatiques", "Darth Vador", true );

    cout<<"Ajout de Cursus aux UVs\n";
    //Ajout d'un cursus à une UV
    UVManage->addUVCursus("LO20", "TC");
    UVManage->addUVCursus("LO21", "GI");
    UVManage->addUVCursus("LO22", "TC");
    UVManage->addUVCursus("LO23", "GI");
    UVManage->addUVCursus("NF16", "TC");
    UVManage->addUVCursus("NF17", "TC");
    UVManage->addUVCursus("NF18", "GI");
    UVManage->addUVCursus("NF18", "GB");
    UVManage->addUVCursus("NF18", "GM");
    UVManage->addUVCursus("NF19", "GI");
    UVManage->addUVCursus("NF19", "GB");
    UVManage->addUVCursus("NF19", "GM");
    UVManage->addUVCursus("NF21", "GI");
    UVManage->addUVCursus("NF22", "GI");
    UVManage->addUVCursus("NF23", "GI");
    UVManage->addUVCursus("TN10", "GI");
    UVManage->addUVCursus("TN10", "GB");
    UVManage->addUVCursus("TN10", "GM");

    cout<<"Modifs de SRI\n";
    int indice_liste1 = CursusManage->addListToCursusSecondaire("SRI",2);

    //Exemple d'ajout d'une UV à une liste dans un Cursus Secondaire
    CursusManage->addUVtoListFromCursusSecondaire("SRI","NF21",indice_liste1);
    CursusManage->addUVtoListFromCursusSecondaire("SRI","NF22",indice_liste1);
    CursusManage->addUVtoListFromCursusSecondaire("SRI","NF23",indice_liste1);

    cout<<"Creation d'un dossier\n";
    //Création d'un dossier

    DossierManage->addDossier("someone", "Coucou Coucou", 4);
    DossierManage->setPrepa("someone", "TC");
    DossierManage->setBranche("someone", "GI");
    DossierManage->setFiliere("someone", "SRI");



    cout<<"Creation des inscriptions\n";
    //Création des inscriptions passées de 'someone'

    Semestre* A11 = new Semestre(Automne, 2011);
    QStringList* TabUVTC = new QStringList("LO20");
    TabUVTC->append("LO22");
    TabUVTC->append("NF16");
    TabUVTC->append("NF17");
    Note* TabResTC = new Note[4];
    TabResTC[0]=A;
    TabResTC[1]=A;
    TabResTC[2]=A;
    TabResTC[3]=A;
    InscriptionPassee* TC01 = new InscriptionPassee(A11, *TabUVTC, "TC", 4, TabResTC);


    Semestre* P12 = new Semestre(Printemps, 2012);
    QStringList* TabUVGI = new QStringList("LO21");
    TabUVGI->append("LO23");
    TabUVGI->append("NF18");
    TabUVGI->append("NF19");
    TabUVGI->append("NF21");
    TabUVGI->append("NF22");
    TabUVGI->append("NF23");
    TabUVGI->append("TN10");
    Note* TabResGI = new Note[9];
    TabResGI[0]=A;
    TabResGI[1]=A;
    TabResGI[2]=A;
    TabResGI[3]=A;
    TabResGI[4]=A;
    TabResGI[5]=A;
    TabResGI[6]=A;
    TabResGI[7]=A;
    TabResGI[8]=A;

    InscriptionPassee* GI01 = new InscriptionPassee(P12, *TabUVGI, "GI", 8, TabResGI);


    DossierManage->addParcours("someone", *TC01);
    DossierManage->addParcours("someone", *GI01);

    cout<<"Test du diplome du dossier\n";
    if(DossierManage->estDiplome("someone"))
        cout<<"Le dossier est validé!\n";
    else cout<<"Le dossier est refusé!\n";
}

/*
void test_cursus_uv(){
    //Exemple de création de Cursus
    CursusManage->addCursus("GI", "Génie Informatique", "Philippe Trigano");
    CursusManage->addCursus("TC", "Tronc Commun", "Obi-Wan Kenobi");
    CursusManage->addCursus("TCN", "Téchnologie Culturelles Numériques", "Darth Vador");

    //Affichage d'un Cursus
    CursusManage->afficherCursus("GI");
    CursusManage->afficherCursus("TC");
    CursusManage->afficherCursus("TCN");

    //Modification d'un Cursus
    CursusManage->addCursus("GI", "Génie Informatique", "Luke Skywalker");
    CursusManage->afficherCursus("GI");

    //Exemple de création d'UVs
    UVManage->addUV("LO23","Conduite de projet informatique", false, true, false);
    UVManage->addUV("LO21","Programmation Objet", true, false, false);

    //Ajout de catégorie à une UV
    UVManage->addUVCategorie("LO21",TM,3);
    UVManage->addUVCategorie("LO21",CS,3);
    UVManage->addUVCategorie("LO23",TM,6);

    //Ajout d'un cursus à une UV
    UVManage->addUVCursus("LO21", "GI");
    UVManage->addUVCursus("LO23", "GI");
    UVManage->addUVCursus("LO21", "TC");

    //Affichage des UVs
    UVManage->afficherUV("LO21");
    UVManage->afficherUV("LO23");

    //Modification d'une UV
    UVManage->addUV("LO21","Object Oriented Programming", true, true, true);
    UVManage->addUVCategorie("LO21",TM,6);
    //Tentative d'ajout d'un Cursus déjà présent
    UVManage->addUVCursus("LO21","GI");
    UVManage->afficherUV("LO21");

    //Tentative d'accès à une UV non existante
    UVManage->afficherUV("NF17");
    UVManage->addUVCategorie("NF17",TM,6);

    //Suppresion d'une UV
    UVManage->deleteUV("LO23");
    UVManage->afficherUV("LO23");
}*/

