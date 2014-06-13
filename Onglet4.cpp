#include "includes.h"

void MainWindow::ExecuterAutoCompletion()
{
    QString login =  ui->Edit_AutoDossier_CurrentSolution->text();
    UVManager* UVManage = UVManager::getInstance();
    DossierManager* DossierManage = DossierManager::getInstance();
    QStringList uvsOui,uvsNon;
    while(ui->Edit_AutoDossier_UV_Oui->count()>0)
        uvsOui.append(ui->Edit_AutoDossier_UV_Oui->item(0)->text());
    while(ui->Edit_AutoDossier_UV_Non->count()>0)
        uvsNon.append(ui->Edit_AutoDossier_UV_Non->item(0)->text());
    QStringList allUV = UVManage->listerUV();
    for(int i=0;i<uvsNon.size();i++)
    {
        if(uvsOui.contains(uvsNon.at(i)))
            uvsOui.removeOne(uvsNon.at(i));
    }
    for(int i=0;i<uvsOui.size();i++)
    {
        if(allUV.contains(uvsOui.at(i)))
            allUV.removeOne(uvsOui.at(i));
    }
    for(int i=0;i<uvsNon.size();i++)
    {
        if(allUV.contains(uvsNon.at(i)))
            allUV.removeOne(uvsNon.at(i));
    }
    for(int i=0;i<allUV.size();i++)
    {
        uvsOui.append(allUV.at(i));
    }
    for(int i=0;i<uvsNon.size();i++)
    {
        uvsOui.append(uvsNon.at(i));
    }
    Solution* Sol;
    //Solution* Sol = DossierManage->proposerSolution(login,uvsOui);
    if(Sol==NULL)
        QMessageBox::information(this,"Erreur","Les paramètres fournis n'ont pas permis de calculer une solution.",QMessageBox::Ok);
    else
    {
        QList<InscriptionFuture> Lfut = Sol->getListePrevisions();
        CursusManager* CursusManage = CursusManager::getInstance();
        for(QList<InscriptionFuture>::iterator it=Lfut.begin() ; it!=Lfut.end() ; ++it)
        {
            if(CursusManage->getCursus(it->getCursusPrincipal())->isWhat1()==1)
            {
                if(MainWindow::ui->Edit_AutoDossier_Semestre1_UV->count() == 0)
                    ui->Edit_AutoDossier_Semestre1_UV->addItems(it->getListUV());
                else if(ui->Edit_AutoDossier_Semestre2_UV->count() == 0)
                    ui->Edit_AutoDossier_Semestre2_UV->addItems(it->getListUV());
                else if(ui->Edit_AutoDossier_Semestre3_UV->count() == 0)
                    ui->Edit_AutoDossier_Semestre3_UV->addItems(it->getListUV());
                else if(ui->Edit_AutoDossier_Semestre4_UV->count() == 0)
                    ui->Edit_AutoDossier_Semestre4_UV->addItems(it->getListUV());
                else if(ui->Edit_AutoDossier_Semestre5_UV->count() == 0)
                    ui->Edit_AutoDossier_Semestre5_UV->addItems(it->getListUV());
                else if(ui->Edit_AutoDossier_Semestre6_UV->count() == 0)
                    ui->Edit_AutoDossier_Semestre6_UV->addItems(it->getListUV());
            }
            else
            {
                if(ui->Edit_AutoDossier_SemestreB1_UV->count() == 0)
                    ui->Edit_AutoDossier_SemestreB1_UV->addItems(it->getListUV());
                else if(ui->Edit_AutoDossier_SemestreB2_UV->count() == 0)
                    ui->Edit_AutoDossier_SemestreB2_UV->addItems(it->getListUV());
                else if(ui->Edit_AutoDossier_SemestreB3_UV->count() == 0)
                    ui->Edit_AutoDossier_SemestreB3_UV->addItems(it->getListUV());
                else if(ui->Edit_AutoDossier_SemestreB4_UV->count() == 0)
                    ui->Edit_AutoDossier_SemestreB4_UV->addItems(it->getListUV());
                else if(ui->Edit_AutoDossier_SemestreB5_UV->count() == 0)
                    ui->Edit_AutoDossier_SemestreB5_UV->addItems(it->getListUV());
                else if(ui->Edit_AutoDossier_SemestreB6_UV->count() == 0)
                    ui->Edit_AutoDossier_SemestreB6_UV->addItems(it->getListUV());
                else if(ui->Edit_AutoDossier_SemestreB7_UV->count() == 0)
                    ui->Edit_AutoDossier_SemestreB7_UV->addItems(it->getListUV());
                else if(ui->Edit_AutoDossier_SemestreB8_UV->count() == 0)
                    ui->Edit_AutoDossier_SemestreB8_UV->addItems(it->getListUV());
            }
        }
    }
}




