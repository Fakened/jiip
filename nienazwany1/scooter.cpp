//
// Created by User on 15.01.2023.
//
#include "scooter.h"

Scooter::Scooter(int id, const string &name, float price, bool rent, const string &date, const string &who, int range, int scooterID): Vehicle(id, name, price, rent, date, who), range(range), scooterID(scooterID)
{
    if (!this)
    {
        throw runtime_error("Error: Unable to create Scooter object");
    }
}

Scooter::Scooter()
{
    range = 0;
    scooterID = 0;
}

bool Scooter::is(const string &type)
{
    if (type == vType)
    {
        return true;
    }

    return false;
}

int Scooter::getRange() const
{
    return range;
}

void Scooter::setRange(int range)
{
    Scooter::range = range;
}

int Scooter::getScooterId() const
{
    return scooterID;
}

void Scooter::setScooterId(int scooterId)
{
    scooterID = scooterId;
}

int Scooter::getId() const
{
    return id;
}

void Scooter::saveToFile(ofstream &fd, char vt)
{
    if (!fd.is_open())
    {
        throw runtime_error("Error: Unable to open file");
        return;
    }

    Vehicle::saveToFile(fd, 's');
    fd.write((char*) &range, sizeof(int));
    fd.write((char*) &scooterID, sizeof(int));
}

void Scooter::readFromFile(ifstream & fd)
{
    if (!fd.is_open())
    {
        throw runtime_error("Error: Unable to open file");
        return;
    }

    Vehicle::readFromFile(fd);
    fd.read((char*) &range, sizeof(int));
    fd.read((char*) &scooterID, sizeof(int));
}

void Scooter::print(const Vehicle &vehicle)
{
    cout << vehicle << setw(105) << scooterID << setw(10) << range << endl;
}

const string &Scooter::getName() const
{
    return name;
}

float Scooter::getPrice() const
{
    return price;
}

bool Scooter::isRent() const
{
    return rent;
}

const string &Scooter::getDate() const
{
    return date;
}

const string &Scooter::getWho() const
{
    return who;
}

void Scooter::setName(const string &name)
{
    Vehicle::name = name;
}

void Scooter::setPrice(float price)
{
    Scooter::price = price;
}

void Scooter::setRent(bool rent)
{
    Scooter::rent = rent;
}

void Scooter::setDate(const string &date)
{
    Scooter::date = date;
}

void Scooter::setWho(const string &who)
{
    Scooter::who = who;
}

void Scooter::setWho(const Person &p)
{
    who = p.name;
}

string Scooter::getVType() const
{
    return Scooter::vType;
}
