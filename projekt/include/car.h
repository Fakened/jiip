//
// Created by User on 15.01.2023.
//

#ifndef PROJEKTCMD_CAR_H
#define PROJEKTCMD_CAR_H

#include "vehicle.h"
class Car : public Vehicle {
    const string vType = "car";
    string engine;
    int horsePower;
    int yearOfProduction;
    string plate;
public:
    Car(int id, const string name, float price, bool rent,const string &date, const string& who, string  engine, int horsePower, int yearOfProduction, string  plate);
    Car();


    bool is(const string &type) override;

    friend ostream &operator<<(ostream &os, const Vehicle &vehicle);

    const string &getEngine() const;

    void saveToFile(ofstream &fd, char vt = 'c') override;

    void readFromFile(ifstream &fd) override;

    void print(const Vehicle &vehicle) override;

    void setEngine(const string &engine);

    int getHorsePower() const;

    void setHorsePower(int horsePower);

    int getYearOfProduction() const;

    void setYearOfProduction(int yearOfProduction);

    const string &getPlate() const;

    void setPlate(const string &plate);
};


#endif //PROJEKTCMD_CAR_H
