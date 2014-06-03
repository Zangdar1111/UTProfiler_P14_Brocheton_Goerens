#include "mainwindow.h"
#include <QApplication>
#include "includes.h"

void test_cursus_uv();
void test_cursus();
void fin();

UVManager* UVManage = UVManager::getInstance();
CursusManager* CursusManage = CursusManager::getInstance();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QPixmap pixmap("../UTProfiler_P14_Brocheton_Goerens/splash.png");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
        splash.showMessage("Verification de l'intégrité des UV", Qt::AlignCenter, Qt::black);
        Sleep(1000);
        int code=UVManage->check_integrity();
        if (code==2)
        {
            splash.clearMessage();
            splash.showMessage("ERREUR lors de l'ouverture du fichier", Qt::AlignCenter, Qt::black);
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
        splash.clearMessage();
        splash.showMessage("Chargement des UV", Qt::AlignCenter, Qt::black);
        UVManage->load();
        Sleep(1000);
        splash.clearMessage();
        splash.showMessage("Chargement des Cursus", Qt::AlignCenter, Qt::black);
        Sleep(1000);

    MainWindow w;
    w.show();

    splash.finish(&w);


    test_cursus();




    return a.exec();
    atexit(fin);

}
void fin()
{
    UVManager::kill();
    CursusManager::kill();
}

void test_cursus(){
    //Exemple de Création d'un Cursus
    CursusManage->addCursusPrincipal("GI","Génie Informatique", "Philippe Trigano", 180, 30, 30, 86, 28, 60, true);
    CursusManage->addCursusPrincipal("TC","Tronc Commun", "Obi-Wan Kenobi", 120, 20, 20, 60, 16, 20, false);
    CursusManage->addCursusSecondaire("TCN", "Téchnologie Culturelles Numériques", "Darth Vador", false );

    //Exemple d'affichage
    CursusManage->afficherCursus("GI");
    CursusManage->afficherCursus("TC");
    CursusManage->afficherCursus("TCN");

    //Exemple d'ajout d'une liste d'UV à un Cursus Secondaire
    int indice_liste1 = CursusManage->addListToCursusSecondaire("TCN",2);
    //Exemple d'ajout d'une UV à une liste dans un Cursus Secondaire
    CursusManage->addUVtoListFormCursusSecondaire("TCN","L021",indice_liste1);
    CursusManage->addUVtoListFormCursusSecondaire("TCN","L022",indice_liste1);
    CursusManage->addUVtoListFormCursusSecondaire("TCN","L023",indice_liste1);
    CursusManage->afficherCursus("TCN");

    //Test Erreurs
    int indice_liste2 = CursusManage->addListToCursusSecondaire("GI",2);
    CursusManage->addUVtoListFormCursusSecondaire("TCN","L023",indice_liste1+1);
    CursusManage->addUVtoListFormCursusSecondaire("TCN","L023",-3);

    int indice_liste3 = CursusManage->addListToCursusSecondaire("TCN", 3);
    CursusManage->addUVtoListFormCursusSecondaire("TCN","NF16",indice_liste3);
    CursusManage->addUVtoListFormCursusSecondaire("TCN","NF17",indice_liste3);
    CursusManage->addUVtoListFormCursusSecondaire("TCN","NF18",indice_liste3);
    CursusManage->afficherCursus("TCN");

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
