/**

@file vehicle.h
@brief This file contains the declaration of the Vehicle class and its members.
The Vehicle class is the base class for all types of vehicles. It contains
information such as the vehicle's id, name, price, whether it is currently
rented, and who it is currently rented to. It also has methods for saving
and reading the vehicle to/from a binary file.
*/
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


/**

* @class Vehicle
* @brief The base class for all types of vehicles. 
The Vehicle class contains information such as the vehicle's id, name, price, whether it is currently rented, and who it is currently rented to. 
It also has methods for saving and reading the vehicle to/from a binary file.
*/
class Vehicle {
protected:
    /*
    @var vType
    @brief Type of vehicle.
    */
    const string vType = "other";
    /**
    @var id
    @brief ID of the vehicle.
    */
    int id;
    /**
    @var name
    @brief Name of the vehicle.
    */
    string name;
    /**
    @var price
    @brief Price of the vehicle.
    */
    float price;
    /**
    @var rent
    @brief Rent status of the vehicle.
    */
    bool rent;
    /**
    @var date
    @brief Date of the rental.
    */
    string date;
    /**
    @var who
    @brief Renter of the vehicle.
    */
    string who;
public:
    /**
    * @brief Default constructor for the Vehicle class.
    */
    Vehicle();
        /**
     * @brief Constructor for the Vehicle class.
     * @param id ID of the vehicle.
     * @param name Name of the vehicle.
     * @param price Price of the vehicle.
     * @param rent Rent status of the vehicle.
     * @param date Date of the rental.
     * @param who Renter of the vehicle.
     */
    Vehicle(int id, string name, float price, bool rent, string date, string who);
    /**
     * @brief Destructor for the Vehicle class.
     */
    ~Vehicle();
    /**
     * @brief Virtual function to check the type of vehicle.
     * @param type Type to check against.
     * @return True if the type of vehicle matches the input, false otherwise.
     */
    virtual bool is(const string &type);
    /**
     * @brief Virtual function to check the type of vehicle.
     * @return True if the type of vehicle is "other", false otherwise.
     */
    virtual bool is();
    /**
     * @brief Virtual function to save the vehicle's information to a file.
     * @param fd File to save to.
     * @param vt Type of vehicle.
     */
    virtual void saveToFile(ofstream &fd, char vt = 'o');
    /**
     * @brief Virtual function to read the vehicle's information from a file.
     * @param fd File to read from.
     */
    virtual void readFromFile(ifstream &fd);
    /**
     * @brief Virtual function to print the vehicle's information.
     * @param vehicle Vehicle to print information of.
     */
    virtual void print(const Vehicle &vehicle);
    /**
     * @brief Overloaded stream operator to output the vehicle's information.
     * @param os Output stream.
     * @param vehicle Vehicle to output information of.
    * @return Output stream.
    */
    friend ostream &operator<<(ostream &os, const Vehicle &vehicle);
    /**
     * @brief Getter for the vehicle's ID.
     * @return ID of the vehicle.
     */
    int getId() const;
    /**
     * @brief Getter for the vehicle's price.
     * @return Price of the vehicle.
     */
    float getPrice() const;
    /**
     * @brief Getter for the vehicle's rent status.
     * @return Rent status of the vehicle.
     */
    bool isRent() const;
    /**
     * @brief Getter for the date of the rental.
     * @return Date of the rental.
     */
    const string &getDate() const;
    /**
     * @brief Getter for the renter of the vehicle.
     * @return Renter of the vehicle.
     */
    const string &getWho() const;
    /**
     * @brief Getter for the vehicle's name.
     * @return Name of the vehicle.
     */
    const string &getName() const;
    /**
     * @brief Setter for the vehicle's name.
     * @param name Name to set for the vehicle.
     */
    void setName(const string &name);
    /**
     * @brief Setter for the vehicle's price.
     * @param price Price to set for the vehicle.
     */
    void setPrice(float price);
    /**
     * @brief Setter for the vehicle's rent status.
     * @param rent Rent status to set for the vehicle.
     */
    void setRent(bool rent);
    /**
     * @brief Setter for the date of the rental.
     * @param date Date to set for the rental.
     */
    void setDate(const string &date);
    /**
     * @brief Setter for the renter of the vehicle.
     * @param who Renter to set for the vehicle.
     */
    void setWho(const string &who);
    /**
     * @brief Setter for the renter of the vehicle.
     * @param p Renter to set for the vehicle.
     */
    void setWho(const Person &p);

};




#endif //PROJEKTCMD_VEHICLE_H
