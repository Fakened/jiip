#ifndef FUNCTION_H
#define FUNCTION_H
#include <fstream>
#include <vector>
#include "vehicle.h"
#include "car.h"
#include "bike.h"
#include "scooter.h"
#include "motorbike.h"
using namespace std;
extern int id;
/**
 *@brief Clear the screen.
 */
void cls();

/**
 *@brief Saves a vector of vehicles to a binary file.
 *@param fileName The name of the file to save the vehicles to.
 *@param vehicles The vector of vehicles to save to the file.
 */
template < typename T>
    void saveVehiclesToFile(const string &fileName, const vector<T> &vehicles)
    {
        ofstream fd;
        fd.open(fileName, ios::binary);
        if (fd.good())
        {
            for (const auto &vehicle: vehicles)
            {
                vehicle->saveToFile(fd);
            }
        }

        fd.close();
    }

/**
 *@brief Reads a vector of vehicles from a binary file.
 *@param fileName The name of the file to read the vehicles from.
 *@param vehicles The vector of vehicles to be read from the file.
 */
template < typename T>
    void readVehiclesFromFile(const string &fileName, vector<T> &vehicles)
    {
        char type;
        ifstream fd;
        fd.open(fileName, ios::binary | ios:: in);
        while (fd.read((char*) &type, sizeof(char)))
        {
            if (type == 'o')
            {
                Vehicle *v = new Vehicle();
                v->readFromFile(fd);
                id = v->getId();
                vehicles.push_back(v);
            }
            else if (type == 'c')
            {
                Vehicle *v = new Car();
                v->readFromFile(fd);
                id = v->getId();
                vehicles.push_back(v);
            }
            else if (type == 'b')
            {;
                Vehicle *v = new Bike();
                v->readFromFile(fd);
                id = v->getId();
                vehicles.push_back(v);
            }
            else if (type == 's')
            {
                Vehicle *v = new Scooter();
                v->readFromFile(fd);
                id = v->getId();
                vehicles.push_back(v);
            }
            else if (type == 'm')
            {
                Vehicle *v = new Motorbike();
                v->readFromFile(fd);
                id = v->getId();
                vehicles.push_back(v);
            }
        }
    }


#endif