void MainWindow::SaveAutoDossier()
{
    QString login =  ui->Edit_AutoDossier_CurrentSolution->text();
    DossierManager* DossierManage = DossierManager::getInstance();
    Dossier* dossier = DossierManage->getDossier(login);
    Solution Sol = Solution();
    Semestre* ajout = dossier->getSemestreCourant();
    Semestre* newSem = new Semestre(*ajout);
    if(ui->Edit_AutoDossier_Semestre1_Notes->count()==0 and ui->Edit_AutoDossier_Semestre1_UV->count()>0)
    {
        newSem->incrementer();
        QStringList uvs;
        while (ui->Edit_Dossier_Semestre1_UV->count () > 0)
            uvs.append(ui->Edit_Dossier_Semestre1_UV->item(0)->text());
        Sol.addPrevision(InscriptionFuture(newSem,uvs,dossier->getPrepa(),uvs.size()));
    }
    if(ui->Edit_AutoDossier_Semestre2_Notes->count()==0 and ui->Edit_AutoDossier_Semestre2_UV->count()>0)
    {
        newSem->incrementer();
        QStringList uvs;
        while (ui->Edit_Dossier_Semestre2_UV->count () > 0)
            uvs.append(ui->Edit_Dossier_Semestre2_UV->item(0)->text());
        Sol.addPrevision(InscriptionFuture(newSem,uvs,dossier->getPrepa(),uvs.size()));
    }
    if(ui->Edit_AutoDossier_Semestre3_Notes->count()==0 and ui->Edit_AutoDossier_Semestre3_UV->count()>0)
    {
        newSem->incrementer();
        QStringList uvs;
        while (ui->Edit_Dossier_Semestre3_UV->count () > 0)
            uvs.append(ui->Edit_Dossier_Semestre3_UV->item(0)->text());
        Sol.addPrevision(InscriptionFuture(newSem,uvs,dossier->getPrepa(),uvs.size()));
    }
    if(ui->Edit_AutoDossier_Semestre4_Notes->count()==0 and ui->Edit_AutoDossier_Semestre4_UV->count()>0)
    {
        newSem->incrementer();
        QStringList uvs;
        while (ui->Edit_Dossier_Semestre4_UV->count () > 0)
            uvs.append(ui->Edit_Dossier_Semestre4_UV->item(0)->text());
        Sol.addPrevision(InscriptionFuture(newSem,uvs,dossier->getPrepa(),uvs.size()));
    }
    if(ui->Edit_AutoDossier_Semestre5_Notes->count()==0 and ui->Edit_AutoDossier_Semestre5_UV->count()>0)
    {
        newSem->incrementer();
        QStringList uvs;
        while (ui->Edit_Dossier_Semestre5_UV->count () > 0)
            uvs.append(ui->Edit_Dossier_Semestre5_UV->item(0)->text());
        Sol.addPrevision(InscriptionFuture(newSem,uvs,dossier->getPrepa(),uvs.size()));
    }
    if(ui->Edit_AutoDossier_Semestre6_Notes->count()==0 and ui->Edit_AutoDossier_Semestre6_UV->count()>0)
    {
        newSem->incrementer();
        QStringList uvs;
        while (ui->Edit_Dossier_Semestre6_UV->count () > 0)
            uvs.append(ui->Edit_Dossier_Semestre6_UV->item(0)->text());
        Sol.addPrevision(InscriptionFuture(newSem,uvs,dossier->getPrepa(),uvs.size()));
    }

    if(ui->Edit_AutoDossier_SemestreB1_Notes->count()==0 and ui->Edit_AutoDossier_SemestreB1_UV->count()>0)
    {
        newSem->incrementer();
        QStringList uvs;
        while (ui->Edit_Dossier_SemestreB1_UV->count () > 0)
            uvs.append(ui->Edit_Dossier_SemestreB1_UV->item(0)->text());
        Sol.addPrevision(InscriptionFuture(newSem,uvs,dossier->getBranche(),uvs.size()));
    }
    if(ui->Edit_AutoDossier_SemestreB2_Notes->count()==0 and ui->Edit_AutoDossier_SemestreB2_UV->count()>0)
    {
        newSem->incrementer();
        QStringList uvs;
        while (ui->Edit_Dossier_SemestreB2_UV->count () > 0)
            uvs.append(ui->Edit_Dossier_SemestreB2_UV->item(0)->text());
        Sol.addPrevision(InscriptionFuture(newSem,uvs,dossier->getBranche(),uvs.size()));
    }
    if(ui->Edit_AutoDossier_SemestreB3_Notes->count()==0 and ui->Edit_AutoDossier_SemestreB3_UV->count()>0)
    {
        newSem->incrementer();
        QStringList uvs;
        while (ui->Edit_Dossier_SemestreB3_UV->count () > 0)
            uvs.append(ui->Edit_Dossier_SemestreB3_UV->item(0)->text());
        Sol.addPrevision(InscriptionFuture(newSem,uvs,dossier->getBranche(),uvs.size()));
    }
    if(ui->Edit_AutoDossier_SemestreB4_Notes->count()==0 and ui->Edit_AutoDossier_SemestreB4_UV->count()>0)
    {
        newSem->incrementer();
        QStringList uvs;
        while (ui->Edit_Dossier_SemestreB4_UV->count () > 0)
            uvs.append(ui->Edit_Dossier_SemestreB4_UV->item(0)->text());
        Sol.addPrevision(InscriptionFuture(newSem,uvs,dossier->getBranche(),uvs.size()));
    }
    if(ui->Edit_AutoDossier_SemestreB5_Notes->count()==0 and ui->Edit_AutoDossier_SemestreB5_UV->count()>0)
    {
        newSem->incrementer();
        QStringList uvs;
        while (ui->Edit_Dossier_SemestreB5_UV->count () > 0)
            uvs.append(ui->Edit_Dossier_SemestreB5_UV->item(0)->text());
        Sol.addPrevision(InscriptionFuture(newSem,uvs,dossier->getBranche(),uvs.size()));
    }
    if(ui->Edit_AutoDossier_SemestreB6_Notes->count()==0 and ui->Edit_AutoDossier_SemestreB6_UV->count()>0)
    {
        newSem->incrementer();
        QStringList uvs;
        while (ui->Edit_Dossier_SemestreB6_UV->count () > 0)
            uvs.append(ui->Edit_Dossier_SemestreB6_UV->item(0)->text());
        Sol.addPrevision(InscriptionFuture(newSem,uvs,dossier->getBranche(),uvs.size()));
    }
    if(ui->Edit_AutoDossier_SemestreB7_Notes->count()==0 and ui->Edit_AutoDossier_SemestreB7_UV->count()>0)
    {
        newSem->incrementer();
        QStringList uvs;
        while (ui->Edit_Dossier_SemestreB7_UV->count () > 0)
            uvs.append(ui->Edit_Dossier_SemestreB7_UV->item(0)->text());
        Sol.addPrevision(InscriptionFuture(newSem,uvs,dossier->getBranche(),uvs.size()));
    }
    if(ui->Edit_AutoDossier_SemestreB8_Notes->count()==0 and ui->Edit_AutoDossier_SemestreB8_UV->count()>0)
    {
        newSem->incrementer();
        QStringList uvs;
        while (ui->Edit_Dossier_SemestreB8_UV->count () > 0)
            uvs.append(ui->Edit_Dossier_SemestreB8_UV->item(0)->text());
        Sol.addPrevision(InscriptionFuture(newSem,uvs,dossier->getBranche(),uvs.size()));
    }
    dossier->addSolution(Sol);
    dossier->addSolution_fichier();
    QMessageBox::information(this,"Solution sauvegardée","La Solution a bien été sauvegardée !",QMessageBox::Ok);
    PrintAutoDossier();
}


