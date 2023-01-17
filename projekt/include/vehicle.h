//
// Created by User on 29.12.2022.
//

#ifndef PROJEKTCMD_VEHICLE_H
#define PROJEKTCMD_VEHICLE_H


#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "person.h"
using namespace std;



class Vehicle {
protected:
    const string vType = "other";
    int id;
    string name;
    float price;
    bool rent;
    string date;
    string who;
public:
    Vehicle();

    Vehicle(int id, string name, float price, bool rent, string date, string who);

    ~Vehicle();

    virtual bool is(const string &type);

    virtual bool is();

    virtual void saveToFile(ofstream &fd, char vt = 'o');

    virtual void readFromFile(ifstream &fd);

    virtual void print(const Vehicle &vehicle);

    friend ostream &operator<<(ostream &os, const Vehicle &vehicle);

    int getId() const;

    float getPrice() const;

    bool isRent() const;

    const string &getDate() const;

    const string &getWho() const;

    const string &getName() const;

    void setName(const string &name);

    void setPrice(float price);

    void setRent(bool rent);

    void setDate(const string &date);

    void setWho(const string &who);

    void setWho(const Person &p);

};




#endif //PROJEKTCMD_VEHICLE_H
