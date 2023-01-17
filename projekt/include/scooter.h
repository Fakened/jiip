//
// Created by User on 15.01.2023.
//

#ifndef PROJEKTCMD_SCOOTER_H
#define PROJEKTCMD_SCOOTER_H

#include "vehicle.h"

class Scooter : public Vehicle {
    const string vType = "Scooter";
    int range;
    int scooterID;
public:
    Scooter();
    Scooter(int id, const string& name, float price, bool rent, const string &date, const string& who, int range, int scooterID);

    bool is(const string &type) override;

    void saveToFile(ofstream &fd, char vt = 's') override;

    void readFromFile(ifstream &fd) override;

    void print(const Vehicle &vehicle) override;

    int getRange() const;

    void setRange(int range);

    int getScooterId() const;

    void setScooterId(int scooterId);
};


#endif //PROJEKTCMD_SCOOTER_H