void MainWindow::AnnSuppAutoDossier()
{
    if(ui->Edit_AutoDossier_Annuler->text()=="Supprimer")
    {
        int reponse = QMessageBox::question(this, "Suppression d'une solution", "Etes vous sûr de vouloir supprimer cette Solution ?", QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QString loginnum =  ui->Edit_AutoDossier_CurrentSolution->text();
            DossierManager* DossierManage = DossierManager::getInstance(); 
            QStringList listedoss = DossierManage->listerDossier();
            QString login;
            int index;
            for(int i=0;i<listedoss.size();i++)
            {
                if(loginnum.contains(listedoss.at(i)))
                {
                    login = listedoss.at(i);
                    index = loginnum.remove(listedoss.at(i)).toInt();
                }
            }
            Dossier* dossier = DossierManage->getDossier(login);
            QList<Solution> Sols =  dossier->getListeSolutions();
            dossier->deleteAllSolutions();
            Sols.removeAt(index);
            for(int i=0;i<Sols.size();i++)
                dossier->addSolution(Sols.at(i));
            dossier->deleteSolution_fichier(index);
        }
    }
    PrintAutoDossier();
}


void MainWindow::Create_AutoDossier()
{
    ResetAutoDossier();
    QString login = ui->Create_AutoDossier_Login->text();
    ui->Edit_AutoDossier_CurrentSolution->setText(login);
    DossierManager* DossierManage = DossierManager::getInstance();
    QStringList listelog = DossierManage->listerDossier();
    bool trouv=false;
    for(int i=0;i<listelog.size();i++)
    {
        if(login==listelog.at(i))
            trouv = true;
    }
    if(!trouv)
    {
        QMessageBox::information(this,"Erreur: Dossier "+login+" inexistant !","Le Dossier "+login+" n'existe pas !",QMessageBox::Ok);

    }
    else
    {
        ui->Edit_AutoDossier_Semestre_Group->setEnabled(true);
        Dossier* doss = DossierManage->getDossier(login);
        QList<InscriptionPassee> Lsem = DossierManage->getAllParcours(login);
        int indexprepa=1,indexbranche=1;
        CursusManager* CursusManage = CursusManager::getInstance();
        Note* result;
        ui->Edit_AutoDossier_Semestre1_Notes->setEnabled(false);
        ui->Edit_AutoDossier_Semestre2_Notes->setEnabled(false);
        ui->Edit_AutoDossier_Semestre3_Notes->setEnabled(false);
        ui->Edit_AutoDossier_Semestre4_Notes->setEnabled(false);
        ui->Edit_AutoDossier_Semestre5_Notes->setEnabled(false);
        ui->Edit_AutoDossier_Semestre6_Notes->setEnabled(false);
        ui->Edit_AutoDossier_SemestreB1_Notes->setEnabled(false);
        ui->Edit_AutoDossier_SemestreB2_Notes->setEnabled(false);
        ui->Edit_AutoDossier_SemestreB3_Notes->setEnabled(false);
        ui->Edit_AutoDossier_SemestreB4_Notes->setEnabled(false);
        ui->Edit_AutoDossier_SemestreB5_Notes->setEnabled(false);
        ui->Edit_AutoDossier_SemestreB6_Notes->setEnabled(false);
        ui->Edit_AutoDossier_SemestreB7_Notes->setEnabled(false);
        ui->Edit_AutoDossier_SemestreB8_Notes->setEnabled(false);

        ui->Edit_AutoDossier_Actions_Group->setEnabled(true);
        ui->Edit_AutoDossier_Sauvegarde->setEnabled(false);
        ui->Edit_AutoDossier_UV_Group->setEnabled(true);
        AutoDossierPrintUV();

        for(QList<InscriptionPassee>::iterator it=Lsem.begin() ; it!=Lsem.end() ; ++it)
        {
            if(CursusManage->getCursus(it->getCursusPrincipal())->isWhat1()==1)
            {
                ui->Edit_AutoDossier_SemestrePrepa_Group->setEnabled(true);
                switch(indexprepa)
                {
                    case 1:
                        ui->Edit_AutoDossier_Semestre1_UV->addItems(it->getListUV());
                        ui->Edit_AutoDossier_Semestre1_Notes->clear();
                        result = it->getResultat();
                        for(unsigned int i=0;i<it->getTailleTab();i++)
                        {
                            QString note = NotetoQString(result[i]);
                            ui->Edit_AutoDossier_Semestre1_Notes->addItem(note);
                        }
                        while(ui->Edit_AutoDossier_Semestre1_Notes->count () < 7)
                            ui->Edit_AutoDossier_Semestre1_Notes->addItem("");
                        ui->Edit_AutoDossier_Semestre1_Nom->setText(it->getCursusPrincipal()+"01");
                        ui->Edit_AutoDossier_Semestre1_UV->setEnabled(false);
                    break;

                    case 2:
                        ui->Edit_AutoDossier_Semestre2_UV->addItems(it->getListUV());
                        ui->Edit_AutoDossier_Semestre2_Notes->clear();
                        result = it->getResultat();
                        for(unsigned int i=0;i<it->getTailleTab();i++)
                        {
                            QString note = NotetoQString(result[i]);
                            ui->Edit_AutoDossier_Semestre2_Notes->addItem(note);
                        }
                        while(ui->Edit_AutoDossier_Semestre2_Notes->count () < 7)
                            ui->Edit_AutoDossier_Semestre2_Notes->addItem("");
                        ui->Edit_AutoDossier_Semestre2_Nom->setText(it->getCursusPrincipal()+"02");
                        ui->Edit_AutoDossier_Semestre2_UV->setEnabled(false);
                    break;

                    case 3:
                        ui->Edit_AutoDossier_Semestre3_UV->addItems(it->getListUV());
                        ui->Edit_AutoDossier_Semestre3_Notes->clear();
                        result = it->getResultat();
                        for(unsigned int i=0;i<it->getTailleTab();i++)
                        {
                            QString note = NotetoQString(result[i]);
                            ui->Edit_AutoDossier_Semestre3_Notes->addItem(note);
                        }
                        while(ui->Edit_AutoDossier_Semestre3_Notes->count () < 7)
                            ui->Edit_AutoDossier_Semestre3_Notes->addItem("");
                        ui->Edit_AutoDossier_Semestre3_Nom->setText(it->getCursusPrincipal()+"03");
                        ui->Edit_AutoDossier_Semestre3_UV->setEnabled(false);
                    break;

                    case 4:
                        ui->Edit_AutoDossier_Semestre4_UV->addItems(it->getListUV());
                        ui->Edit_AutoDossier_Semestre4_Notes->clear();
                        result = it->getResultat();
                        for(unsigned int i=0;i<it->getTailleTab();i++)
                        {
                            QString note = NotetoQString(result[i]);
                            ui->Edit_AutoDossier_Semestre4_Notes->addItem(note);
                        }
                        while(ui->Edit_AutoDossier_Semestre4_Notes->count () < 7)
                            ui->Edit_AutoDossier_Semestre4_Notes->addItem("");
                        ui->Edit_AutoDossier_Semestre4_Nom->setText(it->getCursusPrincipal()+"04");
                        ui->Edit_AutoDossier_Semestre4_UV->setEnabled(false);
                    break;

                    case 5:
                        ui->Edit_AutoDossier_Semestre5_UV->addItems(it->getListUV());
                        ui->Edit_AutoDossier_Semestre5_Notes->clear();
                        result = it->getResultat();
                        for(unsigned int i=0;i<it->getTailleTab();i++)
                        {
                            QString note = NotetoQString(result[i]);
                            ui->Edit_AutoDossier_Semestre5_Notes->addItem(note);
                        }
                        while(ui->Edit_AutoDossier_Semestre5_Notes->count () < 7)
                            ui->Edit_AutoDossier_Semestre5_Notes->addItem("");
                        ui->Edit_AutoDossier_Semestre5_Nom->setText(it->getCursusPrincipal()+"05");
                        ui->Edit_AutoDossier_Semestre5_UV->setEnabled(false);
                    break;

                    case 6:
                        ui->Edit_AutoDossier_Semestre6_UV->addItems(it->getListUV());
                        ui->Edit_AutoDossier_Semestre6_Notes->clear();
                        result = it->getResultat();
                        for(unsigned int i=0;i<it->getTailleTab();i++)
                        {
                            QString note = NotetoQString(result[i]);
                            ui->Edit_AutoDossier_Semestre6_Notes->addItem(note);
                        }
                        while(ui->Edit_AutoDossier_Semestre6_Notes->count () < 7)
                            ui->Edit_AutoDossier_Semestre6_Notes->addItem("");
                        ui->Edit_AutoDossier_Semestre6_Nom->setText(it->getCursusPrincipal()+"06");
                        ui->Edit_AutoDossier_Semestre6_UV->setEnabled(false);
                    break;
                }
                indexprepa++;
            }
            else
            {
                ui->Edit_AutoDossier_SemestreBranche_Group->setEnabled(true);
                switch(indexbranche)
                {
                    case 1:
                        ui->Edit_AutoDossier_SemestreB1_UV->addItems(it->getListUV());
                        ui->Edit_AutoDossier_SemestreB1_Notes->clear();
                        result = it->getResultat();
                        for(unsigned int i=0;i<it->getTailleTab();i++)
                        {
                            QString note = NotetoQString(result[i]);
                            ui->Edit_AutoDossier_SemestreB1_Notes->addItem(note);
                        }
                        while(ui->Edit_AutoDossier_SemestreB1_Notes->count () < 7)
                            ui->Edit_AutoDossier_SemestreB1_Notes->addItem("");
                        ui->Edit_AutoDossier_SemestreB1_Nom->setText(it->getCursusPrincipal()+"01");
                        ui->Edit_AutoDossier_SemestreB1_UV->setEnabled(false);
                    break;

                    case 2:
                        ui->Edit_AutoDossier_SemestreB2_UV->addItems(it->getListUV());
                        ui->Edit_AutoDossier_SemestreB2_Notes->clear();
                        result = it->getResultat();
                        for(unsigned int i=0;i<it->getTailleTab();i++)
                        {
                            QString note = NotetoQString(result[i]);
                            ui->Edit_AutoDossier_SemestreB2_Notes->addItem(note);
                        }
                        while(ui->Edit_AutoDossier_SemestreB2_Notes->count () < 7)
                            ui->Edit_AutoDossier_SemestreB2_Notes->addItem("");
                        ui->Edit_AutoDossier_SemestreB2_Nom->setText(it->getCursusPrincipal()+"02");
                        ui->Edit_AutoDossier_SemestreB2_UV->setEnabled(false);
                    break;

                    case 3:
                        ui->Edit_AutoDossier_SemestreB3_UV->addItems(it->getListUV());
                        ui->Edit_AutoDossier_SemestreB3_Notes->clear();
                        result = it->getResultat();
                        for(unsigned int i=0;i<it->getTailleTab();i++)
                        {
                            QString note = NotetoQString(result[i]);
                            ui->Edit_AutoDossier_SemestreB3_Notes->addItem(note);
                        }
                        while(ui->Edit_AutoDossier_SemestreB3_Notes->count () < 7)
                            ui->Edit_AutoDossier_SemestreB3_Notes->addItem("");
                        ui->Edit_AutoDossier_SemestreB3_Nom->setText(it->getCursusPrincipal()+"03");
                        ui->Edit_AutoDossier_SemestreB3_UV->setEnabled(false);
                    break;

                    case 4:
                        ui->Edit_AutoDossier_SemestreB4_UV->addItems(it->getListUV());
                        ui->Edit_AutoDossier_SemestreB4_Notes->clear();
                        result = it->getResultat();
                        for(unsigned int i=0;i<it->getTailleTab();i++)
                        {
                            QString note = NotetoQString(result[i]);
                            ui->Edit_AutoDossier_SemestreB4_Notes->addItem(note);
                        }
                        while(ui->Edit_AutoDossier_SemestreB4_Notes->count () < 7)
                            ui->Edit_AutoDossier_SemestreB4_Notes->addItem("");
                        ui->Edit_AutoDossier_SemestreB4_Nom->setText(it->getCursusPrincipal()+"04");
                        ui->Edit_AutoDossier_SemestreB4_UV->setEnabled(false);
                    break;

                    case 5:
                        ui->Edit_AutoDossier_SemestreB5_UV->addItems(it->getListUV());
                        ui->Edit_AutoDossier_SemestreB5_Notes->clear();
                        result = it->getResultat();
                        for(unsigned int i=0;i<it->getTailleTab();i++)
                        {
                            QString note = NotetoQString(result[i]);
                            ui->Edit_AutoDossier_SemestreB5_Notes->addItem(note);
                        }
                        while(ui->Edit_AutoDossier_SemestreB5_Notes->count () < 7)
                            ui->Edit_AutoDossier_SemestreB5_Notes->addItem("");
                        ui->Edit_AutoDossier_SemestreB5_Nom->setText(it->getCursusPrincipal()+"05");
                        ui->Edit_AutoDossier_SemestreB5_UV->setEnabled(false);
                    break;

                    case 6:
                        ui->Edit_AutoDossier_SemestreB6_UV->addItems(it->getListUV());
                        ui->Edit_AutoDossier_SemestreB6_Notes->clear();
                        result = it->getResultat();
                        for(unsigned int i=0;i<it->getTailleTab();i++)
                        {
                            QString note = NotetoQString(result[i]);
                            ui->Edit_AutoDossier_SemestreB6_Notes->addItem(note);
                        }
                        while(ui->Edit_AutoDossier_SemestreB6_Notes->count () < 7)
                            ui->Edit_AutoDossier_SemestreB6_Notes->addItem("");
                        ui->Edit_AutoDossier_SemestreB6_Nom->setText(it->getCursusPrincipal()+"06");
                        ui->Edit_AutoDossier_SemestreB6_UV->setEnabled(false);
                    break;

                    case 7:
                        ui->Edit_AutoDossier_SemestreB7_UV->addItems(it->getListUV());
                        ui->Edit_AutoDossier_SemestreB7_Notes->clear();
                        result = it->getResultat();
                        for(unsigned int i=0;i<it->getTailleTab();i++)
                        {
                            QString note = NotetoQString(result[i]);
                            ui->Edit_AutoDossier_SemestreB7_Notes->addItem(note);
                        }
                        while(ui->Edit_AutoDossier_SemestreB7_Notes->count () < 7)
                            ui->Edit_AutoDossier_SemestreB7_Notes->addItem("");
                        ui->Edit_AutoDossier_SemestreB7_Nom->setText(it->getCursusPrincipal()+"07");
                        ui->Edit_AutoDossier_SemestreB7_UV->setEnabled(false);
                    break;

                    case 8:
                        ui->Edit_AutoDossier_SemestreB8_UV->addItems(it->getListUV());
                        ui->Edit_AutoDossier_SemestreB8_Notes->clear();
                        result = it->getResultat();
                        for(unsigned int i=0;i<it->getTailleTab();i++)
                        {
                            QString note = NotetoQString(result[i]);
                            ui->Edit_AutoDossier_SemestreB8_Notes->addItem(note);
                        }
                        while(ui->Edit_AutoDossier_SemestreB8_Notes->count () < 7)
                            ui->Edit_AutoDossier_SemestreB8_Notes->addItem("");
                        ui->Edit_AutoDossier_SemestreB8_Nom->setText(it->getCursusPrincipal()+"08");
                        ui->Edit_AutoDossier_SemestreB8_UV->setEnabled(false);
                    break;
                }
                indexbranche++;
            }
        }
    }
}



