
#include "includes.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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

    QObject::connect(ui->Edit_Dossier_No_Prepa,SIGNAL(clicked()),this,SLOT(No_Prepa()));

    //Onglet 4



    //Configuration au lancement
    PrintUV();

    PrintCursus();

    Print_Prepa();
    Print_Branche();
    Print_Filiere();
    Print_Mineur();
}

void MainWindow::No_Prepa()
{
    if (ui->Edit_Dossier_No_Prepa->isChecked()==true)
        ui->Edit_Dossier_Prepa->setEnabled(false);
    else
        ui->Edit_Dossier_Prepa->setEnabled(true);
}

void MainWindow::Print_Mineur()
{
    CursusManager* CursusManage = CursusManager::getInstance();
    QStringList list = CursusManage->listerCursus();
    list.sort();
    QStringList listnew;
    for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
    {
        if (CursusManage->getCursus(*it)->isWhat2()==1 && CursusManage->getCursus(*it)->isSecondaire()==1)
          listnew.append(*it);
    }
    list=listnew;
    listnew.clear();
    for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        ui->Edit_Dossier_Mineur->addItem(*it);
}

void MainWindow::Print_Filiere()
{
    CursusManager* CursusManage = CursusManager::getInstance();
    QStringList list = CursusManage->listerCursus();
    list.sort();
    QStringList listnew;
    for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
    {
        if (CursusManage->getCursus(*it)->isWhat1()==1 && CursusManage->getCursus(*it)->isSecondaire()==1)
          listnew.append(*it);
    }
    list=listnew;
    listnew.clear();
    for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        ui->Edit_Dossier_Filiere->addItem(*it);
}

void MainWindow::Print_Branche()
{
    CursusManager* CursusManage = CursusManager::getInstance();
    QStringList list = CursusManage->listerCursus();
    list.sort();
    QStringList listnew;
    for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
    {
        if (CursusManage->getCursus(*it)->isWhat2()==1 && CursusManage->getCursus(*it)->isPrincipal()==1)
          listnew.append(*it);
    }
    list=listnew;
    listnew.clear();
    for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        ui->Edit_Dossier_Branche->addItem(*it);
}

void MainWindow::Print_Prepa()
{
    CursusManager* CursusManage = CursusManager::getInstance();
    QStringList list = CursusManage->listerCursus();
    list.sort();
    QStringList listnew;
    for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
    {
        if (CursusManage->getCursus(*it)->isWhat1()==1 && CursusManage->getCursus(*it)->isPrincipal()==1)
          listnew.append(*it);
    }
    list=listnew;
    listnew.clear();
    for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        ui->Edit_Dossier_Prepa->addItem(*it);
}


void MainWindow::quit()
{
    close();
}

