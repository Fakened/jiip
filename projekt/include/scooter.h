//
// Created by User on 15.01.2023.
//

#ifndef PROJEKTCMD_SCOOTER_H
#define PROJEKTCMD_SCOOTER_H

#include "vehicle.h"
/**
*@class Scooter
*@brief Represents a scooter.
* The Scooter class represents a scooter as a child class of Vehicle. It has additional properties such as range, and scooter ID.
* It also overrides some functions from the parent class Vehicle to include these additional properties in the functions such as saving to file, reading from file, and printing information.
*/
class Scooter : public Vehicle {
    /**
    * @var vType
    * @brief Type of vehicle.
    */
    const string vType = "Scooter";
    /**
    * @var range
    * @brief range of the scooter.
    */
    int range;
    /**
    * @var scooterID
    * @brief ID of the scooter.
    */
    int scooterID;
public:
    /**
    * @brief Default constructor for the Scooter class.
    */
    Scooter();
    /**
    * @brief Constructor for the Scooter class.
    * @param id ID of the scooter.
    * @param name Name of the scooter.
    * @param price Price of the scooter.
    * @param rent Rent status of the scooter.
    * @param date Date of the rental.
    * @param who Renter of the scooter.
    * @param range range of the scooter.
    * @param scooterID ID of the scooter.
    */
    Scooter(int id, const string& name, float price, bool rent, const string &date, const string& who, int range, int scooterID);
    /**
    * @brief Overridden function to check the type of vehicle.
    * @param type Type to check against.
    * @return True if the type of vehicle matches the input, false otherwise.
    */
    bool is(const string &type) override;
    /**
    * @brief Overridden function to save the scooter's information to a file.
    * @param fd File to save to.
    * @param vt Type of vehicle.
    */
    void saveToFile(ofstream &fd, char vt = 's') override;
    /**
    * @brief Overridden function to read the scooter's information from a file.
    * @param fd File to read from.
    */
    void readFromFile(ifstream &fd) override;
    /**
    * @brief Overridden function to print the scooter's information.
    * @param vehicle Scooter to print information of.
    */
    void print(const Vehicle &vehicle) override;
    /**
    * @brief Getter for the scooter's range.
    * @return range of the scooter.
    */
    int getRange() const;
    /**
    * @brief Setter for the scooter's range.
    * @param range range to set for the scooter.
    */
    void setRange(int range);
    /**
    * @brief Getter for the scooter's ID.
    * @return ID of the scooter.
    */
    int getScooterId() const;
    /**
    * @brief Setter for the scooter's ID.
    * @param scooterId ID to set for the scooter.
    */
    void setScooterId(int scooterId);
};


#endif //PROJEKTCMD_SCOOTER_H