void MainWindow::EditAutoDossier(QListWidgetItem *item)
{
    ResetAutoDossier();
    ui->Edit_AutoDossier_Actions_Group->setEnabled(true);
    ui->Edit_AutoDossier_Annuler->setText("Supprimer");
    ui->Edit_AutoDossier_Semestre_Group->setEnabled(true);
    QString loginnum = item->text();
    ui->Edit_AutoDossier_CurrentSolution->setText(item->text());
    DossierManager* DossierManage = DossierManager::getInstance();
    CursusManager* CursusManage = CursusManager::getInstance();
    Dossier* dossier = DossierManage->getDossier(loginnum);
    ui->Edit_AutoDossier_Executer->setEnabled(false);
    ui->Edit_AutoDossier_Sauvegarde->setEnabled(false);
    ui->Edit_AutoDossier_Verifier->setEnabled(false);
    QStringList listedoss = DossierManage->listerDossier();
    QString login;
    int index;
    for(int i=0;i<listedoss.size();i++)
    {
        if(loginnum.contains(listedoss.at(i)))
        {
            login = listedoss.at(i);
            index = loginnum.remove(listedoss.at(i)).toInt();
        }
    }
    Dossier* doss = DossierManage->getDossier(login);
    QList<InscriptionPassee> Lsem = DossierManage->getAllParcours(login);
    int indexprepa=1,indexbranche=1;
    Note* result;
    for(QList<InscriptionPassee>::iterator it=Lsem.begin() ; it!=Lsem.end() ; ++it)
    {
        if(CursusManage->getCursus(it->getCursusPrincipal())->isWhat1()==1)
        {
            switch(indexprepa)
            {
                case 1:
                    ui->Edit_AutoDossier_Semestre1_UV->addItems(it->getListUV());
                    ui->Edit_AutoDossier_Semestre1_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_AutoDossier_Semestre1_Notes->addItem(note);
                    }
                    while(ui->Edit_AutoDossier_Semestre1_Notes->count () < 7)
                        ui->Edit_AutoDossier_Semestre1_Notes->addItem("");
                    ui->Edit_AutoDossier_Semestre1_Nom->setText(it->getCursusPrincipal()+"01");
                break;

                case 2:
                    ui->Edit_AutoDossier_Semestre2_UV->addItems(it->getListUV());
                    ui->Edit_AutoDossier_Semestre2_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_AutoDossier_Semestre2_Notes->addItem(note);
                    }
                    while(ui->Edit_AutoDossier_Semestre2_Notes->count () < 7)
                        ui->Edit_AutoDossier_Semestre2_Notes->addItem("");
                    ui->Edit_AutoDossier_Semestre2_Nom->setText(it->getCursusPrincipal()+"02");
                break;

                case 3:
                    ui->Edit_AutoDossier_Semestre3_UV->addItems(it->getListUV());
                    ui->Edit_AutoDossier_Semestre3_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_AutoDossier_Semestre3_Notes->addItem(note);
                    }
                    while(ui->Edit_AutoDossier_Semestre3_Notes->count () < 7)
                        ui->Edit_AutoDossier_Semestre3_Notes->addItem("");
                    ui->Edit_AutoDossier_Semestre3_Nom->setText(it->getCursusPrincipal()+"03");
                break;

                case 4:
                    ui->Edit_AutoDossier_Semestre4_UV->addItems(it->getListUV());
                    ui->Edit_AutoDossier_Semestre4_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_AutoDossier_Semestre4_Notes->addItem(note);
                    }
                    while(ui->Edit_AutoDossier_Semestre4_Notes->count () < 7)
                        ui->Edit_AutoDossier_Semestre4_Notes->addItem("");
                    ui->Edit_AutoDossier_Semestre4_Nom->setText(it->getCursusPrincipal()+"04");
                break;

                case 5:
                    ui->Edit_AutoDossier_Semestre5_UV->addItems(it->getListUV());
                    ui->Edit_AutoDossier_Semestre5_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_AutoDossier_Semestre5_Notes->addItem(note);
                    }
                    while(ui->Edit_AutoDossier_Semestre5_Notes->count () < 7)
                        ui->Edit_AutoDossier_Semestre5_Notes->addItem("");
                    ui->Edit_AutoDossier_Semestre5_Nom->setText(it->getCursusPrincipal()+"05");
                break;

                case 6:
                    ui->Edit_AutoDossier_Semestre6_UV->addItems(it->getListUV());
                    ui->Edit_AutoDossier_Semestre6_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_AutoDossier_Semestre6_Notes->addItem(note);
                    }
                    while(ui->Edit_AutoDossier_Semestre6_Notes->count () < 7)
                        ui->Edit_AutoDossier_Semestre6_Notes->addItem("");
                    ui->Edit_AutoDossier_Semestre6_Nom->setText(it->getCursusPrincipal()+"06");
                break;
            }
            indexprepa++;
        }
        else
        {
            switch(indexbranche)
            {
                case 1:
                    ui->Edit_AutoDossier_SemestreB1_UV->addItems(it->getListUV());
                    ui->Edit_AutoDossier_SemestreB1_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_AutoDossier_SemestreB1_Notes->addItem(note);
                    }
                    while(ui->Edit_AutoDossier_SemestreB1_Notes->count () < 7)
                        ui->Edit_AutoDossier_SemestreB1_Notes->addItem("");
                    ui->Edit_AutoDossier_SemestreB1_Nom->setText(it->getCursusPrincipal()+"01");
                break;

                case 2:
                    ui->Edit_AutoDossier_SemestreB2_UV->addItems(it->getListUV());
                    ui->Edit_AutoDossier_SemestreB2_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_AutoDossier_SemestreB2_Notes->addItem(note);
                    }
                    while(ui->Edit_AutoDossier_SemestreB2_Notes->count () < 7)
                        ui->Edit_AutoDossier_SemestreB2_Notes->addItem("");
                    ui->Edit_AutoDossier_SemestreB2_Nom->setText(it->getCursusPrincipal()+"02");
                break;

                case 3:
                    ui->Edit_AutoDossier_SemestreB3_UV->addItems(it->getListUV());
                    ui->Edit_AutoDossier_SemestreB3_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_AutoDossier_SemestreB3_Notes->addItem(note);
                    }
                    while(ui->Edit_AutoDossier_SemestreB3_Notes->count () < 7)
                        ui->Edit_AutoDossier_SemestreB3_Notes->addItem("");
                    ui->Edit_AutoDossier_SemestreB3_Nom->setText(it->getCursusPrincipal()+"03");
                break;

                case 4:
                    ui->Edit_AutoDossier_SemestreB4_UV->addItems(it->getListUV());
                    ui->Edit_AutoDossier_SemestreB4_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_AutoDossier_SemestreB4_Notes->addItem(note);
                    }
                    while(ui->Edit_AutoDossier_SemestreB4_Notes->count () < 7)
                        ui->Edit_AutoDossier_SemestreB4_Notes->addItem("");
                    ui->Edit_AutoDossier_SemestreB4_Nom->setText(it->getCursusPrincipal()+"04");
                break;

                case 5:
                    ui->Edit_AutoDossier_SemestreB5_UV->addItems(it->getListUV());
                    ui->Edit_AutoDossier_SemestreB5_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_AutoDossier_SemestreB5_Notes->addItem(note);
                    }
                    while(ui->Edit_AutoDossier_SemestreB5_Notes->count () < 7)
                        ui->Edit_AutoDossier_SemestreB5_Notes->addItem("");
                    ui->Edit_AutoDossier_SemestreB5_Nom->setText(it->getCursusPrincipal()+"05");
                break;

                case 6:
                    ui->Edit_AutoDossier_SemestreB6_UV->addItems(it->getListUV());
                    ui->Edit_AutoDossier_SemestreB6_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_AutoDossier_SemestreB6_Notes->addItem(note);
                    }
                    while(ui->Edit_AutoDossier_SemestreB6_Notes->count () < 7)
                        ui->Edit_AutoDossier_SemestreB6_Notes->addItem("");
                    ui->Edit_AutoDossier_SemestreB6_Nom->setText(it->getCursusPrincipal()+"06");
                break;

                case 7:
                    ui->Edit_AutoDossier_SemestreB7_UV->addItems(it->getListUV());
                    ui->Edit_AutoDossier_SemestreB7_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_AutoDossier_SemestreB7_Notes->addItem(note);
                    }
                    while(ui->Edit_AutoDossier_SemestreB7_Notes->count () < 7)
                        ui->Edit_AutoDossier_SemestreB7_Notes->addItem("");
                    ui->Edit_AutoDossier_SemestreB7_Nom->setText(it->getCursusPrincipal()+"07");
                break;

                case 8:
                    ui->Edit_AutoDossier_SemestreB8_UV->addItems(it->getListUV());
                    ui->Edit_AutoDossier_SemestreB8_Notes->clear();
                    result = it->getResultat();
                    for(unsigned int i=0;i<it->getTailleTab();i++)
                    {
                        QString note = NotetoQString(result[i]);
                        ui->Edit_AutoDossier_SemestreB8_Notes->addItem(note);
                    }
                    while(ui->Edit_AutoDossier_SemestreB8_Notes->count () < 7)
                        ui->Edit_AutoDossier_SemestreB8_Notes->addItem("");
                    ui->Edit_AutoDossier_SemestreB8_Nom->setText(it->getCursusPrincipal()+"08");
                break;
            }
            indexbranche++;
        }
    }
    QList<Solution> Soluces = DossierManage->getAllSolutions(login);
    QList<InscriptionFuture> Lfut = Soluces.at(index).getListePrevisions();
    for(QList<InscriptionFuture>::iterator it=Lfut.begin() ; it!=Lfut.end() ; ++it)
    {
        if(CursusManage->getCursus(it->getCursusPrincipal())->isWhat1()==1)
        {
            if(MainWindow::ui->Edit_AutoDossier_Semestre1_UV->count() == 0)
                ui->Edit_AutoDossier_Semestre1_UV->addItems(it->getListUV());
            else if(ui->Edit_AutoDossier_Semestre2_UV->count() == 0)
                ui->Edit_AutoDossier_Semestre2_UV->addItems(it->getListUV());
            else if(ui->Edit_AutoDossier_Semestre3_UV->count() == 0)
                ui->Edit_AutoDossier_Semestre3_UV->addItems(it->getListUV());
            else if(ui->Edit_AutoDossier_Semestre4_UV->count() == 0)
                ui->Edit_AutoDossier_Semestre4_UV->addItems(it->getListUV());
            else if(ui->Edit_AutoDossier_Semestre5_UV->count() == 0)
                ui->Edit_AutoDossier_Semestre5_UV->addItems(it->getListUV());
            else if(ui->Edit_AutoDossier_Semestre6_UV->count() == 0)
                ui->Edit_AutoDossier_Semestre6_UV->addItems(it->getListUV());
        }
        else
        {
            if(ui->Edit_AutoDossier_SemestreB1_UV->count() == 0)
                ui->Edit_AutoDossier_SemestreB1_UV->addItems(it->getListUV());
            else if(ui->Edit_AutoDossier_SemestreB2_UV->count() == 0)
                ui->Edit_AutoDossier_SemestreB2_UV->addItems(it->getListUV());
            else if(ui->Edit_AutoDossier_SemestreB3_UV->count() == 0)
                ui->Edit_AutoDossier_SemestreB3_UV->addItems(it->getListUV());
            else if(ui->Edit_AutoDossier_SemestreB4_UV->count() == 0)
                ui->Edit_AutoDossier_SemestreB4_UV->addItems(it->getListUV());
            else if(ui->Edit_AutoDossier_SemestreB5_UV->count() == 0)
                ui->Edit_AutoDossier_SemestreB5_UV->addItems(it->getListUV());
            else if(ui->Edit_AutoDossier_SemestreB6_UV->count() == 0)
                ui->Edit_AutoDossier_SemestreB6_UV->addItems(it->getListUV());
            else if(ui->Edit_AutoDossier_SemestreB7_UV->count() == 0)
                ui->Edit_AutoDossier_SemestreB7_UV->addItems(it->getListUV());
            else if(ui->Edit_AutoDossier_SemestreB8_UV->count() == 0)
                ui->Edit_AutoDossier_SemestreB8_UV->addItems(it->getListUV());
        }
    }
}


