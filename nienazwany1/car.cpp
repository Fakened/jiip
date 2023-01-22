//
// Created by User on 15.01.2023.
//
#include "car.h"

Car::Car(int id, const string name, float price, bool rent, const string &date, const string &who, string engine,
                    int horsePower, int yearOfProduction, string plate): Vehicle(id, name, price, rent, date, who),
    engine(std::move(engine)), horsePower(horsePower), yearOfProduction(yearOfProduction), plate(std::move(plate))
    {
        if (!this)
        {
            throw runtime_error("Error: Unable to create Car object");
        }
    }

Car::Car()
{
    engine = "none";
    horsePower = 0;
    yearOfProduction = 0;
    plate = "none";
}

const string &Car::getEngine() const
{
    return engine;
}

void Car::setEngine(const string &engine)
{
    Car::engine = engine;
}

int Car::getHorsePower() const
{
    return horsePower;
}

void Car::setHorsePower(int horsePower)
{
    Car::horsePower = horsePower;
}

int Car::getYearOfProduction() const
{
    return yearOfProduction;
}

void Car::setYearOfProduction(int yearOfProduction)
{
    Car::yearOfProduction = yearOfProduction;
}

const string &Car::getPlate() const
{
    return plate;
}

void Car::setPlate(const string &plate)
{
    Car::plate = plate;
}

bool Car::is(const string &type)
{
    if (type == vType)
    {
        return true;
    }

    return false;
}

void Car::saveToFile(ofstream &fd, char vt)
{
    if (!fd.is_open())
    {
        throw runtime_error("Error: Unable to open file");
        return;
    }

    Vehicle::saveToFile(fd, 'c');
    size_t hold;
    hold = engine.size();
    fd.write((char*) &hold, sizeof(hold));
    fd.write((char*) &engine[0], hold);
    fd.write((char*) &horsePower, sizeof(int));
    fd.write((char*) &yearOfProduction, sizeof(int));
    hold = plate.size();
    fd.write((char*) &hold, sizeof(hold));
    fd.write((char*) &plate[0], hold);
}

void Car::readFromFile(ifstream & fd)
{
    if (!fd.is_open())
    {
        throw runtime_error("Error: Unable to open file");
        return;
    }

    Vehicle::readFromFile(fd);
    size_t hold;
    fd.read((char*) &hold, sizeof(hold));
    engine.resize(hold);
    fd.read((char*) &engine[0], hold);
    fd.read((char*) &horsePower, sizeof(int));
    fd.read((char*) &yearOfProduction, sizeof(int));
    fd.read((char*) &hold, sizeof(hold));
    plate.resize(hold);
    fd.read((char*) &plate[0], hold);

}

void Car::print(const Vehicle &vehicle)
{
    cout << vehicle << setw(10) << engine << setw(15) << horsePower << setw(20) << yearOfProduction << setw(20) << plate << endl;
}

const string &Car::getName() const
{
    return name;
}

float Car::getPrice() const
{
    return price;
}

bool Car::isRent() const
{
    return rent;
}

const string &Car::getDate() const
{
    return date;
}

const string &Car::getWho() const
{
    return who;
}

void Car::setName(const string &name)
{
    Vehicle::name = name;
}

void Car::setPrice(float price)
{
    Car::price = price;
}

void Car::setRent(bool rent)
{
    Car::rent = rent;
}

void Car::setDate(const string &date)
{
    Car::date = date;
}

void Car::setWho(const string &who)
{
    Car::who = who;
}

int Car::getId() const
{
    return id;
}

void Car::setWho(const Person &p)
{
    who = p.name;
}

string Car::getVType() const
{
    return Car::vType;
}

bool Car::is()
{
    return true;
}
