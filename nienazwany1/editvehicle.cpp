#include "editvehicle.h"
#include "qcheckbox.h"
#include "qlineedit.h"
#include "ui_editvehicle.h"
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
#include <QMessageBox>
#include <QComboBox>

extern vector<Vehicle*> vehicles;

editVehicle::editVehicle(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::editVehicle)
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

editVehicle::~editVehicle()
{
    delete ui;
}

void editVehicle::on_back_b_clicked()
{
    try
    {
        ui->table->model()->removeRows(0, ui->table->model()->rowCount());
        delete ui->table->model();
        delete ui->table;
        close();
        MainWindow *mainWin = new MainWindow;
        mainWin->show();
        delete ui;
    }

    catch (exception & e)
    {
        QMessageBox::information(this, "Error", e.what());
    }
}

void editVehicle::setTable()
{
    ui->table->model()->removeRows(0, ui->table->model()->rowCount());
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

void editVehicle::on_remove_b_clicked()
{
    if (ui->edit_label->isEmpty())
    {
        bool toRemove = false;
        int i = 0, id = ui->remove_sp->value();
        for (const auto &vehicle: vehicles)
        {
            if (vehicle->getId() == id)
            {
                toRemove = true;
                try
                {
                    delete vehicles[i];
                    vehicles.erase(vehicles.begin() + i);
                }

                catch (exception & e)
                {
                    QMessageBox::information(this, "Error", e.what());
                }

                setTable();
                break;
            }

            i++;
        }

        if (!toRemove)
        {
            QMessageBox::information(this, "Error", "Ivalid id");
        }
    }
    else
    {
        QMessageBox::information(this, "Error", "You must finish editing the previous item");
    }
}

void editVehicle::on_edit_b_clicked()
{
    if (ui->edit_label->isEmpty())
    {
        bool toEdit = false;
        int id = ui->edit_sb->value();
        string type;
        for (const auto &vehicle: vehicles)
        {
            if (vehicle->getId() == id)
            {
                type = vehicle->getVType();
                toEdit = true;
                break;
            }
        }

        if (!toEdit)
        {
            QMessageBox::information(this, "Error", "Ivalid id");
        }
        else
        {
            if (type == "other")
            {
                editOther(id);
            }
            else if (type == "car")
            {
                editCar(id);
            }
            else if (type == "scooter")
            {
                editScooter(id);
            }
            else if (type == "bike")
            {
                editBike(id);
            }
            else if (type == "motorbike")
            {
                editMotorbike(id);
            }
        }
    }
    else
    {
        QMessageBox::information(this, "Error", "You must finish editing the previous item");
    }
}

void editVehicle::editOther(int id)
{
    QLineEdit *who = new QLineEdit();
    who->setPlaceholderText("Name");
    who->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QLineEdit *name = new QLineEdit();
    name->setPlaceholderText("Name");
    name->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QDoubleSpinBox *price = new QDoubleSpinBox();
    price->setToolTip("Price");
    price->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    price->setAlignment(Qt::Alignment(Qt::AlignCenter));
    price->setButtonSymbols(QAbstractSpinBox::NoButtons);
    price->setMaximum(10000000);
    price->setDecimals(2);
    price->setMinimum(0);

    QPushButton *accept_o = new QPushButton();
    accept_o->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    accept_o->setText("Do edit");

    QCheckBox *rent = new QCheckBox();

    QComboBox *day = new QComboBox();
    for (int i = 0; i < 32; i++)
    {
        day->addItem(QString::number(i), QVariant(i));
    }

    QComboBox *month = new QComboBox();
    for (int i = 0; i < 13; i++)
    {
        month->addItem(QString::number(i), QVariant(i));
    }

    QSpinBox *year = new QSpinBox;
    year->setToolTip("Year");
    year->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    year->setAlignment(Qt::Alignment(Qt::AlignCenter));
    year->setButtonSymbols(QAbstractSpinBox::NoButtons);
    year->setMaximum(2023);
    year->setMinimum(1900);

    ui->edit_label->addWidget(name);
    ui->edit_label->addWidget(price);
    ui->edit_label->addWidget(rent);
    ui->edit_label->addWidget(day);
    ui->edit_label->addWidget(month);
    ui->edit_label->addWidget(year);
    ui->edit_label->addWidget(who);
    ui->edit_label->addWidget(accept_o);
    QObject::connect(accept_o, &QPushButton::clicked, this, [this, id, rent, who, name, price, accept_o, day, month, year]()
    {
        try
        {
            for (const auto &vehicle: vehicles)
            {
                if (vehicle->getId() == id)
                {
                    if (name->text() != "")
                    {
                        vehicle->setName(name->text().toStdString());
                    }

                    if (price->value() != 0.00)
                    {
                        vehicle->setPrice(price->value());
                    }

                    if (rent->isChecked() && !vehicle->isRent())
                    {
                        if (who->text() != "" && day->currentIndex() != 0 && month->currentIndex() != 0 && year->value() != 1900)
                        {
                            vehicle->setRent(true);
                            string date;
                            if (month->currentIndex() == 1 || month->currentIndex() == 3 || month->currentIndex() == 5 || month->currentIndex() == 7 || month->currentIndex() == 8 || month->currentIndex() == 10 || month->currentIndex() == 12)
                            {
                                date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                            }
                            else if (month->currentIndex() == 2)
                            {
                                if (isLeapYer(year->value()) && day->currentIndex() < 30)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else if (!isLeapYer(year->value()) && day->currentIndex() < 29)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else
                                {
                                    throw runtime_error("Invalid data");
                                }
                            }
                            else if (day->currentIndex() < 31)
                            {
                                date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                            }
                            else
                            {
                                throw runtime_error("Invalid data");
                            }

                            time_t now = time(nullptr);
                            tm timeset;
                            timeset.tm_hour = 0;
                            timeset.tm_isdst = -1;
                            timeset.tm_min = 0;
                            timeset.tm_sec = 0;
                            timeset.tm_mday = day->currentIndex();
                            timeset.tm_mon = month->currentIndex() - 1;
                            timeset.tm_year = year->value() - 1900;
                            time_t past = mktime(&timeset);
                            if (past > now)
                            {
                                throw runtime_error("Cannot set a future date");
                            }

                            vehicle->setDate(date);
                            vehicle->setWho(who->text().toStdString());
                        }
                        else
                        {
                            throw runtime_error("You cannot set renting without setting name or date");
                        }
                    }

                    if (vehicle->isRent() && who->text() != "")
                    {
                        vehicle->setWho(who->text().toStdString());
                    }

                    if (vehicle->isRent())
                    {
                        string date;
                        if (month->currentIndex() == 1 || month->currentIndex() == 3 || month->currentIndex() == 5 || month->currentIndex() == 7 || month->currentIndex() == 8 || month->currentIndex() == 10 || month->currentIndex() == 12)
                        {
                            date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                        }
                        else if (month->currentIndex() == 2)
                        {
                            if (isLeapYer(year->value()) && day->currentIndex() < 30)
                            {
                                date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                            }
                            else if (!isLeapYer(year->value()) && day->currentIndex() < 29)
                            {
                                date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                            }
                            else
                            {
                                throw runtime_error("Invalid data");
                            }
                        }
                        else if (day->currentIndex() < 31)
                        {
                            date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                        }
                        else
                        {
                            throw runtime_error("Invalid data");
                        }

                        time_t now = time(nullptr);
                        tm timeset;
                        timeset.tm_hour = 0;
                        timeset.tm_isdst = -1;
                        timeset.tm_min = 0;
                        timeset.tm_sec = 0;
                        timeset.tm_mday = day->currentIndex();
                        timeset.tm_mon = month->currentIndex() - 1;
                        timeset.tm_year = year->value() - 1900;
                        time_t past = mktime(&timeset);
                        if (past > now)
                        {
                            throw runtime_error("Cannot set a future date");
                        }

                        vehicle->setDate(date);
                    }

                    if (vehicle->isRent() && !rent->isChecked())
                    {
                        vehicle->setRent(false);
                        vehicle->setDate("-");
                        vehicle->setWho("-");
                    }

                    vehicle->setDay();
                    vehicle->doCost();
                    setTable();
                    delete day;
                    delete year;
                    delete month;
                    delete name;
                    delete price;
                    delete accept_o;
                    delete rent;
                    delete who;
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
        } });
}

void editVehicle::editCar(int id)
{
    QSpinBox *horse = new QSpinBox;
    horse->setToolTip("Horse power");
    horse->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    horse->setAlignment(Qt::Alignment(Qt::AlignCenter));
    horse->setButtonSymbols(QAbstractSpinBox::NoButtons);
    horse->setMaximum(2000);
    horse->setMinimum(0);

    QSpinBox *pyear = new QSpinBox;
    pyear->setToolTip("Year of production");
    pyear->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    pyear->setAlignment(Qt::Alignment(Qt::AlignCenter));
    pyear->setButtonSymbols(QAbstractSpinBox::NoButtons);
    pyear->setMaximum(2023);
    pyear->setMinimum(1900);

    QLineEdit *engine = new QLineEdit();
    engine->setPlaceholderText("Engine");
    engine->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QLineEdit *plate = new QLineEdit;
    plate->setPlaceholderText("Plate");
    plate->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QLineEdit *who = new QLineEdit();
    who->setPlaceholderText("Name");
    who->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QLineEdit *name = new QLineEdit();
    name->setPlaceholderText("Name");
    name->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QDoubleSpinBox *price = new QDoubleSpinBox();
    price->setToolTip("Price");
    price->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    price->setAlignment(Qt::Alignment(Qt::AlignCenter));
    price->setButtonSymbols(QAbstractSpinBox::NoButtons);
    price->setMaximum(10000000);
    price->setDecimals(2);
    price->setMinimum(0);

    QPushButton *accept_o = new QPushButton();
    accept_o->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    accept_o->setText("Do edit");

    QCheckBox *rent = new QCheckBox();

    QComboBox *day = new QComboBox();
    for (int i = 0; i < 32; i++)
    {
        day->addItem(QString::number(i), QVariant(i));
    }

    QComboBox *month = new QComboBox();
    for (int i = 0; i < 13; i++)
    {
        month->addItem(QString::number(i), QVariant(i));
    }

    QSpinBox *year = new QSpinBox;
    year->setToolTip("Year");
    year->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    year->setAlignment(Qt::Alignment(Qt::AlignCenter));
    year->setButtonSymbols(QAbstractSpinBox::NoButtons);
    year->setMaximum(2023);
    year->setMinimum(1900);

    ui->edit_label->addWidget(name);
    ui->edit_label->addWidget(price);
    ui->edit_label->addWidget(rent);
    ui->edit_label->addWidget(day);
    ui->edit_label->addWidget(month);
    ui->edit_label->addWidget(year);
    ui->edit_label->addWidget(who);
    ui->edit_label->addWidget(engine);
    ui->edit_label->addWidget(horse);
    ui->edit_label->addWidget(pyear);
    ui->edit_label->addWidget(plate);
    ui->edit_label->addWidget(accept_o);
    QObject::connect(accept_o, &QPushButton::clicked, this, [this, id, rent, who, name, price, accept_o, engine, horse, pyear, plate, day, year, month]()
    {
        try
        {
            for (const auto &vehicle: vehicles)
            {
                if (vehicle->getId() == id)
                {
                    Car *car = dynamic_cast<Car*> (vehicle);
                    if (car)
                    {
                        if (name->text() != "")
                        {
                            vehicle->setName(name->text().toStdString());
                        }

                        if (price->value() != 0.00)
                        {
                            vehicle->setPrice(price->value());
                        }

                        if (rent->isChecked() && !vehicle->isRent())
                        {
                            if (who->text() != "" && day->currentIndex() != 0 && month->currentIndex() != 0 && year->value() != 1900)
                            {
                                vehicle->setRent(true);
                                string date;
                                if (month->currentIndex() == 1 || month->currentIndex() == 3 || month->currentIndex() == 5 || month->currentIndex() == 7 || month->currentIndex() == 8 || month->currentIndex() == 10 || month->currentIndex() == 12)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else if (month->currentIndex() == 2)
                                {
                                    if (isLeapYer(year->value()) && day->currentIndex() < 30)
                                    {
                                        date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                    }
                                    else if (!isLeapYer(year->value()) && day->currentIndex() < 29)
                                    {
                                        date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                    }
                                    else
                                    {
                                        throw runtime_error("Invalid data");
                                    }
                                }
                                else if (day->currentIndex() < 31)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else
                                {
                                    throw runtime_error("Invalid data");
                                }

                                time_t now = time(nullptr);
                                tm timeset;
                                timeset.tm_hour = 0;
                                timeset.tm_isdst = -1;
                                timeset.tm_min = 0;
                                timeset.tm_sec = 0;
                                timeset.tm_mday = day->currentIndex();
                                timeset.tm_mon = month->currentIndex() - 1;
                                timeset.tm_year = year->value() - 1900;
                                time_t past = mktime(&timeset);
                                if (past > now)
                                {
                                    throw runtime_error("Cannot set a future date");
                                }

                                vehicle->setDate(date);
                                vehicle->setWho(who->text().toStdString());
                            }
                            else
                            {
                                throw runtime_error("You cannot set renting without setting name or date");
                            }
                        }

                        if (vehicle->isRent() && who->text() != "")
                        {
                            vehicle->setWho(who->text().toStdString());
                        }

                        if (vehicle->isRent())
                        {
                            string date;
                            if (month->currentIndex() == 1 || month->currentIndex() == 3 || month->currentIndex() == 5 || month->currentIndex() == 7 || month->currentIndex() == 8 || month->currentIndex() == 10 || month->currentIndex() == 12)
                            {
                                date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                            }
                            else if (month->currentIndex() == 2)
                            {
                                if (isLeapYer(year->value()) && day->currentIndex() < 30)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else if (!isLeapYer(year->value()) && day->currentIndex() < 29)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else
                                {
                                    throw runtime_error("Invalid data");
                                }
                            }
                            else if (day->currentIndex() < 31)
                            {
                                date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                            }
                            else
                            {
                                throw runtime_error("Invalid data");
                            }

                            time_t now = time(nullptr);
                            tm timeset;
                            timeset.tm_hour = 0;
                            timeset.tm_isdst = -1;
                            timeset.tm_min = 0;
                            timeset.tm_sec = 0;
                            timeset.tm_mday = day->currentIndex();
                            timeset.tm_mon = month->currentIndex() - 1;
                            timeset.tm_year = year->value() - 1900;
                            time_t past = mktime(&timeset);
                            if (past > now)
                            {
                                throw runtime_error("Cannot set a future date");
                            }

                            vehicle->setDate(date);
                        }

                        if (vehicle->isRent() && !rent->isChecked())
                        {
                            vehicle->setRent(false);
                            vehicle->setDate("-");
                            vehicle->setWho("-");
                        }

                        if (engine->text() != "")
                        {
                            car->setEngine(engine->text().toStdString());
                        }

                        if (horse->value() != 0)
                        {
                            car->setHorsePower(horse->value());
                        }

                        if (pyear->value() != 1900)
                        {
                            car->setYearOfProduction(pyear->value());
                        }

                        if (plate->text() != "")
                        {
                            car->setPlate(plate->text().toStdString());
                        }

                        vehicle->setDay();
                        vehicle->doCost();
                        setTable();
                        delete day;
                        delete year;
                        delete month;
                        car = nullptr;
                        delete car;
                        delete plate;
                        delete pyear;
                        delete horse;
                        delete engine;
                        delete name;
                        delete price;
                        delete accept_o;
                        delete rent;
                        delete who;
                    }
                }
            }
        }

        catch (runtime_error & e)
        {
            QMessageBox::information(this, "Error", e.what());
        } });
}

void editVehicle::editScooter(int id)
{
    QSpinBox *sid = new QSpinBox;
    sid->setToolTip("Internal ID");
    sid->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sid->setAlignment(Qt::Alignment(Qt::AlignCenter));
    sid->setButtonSymbols(QAbstractSpinBox::NoButtons);
    sid->setMaximum(10000000);
    sid->setMinimum(0);

    QSpinBox *range = new QSpinBox;
    range->setToolTip("Range");
    range->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    range->setAlignment(Qt::Alignment(Qt::AlignCenter));
    range->setButtonSymbols(QAbstractSpinBox::NoButtons);
    range->setMaximum(2000);
    range->setMinimum(0);

    QLineEdit *who = new QLineEdit();
    who->setPlaceholderText("Name");
    who->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QLineEdit *name = new QLineEdit();
    name->setPlaceholderText("Name");
    name->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QDoubleSpinBox *price = new QDoubleSpinBox();
    price->setToolTip("Price");
    price->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    price->setAlignment(Qt::Alignment(Qt::AlignCenter));
    price->setButtonSymbols(QAbstractSpinBox::NoButtons);
    price->setMaximum(10000000);
    price->setDecimals(2);
    price->setMinimum(0);

    QPushButton *accept_o = new QPushButton();
    accept_o->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    accept_o->setText("Do edit");

    QCheckBox *rent = new QCheckBox();

    QComboBox *day = new QComboBox();
    for (int i = 0; i < 32; i++)
    {
        day->addItem(QString::number(i), QVariant(i));
    }

    QComboBox *month = new QComboBox();
    for (int i = 0; i < 13; i++)
    {
        month->addItem(QString::number(i), QVariant(i));
    }

    QSpinBox *year = new QSpinBox;
    year->setToolTip("Year");
    year->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    year->setAlignment(Qt::Alignment(Qt::AlignCenter));
    year->setButtonSymbols(QAbstractSpinBox::NoButtons);
    year->setMaximum(2023);
    year->setMinimum(1900);

    ui->edit_label->addWidget(name);
    ui->edit_label->addWidget(price);
    ui->edit_label->addWidget(rent);
    ui->edit_label->addWidget(day);
    ui->edit_label->addWidget(month);
    ui->edit_label->addWidget(year);
    ui->edit_label->addWidget(who);
    ui->edit_label->addWidget(sid);
    ui->edit_label->addWidget(range);
    ui->edit_label->addWidget(accept_o);
    QObject::connect(accept_o, &QPushButton::clicked, this, [this, id, rent, who, name, price, accept_o, sid, range, day, year, month]()
    {
        try
        {
            for (const auto &vehicle: vehicles)
            {
                if (vehicle->getId() == id)
                {
                    Scooter *scooter = dynamic_cast<Scooter*> (vehicle);
                    if (scooter)
                    {
                        if (name->text() != "")
                        {
                            vehicle->setName(name->text().toStdString());
                        }

                        if (price->value() != 0.00)
                        {
                            vehicle->setPrice(price->value());
                        }

                        if (rent->isChecked() && !vehicle->isRent())
                        {
                            if (who->text() != "" && day->currentIndex() != 0 && month->currentIndex() != 0 && year->value() != 1900)
                            {
                                vehicle->setRent(true);
                                string date;
                                if (month->currentIndex() == 1 || month->currentIndex() == 3 || month->currentIndex() == 5 || month->currentIndex() == 7 || month->currentIndex() == 8 || month->currentIndex() == 10 || month->currentIndex() == 12)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else if (month->currentIndex() == 2)
                                {
                                    if (isLeapYer(year->value()) && day->currentIndex() < 30)
                                    {
                                        date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                    }
                                    else if (!isLeapYer(year->value()) && day->currentIndex() < 29)
                                    {
                                        date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                    }
                                    else
                                    {
                                        throw runtime_error("Invalid data");
                                    }
                                }
                                else if (day->currentIndex() < 31)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else
                                {
                                    throw runtime_error("Invalid data");
                                }

                                time_t now = time(nullptr);
                                tm timeset;
                                timeset.tm_hour = 0;
                                timeset.tm_isdst = -1;
                                timeset.tm_min = 0;
                                timeset.tm_sec = 0;
                                timeset.tm_mday = day->currentIndex();
                                timeset.tm_mon = month->currentIndex() - 1;
                                timeset.tm_year = year->value() - 1900;
                                time_t past = mktime(&timeset);
                                if (past > now)
                                {
                                    throw runtime_error("Cannot set a future date");
                                }

                                vehicle->setDate(date);
                                vehicle->setWho(who->text().toStdString());
                            }
                            else
                            {
                                throw runtime_error("You cannot set renting without setting name or date");
                            }
                        }

                        if (vehicle->isRent() && who->text() != "")
                        {
                            vehicle->setWho(who->text().toStdString());
                        }

                        if (vehicle->isRent())
                        {
                            string date;
                            if (month->currentIndex() == 1 || month->currentIndex() == 3 || month->currentIndex() == 5 || month->currentIndex() == 7 || month->currentIndex() == 8 || month->currentIndex() == 10 || month->currentIndex() == 12)
                            {
                                date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                            }
                            else if (month->currentIndex() == 2)
                            {
                                if (isLeapYer(year->value()) && day->currentIndex() < 30)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else if (!isLeapYer(year->value()) && day->currentIndex() < 29)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else
                                {
                                    throw runtime_error("Invalid data");
                                }
                            }
                            else if (day->currentIndex() < 31)
                            {
                                date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                            }
                            else
                            {
                                throw runtime_error("Invalid data");
                            }

                            time_t now = time(nullptr);
                            tm timeset;
                            timeset.tm_hour = 0;
                            timeset.tm_isdst = -1;
                            timeset.tm_min = 0;
                            timeset.tm_sec = 0;
                            timeset.tm_mday = day->currentIndex();
                            timeset.tm_mon = month->currentIndex() - 1;
                            timeset.tm_year = year->value() - 1900;
                            time_t past = mktime(&timeset);
                            if (past > now)
                            {
                                throw runtime_error("Cannot set a future date");
                            }

                            vehicle->setDate(date);
                        }

                        if (vehicle->isRent() && !rent->isChecked())
                        {
                            vehicle->setRent(false);
                            vehicle->setDate("-");
                            vehicle->setWho("-");
                        }

                        if (sid->value() != 0)
                        {
                            scooter->setScooterId(sid->value());
                        }

                        if (range->value() != 0)
                        {
                            scooter->setRange(range->value());
                        }

                        vehicle->setDay();
                        vehicle->doCost();
                        setTable();
                        delete day;
                        delete year;
                        delete month;
                        scooter = nullptr;
                        delete sid;
                        delete range;
                        delete name;
                        delete price;
                        delete accept_o;
                        delete rent;
                        delete who;
                    }
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
        } });
}

void editVehicle::editBike(int id)
{
    QSpinBox *size = new QSpinBox;
    size->setToolTip("Size");
    size->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    size->setAlignment(Qt::Alignment(Qt::AlignCenter));
    size->setButtonSymbols(QAbstractSpinBox::NoButtons);
    size->setMaximum(10000000);
    size->setMinimum(0);

    QSpinBox *bid = new QSpinBox;
    bid->setToolTip("internal ID");
    bid->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    bid->setAlignment(Qt::Alignment(Qt::AlignCenter));
    bid->setButtonSymbols(QAbstractSpinBox::NoButtons);
    bid->setMaximum(2000);
    bid->setMinimum(0);

    QLineEdit *who = new QLineEdit();
    who->setPlaceholderText("Name");
    who->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QLineEdit *name = new QLineEdit();
    name->setPlaceholderText("Name");
    name->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QDoubleSpinBox *price = new QDoubleSpinBox();
    price->setToolTip("Price");
    price->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    price->setAlignment(Qt::Alignment(Qt::AlignCenter));
    price->setButtonSymbols(QAbstractSpinBox::NoButtons);
    price->setMaximum(10000000);
    price->setDecimals(2);
    price->setMinimum(0);

    QPushButton *accept_o = new QPushButton();
    accept_o->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    accept_o->setText("Do edit");

    QCheckBox *rent = new QCheckBox();

    QLineEdit *type = new QLineEdit();
    type->setPlaceholderText("Type");
    type->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QComboBox *day = new QComboBox();
    for (int i = 0; i < 32; i++)
    {
        day->addItem(QString::number(i), QVariant(i));
    }

    QComboBox *month = new QComboBox();
    for (int i = 0; i < 13; i++)
    {
        month->addItem(QString::number(i), QVariant(i));
    }

    QSpinBox *year = new QSpinBox;
    year->setToolTip("Year");
    year->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    year->setAlignment(Qt::Alignment(Qt::AlignCenter));
    year->setButtonSymbols(QAbstractSpinBox::NoButtons);
    year->setMaximum(2023);
    year->setMinimum(1900);

    ui->edit_label->addWidget(name);
    ui->edit_label->addWidget(price);
    ui->edit_label->addWidget(rent);
    ui->edit_label->addWidget(day);
    ui->edit_label->addWidget(month);
    ui->edit_label->addWidget(year);
    ui->edit_label->addWidget(who);
    ui->edit_label->addWidget(type);
    ui->edit_label->addWidget(size);
    ui->edit_label->addWidget(bid);
    ui->edit_label->addWidget(accept_o);
    QObject::connect(accept_o, &QPushButton::clicked, this, [this, id, rent, who, name, price, accept_o, bid, size, type, day, year, month]()
    {
        try
        {
            for (const auto &vehicle: vehicles)
            {
                if (vehicle->getId() == id)
                {
                    Bike *bike = dynamic_cast<Bike*> (vehicle);
                    if (bike)
                    {
                        if (name->text() != "")
                        {
                            vehicle->setName(name->text().toStdString());
                        }

                        if (price->value() != 0.00)
                        {
                            vehicle->setPrice(price->value());
                        }

                        if (rent->isChecked() && !vehicle->isRent())
                        {
                            if (who->text() != "" && day->currentIndex() != 0 && month->currentIndex() != 0 && year->value() != 1900)
                            {
                                vehicle->setRent(true);
                                string date;
                                if (month->currentIndex() == 1 || month->currentIndex() == 3 || month->currentIndex() == 5 || month->currentIndex() == 7 || month->currentIndex() == 8 || month->currentIndex() == 10 || month->currentIndex() == 12)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else if (month->currentIndex() == 2)
                                {
                                    if (isLeapYer(year->value()) && day->currentIndex() < 30)
                                    {
                                        date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                    }
                                    else if (!isLeapYer(year->value()) && day->currentIndex() < 29)
                                    {
                                        date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                    }
                                    else
                                    {
                                        throw runtime_error("Invalid data");
                                    }
                                }
                                else if (day->currentIndex() < 31)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else
                                {
                                    throw runtime_error("Invalid data");
                                }

                                time_t now = time(nullptr);
                                tm timeset;
                                timeset.tm_hour = 0;
                                timeset.tm_isdst = -1;
                                timeset.tm_min = 0;
                                timeset.tm_sec = 0;
                                timeset.tm_mday = day->currentIndex();
                                timeset.tm_mon = month->currentIndex() - 1;
                                timeset.tm_year = year->value() - 1900;
                                time_t past = mktime(&timeset);
                                if (past > now)
                                {
                                    throw runtime_error("Cannot set a future date");
                                }

                                vehicle->setDate(date);
                                vehicle->setWho(who->text().toStdString());
                            }
                            else
                            {
                                throw runtime_error("You cannot set renting without setting name or date");
                            }
                        }

                        if (vehicle->isRent() && who->text() != "")
                        {
                            vehicle->setWho(who->text().toStdString());
                        }

                        if (vehicle->isRent())
                        {
                            string date;
                            if (month->currentIndex() == 1 || month->currentIndex() == 3 || month->currentIndex() == 5 || month->currentIndex() == 7 || month->currentIndex() == 8 || month->currentIndex() == 10 || month->currentIndex() == 12)
                            {
                                date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                            }
                            else if (month->currentIndex() == 2)
                            {
                                if (isLeapYer(year->value()) && day->currentIndex() < 30)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else if (!isLeapYer(year->value()) && day->currentIndex() < 29)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else
                                {
                                    throw runtime_error("Invalid data");
                                }
                            }
                            else if (day->currentIndex() < 31)
                            {
                                date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                            }
                            else
                            {
                                throw runtime_error("Invalid data");
                            }

                            time_t now = time(nullptr);
                            tm timeset;
                            timeset.tm_hour = 0;
                            timeset.tm_isdst = -1;
                            timeset.tm_min = 0;
                            timeset.tm_sec = 0;
                            timeset.tm_mday = day->currentIndex();
                            timeset.tm_mon = month->currentIndex() - 1;
                            timeset.tm_year = year->value() - 1900;
                            time_t past = mktime(&timeset);
                            if (past > now)
                            {
                                throw runtime_error("Cannot set a future date");
                            }

                            vehicle->setDate(date);
                        }

                        if (vehicle->isRent() && !rent->isChecked())
                        {
                            vehicle->setRent(false);
                            vehicle->setDate("-");
                            vehicle->setWho("-");
                        }

                        if (bid->value() != 0)
                        {
                            bike->setBikeId(bid->value());
                        }

                        if (size->value() != 0)
                        {
                            bike->setSize(size->value());
                        }

                        if (type->text() != "")
                        {
                            bike->setType(type->text().toStdString());
                        }

                        vehicle->setDay();
                        vehicle->doCost();
                        setTable();
                        delete day;
                        delete year;
                        delete month;
                        bike = nullptr;
                        delete bid;
                        delete size;
                        delete type;
                        delete name;
                        delete price;
                        delete accept_o;
                        delete rent;
                        delete who;
                    }
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
        } });
}

void editVehicle::editMotorbike(int id)
{
    QSpinBox *horse = new QSpinBox;
    horse->setToolTip("Horse power");
    horse->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    horse->setAlignment(Qt::Alignment(Qt::AlignCenter));
    horse->setButtonSymbols(QAbstractSpinBox::NoButtons);
    horse->setMaximum(2000);
    horse->setMinimum(0);

    QSpinBox *pyear = new QSpinBox;
    pyear->setToolTip("Year of production");
    pyear->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    pyear->setAlignment(Qt::Alignment(Qt::AlignCenter));
    pyear->setButtonSymbols(QAbstractSpinBox::NoButtons);
    pyear->setMaximum(2023);
    pyear->setMinimum(1900);

    QLineEdit *engine = new QLineEdit();
    engine->setPlaceholderText("Engine");
    engine->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QLineEdit *plate = new QLineEdit;
    plate->setPlaceholderText("Plate");
    plate->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QLineEdit *who = new QLineEdit();
    who->setPlaceholderText("Name");
    who->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QLineEdit *name = new QLineEdit();
    name->setPlaceholderText("Name");
    name->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QDoubleSpinBox *price = new QDoubleSpinBox();
    price->setToolTip("Price");
    price->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    price->setAlignment(Qt::Alignment(Qt::AlignCenter));
    price->setButtonSymbols(QAbstractSpinBox::NoButtons);
    price->setMaximum(10000000);
    price->setDecimals(2);
    price->setMinimum(0);

    QPushButton *accept_o = new QPushButton();
    accept_o->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    accept_o->setText("Do edit");

    QCheckBox *rent = new QCheckBox();

    QLineEdit *type = new QLineEdit;
    type->setPlaceholderText("Type");
    type->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QComboBox *day = new QComboBox();
    for (int i = 0; i < 32; i++)
    {
        day->addItem(QString::number(i), QVariant(i));
    }

    QComboBox *month = new QComboBox();
    for (int i = 0; i < 13; i++)
    {
        month->addItem(QString::number(i), QVariant(i));
    }

    QSpinBox *year = new QSpinBox;
    year->setToolTip("Year");
    year->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    year->setAlignment(Qt::Alignment(Qt::AlignCenter));
    year->setButtonSymbols(QAbstractSpinBox::NoButtons);
    year->setMaximum(2023);
    year->setMinimum(1900);

    ui->edit_label->addWidget(name);
    ui->edit_label->addWidget(price);
    ui->edit_label->addWidget(rent);
    ui->edit_label->addWidget(day);
    ui->edit_label->addWidget(month);
    ui->edit_label->addWidget(year);
    ui->edit_label->addWidget(who);
    ui->edit_label->addWidget(engine);
    ui->edit_label->addWidget(horse);
    ui->edit_label->addWidget(pyear);
    ui->edit_label->addWidget(plate);
    ui->edit_label->addWidget(type);
    ui->edit_label->addWidget(accept_o);
    QObject::connect(accept_o, &QPushButton::clicked, this, [this, id, rent, who, name, price, accept_o, engine, horse, pyear, plate, type, day, year, month]()
    {
        try
        {
            for (const auto &vehicle: vehicles)
            {
                if (vehicle->getId() == id)
                {
                    Motorbike *motorbike = dynamic_cast<Motorbike*> (vehicle);
                    if (motorbike)
                    {
                        if (name->text() != "")
                        {
                            vehicle->setName(name->text().toStdString());
                        }

                        if (price->value() != 0.00)
                        {
                            vehicle->setPrice(price->value());
                        }

                        if (rent->isChecked() && !vehicle->isRent())
                        {
                            if (who->text() != "" && day->currentIndex() != 0 && month->currentIndex() != 0 && year->value() != 1900)
                            {
                                vehicle->setRent(true);
                                string date;
                                if (month->currentIndex() == 1 || month->currentIndex() == 3 || month->currentIndex() == 5 || month->currentIndex() == 7 || month->currentIndex() == 8 || month->currentIndex() == 10 || month->currentIndex() == 12)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else if (month->currentIndex() == 2)
                                {
                                    if (isLeapYer(year->value()) && day->currentIndex() < 30)
                                    {
                                        date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                    }
                                    else if (!isLeapYer(year->value()) && day->currentIndex() < 29)
                                    {
                                        date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                    }
                                    else
                                    {
                                        throw runtime_error("Invalid data");
                                    }
                                }
                                else if (day->currentIndex() < 31)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else
                                {
                                    throw runtime_error("Invalid data");
                                }

                                time_t now = time(nullptr);
                                tm timeset;
                                timeset.tm_hour = 0;
                                timeset.tm_isdst = -1;
                                timeset.tm_min = 0;
                                timeset.tm_sec = 0;
                                timeset.tm_mday = day->currentIndex();
                                timeset.tm_mon = month->currentIndex() - 1;
                                timeset.tm_year = year->value() - 1900;
                                time_t past = mktime(&timeset);
                                if (past > now)
                                {
                                    throw runtime_error("Cannot set a future date");
                                }

                                vehicle->setDate(date);
                                vehicle->setWho(who->text().toStdString());
                            }
                            else
                            {
                                throw runtime_error("You cannot set renting without setting name or date");
                            }
                        }

                        if (vehicle->isRent() && who->text() != "")
                        {
                            vehicle->setWho(who->text().toStdString());
                        }

                        if (vehicle->isRent())
                        {
                            string date;
                            if (month->currentIndex() == 1 || month->currentIndex() == 3 || month->currentIndex() == 5 || month->currentIndex() == 7 || month->currentIndex() == 8 || month->currentIndex() == 10 || month->currentIndex() == 12)
                            {
                                date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                            }
                            else if (month->currentIndex() == 2)
                            {
                                if (isLeapYer(year->value()) && day->currentIndex() < 30)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else if (!isLeapYer(year->value()) && day->currentIndex() < 29)
                                {
                                    date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                                }
                                else
                                {
                                    throw runtime_error("Invalid data");
                                }
                            }
                            else if (day->currentIndex() < 31)
                            {
                                date += to_string(day->currentIndex()) + "-" + to_string(month->currentIndex()) + "-" + to_string(year->value());
                            }
                            else
                            {
                                throw runtime_error("Invalid data");
                            }

                            time_t now = time(nullptr);
                            tm timeset;
                            timeset.tm_hour = 0;
                            timeset.tm_isdst = -1;
                            timeset.tm_min = 0;
                            timeset.tm_sec = 0;
                            timeset.tm_mday = day->currentIndex();
                            timeset.tm_mon = month->currentIndex() - 1;
                            timeset.tm_year = year->value() - 1900;
                            time_t past = mktime(&timeset);
                            if (past > now)
                            {
                                throw runtime_error("Cannot set a future date");
                            }

                            vehicle->setDate(date);
                        }

                        if (vehicle->isRent() && !rent->isChecked())
                        {
                            vehicle->setRent(false);
                            vehicle->setDate("-");
                            vehicle->setWho("-");
                        }

                        if (engine->text() != "")
                        {
                            motorbike->setEngine(engine->text().toStdString());
                        }

                        if (horse->value() != 0)
                        {
                            motorbike->setHorsePower(horse->value());
                        }

                        if (pyear->value() != 1900)
                        {
                            motorbike->setYearOfProduction(pyear->value());
                        }

                        if (plate->text() != "")
                        {
                            motorbike->setPlate(plate->text().toStdString());
                        }

                        if (type->text() != "")
                        {
                            motorbike->setType(type->text().toStdString());
                        }

                        vehicle->setDay();
                        vehicle->doCost();
                        setTable();
                        delete day;
                        delete year;
                        delete month;
                        motorbike = nullptr;
                        delete motorbike;
                        delete type;
                        delete plate;
                        delete pyear;
                        delete horse;
                        delete engine;
                        delete name;
                        delete price;
                        delete accept_o;
                        delete rent;
                        delete who;
                    }
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
        } });
}

bool editVehicle::isLeapYer(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}