void MainWindow::ResetAutoDossier()
{
    ui->Edit_AutoDossier_UV_Group->setEnabled(false);
    ui->Edit_AutoDossier_UV_List->clear();
    ui->Edit_AutoDossier_SemestrePrepa_Group->setEnabled(false);
    ui->Edit_AutoDossier_SemestreBranche_Group->setEnabled(false);
    ui->Edit_AutoDossier_Semestre_Group->setEnabled(false);
    ui->Edit_AutoDossier_Actions_Group->setEnabled(false);
    ui->Edit_AutoDossier_Sauvegarde->setEnabled(true);
    ui->Edit_AutoDossier_Annuler->setEnabled(true);
    ui->Edit_AutoDossier_Annuler->setText("Annuler");
    ui->Edit_AutoDossier_Verifier->setEnabled(true);
    ui->Edit_AutoDossier_Executer->setEnabled(true);
    ui->Edit_AutoDossier_SemestreB1_UV->clear();
    ui->Edit_AutoDossier_SemestreB2_UV->clear();
    ui->Edit_AutoDossier_SemestreB3_UV->clear();
    ui->Edit_AutoDossier_SemestreB4_UV->clear();
    ui->Edit_AutoDossier_SemestreB5_UV->clear();
    ui->Edit_AutoDossier_SemestreB6_UV->clear();
    ui->Edit_AutoDossier_SemestreB7_UV->clear();
    ui->Edit_AutoDossier_SemestreB8_UV->clear();
    ui->Edit_AutoDossier_Semestre1_UV->clear();
    ui->Edit_AutoDossier_Semestre2_UV->clear();
    ui->Edit_AutoDossier_Semestre3_UV->clear();
    ui->Edit_AutoDossier_Semestre4_UV->clear();
    ui->Edit_AutoDossier_Semestre5_UV->clear();
    ui->Edit_AutoDossier_Semestre6_UV->clear();

    ui->Edit_AutoDossier_Semestre1_Notes->clear();
    ui->Edit_AutoDossier_Semestre2_Notes->clear();
    ui->Edit_AutoDossier_Semestre3_Notes->clear();
    ui->Edit_AutoDossier_Semestre4_Notes->clear();
    ui->Edit_AutoDossier_Semestre5_Notes->clear();
    ui->Edit_AutoDossier_Semestre6_Notes->clear();
    ui->Edit_AutoDossier_SemestreB1_Notes->clear();
    ui->Edit_AutoDossier_SemestreB2_Notes->clear();
    ui->Edit_AutoDossier_SemestreB3_Notes->clear();
    ui->Edit_AutoDossier_SemestreB4_Notes->clear();
    ui->Edit_AutoDossier_SemestreB5_Notes->clear();
    ui->Edit_AutoDossier_SemestreB6_Notes->clear();
    ui->Edit_AutoDossier_SemestreB7_Notes->clear();
    ui->Edit_AutoDossier_SemestreB8_Notes->clear();

    ui->Edit_AutoDossier_CurrentSolution->setText("");
}

