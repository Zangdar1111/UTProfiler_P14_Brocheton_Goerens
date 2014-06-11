#include "includes.h"


void MainWindow::poubelleS1(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_Semestre1_UV->currentRow();
    delete ui->Edit_Dossier_Semestre1_Notes->takeItem(ind);
    ui->Edit_Dossier_Semestre1_Notes->addItem("");
    delete item;
}

void MainWindow::poubelleS2(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_Semestre2_UV->currentRow();
    delete ui->Edit_Dossier_Semestre2_Notes->takeItem(ind);
    ui->Edit_Dossier_Semestre2_Notes->addItem("");
    delete item;
}

void MainWindow::poubelleS3(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_Semestre3_UV->currentRow();
    delete ui->Edit_Dossier_Semestre3_Notes->takeItem(ind);
    ui->Edit_Dossier_Semestre3_Notes->addItem("");
    delete item;
}

void MainWindow::poubelleS4(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_Semestre4_UV->currentRow();
    delete ui->Edit_Dossier_Semestre4_Notes->takeItem(ind);
    ui->Edit_Dossier_Semestre4_Notes->addItem("");
    delete item;
}

void MainWindow::poubelleS5(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_Semestre5_UV->currentRow();
    delete ui->Edit_Dossier_Semestre5_Notes->takeItem(ind);
    ui->Edit_Dossier_Semestre5_Notes->addItem("");
    delete item;
}

void MainWindow::poubelleS6(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_Semestre6_UV->currentRow();
    delete ui->Edit_Dossier_Semestre6_Notes->takeItem(ind);
    ui->Edit_Dossier_Semestre6_Notes->addItem("");
    delete item;
}

void MainWindow::poubelleB1(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB1_UV->currentRow();
    delete ui->Edit_Dossier_SemestreB1_Notes->takeItem(ind);
    ui->Edit_Dossier_SemestreB1_Notes->addItem("");
    delete item;
}

void MainWindow::poubelleB2(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB2_UV->currentRow();
    delete ui->Edit_Dossier_SemestreB2_Notes->takeItem(ind);
    ui->Edit_Dossier_SemestreB2_Notes->addItem("");
    delete item;
}

void MainWindow::poubelleB3(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB3_UV->currentRow();
    delete ui->Edit_Dossier_SemestreB3_Notes->takeItem(ind);
    ui->Edit_Dossier_SemestreB3_Notes->addItem("");
    delete item;
}

void MainWindow::poubelleB4(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB4_UV->currentRow();
    delete ui->Edit_Dossier_SemestreB4_Notes->takeItem(ind);
    ui->Edit_Dossier_SemestreB4_Notes->addItem("");
    delete item;
}

void MainWindow::poubelleB5(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB5_UV->currentRow();
    delete ui->Edit_Dossier_SemestreB5_Notes->takeItem(ind);
    ui->Edit_Dossier_SemestreB5_Notes->addItem("");
    delete item;
}

void MainWindow::poubelleB6(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB6_UV->currentRow();
    delete ui->Edit_Dossier_SemestreB6_Notes->takeItem(ind);
    ui->Edit_Dossier_SemestreB6_Notes->addItem("");
    delete item;
}

void MainWindow::poubelleB7(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB7_UV->currentRow();
    delete ui->Edit_Dossier_SemestreB7_Notes->takeItem(ind);
    ui->Edit_Dossier_SemestreB7_Notes->addItem("");
    delete item;
}

