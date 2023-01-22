#include "returnwindow.h"
#include "ui_returnwindow.h"
#include "mainwindow.h"
#include <qtablewidget.h>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QHeaderView>
#include "vehicle.h"
#include "car.h"
#include "bike.h"
#include "scooter.h"
#include "motorbike.h"
#include "mainwindow.h"
#include <time.h>
#include <QMessageBox>

extern vector<Vehicle*> vehicles;
returnWindow::returnWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::returnWindow)
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

returnWindow::~returnWindow()
{
    delete ui;
}

void returnWindow::on_back_b_clicked()
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

void returnWindow::on_return_b_clicked()
{
    int id;
    id = ui->return_id->value();
    bool found = false;
    for (auto &vehicle: vehicles)
    {
        if (vehicle->getId() == id && vehicle->isRent())
        {
            vehicle->setRent(false);
            vehicle->setWho("-");
            vehicle->setDate("-");
            found = true;
            setTable();
            break;
        }
    }

    if (!found)
    {
        QMessageBox::information(this, "Error", "Ivalid id");
    }
}

void returnWindow::setTable()
{
    int sizeV = 0;
    int i = 0;
    for (const auto &vehicle: vehicles)
    {
        if (vehicle->isRent())
        {
            sizeV++;
        }
    }

    ui->table->setRowCount(sizeV);
    for (const auto &vehicle: vehicles)
    {
        if (vehicle->isRent())
        {
            try
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
                        ui->table->model()->setData(ui->table->model()->index(i, 15), vehicle->getDay());
                        ui->table->model()->setData(ui->table->model()->index(i, 16), vehicle->getCost());
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
                        ui->table->model()->setData(ui->table->model()->index(i, 15), vehicle->getDay());
                        ui->table->model()->setData(ui->table->model()->index(i, 16), vehicle->getCost());
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
                        ui->table->model()->setData(ui->table->model()->index(i, 15), vehicle->getDay());
                        ui->table->model()->setData(ui->table->model()->index(i, 16), vehicle->getCost());
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
                        ui->table->model()->setData(ui->table->model()->index(i, 15), vehicle->getDay());
                        ui->table->model()->setData(ui->table->model()->index(i, 16), vehicle->getCost());
                    }

                    motorbike = nullptr;
                    delete motorbike;
                }
            }

            catch (exception & e)
            {
                QMessageBox::information(this, "Error", e.what());
            }

            i++;
        }
    }

    ui->table->resizeColumnsToContents();
}