void MainWindow::PrintAutoDossier()
{
    ResetAutoDossier();
    QString login = ui->Seek_AutoDossier_Login->text();
    DossierManager* DossierManage = DossierManager::getInstance();
    ui->Print_AutoDossier_List->clear();
    QStringList listedoss = DossierManage->listerDossier();
    listedoss = listedoss.filter(login);
    for(int j=0;j<listedoss.size();j++)
    {
        QList<Solution> list = DossierManage->getAllSolutions(listedoss.at(j));
        for(int i=0;i<list.size();i++)
        {
            ui->Print_AutoDossier_List->addItem(listedoss.at(j)+QString::number(i));
        }
    }
}

void MainWindow::AutoDossierPrintUV()
{
    QString code_seek = ui->Edit_AutoDossier_UV_Code->text();
    UVManager* UVManage = UVManager::getInstance();
    while (ui->Edit_AutoDossier_UV_List->count () > 0) ui->Edit_AutoDossier_UV_List->takeItem (0);
    QStringList list = UVManage->listerUV();
    list.sort();
    QStringList listnew;
    if (!ui->Edit_AutoDossier_UV_CS->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (UVManage->getUV(*it)->getCreditsCat(CS)==0)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (!ui->Edit_AutoDossier_UV_TM->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (UVManage->getUV(*it)->getCreditsCat(TM)==0)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (!ui->Edit_AutoDossier_UV_TSH->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (UVManage->getUV(*it)->getCreditsCat(TSH)==0)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (!ui->Edit_AutoDossier_UV_SP->isChecked())
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
        ui->Edit_AutoDossier_UV_List->addItem(code_seek);
    }
    else
    {
        QStringList list2 = list.filter(code_seek);
        for(QList<QString>::iterator it=list2.begin() ; it!=list2.end() ; ++it)
            ui->Edit_AutoDossier_UV_List->addItem(*it);
    }
}
