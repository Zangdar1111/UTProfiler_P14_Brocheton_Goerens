#include "mainwindow.h"
#include <QApplication>
#include "includes.h"

UVManager* UVManage = UVManager::getInstance();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /*
    Cursus* Curs_GI = new Cursus("GI", "Génie Informatique", "Philippe Trigano");
    Cursus* Curs_TC = new Cursus("TC", "Tronc commun", "Alain Storck");

    UV* test = new UV ("LO21", "Programmation Objet", false);
    test->afficherUV();

    test->ajouterCategorie(TM,6);
    test->afficherUV();

    test->ajouterCategorie(CS,6);
    test->afficherUV();

    test->ajouterCursus(*Curs_GI);
    test->afficherUV();

    test->ajouterCursus(*Curs_TC);
    test->afficherUV();
    */

    //Exemple de création d'UVs
    UVManage->addUV("LO21","Programmation Objet", false);
    UVManage->addUV("LO23","Conduite de projet informatique", false);

    //Ajout de catégorie à une UV
    UVManage->addUVCategorie("LO21",TM,3);
    UVManage->addUVCategorie("LO21",CS,3);
    UVManage->addUVCategorie("LO23",TM,6);

    //Affichage des UVs
    UVManage->afficherUV("LO21");
    UVManage->afficherUV("LO23");

    //Modification d'une UV
    UVManage->addUV("LO21","Object Oriented Programming", true);
    UVManage->afficherUV("LO21");

    //Tentative d'accès à une UV non existante
    UVManage->afficherUV("NF17");
    UVManage->addUVCategorie("NF17",TM,6);

    UVManager::kill();

    return a.exec();
}
