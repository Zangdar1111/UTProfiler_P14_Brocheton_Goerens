#include "mainwindow.h"
#include <QApplication>
#include "includes.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Cursus* Curs_GI = new Cursus("GI", "Génie Informatique", "coucou");

    UV* test = new UV ("LO21", "Programmation Objet", false);
    test->afficherUV();

    return a.exec();
}