void MainWindow::poubelleB8(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB8_UV->currentRow();
    delete ui->Edit_Dossier_SemestreB8_Notes->takeItem(ind);
    ui->Edit_Dossier_SemestreB8_Notes->addItem("");
    delete item;
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

void MainWindow::ChangeNoteS1(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_Semestre1_Notes->currentRow();
    if(ui->Edit_Dossier_Semestre1_UV->count()>ind)
    {
       ChangeNote(item);
    }
}

void MainWindow::ChangeNoteS2(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_Semestre2_Notes->currentRow();
    if(ui->Edit_Dossier_Semestre2_UV->count()>ind)
    {
       ChangeNote(item);
    }
}

void MainWindow::ChangeNoteS3(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_Semestre3_Notes->currentRow();
    if(ui->Edit_Dossier_Semestre3_UV->count()>ind)
    {
       ChangeNote(item);
    }
}

void MainWindow::ChangeNoteS4(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_Semestre4_Notes->currentRow();
    if(ui->Edit_Dossier_Semestre4_UV->count()>ind)
    {
       ChangeNote(item);
    }
}

void MainWindow::ChangeNoteS5(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_Semestre5_Notes->currentRow();
    if(ui->Edit_Dossier_Semestre5_UV->count()>ind)
    {
       ChangeNote(item);
    }
}

void MainWindow::ChangeNoteS6(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_Semestre6_Notes->currentRow();
    if(ui->Edit_Dossier_Semestre6_UV->count()>ind)
    {
       ChangeNote(item);
    }
}

void MainWindow::ChangeNoteB1(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB1_Notes->currentRow();
    if(ui->Edit_Dossier_SemestreB1_UV->count()>ind)
    {
       ChangeNote(item);
    }
}

void MainWindow::ChangeNoteB2(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB2_Notes->currentRow();
    if(ui->Edit_Dossier_SemestreB2_UV->count()>ind)
    {
       ChangeNote(item);
    }
}

void MainWindow::ChangeNoteB3(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB3_Notes->currentRow();
    if(ui->Edit_Dossier_SemestreB3_UV->count()>ind)
    {
       ChangeNote(item);
    }
}

void MainWindow::ChangeNoteB4(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB4_Notes->currentRow();
    if(ui->Edit_Dossier_SemestreB4_UV->count()>ind)
    {
       ChangeNote(item);
    }
}

void MainWindow::ChangeNoteB5(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB5_Notes->currentRow();
    if(ui->Edit_Dossier_SemestreB5_UV->count()>ind)
    {
       ChangeNote(item);
    }
}

void MainWindow::ChangeNoteB6(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB6_Notes->currentRow();
    if(ui->Edit_Dossier_SemestreB6_UV->count()>ind)
    {
       ChangeNote(item);
    }
}

void MainWindow::ChangeNoteB7(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB7_Notes->currentRow();
    if(ui->Edit_Dossier_SemestreB7_UV->count()>ind)
    {
       ChangeNote(item);
    }
}

void MainWindow::ChangeNoteB8(QListWidgetItem* item)
{
    int ind = ui->Edit_Dossier_SemestreB8_Notes->currentRow();
    if(ui->Edit_Dossier_SemestreB8_UV->count()>ind)
    {
       ChangeNote(item);
    }
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
    VerifierCurrentCursus();
}

void MainWindow::EditDossierBranche(QListWidgetItem *item)
{
    ui->Edit_Dossier_Current_Branche->setText(item->text());
    VerifierCurrentCursus();
}

void MainWindow::EditDossierFiliere(QListWidgetItem *item)
{
    ui->Edit_Dossier_Current_Filiere->setText(item->text());
    VerifierCurrentCursus();
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
    VerifierCurrentCursus();
}

void MainWindow::EtapeSemestre()
{
    ui->Edit_Dossier_Cursus_Group->setEnabled(false);
    ui->Edit_Dossier_InfosBase_Group->setEnabled(false);
    ui->Edit_Dossier_Anglais->setEnabled(false);
    ui->Edit_Dossier_Current_Frame->setEnabled(false);
    ui->Edit_Dossier_Current_Valider->setEnabled(false);
    ui->Edit_Dossier_Current_Reset->setText("Retour");
    ui->Edit_Dossier_Semestre_Group->setEnabled(true);
    if (ui->Edit_Dossier_Current_Prepa->text()!="EXT" && ui->Edit_Dossier_Current_Prepa->text()!="")
    {
        ui->Edit_Dossier_SemestrePrepa_Group->setEnabled(true);
        ui->Edit_Dossier_UV_Group->setEnabled(true);
        ui->Edit_Dossier_Semestre1_Nom->setText(ui->Edit_Dossier_Current_Prepa->text()+"01");
        ui->Edit_Dossier_Semestre2_Nom->setText(ui->Edit_Dossier_Current_Prepa->text()+"02");
        ui->Edit_Dossier_Semestre3_Nom->setText(ui->Edit_Dossier_Current_Prepa->text()+"03");
        ui->Edit_Dossier_Semestre4_Nom->setText(ui->Edit_Dossier_Current_Prepa->text()+"04");
        ui->Edit_Dossier_Semestre5_Nom->setText(ui->Edit_Dossier_Current_Prepa->text()+"05");
        ui->Edit_Dossier_Semestre6_Nom->setText(ui->Edit_Dossier_Current_Prepa->text()+"06");
    }
    if (ui->Edit_Dossier_Current_Branche->text()!="")
    {
        ui->Edit_Dossier_SemestreBranche_Group->setEnabled(true);
        ui->Edit_Dossier_UV_Group->setEnabled(true);
        ui->Edit_Dossier_SemestreB1_Nom->setText(ui->Edit_Dossier_Current_Branche->text()+"01");
        ui->Edit_Dossier_SemestreB2_Nom->setText(ui->Edit_Dossier_Current_Branche->text()+"02");
        ui->Edit_Dossier_SemestreB3_Nom->setText(ui->Edit_Dossier_Current_Branche->text()+"03");
        ui->Edit_Dossier_SemestreB4_Nom->setText(ui->Edit_Dossier_Current_Branche->text()+"04");
        ui->Edit_Dossier_SemestreB5_Nom->setText(ui->Edit_Dossier_Current_Branche->text()+"05");
        ui->Edit_Dossier_SemestreB6_Nom->setText(ui->Edit_Dossier_Current_Branche->text()+"06");
        ui->Edit_Dossier_SemestreB7_Nom->setText(ui->Edit_Dossier_Current_Branche->text()+"07");
        ui->Edit_Dossier_SemestreB8_Nom->setText(ui->Edit_Dossier_Current_Branche->text()+"08");
    }
}

void MainWindow::VerifierCurrentCursus()
{
    bool stop=false;
    if(ui->Edit_Dossier_Current_Mineur->text()!="" && ui->Edit_Dossier_Current_Branche->text()=="" && (ui->Edit_Dossier_Current_Prepa->text()=="" || ui->Edit_Dossier_Current_Prepa->text()=="EXT"))
        stop=true;
    if(ui->Edit_Dossier_Current_Filiere->text()!="" && ui->Edit_Dossier_Current_Branche->text()=="")
        stop=true;
    if (stop)
        ui->Edit_Dossier_Current_Valider->setEnabled(false);
    else
        ui->Edit_Dossier_Current_Valider->setEnabled(true);
}

void MainWindow::ResetCurrent()
{
    if(ui->Edit_Dossier_Current_Reset->text()=="Reset")
    {
        ui->Edit_Dossier_Semestre_Group->setEnabled(false);
        ui->Edit_Dossier_Infos_Group->setEnabled(true);
        ui->Edit_Dossier_Current_Prepa->setText("");
        ui->Edit_Dossier_Current_Branche->setText("");
        ui->Edit_Dossier_Current_Filiere->setText("");
        ui->Edit_Dossier_Current_Mineur->setText("");
        ui->Edit_Dossier_Current_Valider->setEnabled(true);
    }
    else
    {
        ui->Edit_Dossier_SemestreBranche_Group->setEnabled(false);
        ui->Edit_Dossier_SemestrePrepa_Group->setEnabled(false);
        ui->Edit_Dossier_Semestre_Group->setEnabled(false);
        ui->Edit_Dossier_UV_Group->setEnabled(false);
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
    ui->Edit_Dossier_Infos_Group->setEnabled(true);
    ui->Edit_Dossier_Login->setReadOnly(true);
    QString login = item->text();
    DossierManager* DossierManage = DossierManager::getInstance();
    CursusManager* CursusManage = CursusManager::getInstance();
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
    QList<InscriptionPassee> Lsem = DossierManage->getAllParcours(item->text());
    int indexprepa=1,indexbranche=1;
    Note* result;
    for(QList<InscriptionPassee>::iterator it=Lsem.begin() ; it!=Lsem.end() ; ++it)
    {
        if(CursusManage->getCursus(it->getCursusPrincipal())->isWhat1()==1)
        {
            switch(indexprepa)
            {
                case 1:
                    ui->Edit_Dossier_Semestre1_UV->addItems(it->getListUV());
                    ui->Edit_Dossier_Semestre1_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_Dossier_Semestre1_Notes->addItem(note);
                    }
                    ui->Edit_Dossier_Semestre1_Nom->setText(it->getCursusPrincipal()+"01");
                break;

                case 2:
                    ui->Edit_Dossier_Semestre2_UV->addItems(it->getListUV());
                    ui->Edit_Dossier_Semestre2_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_Dossier_Semestre2_Notes->addItem(note);
                    }
                    ui->Edit_Dossier_Semestre2_Nom->setText(it->getCursusPrincipal()+"02");
                break;

                case 3:
                    ui->Edit_Dossier_Semestre3_UV->addItems(it->getListUV());
                    ui->Edit_Dossier_Semestre3_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_Dossier_Semestre3_Notes->addItem(note);
                    }
                    ui->Edit_Dossier_Semestre3_Nom->setText(it->getCursusPrincipal()+"03");
                break;

                case 4:
                    ui->Edit_Dossier_Semestre4_UV->addItems(it->getListUV());
                    ui->Edit_Dossier_Semestre4_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_Dossier_Semestre4_Notes->addItem(note);
                    }
                    ui->Edit_Dossier_Semestre4_Nom->setText(it->getCursusPrincipal()+"04");
                break;

                case 5:
                    ui->Edit_Dossier_Semestre5_UV->addItems(it->getListUV());
                    ui->Edit_Dossier_Semestre5_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_Dossier_Semestre5_Notes->addItem(note);
                    }
                    ui->Edit_Dossier_Semestre5_Nom->setText(it->getCursusPrincipal()+"05");
                break;

                case 6:
                    ui->Edit_Dossier_Semestre6_UV->addItems(it->getListUV());
                    ui->Edit_Dossier_Semestre6_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_Dossier_Semestre6_Notes->addItem(note);
                    }
                    ui->Edit_Dossier_Semestre6_Nom->setText(it->getCursusPrincipal()+"06");
                break;
            }
            indexprepa++;
        }
        else
        {
            switch(indexbranche)
            {
                case 1:
                    ui->Edit_Dossier_SemestreB1_UV->addItems(it->getListUV());
                    ui->Edit_Dossier_SemestreB1_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_Dossier_SemestreB1_Notes->addItem(note);
                    }
                    ui->Edit_Dossier_SemestreB1_Nom->setText(it->getCursusPrincipal()+"01");
                break;

                case 2:
                    ui->Edit_Dossier_SemestreB2_UV->addItems(it->getListUV());
                    ui->Edit_Dossier_SemestreB2_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_Dossier_SemestreB2_Notes->addItem(note);
                    }
                    ui->Edit_Dossier_SemestreB2_Nom->setText(it->getCursusPrincipal()+"02");
                break;

                case 3:
                    ui->Edit_Dossier_SemestreB3_UV->addItems(it->getListUV());
                    ui->Edit_Dossier_SemestreB3_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_Dossier_SemestreB3_Notes->addItem(note);
                    }
                    ui->Edit_Dossier_SemestreB3_Nom->setText(it->getCursusPrincipal()+"03");
                break;

                case 4:
                    ui->Edit_Dossier_SemestreB4_UV->addItems(it->getListUV());
                    ui->Edit_Dossier_SemestreB4_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_Dossier_SemestreB4_Notes->addItem(note);
                    }
                    ui->Edit_Dossier_SemestreB4_Nom->setText(it->getCursusPrincipal()+"04");
                break;

                case 5:
                    ui->Edit_Dossier_SemestreB5_UV->addItems(it->getListUV());
                    ui->Edit_Dossier_SemestreB5_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_Dossier_SemestreB5_Notes->addItem(note);
                    }
                    ui->Edit_Dossier_SemestreB5_Nom->setText(it->getCursusPrincipal()+"05");
                break;

                case 6:
                    ui->Edit_Dossier_SemestreB6_UV->addItems(it->getListUV());
                    ui->Edit_Dossier_SemestreB6_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_Dossier_SemestreB6_Notes->addItem(note);
                    }
                    ui->Edit_Dossier_SemestreB6_Nom->setText(it->getCursusPrincipal()+"06");
                break;

                case 7:
                    ui->Edit_Dossier_SemestreB7_UV->addItems(it->getListUV());
                    ui->Edit_Dossier_SemestreB7_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_Dossier_SemestreB7_Notes->addItem(note);
                    }
                    ui->Edit_Dossier_SemestreB7_Nom->setText(it->getCursusPrincipal()+"07");
                break;

                case 8:
                    ui->Edit_Dossier_SemestreB8_UV->addItems(it->getListUV());
                    ui->Edit_Dossier_SemestreB8_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_Dossier_SemestreB8_Notes->addItem(note);
                    }
                    ui->Edit_Dossier_SemestreB8_Nom->setText(it->getCursusPrincipal()+"08");
                break;
            }
            indexbranche++;
        }
    }






}

