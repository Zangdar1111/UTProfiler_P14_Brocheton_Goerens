
#include "includes.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Menu
    QObject::connect(ui->MenuFichier_Quitter, SIGNAL(triggered()), this, SLOT(quit()));
    //Onglet 1
    QObject::connect(ui->Seek_UV_Submit, SIGNAL(clicked()), this, SLOT(PrintUV()));
    QObject::connect(ui->Create_UV, SIGNAL(clicked()), this, SLOT(CreateUV()));
    QObject::connect(ui->Print_UV_List, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(EditUV(QListWidgetItem *)));
    QObject::connect(ui->Delete_UV, SIGNAL(clicked()), this, SLOT(DeleteUV()));
    QObject::connect(ui->Save_UV, SIGNAL(clicked()), this, SLOT(SaveUV()));
    //Onglet 2
    QObject::connect(ui->Seek_Cursus_Submit, SIGNAL(clicked()), this, SLOT(PrintCursus()));
    QObject::connect(ui->Create_Cursus, SIGNAL(clicked()), this, SLOT(CreateCursus()));
    QObject::connect(ui->Print_Cursus_List, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(EditCursus(QListWidgetItem *)));
    QObject::connect(ui->Delete_Cursus, SIGNAL(clicked()), this, SLOT(DeleteCursus()));
    QObject::connect(ui->Save_Cursus, SIGNAL(clicked()), this, SLOT(SaveCursus()));

    QObject::connect(ui->Edit_Cursus_Prepa, SIGNAL(toggled(bool)), this, SLOT(cursus_diff()));
    QObject::connect(ui->Edit_Cursus_Branche, SIGNAL(toggled(bool)), this, SLOT(cursus_diff()));
    QObject::connect(ui->Edit_Cursus_Filiere, SIGNAL(toggled(bool)), this, SLOT(cursus_diff()));
    QObject::connect(ui->Edit_Cursus_Mineur, SIGNAL(toggled(bool)), this, SLOT(cursus_diff()));

    QObject::connect(ui->Edit_Cursus_Seek_Submit, SIGNAL(clicked()), this, SLOT(addUV_Cursus()));

    QObject::connect(ui->Edit_Cursus_List1, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelle(QListWidgetItem *)));
    QObject::connect(ui->Edit_Cursus_List2, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelle(QListWidgetItem *)));
    QObject::connect(ui->Edit_Cursus_List3, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelle(QListWidgetItem *)));
    //Onglet 3
    QObject::connect(ui->Create_Dossier, SIGNAL(clicked()), this, SLOT(CreateDossier()));
    QObject::connect(ui->Seek_Dossier_Submit, SIGNAL(clicked()), this, SLOT(PrintDossier()));
    QObject::connect(ui->Print_Dossier_List, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(EditDossier(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Prepa, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(EditDossierPrepa(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Branche, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(EditDossierBranche(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Filiere, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(EditDossierFiliere(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Mineur, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(EditDossierMineur(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Current_Valider, SIGNAL(clicked()), this, SLOT(EtapeSemestre()));
    QObject::connect(ui->Edit_Dossier_Current_Reset, SIGNAL(clicked()), this, SLOT(ResetCurrent()));
    QObject::connect(ui->Edit_Dossier_UV_Seek, SIGNAL(clicked()), this, SLOT(DossierPrintUV()));

    QObject::connect(ui->Edit_Dossier_Semestre1_UV, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelleS1(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Semestre1_Notes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ChangeNoteS1(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Semestre2_UV, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelleS2(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Semestre2_Notes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ChangeNoteS2(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Semestre3_UV, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelleS3(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Semestre3_Notes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ChangeNoteS3(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Semestre4_UV, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelleS4(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Semestre4_Notes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ChangeNoteS4(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Semestre5_UV, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelleS5(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Semestre5_Notes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ChangeNoteS5(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Semestre6_UV, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelleS6(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Semestre6_Notes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ChangeNoteS6(QListWidgetItem *)));

    QObject::connect(ui->Edit_Dossier_SemestreB1_UV, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelleB1(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_SemestreB1_Notes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ChangeNoteB1(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_SemestreB2_UV, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelleB2(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_SemestreB2_Notes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ChangeNoteB2(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_SemestreB3_UV, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelleB3(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_SemestreB3_Notes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ChangeNoteB3(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_SemestreB4_UV, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelleB4(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_SemestreB4_Notes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ChangeNoteB4(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_SemestreB5_UV, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelleB5(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_SemestreB5_Notes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ChangeNoteB5(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_SemestreB6_UV, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelleB6(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_SemestreB6_Notes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ChangeNoteB6(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_SemestreB7_UV, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelleB7(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_SemestreB7_Notes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ChangeNoteB7(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_SemestreB8_UV, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelleB8(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_SemestreB8_Notes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ChangeNoteB8(QListWidgetItem *)));

    QObject::connect(ui->Edit_Dossier_Save, SIGNAL(clicked()), this, SLOT(SaveDossier()));
    QObject::connect(ui->Edit_Dossier_Delete, SIGNAL(clicked()), this, SLOT(DeleteDossier()));
    //Onglet 4



    //Configuration au lancement
    PrintUV();
    PrintCursus();
    PrintDossier();
}

void MainWindow::quit()
{
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::poubelle(QListWidgetItem * item)
{
    delete item;
}
