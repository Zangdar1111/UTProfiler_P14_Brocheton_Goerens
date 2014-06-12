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
    void poubelle(QListWidgetItem * item);
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
    //Onglet 3
    void Print_ListeCursus_Dossier();
    void PrintDossier();
    void CreateDossier();
    void ResetDossier();
    void EditDossier(QListWidgetItem* item);
    void EtapeSemestre();
    void ResetCurrent();
    void EditDossierPrepa(QListWidgetItem *);
    void EditDossierBranche(QListWidgetItem *);
    void EditDossierFiliere(QListWidgetItem *);
    void EditDossierMineur(QListWidgetItem *);
    void DossierPrintUV();
    void ChangeNote(QListWidgetItem *);
    void ChangeNoteS1(QListWidgetItem *);
    void ChangeNoteS2(QListWidgetItem *);
    void ChangeNoteS3(QListWidgetItem *);
    void ChangeNoteS4(QListWidgetItem *);
    void ChangeNoteS5(QListWidgetItem *);
    void ChangeNoteS6(QListWidgetItem *);
    void poubelleS1(QListWidgetItem*);
    void poubelleS2(QListWidgetItem*);
    void poubelleS3(QListWidgetItem*);
    void poubelleS4(QListWidgetItem*);
    void poubelleS5(QListWidgetItem*);
    void poubelleS6(QListWidgetItem*);
    void VerifierCurrentCursus();
    void SaveDossier();
    void DeleteDossier();
    void poubelleB1(QListWidgetItem*);
    void poubelleB2(QListWidgetItem*);
    void poubelleB3(QListWidgetItem*);
    void poubelleB4(QListWidgetItem*);
    void poubelleB5(QListWidgetItem*);
    void poubelleB6(QListWidgetItem*);
    void poubelleB7(QListWidgetItem*);
    void poubelleB8(QListWidgetItem*);
    void ChangeNoteB1(QListWidgetItem *);
    void ChangeNoteB2(QListWidgetItem *);
    void ChangeNoteB3(QListWidgetItem *);
    void ChangeNoteB4(QListWidgetItem *);
    void ChangeNoteB5(QListWidgetItem *);
    void ChangeNoteB6(QListWidgetItem *);
    void ChangeNoteB7(QListWidgetItem *);
    void ChangeNoteB8(QListWidgetItem *);
    //Onglet 4
    void AutoDossierPrintUV();
    void PrintAutoDossier();
    void ResetAutoDossier();
    void EditAutoDossier(QListWidgetItem *);



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
