#include "displaywindow.h"
#include "ui_displaywindow.h"
#include "mainwindow.h"
#include <iostream>
#include <qtablewidget.h>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QHeaderView>
#include "vehicle.h"
#include "car.h"
#include "bike.h"
#include "scooter.h"
#include "motorbike.h"
#include <QMessageBox>

extern vector<Vehicle*> vehicles;
extern int id;

displaywindow::displaywindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::displaywindow)
    {
        ui->setupUi(this);
        setWindowFlag(Qt::WindowCloseButtonHint, false);

        ui->table->setColumnCount(17);

        QStringList header;
        header << "ID" << "TYPE" << "NAME" << "PRICE" << "RENT" << "DATE" << "WHO" << "ENGINE" << "HORSEPOWER" << "YEAROFPRODUCTION" << "PLATE" << "TYPE" << "SIZE" << "INTERNALID" << "RANGE" << "DAY" << "COST";
        ui->table->setHorizontalHeaderLabels(header);
        ui->table->verticalHeader()->hide();
        setTable();
    }

displaywindow::~displaywindow()
{
    delete ui;
}

void displaywindow::setTable()
{
    int sizeV = 0;
    for (const auto &vehicle: vehicles)
    {
        if (vehicle->is())
        {
            sizeV++;
        }
    }

    ui->table->setRowCount(sizeV);
    int i = 0;
    try
    {
        for (const auto &vehicle: vehicles)
        {
            if (vehicle->is("other"))
            {
                ui->table->model()->setData(ui->table->model()->index(i, 0), vehicle->getId());
                ui->table->model()->setData(ui->table->model()->index(i, 1), QString::fromStdString(vehicle->getVType()));
                ui->table->model()->setData(ui->table->model()->index(i, 2), QString::fromStdString(vehicle->getName()));
                ui->table->model()->setData(ui->table->model()->index(i, 3), vehicle->getPrice());
                ui->table->model()->setData(ui->table->model()->index(i, 4), QString::fromStdString(vehicle->isRent() ? "true" : "false"));
                ui->table->model()->setData(ui->table->model()->index(i, 5), QString::fromStdString(vehicle->getDate()));
                ui->table->model()->setData(ui->table->model()->index(i, 6), QString::fromStdString(vehicle->getWho()));
                ui->table->model()->setData(ui->table->model()->index(i, 15), vehicle->getDay());
                ui->table->model()->setData(ui->table->model()->index(i, 16), vehicle->getCost());
            }

            if (vehicle->is("car"))
            {
                Car *car = dynamic_cast<Car*> (vehicle);
                if (car)
                {
                    ui->table->model()->setData(ui->table->model()->index(i, 0), car->getId());
                    ui->table->model()->setData(ui->table->model()->index(i, 1), QString::fromStdString(car->getVType()));
                    ui->table->model()->setData(ui->table->model()->index(i, 2), QString::fromStdString(car->getName()));
                    ui->table->model()->setData(ui->table->model()->index(i, 3), car->getPrice());
                    ui->table->model()->setData(ui->table->model()->index(i, 4), QString::fromStdString(car->isRent() ? "true" : "false"));
                    ui->table->model()->setData(ui->table->model()->index(i, 5), QString::fromStdString(car->getDate()));
                    ui->table->model()->setData(ui->table->model()->index(i, 6), QString::fromStdString(car->getWho()));
                    ui->table->model()->setData(ui->table->model()->index(i, 7), QString::fromStdString(car->getEngine()));
                    ui->table->model()->setData(ui->table->model()->index(i, 8), car->getHorsePower());
                    ui->table->model()->setData(ui->table->model()->index(i, 9), car->getYearOfProduction());
                    ui->table->model()->setData(ui->table->model()->index(i, 10), QString::fromStdString(car->getPlate()));
                    ui->table->model()->setData(ui->table->model()->index(i, 15), car->getDay());
                    ui->table->model()->setData(ui->table->model()->index(i, 16), car->getCost());
                }

                car = nullptr;
                delete car;
            }

            if (vehicle->is("bike"))
            {
                Bike *bike = dynamic_cast<Bike*> (vehicle);
                if (bike)
                {
                    ui->table->model()->setData(ui->table->model()->index(i, 0), bike->getId());
                    ui->table->model()->setData(ui->table->model()->index(i, 1), QString::fromStdString(bike->getVType()));
                    ui->table->model()->setData(ui->table->model()->index(i, 2), QString::fromStdString(bike->getName()));
                    ui->table->model()->setData(ui->table->model()->index(i, 3), bike->getPrice());
                    ui->table->model()->setData(ui->table->model()->index(i, 4), QString::fromStdString(bike->isRent() ? "true" : "false"));
                    ui->table->model()->setData(ui->table->model()->index(i, 5), QString::fromStdString(bike->getDate()));
                    ui->table->model()->setData(ui->table->model()->index(i, 6), QString::fromStdString(bike->getWho()));
                    ui->table->model()->setData(ui->table->model()->index(i, 11), QString::fromStdString(bike->getType()));
                    ui->table->model()->setData(ui->table->model()->index(i, 12), bike->getSize());
                    ui->table->model()->setData(ui->table->model()->index(i, 13), bike->getBikeId());
                    ui->table->model()->setData(ui->table->model()->index(i, 15), bike->getDay());
                    ui->table->model()->setData(ui->table->model()->index(i, 16), bike->getCost());
                }

                bike = nullptr;
                delete bike;
            }

            if (vehicle->is("scooter"))
            {
                Scooter *scooter = dynamic_cast<Scooter*> (vehicle);
                if (scooter)
                {
                    ui->table->model()->setData(ui->table->model()->index(i, 0), scooter->getId());
                    ui->table->model()->setData(ui->table->model()->index(i, 1), QString::fromStdString(scooter->getVType()));
                    ui->table->model()->setData(ui->table->model()->index(i, 2), QString::fromStdString(scooter->getName()));
                    ui->table->model()->setData(ui->table->model()->index(i, 3), scooter->getPrice());
                    ui->table->model()->setData(ui->table->model()->index(i, 4), QString::fromStdString(scooter->isRent() ? "true" : "false"));
                    ui->table->model()->setData(ui->table->model()->index(i, 5), QString::fromStdString(scooter->getDate()));
                    ui->table->model()->setData(ui->table->model()->index(i, 6), QString::fromStdString(scooter->getWho()));
                    ui->table->model()->setData(ui->table->model()->index(i, 13), scooter->getScooterId());
                    ui->table->model()->setData(ui->table->model()->index(i, 14), scooter->getRange());
                    ui->table->model()->setData(ui->table->model()->index(i, 15), scooter->getDay());
                    ui->table->model()->setData(ui->table->model()->index(i, 16), scooter->getCost());
                }

                scooter = nullptr;
                delete scooter;
            }

            if (vehicle->is("motorbike"))
            {
                Motorbike *motorbike = dynamic_cast<Motorbike*> (vehicle);
                if (motorbike)
                {
                    ui->table->model()->setData(ui->table->model()->index(i, 0), motorbike->getId());
                    ui->table->model()->setData(ui->table->model()->index(i, 1), QString::fromStdString(motorbike->getVType()));
                    ui->table->model()->setData(ui->table->model()->index(i, 2), QString::fromStdString(motorbike->getName()));
                    ui->table->model()->setData(ui->table->model()->index(i, 3), motorbike->getPrice());
                    ui->table->model()->setData(ui->table->model()->index(i, 4), QString::fromStdString(motorbike->isRent() ? "true" : "false"));
                    ui->table->model()->setData(ui->table->model()->index(i, 5), QString::fromStdString(motorbike->getDate()));
                    ui->table->model()->setData(ui->table->model()->index(i, 6), QString::fromStdString(motorbike->getWho()));
                    ui->table->model()->setData(ui->table->model()->index(i, 7), QString::fromStdString(motorbike->getEngine()));
                    ui->table->model()->setData(ui->table->model()->index(i, 8), motorbike->getHorsePower());
                    ui->table->model()->setData(ui->table->model()->index(i, 9), motorbike->getYearOfProduction());
                    ui->table->model()->setData(ui->table->model()->index(i, 10), QString::fromStdString(motorbike->getPlate()));
                    ui->table->model()->setData(ui->table->model()->index(i, 11), QString::fromStdString(motorbike->getType()));
                    ui->table->model()->setData(ui->table->model()->index(i, 15), motorbike->getDay());
                    ui->table->model()->setData(ui->table->model()->index(i, 16), motorbike->getCost());
                }

                motorbike = nullptr;
                delete motorbike;
            }

            i++;
        }
    }

    catch (runtime_error & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    ui->table->resizeColumnsToContents();
}

void displaywindow::on_back_b_clicked()
{
    try
    {
        ui->table->model()->removeRows(0, ui->table->model()->rowCount());
        delete ui->table->model();
        delete ui->table;
        close();
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
        delete ui;
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }
}

void displaywindow::on_all_b_clicked()
{
    setTable();
}

void displaywindow::on_others_b_clicked()
{
    ui->table->model()->removeRows(0, ui->table->model()->rowCount());

    int sizeV = 0;
    for (const auto &vehicle: vehicles)
    {
        if (vehicle->is("other"))
        {
            sizeV++;
        }
    }

    ui->table->setRowCount(sizeV);
    int i = 0;
    try
    {
        for (const auto &vehicle: vehicles)
        {
            if (vehicle->is("other"))
            {
                ui->table->model()->setData(ui->table->model()->index(i, 0), vehicle->getId());
                ui->table->model()->setData(ui->table->model()->index(i, 1), QString::fromStdString(vehicle->getVType()));
                ui->table->model()->setData(ui->table->model()->index(i, 2), QString::fromStdString(vehicle->getName()));
                ui->table->model()->setData(ui->table->model()->index(i, 3), vehicle->getPrice());
                ui->table->model()->setData(ui->table->model()->index(i, 4), QString::fromStdString(vehicle->isRent() ? "true" : "false"));
                ui->table->model()->setData(ui->table->model()->index(i, 5), QString::fromStdString(vehicle->getDate()));
                ui->table->model()->setData(ui->table->model()->index(i, 6), QString::fromStdString(vehicle->getWho()));
                ui->table->model()->setData(ui->table->model()->index(i, 15), vehicle->getDay());
                ui->table->model()->setData(ui->table->model()->index(i, 16), vehicle->getCost());
                i++;
            }
        }
    }

    catch (runtime_error & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    ui->table->resizeColumnsToContents();
}

void displaywindow::on_motorbikes_b_clicked()
{
    ui->table->model()->removeRows(0, ui->table->model()->rowCount());

    int sizeV = 0;
    for (const auto &vehicle: vehicles)
    {
        if (vehicle->is("motorbike"))
        {
            sizeV++;
        }
    }

    ui->table->setRowCount(sizeV);
    int i = 0;
    try
    {
        for (const auto &vehicle: vehicles)
        {
            if (vehicle->is("motorbike"))
            {
                Motorbike *motorbike = dynamic_cast<Motorbike*> (vehicle);
                if (motorbike)
                {
                    ui->table->model()->setData(ui->table->model()->index(i, 0), motorbike->getId());
                    ui->table->model()->setData(ui->table->model()->index(i, 1), QString::fromStdString(motorbike->getVType()));
                    ui->table->model()->setData(ui->table->model()->index(i, 2), QString::fromStdString(motorbike->getName()));
                    ui->table->model()->setData(ui->table->model()->index(i, 3), motorbike->getPrice());
                    ui->table->model()->setData(ui->table->model()->index(i, 4), QString::fromStdString(motorbike->isRent() ? "true" : "false"));
                    ui->table->model()->setData(ui->table->model()->index(i, 5), QString::fromStdString(motorbike->getDate()));
                    ui->table->model()->setData(ui->table->model()->index(i, 6), QString::fromStdString(motorbike->getWho()));
                    ui->table->model()->setData(ui->table->model()->index(i, 7), QString::fromStdString(motorbike->getEngine()));
                    ui->table->model()->setData(ui->table->model()->index(i, 8), motorbike->getHorsePower());
                    ui->table->model()->setData(ui->table->model()->index(i, 9), motorbike->getYearOfProduction());
                    ui->table->model()->setData(ui->table->model()->index(i, 10), QString::fromStdString(motorbike->getPlate()));
                    ui->table->model()->setData(ui->table->model()->index(i, 11), QString::fromStdString(motorbike->getType()));
                    ui->table->model()->setData(ui->table->model()->index(i, 15), motorbike->getDay());
                    ui->table->model()->setData(ui->table->model()->index(i, 16), motorbike->getCost());
                    i++;
                }

                motorbike = nullptr;
                delete motorbike;
            }
        }
    }

    catch (runtime_error & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    ui->table->resizeColumnsToContents();
}

void displaywindow::on_scooters_b_clicked()
{
    ui->table->model()->removeRows(0, ui->table->model()->rowCount());

    int sizeV = 0;
    for (const auto &vehicle: vehicles)
    {
        if (vehicle->is("scooter"))
        {
            sizeV++;
        }
    }

    ui->table->setRowCount(sizeV);
    int i = 0;
    try
    {
        for (const auto &vehicle: vehicles)
        {
            if (vehicle->is("scooter"))
            {
                Scooter *scooter = dynamic_cast<Scooter*> (vehicle);
                if (scooter)
                {
                    ui->table->model()->setData(ui->table->model()->index(i, 0), scooter->getId());
                    ui->table->model()->setData(ui->table->model()->index(i, 1), QString::fromStdString(scooter->getVType()));
                    ui->table->model()->setData(ui->table->model()->index(i, 2), QString::fromStdString(scooter->getName()));
                    ui->table->model()->setData(ui->table->model()->index(i, 3), scooter->getPrice());
                    ui->table->model()->setData(ui->table->model()->index(i, 4), QString::fromStdString(scooter->isRent() ? "true" : "false"));
                    ui->table->model()->setData(ui->table->model()->index(i, 5), QString::fromStdString(scooter->getDate()));
                    ui->table->model()->setData(ui->table->model()->index(i, 6), QString::fromStdString(scooter->getWho()));
                    ui->table->model()->setData(ui->table->model()->index(i, 13), scooter->getScooterId());
                    ui->table->model()->setData(ui->table->model()->index(i, 14), scooter->getRange());
                    ui->table->model()->setData(ui->table->model()->index(i, 15), scooter->getDay());
                    ui->table->model()->setData(ui->table->model()->index(i, 16), scooter->getCost());
                    i++;
                }

                scooter = nullptr;
                delete scooter;
            }
        }
    }

    catch (runtime_error & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    ui->table->resizeColumnsToContents();
}

void displaywindow::on_bikes_b_clicked()
{
    ui->table->model()->removeRows(0, ui->table->model()->rowCount());

    int sizeV = 0;
    for (const auto &vehicle: vehicles)
    {
        if (vehicle->is("bike"))
        {
            sizeV++;
        }
    }

    ui->table->setRowCount(sizeV);
    int i = 0;
    try
    {
        for (const auto &vehicle: vehicles)
        {
            if (vehicle->is("bike"))
            {
                Bike *bike = dynamic_cast<Bike*> (vehicle);
                if (bike)
                {
                    ui->table->model()->setData(ui->table->model()->index(i, 0), bike->getId());
                    ui->table->model()->setData(ui->table->model()->index(i, 1), QString::fromStdString(bike->getVType()));
                    ui->table->model()->setData(ui->table->model()->index(i, 2), QString::fromStdString(bike->getName()));
                    ui->table->model()->setData(ui->table->model()->index(i, 3), bike->getPrice());
                    ui->table->model()->setData(ui->table->model()->index(i, 4), QString::fromStdString(bike->isRent() ? "true" : "false"));
                    ui->table->model()->setData(ui->table->model()->index(i, 5), QString::fromStdString(bike->getDate()));
                    ui->table->model()->setData(ui->table->model()->index(i, 6), QString::fromStdString(bike->getWho()));
                    ui->table->model()->setData(ui->table->model()->index(i, 11), QString::fromStdString(bike->getType()));
                    ui->table->model()->setData(ui->table->model()->index(i, 12), bike->getSize());
                    ui->table->model()->setData(ui->table->model()->index(i, 13), bike->getBikeId());
                    ui->table->model()->setData(ui->table->model()->index(i, 15), bike->getDay());
                    ui->table->model()->setData(ui->table->model()->index(i, 16), bike->getCost());
                    i++;
                }

                bike = nullptr;
                delete bike;
            }
        }
    }

    catch (runtime_error & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    ui->table->resizeColumnsToContents();
}

void displaywindow::on_cars_b_clicked()
{
    ui->table->model()->removeRows(0, ui->table->model()->rowCount());

    int sizeV = 0;
    for (const auto &vehicle: vehicles)
    {
        if (vehicle->is("car"))
        {
            sizeV++;
        }
    }

    ui->table->setRowCount(sizeV);
    int i = 0;
    try
    {
        for (const auto &vehicle: vehicles)
        {
            if (vehicle->is("car"))
            {
                Car *car = dynamic_cast<Car*> (vehicle);
                if (car)
                {
                    ui->table->model()->setData(ui->table->model()->index(i, 0), car->getId());
                    ui->table->model()->setData(ui->table->model()->index(i, 1), QString::fromStdString(car->getVType()));
                    ui->table->model()->setData(ui->table->model()->index(i, 2), QString::fromStdString(car->getName()));
                    ui->table->model()->setData(ui->table->model()->index(i, 3), car->getPrice());
                    ui->table->model()->setData(ui->table->model()->index(i, 4), QString::fromStdString(car->isRent() ? "true" : "false"));
                    ui->table->model()->setData(ui->table->model()->index(i, 5), QString::fromStdString(car->getDate()));
                    ui->table->model()->setData(ui->table->model()->index(i, 6), QString::fromStdString(car->getWho()));
                    ui->table->model()->setData(ui->table->model()->index(i, 7), QString::fromStdString(car->getEngine()));
                    ui->table->model()->setData(ui->table->model()->index(i, 8), car->getHorsePower());
                    ui->table->model()->setData(ui->table->model()->index(i, 9), car->getYearOfProduction());
                    ui->table->model()->setData(ui->table->model()->index(i, 10), QString::fromStdString(car->getPlate()));
                    ui->table->model()->setData(ui->table->model()->index(i, 15), car->getDay());
                    ui->table->model()->setData(ui->table->model()->index(i, 16), car->getCost());
                    i++;
                }

                car = nullptr;
                delete car;
            }
        }
    }

    catch (runtime_error & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    ui->table->resizeColumnsToContents();
}
