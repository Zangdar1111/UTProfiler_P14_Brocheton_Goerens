#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "includes.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->Seek_UV_Submit, SIGNAL(clicked()), this, SLOT(Print_UV()));

    //Recuperation de la liste des UV

    ui->Print_UV_List->addItem("Indic1");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Print_UV()
{
    QString code_seek = ui->Seek_UV_Code->text();
    UVManager* UVManage = UVManager::getInstance();
    while (ui->Print_UV_List->count () > 0) delete ui->Print_UV_List->takeItem (0);
    ui->Print_UV_List->addItem(code_seek);
    if (UVManage->getUV(code_seek))
    {
        cout<<code_seek.toStdString()<<endl;
        ui->Print_UV_List->addItem(code_seek);
    }
    else
    {
        cout<<"else"<<endl;
    }
}
