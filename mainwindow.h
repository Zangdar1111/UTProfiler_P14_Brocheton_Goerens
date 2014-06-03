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
    void quit();

    void PrintUV();
    void CreateUV();
    void ResetUV();
    void EditUV(QListWidgetItem *item);
    void DeleteUV();
    void SaveUV();

    void PrintCursus();
    void CreateCursus();
    void ResetCursus();
    void EditCursus(QListWidgetItem *item);
    void DeleteCursus();
    void SaveCursus();
    void addUV_Cursus();

    void cursus_diff();

    void poubelle(QListWidgetItem * item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
