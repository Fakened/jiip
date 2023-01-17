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
int id = 0;
int main() {
    vector<Vehicle *> vehicles;
    readVehiclesFromFile("test.bin", vehicles);
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
        cin >> option;

        switch (option) {
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
                int id;
                cin >> id;

                bool found = false;
                for (auto &vehicle: vehicles) {
                    if (vehicle->getId() == id && !vehicle->isRent()) {
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
                int id;
                cin >> id;

                bool found = false;
                for (auto &vehicle: vehicles) {
                    if (vehicle->getId() == id && vehicle->isRent()) {
                        vehicle->setRent(false);
                        vehicle->setWho("");
                        vehicle->setDate("");
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Vehicle not found or not rented." << endl;
                }
                break;
            }
            case 5: {
                bool test = true;
                while(test){
                    cout << flush;
                    cls();
                    cout << "What you want to do?" << endl;
                    cout << "1. Remove vehicle" << endl;
                    cout << "2. Edit vehicle" << endl;
                    cout << "3. Quit" << endl;
                    cin >> option;
                    switch (option) {
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
                            cin >> idToRem;
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
                        case 2: {
                            cout << flush;
                            cls();
                            break;
                        }
                        case 3: {
                            test = false;
                            break;
                        }
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
            case 6: {
                cout << flush;
                cls();
                saveVehiclesToFile("test.bin", vehicles);
                exit(0);
                break;
            }

                //        } else if (option == 8) {
                //            for (auto &vehicle: vehicles) {
                //                const Person p = Person("asd", 12);
                //                vehicle->setWho(p);
                //                }
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

