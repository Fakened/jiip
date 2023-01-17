#include "function.h"

void cls() {
    #if defined(_WIN32) 
        system("cls");

    #else
        system("clear");
    #endif
}


Vehicle* addVehicle(const string &type)
{
    cout << flush;
    cls();
    id++;
    cout << "Enter the name: ";
    string name;
    getline(cin >> ws, name);
    cout << "Enter the price: ";
    float price;
    while (!(cin >> price)) {
            cout << "Enter a floating point number number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    if (type == "car") {
        cout << "Enter the engine of the car: ";
        string engine;
        getline(cin >> ws, engine);
        cout << "Enter the horse power of the car: ";
        int horsePower;
        while (!(cin >> horsePower)) {
            cout << "Enter a whole number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Enter the year of production of the car: ";
        int yearOfProduction;
        while (!(cin >> yearOfProduction)) {
            cout << "Enter a whole number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Enter the plate of the car: ";
        string plate;
        getline(cin >> ws, plate);
        return new Car(id, name, price, false, "-", "-", engine, horsePower, yearOfProduction, plate);
    } else if(type == "bike") {
        cout << "Enter the type of the bike: ";
        string type;
        getline(cin >> ws, type);
        cout << "Enter the size of the bike: ";
        int size;
        while (!(cin >> size)) {
            cout << "Enter a whole number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Enter ID of the bike: ";
        int ID;
        while (!(cin >> ID)) {
            cout << "Enter a whole number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return new Bike(id, name, price, false, "-", "-", type, size, ID);
    } else if(type == "scooter") {
        cout << "Enter the range of the scooter: ";
        int range;
        while (!(cin >> range)) {
            cout << "Enter a whole number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Enter the ID of the scooter: ";
        int ID;
        while (!(cin >> ID)) {
            cout << "Enter a whole number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return new Scooter(id, name, price, false, "-", "-", range, ID);
    } else if (type == "motorbike") {
        cout << "Enter the engine of the motorbike: ";
        string engine;
        getline(cin >> ws, engine);
        cout << "Enter the horse power of the motorbike: ";
        int horsePower;
        while (!(cin >> horsePower)) {
            cout << "Enter a whole number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Enter the year of production of the motorbike: ";
        int yearOfProduction;
        while (!(cin >> yearOfProduction)) {
            cout << "Enter a whole number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Enter the plate of the motorbike: ";
        string plate;
        getline(cin >> ws, plate);
        cout << "Enter the type of the motorbike: ";
        string type;
        getline(cin >> ws, type);
        return new Motorbike(id, name, price, false, "-", "-", engine, horsePower, yearOfProduction, plate, type);
    } else if (type == "other") {
        return new Vehicle(id, name, price, false, "-", "-");
    }
    return 0;
}