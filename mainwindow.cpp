#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "includes.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->Seek_UV_Submit, SIGNAL(clicked()), this, SLOT(Print_UV()));

    QObject::connect(ui->Create_UV, SIGNAL(clicked()), this, SLOT(Create_Reset_UV()));


    //Recuperation de la liste des UV
    Print_UV();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Create_Reset_UV()
{
    ui->Edit_UV_Group->setEnabled(true);
}


void MainWindow::Print_UV()
{
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
            if (UVManage->getUV(*it)->hasCategorie(CS)==-1)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (!ui->Seek_UV_TM->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (UVManage->getUV(*it)->hasCategorie(TM)==-1)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (!ui->Seek_UV_TSH->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (UVManage->getUV(*it)->hasCategorie(TSH)==-1)
              listnew.append(*it);
        }
        list=listnew;
        listnew.clear();
    }
    if (!ui->Seek_UV_SP->isChecked())
    {
        for(QList<QString>::iterator it=list.begin() ; it!=list.end() ; ++it)
        {
            if (UVManage->getUV(*it)->hasCategorie(SP)==-1)
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
