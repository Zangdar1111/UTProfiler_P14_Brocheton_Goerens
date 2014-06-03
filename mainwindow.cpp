
#include "includes.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->MenuFichier_Quitter, SIGNAL(triggered()), this, SLOT(quit()));

    QObject::connect(ui->Seek_UV_Submit, SIGNAL(clicked()), this, SLOT(PrintUV()));
    QObject::connect(ui->Create_UV, SIGNAL(clicked()), this, SLOT(CreateUV()));
    QObject::connect(ui->Print_UV_List, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(EditUV(QListWidgetItem *)));
    QObject::connect(ui->Delete_UV, SIGNAL(clicked()), this, SLOT(DeleteUV()));
    QObject::connect(ui->Save_UV, SIGNAL(clicked()), this, SLOT(SaveUV()));

    QObject::connect(ui->Seek_Cursus_Submit, SIGNAL(clicked()), this, SLOT(PrintCursus()));
    QObject::connect(ui->Create_Cursus, SIGNAL(clicked()), this, SLOT(CreateCursus()));
    QObject::connect(ui->Print_Cursus_List, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(EditCursus(QListWidgetItem *)));
    QObject::connect(ui->Delete_Cursus, SIGNAL(clicked()), this, SLOT(DeleteCursus()));
    QObject::connect(ui->Save_Cursus, SIGNAL(clicked()), this, SLOT(SaveCursus()));

    QObject::connect(ui->Edit_Cursus_Prepa, SIGNAL(clicked()), this, SLOT(cursus_diff()));
    QObject::connect(ui->Edit_Cursus_Branche, SIGNAL(clicked()), this, SLOT(cursus_diff()));
    QObject::connect(ui->Edit_Cursus_Filiere, SIGNAL(clicked()), this, SLOT(cursus_diff()));
    QObject::connect(ui->Edit_Cursus_Mineur, SIGNAL(clicked()), this, SLOT(cursus_diff()));


    //Recuperation de la liste des UV
    PrintUV();
    PrintCursus();
}

//CursusManager* CursusManage = CursusManager::getInstance();
void MainWindow::quit()
{
    close();
}

void MainWindow::PrintCursus()
{

}

void MainWindow::CreateCursus()
{

}

void MainWindow::ResetCursus()
{
    ui->Edit_Cursus_Code->setText("");
    ui->Edit_Cursus_Titre->setText("");
    ui->Edit_Cursus_Resp->setText("");
    ui->Edit_Cursus_Prepa->setChecked(false);
    ui->Edit_Cursus_Branche->setChecked(false);
    ui->Edit_Cursus_Filiere->setChecked(false);
    ui->Edit_Cursus_Mineur->setChecked(false);
    ui->Edit_Cursus_CS->setValue(0);
    ui->Edit_Cursus_TM->setValue(0);
    ui->Edit_Cursus_TSH->setValue(0);
    ui->Edit_Cursus_SP->setValue(0);
    ui->Edit_Cursus_CSTM->setValue(0);
    ui->Edit_Cursus_Total->setValue(0);
    while (ui->Edit_Cursus_List1->count () > 0) delete ui->Edit_Cursus_List1->takeItem (0);
    while (ui->Edit_Cursus_List2->count () > 0) delete ui->Edit_Cursus_List2->takeItem (0);
    while (ui->Edit_Cursus_List3->count () > 0) delete ui->Edit_Cursus_List3->takeItem (0);
    ui->Edit_Cursus_Seek_Code->setText("");
}

void MainWindow::EditCursus(QListWidgetItem *item)
{

}

void MainWindow::DeleteCursus()
{

}

void MainWindow::SaveCursus()
{

}

