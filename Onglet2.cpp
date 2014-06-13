#include "includes.h"

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
    ui->Edit_Cursus_Prepa->setEnabled(true);
    ui->Edit_Cursus_Branche->setEnabled(true);
    ui->Edit_Cursus_Filiere->setEnabled(true);
    ui->Edit_Cursus_Mineur->setEnabled(true);
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
        for (int i=0;i<liste.size();i++)
            ui->Edit_Cursus_List1->addItem(liste.at(i));
        ui->Edit_Cursus_AValider1->setValue(curs2->getNbUVAValiderfromList(0));
        if (curs2->getTailleTab()>1)
        {
            liste = curs2->getList(1);
            for (int i=0;i<liste.size();i++)
                ui->Edit_Cursus_List2->addItem(liste.at(i));
            ui->Edit_Cursus_AValider2->setValue(curs2->getNbUVAValiderfromList(1));
        }
        if (curs2->getTailleTab()>2)
        {
            liste = curs2->getList(2);
            for (int i=0;i<liste.size();i++)
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
    else
    {
        ui->Delete_Cursus->setEnabled(true);
        ui->Edit_Cursus_Branche->setEnabled(true);
        ui->Edit_Cursus_Filiere->setEnabled(true);
        ui->Edit_Cursus_Mineur->setEnabled(true);
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
        for (int i=ttab-1;i>-1;i--)
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
