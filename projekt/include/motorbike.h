//
// Created by User on 15.01.2023.
//

#ifndef PROJEKTCMD_MOTORBIKE_H
#define PROJEKTCMD_MOTORBIKE_H

#include "vehicle.h"

/**
* @class Motorbike
* @brief Represents a motorbike.
* The Motorbike class represents a motorbike as a child class of Vehicle. It has additional properties such as engine, horsepower, year of production, plate number, and type.
* It also overrides some functions from the parent class Vehicle to include these additional properties in the functions such as saving to file, reading from file, and printing information.
*/
class Motorbike : public Vehicle {
    /**
    * @var vType
    * @brief Type of vehicle.
    */
    const string vType = "Motorbike";
    /**
    * @var engine
    * @brief Engine of the motorbike.
    */
    string engine;
    /**
    * @var horsePower
    * @brief Horsepower of the motorbike.
    */
    int horsePower;
    /**
    * @var yearOfProduction
    * @brief Year of production of the motorbike.
    */
    int yearOfProduction;
    /**
    * @var plate
    * @brief Plate number of the motorbike.
    */
    string plate;
    /**
    * @var type
    * @brief Type of the motorbike.
    */
    string type;
public:
    /**
    * @brief Default constructor for the Motorbike class.
    */
    Motorbike();
    /**
    * @brief Constructor for the Motorbike class.
    * @param id ID of the motorbike.
    * @param name Name of the motorbike.
    * @param price Price of the motorbike.
    * @param rent Rent status of the motorbike.
    * @param date Date of the rental.
    * @param who Renter of the motorbike.
    * @param engine Engine of the motorbike.
    * @param horsePower Horsepower of the motorbike.
    * @param yearOfProduction Year of production of the motorbike.
    * @param plate Plate number of the motorbike.
    * @param type Type of the motorbike.
    */
    Motorbike(int id, const string name, float price, bool rent, const string &date, const string& who, string  engine, int horsePower, int yearOfProduction, string  plate, string  type);
    /**
    * @brief Overridden function to check the type of vehicle.
    * @param type Type to check against.
    * @return True if the type of vehicle matches the input, false otherwise.
    */
    bool is(const string &type) override;
    /**
    * @brief Overridden function to save the motorbike's information to a file.
    * @param fd File to save to.
    * @param vt Type of vehicle.
    */
    void saveToFile(ofstream &fd, char vt = 'm') override;
    /**
    * @brief Overridden function to read the motorbike's information from a file.
    * @param fd File to read from.
    */
    void readFromFile(ifstream &fd) override;
    /**
    * @brief Overridden function to print the motorbike's information.
    * @param vehicle Motorbike to print information of.
    */
    void print(const Vehicle &vehicle) override;
    /**
    * @brief Getter for the motorbike's engine.
    * @return Engine of the motorbike.
    */
    const string &getEngine() const;
    /**
    * @brief Setter for the motorbike's engine.
    * @param engine Engine to set for the motorbike.
    */
    void setEngine(const string &engine);

    /**
    * @brief Getter for the motorbike's horsepower.
    * @return Horsepower of the motorbike.
    */
    int getHorsePower() const;
    /**
    * @brief Setter for the motorbike's horsepower.
    * @param horsePower Horsepower to set for the motorbike.
    */
    void setHorsePower(int horsePower);
    /**
    * @brief Getter for the motorbike's year of production.
    * @return Year of production of the motorbike.
    */
    int getYearOfProduction() const;
    /**
    * @brief Setter for the motorbike's year of production.
    * @param yearOfProduction Year of production to set for the motorbike.
    */
    void setYearOfProduction(int yearOfProduction);
    /**
    * @brief Getter for the motorbike's plate number.
    * @return Plate number of the motorbike.
    */
    const string &getPlate() const;
    /**
     * @brief Setter for the motorbike's plate number.
     * @param plate Plate number to set for the motorbike.
     */
    void setPlate(const string &plate);
    /**
    * @brief Getter for the motorbike's type.
    * @return Type of the motorbike.
    */
    const string &getType() const;
    /**
    * @brief Setter for the motorbike's type.
    * @param type Type to set for the motorbike.
    */
    void setType(const string &type);
};


#endif //PROJEKTCMD_MOTORBIKE_H
