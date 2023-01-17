/**
 * @file main.cpp
 * @author Michał Szymacha
 * @brief 
 * @version 0.1
 * @date 2022-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include "vehicle.h"
#include "car.h"
#include "bike.h"
#include "scooter.h"
#include "motorbike.h"
#include "function.h"
#include <iomanip>
#include <time.h> 
using namespace std;
/**
 * @brief id for vehicle
 * 
 */
int id = 0;
int main(int argc, char* argv[]) {
    cout << argc << endl; 
    /**
     * @brief variable to handler a name of file
     * 
     */
    string saveFD = "default.bin", readFD = "default.bin";
    /**
     * @brief if statement for checking filename
     * 
     */
    if (argc == 2) {
        ifstream file;
        file.open(argv[1], ios::binary | ios::app);
        if( !file.good() ){
            cout << "Failed to open the file, the default file will be used" << endl;
            cout << "Press any key to continue" << endl;
            getch();
        } else {
            saveFD = argv[1];
            readFD = argv[1];
            file.close();
        }
    }
    if (argc == 3) {
        ifstream filer;
        filer.open(argv[1], ios::binary | ios::app);
        if( !filer.good() ){
            cout << "Failed to open the file to read, the default file will be used" << endl;
            cout << "Press any key to continue" << endl;
            getch();
        } else {
            readFD = argv[1];
            filer.close();
        }
        ofstream filew;
        filew.open(argv[2], ios::binary | ios::app);
        if( !filew.good() ){
            cout << "Failed to open the file to write, the default file will be used" << endl;
            cout << "Press any key to continue" << endl;
            getch();
        } else {
            saveFD = argv[2];
            filew.close();
        }
    }
    if(argc > 3) {
        cout << "Too many arguments, the default file will be used" << endl;
        cout << "Press any key to continue" << endl;
        getch();
    }
    /**
     * @brief vectof for object 
     * 
     */
    vector<Vehicle *> vehicles;
    /**
     * @brief Construct a new read Vehicles From File object
     * 
     */
    readVehiclesFromFile(readFD, vehicles);
    /**
     * @brief mainloop
     * 
     */
    while (true) {
        cout << flush;
        cls();
        cout << "Welcome to the Vehicle Rental Service!" << endl;
        cout << "Please choose an option:" << endl;
        cout << "1. Add a new vehicle" << endl;
        cout << "2. Display the list of vehicles" << endl;
        cout << "3. Rent a vehicle" << endl;
        cout << "4. Return a rented vehicle" << endl;
        cout << "5. Edit" << endl;
        cout << "6. Quit" << endl;
        int option;
        while (!(cin >> option)) {
            cout << "Enter a whole number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (option) {
            /**
             * @brief adding new vehilce case
             * 
             */
            case 1: {
                cout << flush;
                cls();
                // Add a new vehicle
                cout << "Enter the type of vehicle you want to add (car, bike, scooter, motorbike, other): ";
                string type;
                cin >> type;
                if (type == "car") {
                    vehicles.push_back(addVehicle("car"));
                } else if (type == "bike") {
                    vehicles.push_back(addVehicle("bike"));
                } else if (type == "scooter") {
                    vehicles.push_back(addVehicle("scooter"));
                } else if (type == "motorbike") {
                    vehicles.push_back(addVehicle("motorbike"));
                } else if (type == "other") {
                    vehicles.push_back(addVehicle("other"));
                } else {
                    cout << "Invalid vehicle type." << endl;
                }
                break;
            }
            /**
             * @brief display vehilce case
             * 
             */
            case 2: {
                cout << flush;
                cls();
                cout << "Enter the type of vehicle you want to see (car, bike, scooter, motorbike, other, all): ";
                string type;
                cin >> type;
                cout << flush;
                cls();
                cout << "ID" << setw(20) << "NAME" << setw(10) << "PRICE" << setw(10) << "RENT" << setw(15) << "DATE" << setw(20) << "WHO" << setw(10) << "ENGINE" << setw(15) << "HORSEPOWER" << setw(20) << "YEAROFPRODUCTION" << setw(20) << "PLATE" << setw(15) << "TYPE" << setw(10) << "SIZE" << setw(15) << "INTERNALID" << setw(10) << "RANGE" << endl;
                if (type == "car" || type == "bike" || type == "scooter" || type == "motorbike" || type == "other")
                    for (const auto &vehicle: vehicles) {
                        if (vehicle->is(type)) {
                            vehicle->print(*vehicle);
                        }
                    }
                else if (type == "all") {
                    for (const auto &vehicle: vehicles) {
                        if (vehicle->is()) {
                            vehicle->print(*vehicle);
                        }
                    }
                } else {
                    cout << "Invalid vehicle type." << endl;
                }
                cout << "Press any key to back to menu" << endl;
                getch();
                break;
            }
            /**
             * @brief renting vehilce case
             * 
             */
            case 3: {
                cout << flush;
                cls();
                cout << "Available vehicles" << endl;
                for (const auto &vehicle: vehicles) {
                    if (vehicle->isRent() == false) {
                        vehicle->print(*vehicle);
                    }
                }
                // Rent a vehicle
                cout << "Enter the ID of the vehicle you want to rent: ";
                int idR;
                while (!(cin >> idR)) {
                    cout << "Enter a whole number" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                bool found = false;
                for (auto &vehicle: vehicles) {
                    if (vehicle->getId() == idR && !vehicle->isRent()) {
                        cout << "Enter your name: ";
                        string who;
                        cin >> who;
                        time_t now = time(nullptr);
                        tm * timeinfo = localtime(&now);
                        string date;
                        date += to_string(timeinfo->tm_mday)+"-"+to_string(1+timeinfo->tm_mon)+"-"+to_string(1900+timeinfo->tm_year);
                        vehicle->setRent(true);
                        vehicle->setWho(who);
                        vehicle->setDate(date);
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Vehicle not found or already rented." << endl;
                }
                break;
            }
            /**
             * @brief return vehilce case
             * 
             */
            case 4: {
                cout << flush;
                cls();
                cout << "Borrowed vehicles" << endl;
                for (const auto &vehicle: vehicles) {
                    if (vehicle->isRent()) {
                        vehicle->print(*vehicle);
                    }
                }
                // Return a rented vehicle
                cout << "Enter the ID of the vehicle you want to return: ";
                int idR;
                while (!(cin >> idR)) {
                    cout << "Enter a whole number" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                bool found = false;
                for (auto &vehicle: vehicles) {
                    if (vehicle->getId() == idR && vehicle->isRent()) {
                        vehicle->setRent(false);
                        vehicle->setWho("-");
                        vehicle->setDate("-");
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Vehicle not found or not rented." << endl;
                }
                break;
            }
            /**
             * @brief edit case
             * 
             */
            case 5: {
                bool test = true;
                while(test){
                    cout << flush;
                    cls();
                    cout << "What you want to do?" << endl;
                    cout << "1. Remove vehicle" << endl;
                    cout << "2. Edit vehicle" << endl;
                    cout << "3. Quit" << endl;
                    while (!(cin >> option)) {
                        cout << "Enter a whole number" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    switch (option) {
                        /**
                         * @brief remove vehicle case
                         * 
                         */
                        case 1: {
                            cout << flush;
                            cls();
                            cout << "Which vehicle ID do you want remove?" << endl;
                            cout << "ID" << setw(20) << "NAME" << setw(10) << "PRICE" << setw(10) << "RENT" << setw(15) << "DATE" << setw(20) << "WHO" << setw(10) << "ENGINE" << setw(15) << "HORSEPOWER" << setw(20) << "YEAROFPRODUCTION" << setw(20) << "PLATE" << setw(15) << "TYPE" << setw(10) << "SIZE" << setw(15) << "INTERNALID" << setw(10) << "RANGE" << endl;
                            for (const auto &vehicle: vehicles) {
                                if (vehicle->is()) {
                                    vehicle->print(*vehicle);
                                }
                            }
                            bool toRemove = false;
                            int idToRem, i = 0;
                            while (!(cin >> idToRem)) {
                                cout << "Enter a whole number" << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            for (const auto &vehicle: vehicles) {
                                if (vehicle->getId() == idToRem) {
                                    toRemove = true;
                                    break;
                                }
                                i++;
                            }
                            cout << flush;
                            cls();
                            if  (toRemove){
                                vehicles.erase(vehicles.begin()+i);
                                cout << "Vehicle with ID " << idToRem << " has been removed" << endl;
                                getch(); 
                            } else {
                                cout << "Vehicle with ID " << idToRem << " has not been removed because it could not be found " << endl;
                                getch();
                            }

                            break;
                        }
                        /**
                         * @brief edit vehicle case
                         * 
                         */
                        case 2: {
                            cout << flush;
                            cls();
                            cout << "Which vehicle ID do you want edit?" << endl;
                            cout << "ID" << setw(20) << "NAME" << setw(10) << "PRICE" << setw(10) << "RENT" << setw(15) << "DATE" << setw(20) << "WHO" << setw(10) << "ENGINE" << setw(15) << "HORSEPOWER" << setw(20) << "YEAROFPRODUCTION" << setw(20) << "PLATE" << setw(15) << "TYPE" << setw(10) << "SIZE" << setw(15) << "INTERNALID" << setw(10) << "RANGE" << endl;
                            for (const auto &vehicle: vehicles) {
                                if (vehicle->is()) {
                                    vehicle->print(*vehicle);
                                }
                            }
                            bool toEdit;
                            int idToEdit;
                            while (!(cin >> idToEdit)) {
                                cout << "Enter a whole number" << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                             for (const auto &vehicle: vehicles) {
                                if (vehicle->getId() == idToEdit) {
                                    toEdit = true;
                                    bool edit = true;
                                    while(edit){
                                        cout << flush;
                                        cls();
                                        cout << "ID" << setw(20) << "NAME" << setw(10) << "PRICE" << setw(10) << "RENT" << setw(15) << "DATE" << setw(20) << "WHO" << setw(10) << "ENGINE" << setw(15) << "HORSEPOWER" << setw(20) << "YEAROFPRODUCTION" << setw(20) << "PLATE" << setw(15) << "TYPE" << setw(10) << "SIZE" << setw(15) << "INTERNALID" << setw(10) << "RANGE" << endl;
                                        vehicle->print(*vehicle);
                                        cout << "What you want to do?\n\n" << endl;
                                        cout << "1.Edit name" << endl;
                                        cout << "2.Edit price" << endl;
                                        cout << "3.Edit rent" << endl;
                                        cout << "4.Edit date" << endl;
                                        cout << "5.Edit who" << endl;
                                        cout << "6.Quit" << endl;
                                        while (!(cin >> option)) {
                                            cout << "Enter a whole number" << endl;
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        }
                                        switch (option) {
                                            /**
                                             * @brief edit name case
                                             * 
                                             */
                                            case 1: {
                                                cout << flush;
                                                cls();
                                                string nameE;
                                                cout << "Enter a new name" << endl;
                                                getline(cin >> ws, nameE);
                                                vehicle->setName(nameE);
                                                break;
                                            }
                                            /**
                                             * @brief edit price case
                                             * 
                                             */
                                            case 2: {
                                                cout << flush;
                                                cls();
                                                float priceE;
                                                cout << "Enter a new price" << endl;
                                                while (!(cin >> priceE)) {
                                                    cout << "Enter a floating point number number" << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                }
                                                vehicle->setPrice(priceE);
                                                cout << "Press any key to continue" << endl;
                                                getch();
                                                break;
                                            }
                                            /**
                                             * @brief edit rent case
                                             * 
                                             */
                                            case 3: {
                                                cout << flush;
                                                cls();
                                                if(vehicle->isRent()) {
                                                    cout << "The vehicle is no longer rented" << endl;
                                                    cout << "Press any key to continue" << endl;
                                                    vehicle->setRent(false);
                                                    vehicle->setWho("-");
                                                    vehicle->setDate("-");
                                                    getch();
                                                } else {
                                                    cout << "Who rent vehicle?" << endl;
                                                    string nameE;
                                                    getline(cin >> ws, nameE);
                                                    vehicle->setName(nameE);
                                                    cout << "When vehicle was rented?" << endl;
                                                    int year, month, day;
                                                    cout << "year: ";
                                                    while (!(cin >> year)) {
                                                        cout << "Enter a whole number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                    }
                                                    cout << endl;
                                                    cout << "month: ";
                                                    while (!(cin >> month)) {
                                                        cout << "Enter a whole number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                    }
                                                    cout << endl;
                                                    cout << "day: ";
                                                    while (!(cin >> day)) {
                                                        cout << "Enter a whole number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                    }
                                                    cout << endl;
                                                    string dateE = to_string(day)+"-"+to_string(month)+"-"+to_string(year);
                                                    vehicle->setDate(dateE);
                                                    cout << "The vehicle is rented" << endl;
                                                    vehicle->setRent(true);
                                                    cout << "Press any key to continue" << endl;
                                                    getch();
                                                }
                                                break;
                                            }
                                            /**
                                             * @brief edit date case
                                             * 
                                             */
                                            case 4: {
                                                cout << flush;
                                                cls();
                                                cout << "When vehicle was rented?" << endl;
                                                int year, month, day;
                                                cout << "year: ";
                                                while (!(cin >> year)) {
                                                    cout << "Enter a whole number" << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                }
                                                cout << endl;
                                                cout << "month: ";
                                                while (!(cin >> month)) {
                                                    cout << "Enter a whole number" << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                }
                                                cout << endl;
                                                cout << "day: ";
                                                while (!(cin >> day)) {
                                                    cout << "Enter a whole number" << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                }
                                                cout << endl;
                                                string dateE = to_string(day)+"-"+to_string(month)+"-"+to_string(year);
                                                vehicle->setDate(dateE);
                                                cout << "Press any key to continue" << endl;
                                                getch();
                                                break;
                                            }
                                            /**
                                             * @brief edit who case
                                             * 
                                             */
                                            case 5: {
                                                cout << flush;
                                                cls();
                                                cout << "Who rent vehicle?" << endl;
                                                string nameE;
                                                getline(cin >> ws, nameE);
                                                vehicle->setName(nameE);
                                                cout << "Press any key to continue" << endl;
                                                getch();
                                                break;
                                            }
                                            /**
                                             * @brief quit case
                                             * 
                                             */
                                            case 6: {
                                                edit = false;
                                                break;
                                            }
                                            /**
                                             * @brief invalid option case
                                             * 
                                             */
                                            default:
                                                cout << flush;
                                                cls();
                                                cout << "Invalid option." << endl;
                                                getch();
                                                break;
                                        }
                                    }
                                }
                            }
                            break;
                        }
                        /**
                         * @brief quit case
                         * 
                         */
                        case 3: {
                            test = false;
                            break;
                        }
                        /**
                         * @brief invalid option case
                         * 
                         */
                        default: {
                            cout << flush;
                            cls();
                            cout << "Invalid option." << endl;
                            getch();
                            break;
                        }
                    }
                }
                break;
            } 
            /**
             * @brief quit case
             * 
             */
            case 6: {
                cout << flush;
                cls();
                saveVehiclesToFile(saveFD, vehicles);
                exit(0);
                break;
            }
            /**
             * @brief invalid option case
             * 
             */
            default: {
                cout << flush;
                cls();
                cout << "Invalid option.";
                getch();
                break;
            }
        }

    }
}

