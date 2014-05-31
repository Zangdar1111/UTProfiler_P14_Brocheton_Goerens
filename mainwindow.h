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
    void Print_UV();
    void Create_Edit_UV();
    void Delete_UV();
    void CreateUV();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