void MainWindow::ResetDossier()
{
    ui->Edit_Dossier_Login->setText("");
    ui->Edit_Dossier_NomPrenom->setText("");

    ui->Edit_Dossier_Anglais1->setChecked(false);
    ui->Edit_Dossier_Anglais2->setChecked(false);
    ui->Edit_Dossier_Anglais3->setChecked(false);
    ui->Edit_Dossier_Anglais4->setChecked(false);
    ui->Edit_Dossier_Anglais5->setChecked(false);
    ui->Edit_Dossier_Anglais6->setChecked(false);

    while (ui->Edit_Dossier_Prepa->count () > 0) ui->Edit_Dossier_Prepa->takeItem (0);
    while (ui->Edit_Dossier_Branche->count () > 0) ui->Edit_Dossier_Branche->takeItem (0);
    while (ui->Edit_Dossier_Filiere->count () > 0) ui->Edit_Dossier_Filiere->takeItem (0);
    while (ui->Edit_Dossier_Mineur->count () > 0) ui->Edit_Dossier_Mineur->takeItem (0);

    ui->Edit_Dossier_Current_Prepa->setText("");
    ui->Edit_Dossier_Current_Branche->setText("");
    ui->Edit_Dossier_Current_Filiere->setText("");
    ui->Edit_Dossier_Current_Mineur->setText("");
    ui->Edit_Dossier_Current_Reset->setText("Reset");

    ui->Edit_Dossier_InfosBase_Group->setEnabled(true);
    ui->Edit_Dossier_Anglais->setEnabled(true);
    ui->Edit_Dossier_Cursus_Group->setEnabled(true);
    ui->Edit_Dossier_Current_Valider->setEnabled(true);
    ui->Edit_Dossier_Current_Frame->setEnabled(true);
    ui->Edit_Dossier_Current->setEnabled(true);

    ui->Edit_Dossier_SemestrePrepa_Group->setEnabled(false);
    ui->Edit_Dossier_SemestreBranche_Group->setEnabled(false);
    ui->Edit_Dossier_Semestre_Group->setEnabled(false);
    ui->Edit_Dossier_UV_Group->setEnabled(false);
    ui->Edit_Dossier_Login->setReadOnly(false);
    ui->Edit_Dossier_Infos_Group->setEnabled(false);
    ui->Edit_Dossier_Group->setEnabled(false);
}

void MainWindow::CreateDossier()
{
    ResetDossier();
    Print_ListeCursus_Dossier();
    ui->Edit_Dossier_Group->setEnabled(true);
    ui->Edit_Dossier_Infos_Group->setEnabled(true);
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


void MainWindow::SaveDossier()
{

}

void MainWindow::DeleteDossier()
{
    int reponse = QMessageBox::question(this, "Supprimer le dossier "+ui->Edit_Dossier_Login->text(), "Etes vous sûr de vouloir supprimer ce Dossier ?", QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            //récupérer UV dans UVManager
            DossierManager* DossierManage = DossierManager::getInstance();
            //supprimer l'UV du fichier
            DossierManage->deleteDossier_fichier(ui->Edit_Dossier_Login->text());
            //supprimer l'UV de UVManager et elle même
            DossierManage->deleteDossier(ui->Edit_Dossier_Login->text());
            PrintDossier();
            ResetDossier();
        }
}
