//
// Created by User on 15.01.2023.
//

#ifndef PROJEKTCMD_BIKE_H
#define PROJEKTCMD_BIKE_H

#include "vehicle.h"

class Bike : public Vehicle {
    const string vType = "bike";
    string type;
    int size;
    int bikeID;
public:
    Bike();
    Bike(int id, const string& name, float price, bool rent, const string &date, const string& who, string  type, int size, int bikeID);


    void saveToFile(ofstream &fd, char vt = 'b') override;

    void readFromFile(ifstream &fd) override;

    bool is(const string &type) override;

    void print(const Vehicle &vehicle) override;

    const string &getType() const;

    void setType(const string &type);

    int getSize() const;

    void setSize(int size);

    int getBikeId() const;

    void setBikeId(int bikeId);
};


#endif //PROJEKTCMD_BIKE_H
