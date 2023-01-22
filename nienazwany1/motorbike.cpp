//
// Created by User on 15.01.2023.
//
#include "motorbike.h"

Motorbike::Motorbike(int id, const string name, float price, bool rent, const string &date, const string &who, string engine, int horsePower, int yearofProduction, string plate, string type): Vehicle(id, name, price, rent, date, who), engine(std::move(engine)), horsePower(horsePower), yearOfProduction(yearofProduction), plate(std::move(plate)), type(std::move(type))
{
    if (!this)
    {
        throw runtime_error("Error: Unable to create Motorbike object");
    }
}

Motorbike::Motorbike()
{
    engine = "none";
    horsePower = 0;
    yearOfProduction = 0;
    plate = "none";
    type = "none";
}

bool Motorbike::is(const string &type)
{
    if (type == vType)
    {
        return true;
    }

    return false;
}

const string &Motorbike::getEngine() const
{
    return engine;
}

void Motorbike::setEngine(const string &engine)
{
    Motorbike::engine = engine;
}

int Motorbike::getHorsePower() const
{
    return horsePower;
}

void Motorbike::setHorsePower(int horsePower)
{
    Motorbike::horsePower = horsePower;
}

int Motorbike::getYearOfProduction() const
{
    return yearOfProduction;
}

void Motorbike::setYearOfProduction(int yearOfProduction)
{
    Motorbike::yearOfProduction = yearOfProduction;
}

const string &Motorbike::getPlate() const
{
    return plate;
}

void Motorbike::setPlate(const string &plate)
{
    Motorbike::plate = plate;
}

const string &Motorbike::getType() const
{
    return type;
}

void Motorbike::setType(const string &type)
{
    Motorbike::type = type;
}

void Motorbike::saveToFile(ofstream &fd, char vt)
{
    if (!fd.is_open())
    {
        throw runtime_error("Error: Unable to open file");
        return;
    }

    Vehicle::saveToFile(fd, 'm');
    size_t hold;
    hold = engine.size();
    fd.write((char*) &hold, sizeof(hold));
    fd.write((char*) &engine[0], hold);
    fd.write((char*) &horsePower, sizeof(int));
    fd.write((char*) &yearOfProduction, sizeof(int));
    hold = plate.size();
    fd.write((char*) &hold, sizeof(hold));
    fd.write((char*) &plate[0], hold);
    hold = type.size();
    fd.write((char*) &hold, sizeof(hold));
    fd.write((char*) &type[0], hold);
}

void Motorbike::readFromFile(ifstream & fd)
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
    fd.read((char*) &hold, sizeof(hold));
    type.resize(hold);
    fd.read((char*) &type[0], hold);
}

void Motorbike::print(const Vehicle &vehicle)
{
    cout << vehicle << setw(10) << engine << setw(15) << horsePower << setw(20) << yearOfProduction << setw(20) << plate << setw(15) << type << endl;
}

const string &Motorbike::getName() const
{
    return name;
}

float Motorbike::getPrice() const
{
    return price;
}

bool Motorbike::isRent() const
{
    return rent;
}

const string &Motorbike::getDate() const
{
    return date;
}

const string &Motorbike::getWho() const
{
    return who;
}

void Motorbike::setName(const string &name)
{
    Vehicle::name = name;
}

void Motorbike::setPrice(float price)
{
    Motorbike::price = price;
}

void Motorbike::setRent(bool rent)
{
    Motorbike::rent = rent;
}

void Motorbike::setDate(const string &date)
{
    Motorbike::date = date;
}

void Motorbike::setWho(const string &who)
{
    Motorbike::who = who;
}

int Motorbike::getId() const
{
    return id;
}

void Motorbike::setWho(const Person &p)
{
    who = p.name;
}

string Motorbike::getVType() const
{
    return Motorbike::vType;
}
