#include "addvehicle.h"
#include "mainwindow.h"
#include "ui_addvehicle.h"
#include <QString>
#include "vehicle.h"
#include "car.h"
#include "bike.h"
#include "scooter.h"
#include "motorbike.h"
#include <QMessageBox>

extern int id;
extern vector<Vehicle*> vehicles;
using namespace std;
addVehicle::addVehicle(QWidget *parent):
    QDialog(parent),
    ui(new Ui::addVehicle)
    {
        ui->setupUi(this);
        setWindowFlag(Qt::WindowCloseButtonHint, false);
    }

addVehicle::~addVehicle()
{
    delete ui;
}

void addVehicle::on_BackButton_b_clicked()
{
    try
    {
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

void addVehicle::on_addCar_b_clicked()
{
    try
    {
        if (ui->car_engine->text() == "" || ui->car_name->text() == "" || ui->car_price->value() == 0 || ui->car_plate->text() == "" || ui->car_horse == 0 || ui->car_year->value() == 0)
        {
            throw runtime_error("all fields must by writen");
        }

        string name, plate, engine, holder;
        int horsepower, year;
        float price;
        name = ui->car_name->text().toStdString();
        price = ui->car_price->value();
        engine = ui->car_engine->text().toStdString();
        horsepower = ui->car_horse->value();
        year = ui->car_year->value();
        plate = ui->car_plate->text().toStdString();
        id++;
        vehicles.push_back(new Car(id, name, price, false, "-", "-", engine, horsepower, year, plate));
        ui->car_engine->clear();
        ui->car_name->clear();
        ui->car_plate->clear();
        ui->car_horse->clear();
        ui->car_price->clear();
        ui->car_year->clear();
    }

    catch (runtime_error & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }
}

void addVehicle::on_addBike_b_clicked()
{
    try
    {
        if (ui->bike_id->value() == 0 || ui->bike_name->text() == "" || ui->bike_price->value() == 0 || ui->bike_size->value() == 0 || ui->bike_type->text() == "")
        {
            throw runtime_error("all fields must by writen");
        }

        string name, type, holder;
        int size, bid;
        float price;
        name = ui->bike_name->text().toStdString();
        price = ui->bike_price->value();
        type = ui->bike_type->text().toStdString();
        size = ui->bike_size->value();
        bid = ui->bike_id->value();
        id++;
        vehicles.push_back(new Bike(id, name, price, false, "-", "-", type, size, bid));
        ui->bike_size->clear();
        ui->bike_id->clear();
        ui->bike_name->clear();
        ui->bike_price->clear();
        ui->bike_type->clear();
    }

    catch (runtime_error & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }
}

void addVehicle::on_addScooter_b_clicked()
{
    try
    {
        if (ui->scooter_name->text() == "" || ui->scooter_price->value() == 0 || ui->scooter_range->value() == 0 || ui->scooter_id->value() == 0)
        {
            throw runtime_error("all fields must by writen");
        }

        string name;
        int range, sid;
        float price;
        name = ui->scooter_name->text().toStdString();
        price = ui->scooter_price->value();
        range = ui->scooter_range->value();
        sid = ui->scooter_id->value();
        id++;
        vehicles.push_back(new Scooter(id, name, price, false, "-", "-", range, sid));
        ui->scooter_name->clear();
        ui->scooter_price->clear();
        ui->scooter_id->clear();
        ui->scooter_range->clear();
    }

    catch (runtime_error & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }
}

void addVehicle::on_addMotorbike_b_clicked()
{
    try
    {
        if (ui->motor_engine->text() == "" || ui->motor_name->text() == "" || ui->motor_price->value() == 0 || ui->motor_plate->text() == "" || ui->motor_horse == 0 || ui->motor_year->value() == 0 || ui->motor_type->text() == "")
        {
            throw runtime_error("all fields must by writen");
        }

        string name, plate, engine, type;
        int horse, year;
        float price;
        name = ui->motor_name->text().toStdString();
        price = ui->motor_price->value();
        engine = ui->motor_engine->text().toStdString();
        horse = ui->motor_horse->value();
        year = ui->motor_year->value();
        plate = ui->motor_plate->text().toStdString();
        type = ui->motor_type->text().toStdString();
        id++;
        vehicles.push_back(new Motorbike(id, name, price, false, "-", "-", engine, horse, year, plate, type));
        ui->motor_name->clear();
        ui->motor_price->clear();
        ui->motor_engine->clear();
        ui->motor_horse->clear();
        ui->motor_year->clear();
        ui->motor_plate->clear();
        ui->motor_type->clear();
    }

    catch (runtime_error & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }
}

void addVehicle::on_addOther_b_clicked()
{
    try
    {
        if (ui->other_name->text() == "" || ui->other_price->value() == 0)
        {
            throw runtime_error("all fields must by writen");
        }

        string name, holder;
        float price;
        name = ui->other_name->text().toStdString();
        price = ui->other_price->value();
        id++;
        vehicles.push_back(new Vehicle(id, name, price, false, "-", "-"));

        ui->other_name->clear();
        ui->other_price->clear();
    }

    catch (runtime_error & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }
}
