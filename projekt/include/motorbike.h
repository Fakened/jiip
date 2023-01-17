//
// Created by User on 15.01.2023.
//

#ifndef PROJEKTCMD_MOTORBIKE_H
#define PROJEKTCMD_MOTORBIKE_H

#include "vehicle.h"


class Motorbike : public Vehicle {
    const string vType = "Motorbike";
    string engine;
    int horsePower;
    int yearOfProduction;
    string plate;
    string type;
public:
    Motorbike();
    Motorbike(int id, const string name, float price, bool rent, const string &date, const string& who, string  engine, int horsePower, int yearOfProduction, string  plate, string  type);

    bool is(const string &type) override;

    void saveToFile(ofstream &fd, char vt = 'm') override;

    void readFromFile(ifstream &fd) override;

    void print(const Vehicle &vehicle) override;

    const string &getEngine() const;

    void setEngine(const string &engine);

    int getHorsePower() const;

    void setHorsePower(int horsePower);

    int getYearOfProduction() const;

    void setYearOfProduction(int yearOfProduction);

    const string &getPlate() const;

    void setPlate(const string &plate);

    const string &getType() const;

    void setType(const string &type);
};


#endif //PROJEKTCMD_MOTORBIKE_H
