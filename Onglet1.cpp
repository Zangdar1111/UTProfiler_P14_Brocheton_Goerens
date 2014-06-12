#include "includes.h"

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
    CursusManager* CursusManage = CursusManager::getInstance();
    QStringList liste= CursusManage->listerCursus();
    for (int i=0;i<liste.size();i++)
        ui->Edit_UV_List1->addItem(liste.at(i));
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
