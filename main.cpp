#include "mainwindow.h"
#include <QApplication>
#include "includes.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

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

    return a.exec();
}
