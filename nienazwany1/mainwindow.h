#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "addvehicle.h"
#include "displaywindow.h"
#include "rentvehicle.h"
#include "returnwindow.h"
#include "editvehicle.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow: public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    private slots:
        void on_Quit_b_clicked();

    void on_AddV_b_clicked();

    void on_DisplayV_b_clicked();

    void on_RentV_b_clicked();

    void on_ReturnV_b_clicked();

    void on_EditV_B_clicked();

    private:
        Ui::MainWindow * ui;
    addVehicle * addVeh;
    displaywindow * disWin;
    rentVehicle * rentVeh;
    returnWindow * reVeh;
    editVehicle * editVeh;
};

#endif	// MAINWINDOW_H
