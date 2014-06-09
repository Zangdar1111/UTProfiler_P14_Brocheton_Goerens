#include "mainwindow.h"
#include <QApplication>
#include "includes.h"

void test_cursus_uv();
void test_cursus();
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

    MainWindow w;
    w.show();

    splash.finish(&w);


    DossierManage->addDossier("tbrochet","Brocheton Thibault",3);
    DossierManage->addDossier("mgoerens","Goerens Matthias",5);

    return a.exec();
    atexit(fin);

}
void fin()
{
    UVManager::kill();
    CursusManager::kill();
}
