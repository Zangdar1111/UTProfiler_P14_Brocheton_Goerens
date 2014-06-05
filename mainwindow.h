#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "includes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    //Menu
    void quit();
    //Onglet 1
    void PrintUV();
    void CreateUV();
    void ResetUV();
    void EditUV(QListWidgetItem *item);
    void DeleteUV();
    void SaveUV();
    //Onglet 2
    void PrintCursus();
    void CreateCursus();
    void ResetCursus();
    void EditCursus(QListWidgetItem *item);
    void DeleteCursus();
    void SaveCursus();
    void addUV_Cursus();
    void cursus_diff();
    void poubelle(QListWidgetItem * item);
    //Onglet 3
    void Print_Prepa();
    void Print_Branche();
    void Print_Filiere();
    void Print_Mineur();
    void No_Prepa();
    //Onglet 4

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
