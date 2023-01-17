//
// Created by User on 15.01.2023.
//

#include "car.h"
Car::Car(int id, const string name, float price, bool rent,const string &date , const string &who,
         string engine, int horsePower, int yearOfProduction, string plate):Vehicle(id,name, price, rent, date, who), engine(std::move(engine)), horsePower(horsePower), yearOfProduction(yearOfProduction), plate(std::move(plate)) {

}

Car::Car() {
    engine = "none";
    horsePower = 0;
    yearOfProduction = 0;
    plate = "none";
}

const string &Car::getEngine() const {
    return engine;
}

void Car::setEngine(const string &engine) {
    Car::engine = engine;
}

int Car::getHorsePower() const {
    return horsePower;
}

void Car::setHorsePower(int horsePower) {
    Car::horsePower = horsePower;
}

int Car::getYearOfProduction() const {
    return yearOfProduction;
}

void Car::setYearOfProduction(int yearOfProduction) {
    Car::yearOfProduction = yearOfProduction;
}

const string &Car::getPlate() const {
    return plate;
}

void Car::setPlate(const string &plate) {
    Car::plate = plate;
}

bool Car::is(const string &type) {
    if (type == vType) {
        return true;
    }
    return false;
}

void Car::saveToFile(ofstream &fd, char vt) {
    Vehicle::saveToFile(fd, 'c');
    size_t hold;
    hold = engine.size();
    fd.write((char *) &hold, sizeof(hold));
    fd.write((char *) &engine[0], hold);
    fd.write((char *) &horsePower, sizeof(int));
    fd.write((char *) &yearOfProduction, sizeof(int));
    hold = plate.size();
    fd.write((char *) &hold, sizeof(hold));
    fd.write((char *) &plate[0], hold);
}

void Car::readFromFile(ifstream &fd) {
    Vehicle::readFromFile(fd);
    size_t hold;
    fd.read((char *) &hold, sizeof(hold));
    engine.resize(hold);
    fd.read((char *) &engine[0], hold);
    fd.read((char *) &horsePower, sizeof(int));
    fd.read((char *) &yearOfProduction, sizeof(int));
    fd.read((char *) &hold, sizeof(hold));
    engine.resize(hold);
    fd.read((char *) &plate[0], hold);

}


void Car::print(const Vehicle &vehicle) {
        cout << vehicle << setw(10) << engine << setw(15) << horsePower << setw(20) << yearOfProduction << setw(20) << plate << endl;
}

