//
// Created by User on 15.01.2023.
//

#ifndef SCOOTER_H
#define SCOOTER_H
#include "vehicle.h"

/**
 *@class Scooter
 *@brief Represents a scooter.
 *The Scooter class represents a scooter as a child class of Vehicle. It has additional properties such as range, and scooter ID.
 *It also overrides some functions from the parent class Vehicle to include these additional properties in the functions such as saving to file, reading from file, and printing information.
 */
class Scooter: public Vehicle
{
    /**
     *@var vType
     *@brief Type of vehicle.
     */
    const string vType = "scooter";
    /**
     *@var range
     *@brief range of the scooter.
     */
    int range;
    /**
     *@var scooterID
     *@brief ID of the scooter.
     */
    int scooterID;
    public:
        /**
         *@brief Default constructor for the Scooter class.
         */
        Scooter();
    /**
     *@brief Constructor for the Scooter class.
     *@param id ID of the scooter.
     *@param name Name of the scooter.
     *@param price Price of the scooter.
     *@param rent Rent status of the scooter.
     *@param date Date of the rental.
     *@param who Renter of the scooter.
     *@param range range of the scooter.
     *@param scooterID ID of the scooter.
     */
    Scooter(int id, const string &name, float price, bool rent, const string &date, const string &who, int range, int scooterID);
    /**
     *@brief Overridden function to check the type of vehicle.
     *@param type Type to check against.
     *@return True if the type of vehicle matches the input, false otherwise.
     */
    bool is(const string &type) override;
    /**
     *@brief Overridden function to save the scooter's information to a file.
     *@param fd File to save to.
     *@param vt Type of vehicle.
     */
    void saveToFile(ofstream &fd, char vt = 's') override;
    /**
     *@brief Overridden function to read the scooter's information from a file.
     *@param fd File to read from.
     */
    void readFromFile(ifstream & fd) override;
    /**
     *@brief Overridden function to print the scooter's information.
     *@param vehicle Scooter to print information of.
     */
    void print(const Vehicle &vehicle) override;
    /**
     *@brief Getter for the scooter's range.
     *@return range of the scooter.
     */
    int getRange() const;
    /**
     *@brief Setter for the scooter's range.
     *@param range range to set for the scooter.
     */
    void setRange(int range);
    /**
     *@brief Getter for the scooter's ID.
     *@return ID of the scooter.
     */
    int getScooterId() const;
    /**
     *@brief Setter for the scooter's ID.
     *@param scooterId ID to set for the scooter.
     */
    void setScooterId(int scooterId);

    /**
     *@brief Getter for the vehicle's ID.
     *@return ID of the vehicle.
     */
    virtual int getId() const override;
    /**
     *@brief Getter for the vehicle's price.
     *@return Price of the vehicle.
     */
    virtual float getPrice() const override;
    /**
     *@brief Getter for the vehicle's rent status.
     *@return Rent status of the vehicle.
     */
    virtual bool isRent() const override;
    /**
     *@brief Getter for the date of the rental.
     *@return Date of the rental.
     */
    virtual
    const string &getDate() const override;
    /**
     *@brief Getter for the renter of the vehicle.
     *@return Renter of the vehicle.
     */
    virtual
    const string &getWho() const override;
    /**
     *@brief Getter for the vehicle's name.
     *@return Name of the vehicle.
     */
    virtual
    const string &getName() const override;
    /**
     *@brief Setter for the vehicle's name.
     *@param name Name to set for the vehicle.
     */
    virtual void setName(const string &name) override;
    /**
     *@brief Setter for the vehicle's price.
     *@param price Price to set for the vehicle.
     */
    virtual void setPrice(float price) override;
    /**
     *@brief Setter for the vehicle's rent status.
     *@param rent Rent status to set for the vehicle.
     */
    virtual void setRent(bool rent) override;
    /**
     *@brief Setter for the date of the rental.
     *@param date Date to set for the rental.
     */
    virtual void setDate(const string &date) override;
    /**
     *@brief Setter for the renter of the vehicle.
     *@param who Renter to set for the vehicle.
     */
    virtual void setWho(const string &who) override;
    /**
     *@brief Setter for the renter of the vehicle.
     *@param p Renter to set for the vehicle.
     */
    virtual void setWho(const Person &p) override;
    /**
     *@brief The getVType function returns the type of the vehicle
     *This function returns the type of the vehicle. It is a virtual function, which means that it can be overridden by derived classes.
     *@returns a string representing the type of the vehicle
     */
    virtual string getVType() const override;
};


#endif	//PROJEKTCMD_SCOOTER_H
