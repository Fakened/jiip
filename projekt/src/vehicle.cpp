//
// Created by User on 29.12.1022.
//

#include "vehicle.h"

#include <utility>

Vehicle::Vehicle(int id, string name, float price, bool rent, string date, string who)
        :id(id), name(std::move(name)), price(price), rent(rent),date(std::move(date)), who(std::move(who))  {

}

Vehicle::Vehicle() {
    name = "default";
    id = -1;
    price = 0;
    date = "1990-01-01";
    who = "nobody";
}

Vehicle::~Vehicle()= default;


const string &Vehicle::getName() const {
    return name;
}

float Vehicle::getPrice() const {
    return price;
}

bool Vehicle::isRent() const {
    return rent;
}

const string &Vehicle::getDate() const {
    return date;
}

const string &Vehicle::getWho() const {
    return who;
}

void Vehicle::setName(const string &name) {
    Vehicle::name = name;
}

void Vehicle::setPrice(float price) {
    Vehicle::price = price;
}

void Vehicle::setRent(bool rent) {
    Vehicle::rent = rent;
}

void Vehicle::setDate(const string &date) {
    Vehicle::date = date;
}

void Vehicle::setWho(const string &who) {
    Vehicle::who = who;
}

bool Vehicle::is(const string &type) {
    if (type == vType) {
        return true;
    }
    return false;
}

void Vehicle::saveToFile(ofstream &fd, char vt) {
    if (fd.good()) {
        size_t hold;
        fd.write((char *) &vt, sizeof(const char));
        fd.write((char *) &id, sizeof(int));
        hold = name.size();
        fd.write((char *) &hold, sizeof(hold));
        fd.write((char *) &name[0], hold);
        fd.write((char *) &price, sizeof(price));
        fd.write((char *) &rent, sizeof(rent));
        hold = date.size();
        fd.write((char *) &hold, sizeof(hold));
        fd.write((char *) &date[0], hold);
        hold = who.size();
        fd.write((char *) &hold, sizeof(hold));
        fd.write((char *) &who[0], hold);
    }
}

void Vehicle::readFromFile(ifstream &fd) {
    if (fd.good()) {
        size_t hold;
        fd.read((char *) &id, sizeof(int));
        fd.read((char *) &hold, sizeof(hold));
        name.resize(hold);
        fd.read((char *) &name[0], hold);
        fd.read((char *) &price, sizeof(price));
        fd.read((char *) &rent, sizeof(rent));
        fd.read((char *) &hold, sizeof(hold));
        date.resize(hold);
        fd.read((char *) &date[0], hold);
        fd.read((char *) &hold, sizeof(hold));
        who.resize(hold);
        fd.read((char *) &who[0], hold);
    }
}


int Vehicle::getId() const {
    return id;
}

void Vehicle::setWho(const Person &p) {
    who = p.name;
}

ostream &operator<<(ostream &os, const Vehicle &vehicle) {

    os << vehicle.id << setw(20) << vehicle.name  << setw(10) << vehicle.price << setw(10) << (vehicle.rent ? "true" : "false") << setw(15) << vehicle.date << setw(20) << vehicle.who;
    return os;
}

void Vehicle::print(const Vehicle &vehicle) {
    cout << vehicle << endl;
}

bool Vehicle::is() {
    return true;
}


