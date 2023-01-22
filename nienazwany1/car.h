//
// Created by User on 15.01.2023.
//

#ifndef CAR_H
#define CAR_H
#include "vehicle.h"

/**
 *@class Car
 *@brief Represents a car. The Car class represents a car as a child class of Vehicle. It has additional properties such as engine, horsepower, year of production, and plate number. It also overrides some functions from the parent class Vehicle to include these additional properties in the functions such as saving to file, reading from file, and printing information.
 */
class Car: public Vehicle
{
    /**
     *@var vType
     *@brief Type of vehicle.
     */
    const string vType = "car";
    /**
     *@var engine
     *@brief Engine of the car.
     */
    string engine;
    /**
     *@var horsePower
     *@brief Horsepower of the car.
     */
    int horsePower;
    /**
     *@var yearOfProduction
     *@brief Year of production of the car.
     */
    int yearOfProduction;
    /**
     *@var plate
     *@brief Plate number of the car.
     */
    string plate;
    public:
        /**
         *@brief Constructor for the Car class.
         *@param id ID of the car.
         *@param name Name of the car.
         *@param price Price of the car.
         *@param rent Rent status of the car.
         *@param date Date of the rental.
         *@param who Renter of the car.
         *@param engine Engine of the car.
         *@param horsePower Horsepower of the car.
         *@param yearOfProduction Year of production of the car.
         *@param plate Plate number of the car.
         */
        Car(int id, const string name, float price, bool rent, const string &date, const string &who, string engine, int horsePower, int yearOfProduction, string plate);
    /**
     *@brief Default constructor for the Car class.
     */
    Car();

    /**
     *@brief Overridden function to check the type of vehicle.
     *@param type Type to check against.
     *@return True if the type of vehicle matches the input, false otherwise.
     */
    bool is(const string &type) override;
    /**
     *@brief Overloaded stream operator to output the car's information.
     *@param os Output stream.
     *@param vehicle Car to output information of.
     *@return Output stream.
     */
    friend ostream &operator<<(ostream &os, const Vehicle &vehicle);
    /**
     *@brief Getter for the car's engine.
     *@return Engine of the car.
     */
    const string &getEngine() const;
    /**
     *@brief Overridden function to save the car's information to a file.
     *@param fd File to save to.
     *@param vt Type of vehicle.
     */
    void saveToFile(ofstream &fd, char vt = 'c') override;
    /**
     *@brief Overridden function to read the car's information from a file.
     *@param fd File to read from.
     */
    void readFromFile(ifstream & fd) override;
    /**
     *@brief Overridden function to print the car's information.
     *@param vehicle Car to print information of.
     */
    void print(const Vehicle &vehicle) override;
    /**
     *@brief Setter for the car's engine.
     *@param engine Engine to set for the car.
     */
    void setEngine(const string &engine);
    /**
     *@brief Getter for the car's horsepower.
     *@return Horsepower of the car.
     */
    int getHorsePower() const;
    /**
     *@brief Setter for the car's horsepower.
     *@param horsePower Horsepower to set for the car.
     */
    void setHorsePower(int horsePower);
    /**
     *@brief Getter for the car's year of production.
     *@return Year of production of the car.
     */
    int getYearOfProduction() const;
    /**
     *@brief Setter for the car's year of production.
     *@param yearOfProduction Year of production to set for the car.
     */
    void setYearOfProduction(int yearOfProduction);
    /**
     *@brief Getter for the car's plate number.
     *@return Plate number of the car.
     */
    const string &getPlate() const;
    /**
     *@brief Setter for the car's plate number.
     *@param plate Plate number to set for the car.
     */
    void setPlate(const string &plate);

    /**
     *@brief Virtual function to check the type of vehicle.
     *@return True if the type of vehicle is "other", false otherwise.
     */
    bool is() override;
    /**
     *@brief Virtual function to save the vehicle's information to a file.
     *@param fd File to save to.
     *@param vt Type of vehicle.
     */

    friend ostream &operator<<(ostream &os, const Vehicle &vehicle);
    /**
     *@brief Getter for the vehicle's ID.
     *@return ID of the vehicle.
     */
    int getId() const override;
    /**
     *@brief Getter for the vehicle's price.
     *@return Price of the vehicle.
     */
    float getPrice() const override;
    /**
     *@brief Getter for the vehicle's rent status.
     *@return Rent status of the vehicle.
     */
    bool isRent() const override;
    /**
     *@brief Getter for the date of the rental.
     *@return Date of the rental.
     */
    const string &getDate() const override;
    /**
     *@brief Getter for the renter of the vehicle.
     *@return Renter of the vehicle.
     */
    const string &getWho() const override;
    /**
     *@brief Getter for the vehicle's name.
     *@return Name of the vehicle.
     */
    const string &getName() const override;
    /**
     *@brief Setter for the vehicle's name.
     *@param name Name to set for the vehicle.
     */
    void setName(const string &name) override;
    /**
     *@brief Setter for the vehicle's price.
     *@param price Price to set for the vehicle.
     */
    void setPrice(float price) override;
    /**
     *@brief Setter for the vehicle's rent status.
     *@param rent Rent status to set for the vehicle.
     */
    void setRent(bool rent) override;
    /**
     *@brief Setter for the date of the rental.
     *@param date Date to set for the rental.
     */
    void setDate(const string &date) override;
    /**
     *@brief Setter for the renter of the vehicle.
     *@param who Renter to set for the vehicle.
     */
    void setWho(const string &who) override;
    /**
     *@brief Setter for the renter of the vehicle.
     *@param p Renter to set for the vehicle.
     */
    void setWho(const Person &p) override;
    /**
     *@brief The getVType function returns the type of the vehicle
     *This function returns the type of the vehicle. It is a virtual function, which means that it can be overridden by derived classes.
     *@returns a string representing the type of the vehicle
     */
    string getVType() const override;
};


#endif	//PROJEKTCMD_CAR_H
