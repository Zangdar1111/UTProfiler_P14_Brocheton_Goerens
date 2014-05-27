#include "mainwindow.h"
#include <QApplication>
#include "includes.h"


int main(int argc, char *argv[])
{
    int i=0;
    QApplication a(argc, argv);


    QPixmap pixmap("./splash.png"); //PATH A MODIFIER
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
    splash.showMessage("Chargement des UV", Qt::AlignCenter, Qt::black);
    //for (i=0;i<1000000000;i++){}
    splash.clearMessage();
    splash.showMessage("Chargement des Cursus", Qt::AlignCenter, Qt::black);
    //for (i=0;i<1000000000;i++){}

    MainWindow w;
    w.show();

    splash.finish(&w);









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