void MainWindow::PrintCursus()
{
    ResetCursus();
    ui->Edit_Cursus_Group->setEnabled(false);
    QString code_seek = ui->Seek_Cursus_Code->text();
    CursusManager* CursusManage = CursusManager::getInstance();
    while (ui->Print_Cursus_List->count () > 0) delete ui->Print_Cursus_List->takeItem (0);
    QStringList list = CursusManage->listerCursus();
    list.sort();
    QStringList listnew;
    if (!ui->Seek_Cursus_Prepa->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (CursusManage->getCursus(*it)->isWhat1()==0 || CursusManage->getCursus(*it)->isPrincipal()==0)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (!ui->Seek_Cursus_Branche->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (CursusManage->getCursus(*it)->isWhat2()==0 || CursusManage->getCursus(*it)->isPrincipal()==0)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (!ui->Seek_Cursus_Filiere->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (CursusManage->getCursus(*it)->isWhat1()==0 || CursusManage->getCursus(*it)->isSecondaire()==0)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (!ui->Seek_Cursus_Mineur->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (CursusManage->getCursus(*it)->isWhat2()==0 || CursusManage->getCursus(*it)->isSecondaire()==0)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (list.contains(code_seek))
    {
        ui->Print_Cursus_List->addItem(code_seek);
    }
    else
    {
        QStringList list2 = list.filter(code_seek);
        for(QList<QString>::iterator it=list2.begin() ; it!=list2.end() ; ++it)
            ui->Print_Cursus_List->addItem(*it);
    }
}

void MainWindow::CreateCursus()
{
    ResetCursus();
    ui->Edit_Cursus_Code->setReadOnly(false);
    ui->Edit_Cursus_Group->setEnabled(true);
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
    ui->Edit_Cursus_AValider1->setValue(0);
    ui->Edit_Cursus_AValider2->setValue(0);
    ui->Edit_Cursus_AValider3->setValue(0);
    ui->Edit_Cursus_Seek_Code->setText("");
}

void MainWindow::EditCursus(QListWidgetItem *item)
{
    ResetCursus();
    //initialisation
    QString code = item->text();
    CursusManager* CursusManage = CursusManager::getInstance();
    Cursus* curs = CursusManage->getCursus(code);
    ui->Edit_Cursus_Code->setReadOnly(true);
    ui->Edit_Cursus_Code->setText(code);
    ui->Edit_Cursus_Titre->setText(curs->getTitre());
    ui->Edit_Cursus_Resp->setText(curs->getResp());
    if (curs->isPrincipal()==1)
    {
        if (curs->isWhat1()==1) //Prépa
            ui->Edit_Cursus_Prepa->setChecked(true);
        else //Branche
            ui->Edit_Cursus_Branche->setChecked(true);
        CursusPrincipal* curs1 = dynamic_cast<CursusPrincipal*>(curs);
        ui->Edit_Cursus_CS->setValue(curs1->getCreditsCS());
        ui->Edit_Cursus_TM->setValue(curs1->getCreditsTM());
        ui->Edit_Cursus_TSH->setValue(curs1->getCreditsTSH());
        ui->Edit_Cursus_SP->setValue(curs1->getCreditsSP());
        ui->Edit_Cursus_CSTM->setValue(curs1->getCreditsCSTM());
        ui->Edit_Cursus_Total->setValue(curs1->getCreditsTotal());
    }
    else
    {
        CursusSecondaire* curs2 = dynamic_cast<CursusSecondaire*>(curs);
        if (curs2->isWhat1()==1) //Filière
        {
            ui->Edit_Cursus_Filiere->setChecked(true);
        }
        else //Mineur
        {
            ui->Edit_Cursus_Mineur->setChecked(true);
        }
        QStringList liste = curs2->getList(0);
        for (unsigned int i=0;i<liste.size();i++)
            ui->Edit_Cursus_List1->addItem(liste.at(i));
        ui->Edit_Cursus_AValider1->setValue(curs2->getNbUVAValiderfromList(0));
        if (curs2->getTailleTab()>1)
        {
            liste = curs2->getList(1);
            for (unsigned int i=0;i<liste.size();i++)
                ui->Edit_Cursus_List2->addItem(liste.at(i));
            ui->Edit_Cursus_AValider2->setValue(curs2->getNbUVAValiderfromList(1));
        }
        if (curs2->getTailleTab()>2)
        {
            liste = curs2->getList(2);
            for (unsigned int i=0;i<liste.size();i++)
                ui->Edit_Cursus_List3->addItem(liste.at(i));
            ui->Edit_Cursus_AValider3->setValue(curs2->getNbUVAValiderfromList(2));
        }
    }
    ui->Edit_Cursus_Group->setEnabled(true);
}

void MainWindow::DeleteCursus()
{

}

void MainWindow::SaveCursus()
{
    //récupérer UV dans UVManager
    CursusManager* CursusManage = CursusManager::getInstance();
    //Edition ou Sauvegarde
    if (CursusManage->getCursus(ui->Edit_Cursus_Code->text())->isPrincipal())
    {
        CursusManage->addCursusPrincipal(
            ui->Edit_Cursus_Code->text(),
            ui->Edit_Cursus_Titre->text(),
            ui->Edit_Cursus_Resp->text(),
            ui->Edit_Cursus_Total->value(),
            ui->Edit_Cursus_CS->value(),
            ui->Edit_Cursus_TM->value(),
            ui->Edit_Cursus_CSTM->value(),
            ui->Edit_Cursus_TSH->value(),
            ui->Edit_Cursus_SP->value(),
            ui->Edit_Cursus_Branche->isChecked()
            );
    }
    else
    {
        CursusManage->addCursusSecondaire(
            ui->Edit_Cursus_Code->text(),
            ui->Edit_Cursus_Titre->text(),
            ui->Edit_Cursus_Resp->text(),
            ui->Edit_Cursus_Filiere->isChecked()
            );

    }

    //mise à jour du fichier
    CursusManage->addCursus_fichier(ui->Edit_Cursus_Code->text());
    //information de succès
    QMessageBox::information(this,"Cursus "+ui->Edit_Cursus_Code->text()+" sauvegardée","Le Cursus "+ui->Edit_Cursus_Code->text()+" a bien été sauvegardée !",QMessageBox::Ok);
    ui->Edit_Cursus_Group->setEnabled(false);
    ResetCursus();
    PrintCursus();
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
        ui->Edit_Cursus_AValider2->setEnabled(true);
        ui->Edit_Cursus_AValider3->setEnabled(true);
    }
    else if (ui->Edit_Cursus_Filiere->isChecked())
    {
        ui->Edit_Cursus_GroupCredits->setEnabled(false);
        ui->Edit_Cursus_GroupUV->setEnabled(true);
        ui->Edit_Cursus_List2->setEnabled(false);
        ui->Edit_Cursus_List3->setEnabled(false);
        ui->Edit_Cursus_AValider2->setEnabled(false);
        ui->Edit_Cursus_AValider3->setEnabled(false);
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
    CursusManager* CursusManage = CursusManager::getInstance();
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

    QStringList liste = UVManage->getTabCursus(code);
    liste.sort();
    for (int i=0;i<liste.size();i++)
        ui->Edit_UV_List2->addItem(liste.at(i));

    QStringList liste2= CursusManage->listerCursus();
    QStringList liste3;
    for (int i=0;i<liste2.size();i++)
        if(!liste.contains(liste2.at(i)))
            liste3.append(liste2.at(i));
    liste3.sort();
    for (int i=0;i<liste3.size();i++)
        ui->Edit_UV_List1->addItem(liste3.at(i));

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

    //récupérer l'UVManager
    UVManager* UVManage = UVManager::getInstance();
    //Edition ou Sauvegarde
    UVManage->addUV(ui->Edit_UV_Code->text(),ui->Edit_UV_Titre->text(),ui->Edit_UV_Printemps->isChecked(),ui->Edit_UV_Automne->isChecked(),ui->Edit_UV_DemiUV->isChecked());
    UVManage->editUVCategorie(ui->Edit_UV_Code->text(),CS,ui->Edit_UV_CS->value());
    UVManage->editUVCategorie(ui->Edit_UV_Code->text(),TM,ui->Edit_UV_TM->value());
    UVManage->editUVCategorie(ui->Edit_UV_Code->text(),TSH,ui->Edit_UV_TSH->value());
    UVManage->editUVCategorie(ui->Edit_UV_Code->text(),SP,ui->Edit_UV_SP->value());
    UVManage->removeAllUVCursus(ui->Edit_UV_Code->text());
    while (ui->Edit_UV_List2->count () > 0)
    {
        QListWidgetItem* item = ui->Edit_UV_List2->item(0);
        UVManage->addUVCursus(ui->Edit_UV_Code->text(),item->text());
        delete ui->Edit_UV_List2->takeItem(0);
    }
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
    while (ui->Print_UV_List->count () > 0) ui->Print_UV_List->takeItem (0);
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

void MainWindow::addUV_Cursus()
{
    QString code_seek = ui->Edit_Cursus_Seek_Code->text();
    UVManager* UVManage = UVManager::getInstance();
    if (UVManage->getUV(code_seek)!=NULL)
    {
        ui->Edit_Cursus_List1->addItem(code_seek);
    }
    ui->Edit_Cursus_Seek_Code->setText("");
}

void MainWindow::poubelle(QListWidgetItem * item)
{
    delete item;
}
