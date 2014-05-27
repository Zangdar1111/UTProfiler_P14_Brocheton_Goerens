#include "mainwindow.h"
#include <QApplication>
#include "includes.h"

UVManager* UVManage = UVManager::getInstance();
CursusManager* CursusManage = CursusManager::getInstance();

int main(int argc, char *argv[])
{
    int i=0;
    QApplication a(argc, argv);


    QPixmap pixmap("./splash.png"); //PATH A MODIFIER
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
    splash.showMessage("Chargement des UV", Qt::AlignCenter, Qt::black);
    //UVManage->load();
    splash.clearMessage();
    splash.showMessage("Chargement des Cursus", Qt::AlignCenter, Qt::black);
    for (i=0;i<200000000;i++){}

    MainWindow w;
    w.show();

    splash.finish(&w);

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
    UVManage->addUV("LO21","Programmation Objet", true, false, false);
    UVManage->addUV("LO23","Conduite de projet informatique", false, true, false);

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
    UVManage->afficherUV("LO21");

    //Tentative d'accès à une UV non existante
    UVManage->afficherUV("NF17");
    UVManage->addUVCategorie("NF17",TM,6);

    //Suppresion d'une UV
    UVManage->deleteUV("LO23");
    UVManage->afficherUV("LO23");

    UVManager::kill();
    CursusManager::kill();

    return a.exec();
}
