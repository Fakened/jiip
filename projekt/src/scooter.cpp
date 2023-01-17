//
// Created by User on 15.01.2023.
//

#include "scooter.h"
Scooter::Scooter(int id, const string& name, float price, bool rent, const string &date, const string& who, int range, int scooterID) : Vehicle(id, name, price, rent, date, who), range(range), scooterID(scooterID) {

}

Scooter::Scooter() {
    range = 0;
    scooterID = 0;
}

bool Scooter::is(const string &type) {
    if (type == vType) {
        return true;
    }
    return false;
}

int Scooter::getRange() const {
    return range;
}

void Scooter::setRange(int range) {
    Scooter::range = range;
}

int Scooter::getScooterId() const {
    return scooterID;
}

void Scooter::setScooterId(int scooterId) {
    scooterID = scooterId;
}

void Scooter::saveToFile(ofstream &fd, char vt) {
    Vehicle::saveToFile(fd, 's');
    fd.write((char *) &range, sizeof(int));
    fd.write((char *) &scooterID, sizeof(int));
}

void Scooter::readFromFile(ifstream &fd) {
    Vehicle::readFromFile(fd);
    fd.read((char *) &range, sizeof(int));
    fd.read((char *) &scooterID, sizeof(int));
}

void Scooter::print(const Vehicle &vehicle) {
    cout << vehicle << setw(105) << scooterID << setw(10) << range << endl;
}

