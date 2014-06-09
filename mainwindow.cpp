
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
    QObject::connect(ui->Edit_Dossier_Semestre1_UV, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(poubelle(QListWidgetItem *)));
    QObject::connect(ui->Edit_Dossier_Semestre1_Notes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ChangeNote(QListWidgetItem *)));

    //Onglet 4



    //Configuration au lancement
    PrintUV();
    PrintCursus();
    PrintDossier();
}

void MainWindow::ChangeNote(QListWidgetItem* item)
{
    QString ancien = item->text(),New;
    if(ancien=="")
        New="EC";
    else if(ancien=="EC")
        New="A";
    else if(ancien=="A")
        New="B";
    else if(ancien=="B")
        New="C";
    else if(ancien=="C")
        New="D";
    else if(ancien=="D")
        New="E";
    else if(ancien=="E")
        New="F";
    else if(ancien=="F")
        New="FX";
    else if(ancien=="FX")
        New="RES";
    else if(ancien=="RES")
        New="ABS";
    else if(ancien=="ABS")
        New="";

    item->setText(New);
}

void MainWindow::DossierPrintUV()
{
    QString code_seek = ui->Edit_Dossier_UV_Code->text();
    UVManager* UVManage = UVManager::getInstance();
    while (ui->Edit_Dossier_UV_List->count () > 0) ui->Edit_Dossier_UV_List->takeItem (0);
    QStringList list = UVManage->listerUV();
    list.sort();
    QStringList listnew;
    if (!ui->Edit_Dossier_UV_CS->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (UVManage->getUV(*it)->getCreditsCat(CS)==0)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (!ui->Edit_Dossier_UV_TM->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (UVManage->getUV(*it)->getCreditsCat(TM)==0)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (!ui->Edit_Dossier_UV_TSH->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (UVManage->getUV(*it)->getCreditsCat(TSH)==0)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (!ui->Edit_Dossier_UV_SP->isChecked())
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
        ui->Edit_Dossier_UV_List->addItem(code_seek);
    }
    else
    {
        QStringList list2 = list.filter(code_seek);
        for(QList<QString>::iterator it=list2.begin() ; it!=list2.end() ; ++it)
            ui->Edit_Dossier_UV_List->addItem(*it);
    }
}

void MainWindow::EditDossierPrepa(QListWidgetItem *item)
{
    ui->Edit_Dossier_Current_Prepa->setText(item->text());
}

void MainWindow::EditDossierBranche(QListWidgetItem *item)
{
    ui->Edit_Dossier_Current_Branche->setText(item->text());
}

void MainWindow::EditDossierFiliere(QListWidgetItem *item)
{
    ui->Edit_Dossier_Current_Filiere->setText(item->text());
}

void MainWindow::EditDossierMineur(QListWidgetItem *item)
{
    QString min = ui->Edit_Dossier_Current_Mineur->text();
    QStringList mineur = min.split(",");
    if (mineur.contains(item->text()))
    {}
    else
    {
        if(min!="")
            min+=",";
        min+=item->text();
        ui->Edit_Dossier_Current_Mineur->setText(min);
    }
}

void MainWindow::EtapeSemestre()
{
    ui->Edit_Dossier_Semestre_Group->setEnabled(true);
    ui->Edit_Dossier_Cursus_Group->setEnabled(false);
    ui->Edit_Dossier_InfosBase_Group->setEnabled(false);
    ui->Edit_Dossier_Anglais->setEnabled(false);
    ui->Edit_Dossier_Current_Frame->setEnabled(false);
    ui->Edit_Dossier_Current_Valider->setEnabled(false);
    ui->Edit_Dossier_Current_Reset->setText("Retour");
}

void MainWindow::ResetCurrent()
{
    if(ui->Edit_Dossier_Current_Valider->isEnabled()==true)
    {
        ui->Edit_Dossier_Semestre_Group->setEnabled(false);
        ui->Edit_Dossier_Infos_Group->setEnabled(true);
        ui->Edit_Dossier_Current_Prepa->setText("");
        ui->Edit_Dossier_Current_Branche->setText("");
        ui->Edit_Dossier_Current_Filiere->setText("");
        ui->Edit_Dossier_Current_Mineur->setText("");
    }
    else
    {
        ui->Edit_Dossier_Semestre_Group->setEnabled(false);
        ui->Edit_Dossier_Cursus_Group->setEnabled(true);
        ui->Edit_Dossier_InfosBase_Group->setEnabled(true);
        ui->Edit_Dossier_Anglais->setEnabled(true);
        ui->Edit_Dossier_Current_Frame->setEnabled(true);
        ui->Edit_Dossier_Current_Valider->setEnabled(true);
        ui->Edit_Dossier_Current_Reset->setText("Reset");
    }
}

void MainWindow::EditDossier(QListWidgetItem* item)
{
    ResetDossier();
    ui->Edit_Dossier_Group->setEnabled(true);
    QString login = item->text();
    DossierManager* DossierManage = DossierManager::getInstance();
    Dossier* dossier = DossierManage->getDossier(login);
    ui->Edit_Dossier_Login->setText(login);
    ui->Edit_Dossier_NomPrenom->setText(dossier->getNomPrenom());
    if(dossier->getNiveauLangue()==1) ui->Edit_Dossier_Anglais1->setChecked(true);
    if(dossier->getNiveauLangue()==2) ui->Edit_Dossier_Anglais2->setChecked(true);
    if(dossier->getNiveauLangue()==3) ui->Edit_Dossier_Anglais3->setChecked(true);
    if(dossier->getNiveauLangue()==4) ui->Edit_Dossier_Anglais4->setChecked(true);
    if(dossier->getNiveauLangue()==5) ui->Edit_Dossier_Anglais5->setChecked(true);
    if(dossier->getNiveauLangue()==6) ui->Edit_Dossier_Anglais6->setChecked(true);
    Print_ListeCursus_Dossier();
    if (!dossier->getMineur().empty())
    {
        QStringList mineur= dossier->getMineur();
        QString listemineur;
        for(int i=0;i<mineur.size();i++)
        {
            listemineur+=mineur.at(i);
            if(i<mineur.size()-1)
                listemineur+=",";
        }
        ui->Edit_Dossier_Current_Prepa->setText(listemineur);
    }
    if (dossier->getPrepa()!=NULL) ui->Edit_Dossier_Current_Prepa->setText(dossier->getPrepa());
    if (dossier->getBranche()!=NULL) ui->Edit_Dossier_Current_Branche->setText(dossier->getBranche());
    if (dossier->getFiliere()!=NULL) ui->Edit_Dossier_Current_Filiere->setText(dossier->getFiliere());
}

void MainWindow::ResetDossier()
{
    ui->Edit_Dossier_Login->setText("");
    while (ui->Edit_Dossier_Prepa->count () > 0) ui->Edit_Dossier_Prepa->takeItem (0);
    while (ui->Edit_Dossier_Branche->count () > 0) ui->Edit_Dossier_Branche->takeItem (0);
    while (ui->Edit_Dossier_Filiere->count () > 0) ui->Edit_Dossier_Filiere->takeItem (0);
    while (ui->Edit_Dossier_Mineur->count () > 0) ui->Edit_Dossier_Mineur->takeItem (0);
}

void MainWindow::CreateDossier()
{
    ResetDossier();
    ui->Edit_Dossier_Login->setReadOnly(false);
    ui->Edit_Dossier_Group->setEnabled(true);
}

void MainWindow::PrintDossier()
{
    ResetDossier();
    ui->Edit_Dossier_Group->setEnabled(false);
    QString login = ui->Seek_Dossier_Login->text();
    DossierManager* DossierManage = DossierManager::getInstance();
    while (ui->Print_Dossier_List->count () > 0) ui->Print_Dossier_List->takeItem (0);
    QStringList list = DossierManage->listerDossier();
    list.sort();
    if (list.contains(login))
    {
        ui->Print_Dossier_List->addItem(login);
    }
    else
    {
        QStringList list2 = list.filter(login);
        for(QList<QString>::iterator it=list2.begin() ; it!=list2.end() ; ++it)
            ui->Print_Dossier_List->addItem(*it);
    }
}


void MainWindow::Print_ListeCursus_Dossier()
{
    //Mineur
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
    //Filiere
    list = CursusManage->listerCursus();
    list.sort();
    for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
    {
        if (CursusManage->getCursus(*it)->isWhat1()==1 && CursusManage->getCursus(*it)->isSecondaire()==1)
          listnew.append(*it);
    }
    list=listnew;
    listnew.clear();
    for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        ui->Edit_Dossier_Filiere->addItem(*it);
    //Branche
    list = CursusManage->listerCursus();
    list.sort();
    for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
    {
        if (CursusManage->getCursus(*it)->isWhat2()==1 && CursusManage->getCursus(*it)->isPrincipal()==1)
          listnew.append(*it);
    }
    list=listnew;
    listnew.clear();
    for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        ui->Edit_Dossier_Branche->addItem(*it);
    //Prepa
    list = CursusManage->listerCursus();
    list.sort();
    for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
    {
        if (CursusManage->getCursus(*it)->isWhat1()==1 && CursusManage->getCursus(*it)->isPrincipal()==1)
          listnew.append(*it);
    }
    list=listnew;
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
    if (item->text()=="EXT")
    {
        ui->Delete_Cursus->setEnabled(false);
        ui->Edit_Cursus_Branche->setEnabled(false);
        ui->Edit_Cursus_Filiere->setEnabled(false);
        ui->Edit_Cursus_Mineur->setEnabled(false);
    }
    ui->Edit_Cursus_Group->setEnabled(true);
}

void MainWindow::DeleteCursus()
{
    int reponse = QMessageBox::question(this, "Supprimer le Cursus "+ui->Edit_Cursus_Code->text(), "Etes vous sûr de vouloir supprimer ce Cursus ?", QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            //récupérer UV dans CursusManager
            CursusManager* CursusManage = CursusManager::getInstance();
            //supprimer l'UV du fichier
            CursusManage->deleteCursus_fichier(ui->Edit_Cursus_Code->text());
            //supprimer l'UV de UVManager et elle même
            CursusManage->deleteCursus(ui->Edit_Cursus_Code->text());
            ui->Edit_Cursus_Group->setEnabled(false);
            PrintCursus();
            ResetCursus();
        }
}

void MainWindow::SaveCursus()
{
    //récupérer UV dans UVManager
    CursusManager* CursusManage = CursusManager::getInstance();
    //Edition ou Sauvegarde
    int quel=0;
    if (CursusManage->getCursus(ui->Edit_Cursus_Code->text())==NULL)
    {
        if(ui->Edit_Cursus_Prepa->isChecked() ||  ui->Edit_Cursus_Branche->isChecked())
            quel=1;
    }
    else if (CursusManage->getCursus(ui->Edit_Cursus_Code->text())->isPrincipal())
        quel=1;

    if (quel==1)
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
        Cursus* curs = CursusManage->getCursus(ui->Edit_Cursus_Code->text());
        CursusSecondaire* curs2 = dynamic_cast<CursusSecondaire*>(curs);
        unsigned int ttab = curs2->getTailleTab();
        for (unsigned int i=ttab-1;i>-1;i--)
        {
            curs2->removeList(i);
            curs2->setNbUVsforList(0,i);
        }

        if (ui->Edit_Cursus_List1->count () > 0)
        {
            curs2->creerList(ui->Edit_Cursus_AValider1->value());

            while (ui->Edit_Cursus_List1->count () > 0)
            {
                QListWidgetItem* item = ui->Edit_Cursus_List1->item(0);
                curs2->addUVtoList(item->text(),0);
                delete ui->Edit_Cursus_List1->takeItem(0);
            }
        }
        if (ui->Edit_Cursus_List2->count () > 0)
        {
            curs2->creerList(ui->Edit_Cursus_AValider2->value());
            while (ui->Edit_Cursus_List2->count () > 0)
            {
                QListWidgetItem* item = ui->Edit_Cursus_List2->item(0);
                curs2->addUVtoList(item->text(),1);
                delete ui->Edit_Cursus_List2->takeItem(0);
            }
        }
        if (ui->Edit_Cursus_List3->count () > 0)
        {
            curs2->creerList(ui->Edit_Cursus_AValider3->value());
            while (ui->Edit_Cursus_List3->count () > 0)
            {
                QListWidgetItem* item = ui->Edit_Cursus_List3->item(0);
                curs2->addUVtoList(item->text(),2);
                delete ui->Edit_Cursus_List3->takeItem(0);
            }
        }
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
        while (ui->Edit_Cursus_List2->count () > 0) delete ui->Edit_Cursus_List1->takeItem (0);
        while (ui->Edit_Cursus_List2->count () > 0) delete ui->Edit_Cursus_List2->takeItem (0);
        while (ui->Edit_Cursus_List3->count () > 0) delete ui->Edit_Cursus_List3->takeItem (0);
        ui->Edit_Cursus_AValider1->setValue(0);
        ui->Edit_Cursus_AValider2->setValue(0);
        ui->Edit_Cursus_AValider3->setValue(0);
    }
    else if (ui->Edit_Cursus_Mineur->isChecked())
    {
        ui->Edit_Cursus_GroupCredits->setEnabled(false);
        ui->Edit_Cursus_GroupUV->setEnabled(true);
        ui->Edit_Cursus_List2->setEnabled(true);
        ui->Edit_Cursus_List3->setEnabled(true);
        ui->Edit_Cursus_AValider2->setEnabled(true);
        ui->Edit_Cursus_AValider3->setEnabled(true);
        ui->Edit_Cursus_CS->setValue(0);
        ui->Edit_Cursus_TM->setValue(0);
        ui->Edit_Cursus_TSH->setValue(0);
        ui->Edit_Cursus_SP->setValue(0);
        ui->Edit_Cursus_CSTM->setValue(0);
        ui->Edit_Cursus_Total->setValue(0);
    }
    else if (ui->Edit_Cursus_Filiere->isChecked())
    {
        ui->Edit_Cursus_GroupCredits->setEnabled(false);
        ui->Edit_Cursus_GroupUV->setEnabled(true);
        ui->Edit_Cursus_List2->setEnabled(false);
        ui->Edit_Cursus_List3->setEnabled(false);
        ui->Edit_Cursus_AValider2->setEnabled(false);
        ui->Edit_Cursus_AValider3->setEnabled(false);
        while (ui->Edit_Cursus_List2->count () > 0) delete ui->Edit_Cursus_List2->takeItem (0);
        while (ui->Edit_Cursus_List3->count () > 0) delete ui->Edit_Cursus_List3->takeItem (0);
        ui->Edit_Cursus_AValider2->setValue(0);
        ui->Edit_Cursus_AValider3->setValue(0);
        ui->Edit_Cursus_CS->setValue(0);
        ui->Edit_Cursus_TM->setValue(0);
        ui->Edit_Cursus_TSH->setValue(0);
        ui->Edit_Cursus_SP->setValue(0);
        ui->Edit_Cursus_CSTM->setValue(0);
        ui->Edit_Cursus_Total->setValue(0);
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
