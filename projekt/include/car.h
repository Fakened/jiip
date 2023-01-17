//
// Created by User on 15.01.2023.
//

#ifndef PROJEKTCMD_CAR_H
#define PROJEKTCMD_CAR_H

#include "vehicle.h"

/**
* @class Car
* @brief Represents a car. The Car class represents a car as a child class of Vehicle. It has additional properties such as engine, horsepower, year of production, and plate number. It also overrides some functions from the parent class Vehicle to include these additional properties in the functions such as saving to file, reading from file, and printing information.
*/
class Car : public Vehicle {
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
    * @brief Constructor for the Car class.
    * @param id ID of the car.
    * @param name Name of the car.
    * @param price Price of the car.
    * @param rent Rent status of the car.
    * @param date Date of the rental.
    * @param who Renter of the car.
    * @param engine Engine of the car.
    * @param horsePower Horsepower of the car.
    * @param yearOfProduction Year of production of the car.
    * @param plate Plate number of the car.
    */
    Car(int id, const string name, float price, bool rent,const string &date, const string& who, string  engine, int horsePower, int yearOfProduction, string  plate);
    /**
    * @brief Default constructor for the Car class.
    */
    Car();

    /**
    * @brief Overridden function to check the type of vehicle.
    * @param type Type to check against.
    * @return True if the type of vehicle matches the input, false otherwise.
    */
    bool is(const string &type) override;
    /**
    * @brief Overloaded stream operator to output the car's information.
    * @param os Output stream.
    * @param vehicle Car to output information of.
    * @return Output stream.
    */
    friend ostream &operator<<(ostream &os, const Vehicle &vehicle);
    /**
    * @brief Getter for the car's engine.
    * @return Engine of the car.
    */
    const string &getEngine() const;
    /**
    * @brief Overridden function to save the car's information to a file.
    * @param fd File to save to.
    * @param vt Type of vehicle.
    */
    void saveToFile(ofstream &fd, char vt = 'c') override;
    /**
    * @brief Overridden function to read the car's information from a file.
    * @param fd File to read from.
    */
    void readFromFile(ifstream &fd) override;
    /**
    * @brief Overridden function to print the car's information.
    * @param vehicle Car to print information of.
    */
    void print(const Vehicle &vehicle) override;
    /**
    * @brief Setter for the car's engine.
    * @param engine Engine to set for the car.
    */
    void setEngine(const string &engine);
    /**
    * @brief Getter for the car's horsepower.
    * @return Horsepower of the car.
    */
    int getHorsePower() const;
    /**
    * @brief Setter for the car's horsepower.
    * @param horsePower Horsepower to set for the car.
    */
    void setHorsePower(int horsePower);
    /**
    * @brief Getter for the car's year of production.
    * @return Year of production of the car.
    */
    int getYearOfProduction() const;
    /**
    * @brief Setter for the car's year of production.
    * @param yearOfProduction Year of production to set for the car.
    */
    void setYearOfProduction(int yearOfProduction);
    /**
    * @brief Getter for the car's plate number.
    * @return Plate number of the car.
    */
    const string &getPlate() const;
    /**
    * @brief Setter for the car's plate number.
    * @param plate Plate number to set for the car.
    */
    void setPlate(const string &plate);
};


#endif //PROJEKTCMD_CAR_H