void MainWindow::cursus_diff()
{
    if (ui->Edit_Cursus_Prepa->isChecked() || ui->Edit_Cursus_Branche->isChecked())
    {
        ui->Edit_Cursus_GroupCredits->setEnabled(true);
        ui->Edit_Cursus_GroupUV->setEnabled(false);
    }
    else if (ui->Edit_Cursus_Mineur->isChecked())
    {
        ui->Edit_Cursus_GroupCredits->setEnabled(false);
        ui->Edit_Cursus_GroupUV->setEnabled(true);
        ui->Edit_Cursus_List2->setEnabled(true);
        ui->Edit_Cursus_List3->setEnabled(true);
    }
    else if (ui->Edit_Cursus_Filiere->isChecked())
    {
        ui->Edit_Cursus_GroupCredits->setEnabled(false);
        ui->Edit_Cursus_GroupUV->setEnabled(true);
        ui->Edit_Cursus_List2->setEnabled(false);
        ui->Edit_Cursus_List3->setEnabled(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ResetUV()
{
    ui->Edit_UV_Code->setText("");
    ui->Edit_UV_Titre->setText("");
    ui->Edit_UV_Printemps->setChecked(false);
    ui->Edit_UV_Automne->setChecked(false);
    ui->Edit_UV_DemiUV->setChecked(false);
    ui->Edit_UV_CS->setValue(0);
    ui->Edit_UV_TM->setValue(0);
    ui->Edit_UV_TSH->setValue(0);
    ui->Edit_UV_SP->setValue(0);
    while (ui->Edit_UV_List1->count () > 0) delete ui->Edit_UV_List1->takeItem (0);
    while (ui->Edit_UV_List2->count () > 0) delete ui->Edit_UV_List2->takeItem (0);
}

void MainWindow::CreateUV()
{
    ResetUV();
    ui->Edit_UV_Code->setReadOnly(false);
    ui->Edit_UV_Group->setEnabled(true);
}

void MainWindow::EditUV(QListWidgetItem * item)
{
    ResetUV();
    //initialisation
    QString code = item->text();
    UVManager* UVManage = UVManager::getInstance();
    UV* uv = UVManage->getUV(code);
    ui->Edit_UV_Code->setReadOnly(true);
    ui->Edit_UV_Code->setText(code);
    ui->Edit_UV_Titre->setText(uv->getTitre());
    if (uv->getPresentPrintemps()) ui->Edit_UV_Printemps->setChecked(true);
    if (uv->getPresentAutomne()) ui->Edit_UV_Automne->setChecked(true);
    if (uv->getDemiUV()) ui->Edit_UV_DemiUV->setChecked(true);
    ui->Edit_UV_CS->setValue(uv->getCreditsCat(CS));
    ui->Edit_UV_TM->setValue(uv->getCreditsCat(TM));
    ui->Edit_UV_TSH->setValue(uv->getCreditsCat(TSH));
    ui->Edit_UV_SP->setValue(uv->getCreditsCat(SP));

    //Cursus ICI A AJOUTER

    ui->Edit_UV_Group->setEnabled(true);
}

void MainWindow::DeleteUV()
{
    int reponse = QMessageBox::question(this, "Supprimer l'UV "+ui->Edit_UV_Code->text(), "Etes vous sûr de vouloir supprimer cette UV ?", QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            //récupérer UV dans UVManager
            UVManager* UVManage = UVManager::getInstance();
            //supprimer l'UV du fichier
            UVManage->deleteUV_fichier(ui->Edit_UV_Code->text());
            //supprimer l'UV de UVManager et elle même
            UVManage->deleteUV(ui->Edit_UV_Code->text());
            ui->Edit_UV_Group->setEnabled(false);
            PrintUV();
            ResetUV();
        }
}

void MainWindow::SaveUV()
{
    //récupérer UV dans UVManager
    UVManager* UVManage = UVManager::getInstance();
    //Edition ou Sauvegarde
    UVManage->addUV(ui->Edit_UV_Code->text(),ui->Edit_UV_Titre->text(),ui->Edit_UV_Printemps->isChecked(),ui->Edit_UV_Automne->isChecked(),ui->Edit_UV_DemiUV->isChecked());
    UVManage->editUVCategorie(ui->Edit_UV_Code->text(),CS,ui->Edit_UV_CS->value());
    UVManage->editUVCategorie(ui->Edit_UV_Code->text(),TM,ui->Edit_UV_TM->value());
    UVManage->editUVCategorie(ui->Edit_UV_Code->text(),TSH,ui->Edit_UV_TSH->value());
    UVManage->editUVCategorie(ui->Edit_UV_Code->text(),SP,ui->Edit_UV_SP->value());
    //mise à jour du fichier
    UVManage->addUV_fichier(ui->Edit_UV_Code->text());
    //information de succès
    QMessageBox::information(this,"UV "+ui->Edit_UV_Code->text()+" sauvegardée","L'UV "+ui->Edit_UV_Code->text()+" a bien été sauvegardée !",QMessageBox::Ok);
    ui->Edit_UV_Group->setEnabled(false);
    ResetUV();
    PrintUV();
}

void MainWindow::PrintUV()
{
    ResetUV();
    ui->Edit_UV_Group->setEnabled(false);
    QString code_seek = ui->Seek_UV_Code->text();
    UVManager* UVManage = UVManager::getInstance();
    while (ui->Print_UV_List->count () > 0) delete ui->Print_UV_List->takeItem (0);
    QStringList list = UVManage->listerUV();
    list.sort();
    QStringList listnew;
    if (!ui->Seek_UV_CS->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (UVManage->getUV(*it)->getCreditsCat(CS)==0)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (!ui->Seek_UV_TM->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (UVManage->getUV(*it)->getCreditsCat(TM)==0)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (!ui->Seek_UV_TSH->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (UVManage->getUV(*it)->getCreditsCat(TSH)==0)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (!ui->Seek_UV_SP->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (UVManage->getUV(*it)->getCreditsCat(SP)==0)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (list.contains(code_seek))
    {
        ui->Print_UV_List->addItem(code_seek);
    }
    else
    {
        QStringList list2 = list.filter(code_seek);
        for(QList<QString>::iterator it=list2.begin() ; it!=list2.end() ; ++it)
            ui->Print_UV_List->addItem(*it);
    }
}
