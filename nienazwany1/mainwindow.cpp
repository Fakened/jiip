#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "function.h"

extern vector<Vehicle*> vehicles;
extern string saveFD;
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::WindowCloseButtonHint, false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Quit_b_clicked()
{
    try
    {
        saveVehiclesToFile(saveFD, vehicles);
        for (const auto &vehicle: vehicles)
        {
            if (vehicle->is())
            {
                delete vehicle;
            }
        }
        vehicles.clear();
        delete ui;
        exit(0);
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }
}

void MainWindow::on_AddV_b_clicked()
{
    try
    {
        close();
        addVeh = new addVehicle();
        addVeh->show();
        delete ui;
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }
}

void MainWindow::on_DisplayV_b_clicked()
{
    try
    {
        close();
        disWin = new displaywindow();
        disWin->show();
        delete ui;
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }
}

void MainWindow::on_RentV_b_clicked()
{
    try
    {
        close();
        rentVeh = new rentVehicle();
        rentVeh->show();
        delete ui;
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }
}

void MainWindow::on_ReturnV_b_clicked()
{
    try
    {
        close();
        reVeh = new returnWindow();
        reVeh->show();
        delete ui;
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }
}

void MainWindow::on_EditV_B_clicked()
{
    try
    {
        close();
        editVeh = new editVehicle();
        editVeh->show();
        delete ui;
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }
}
