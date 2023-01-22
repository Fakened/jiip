//
// Created by User on 15.01.2023.
//

#ifndef BIKE_H
#define BIKE_H
#include "vehicle.h"

/**
*@class Bike
*@brief Represents a bike.
The Bike class represents a bike as a child class of Vehicle. It has additional properties such as type, size, and bike ID.
It also overrides some functions from the parent class Vehicle to include these additional properties in the functions such as saving to file,
reading from file, and printing information.
*/
class Bike: public Vehicle
{
    /**
     *@var vType
     *@brief Type of vehicle.
     */
    const string vType = "bike";
    /**
     *@var type
     *@brief Type of bike.
     */
    string type;
    /**
     *@var size
     *@brief Size of the bike.
     */
    int size;
    /**
     *@var bikeID
     *@brief Bike ID of the bike.
     */
    int bikeID;
    public:
        /**
         *@brief Default constructor for the Bike class.
         */
        Bike();
    /**
     *@brief Constructor for the Bike class.
     *@param id ID of the bike.
     *@param name Name of the bike.
     *@param price Price of the bike.
     *@param rent Rent status of the bike.
     *@param date Date of the rental.
     *@param who Renter of the bike.
     *@param type Type of the bike.
     *@param size Size of the bike.
     *@param bikeID Bike ID of the bike.
     */
    Bike(int id, const string &name, float price, bool rent, const string &date, const string &who, string type, int size, int bikeID);

    /**
     *@brief Overridden function to save the bike's information to a file.
     *@param fd File to save to.
     *@param vt Type of vehicle.
     */
    void saveToFile(ofstream &fd, char vt = 'b') override;
    /**
     *@brief Overridden function to read the bike's information from a file.
     *@param fd File to read from.
     */
    void readFromFile(ifstream & fd) override;
    /**
     *@brief Overridden function to check the type of vehicle.
     *@param type Type to check against.
     *@return True if the type of vehicle matches the input, false otherwise.
     */
    bool is(const string &type) override;
    /**
     *@brief Overridden function to print the bike's information.
     *@param vehicle Bike to print information of.
     */
    void print(const Vehicle &vehicle) override;
    /**
     *@brief Getter for the bike's type.
     *@return Type of the bike.
     */
    const string &getType() const;
    /**
     *@brief Setter for the bike's type.
     *@param type Type to set for the bike.
     */
    void setType(const string &type);
    /**
     *@brief Getter for the bike's size.
     *@return Size of the bike.
     */
    int getSize() const;
    /**
     *@brief Setter for the bike's size.
     *@param size Size to set for the bike.
     */
    void setSize(int size);
    /**
     *@brief Getter for the bike's bike ID.
     *@return Bike ID of the bike.
     */
    int getBikeId() const;
    /**
     *@brief Setter for the bike's bike ID.
     *@param bikeId Bike ID to set for the bike.
     */
    void setBikeId(int bikeId);

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


#endif	//PROJEKTCMD_BIKE_H
