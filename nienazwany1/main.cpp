#include "mainwindow.h"
#include "vehicle.h"
#include "car.h"
#include "bike.h"
#include "scooter.h"
#include "motorbike.h"
#include "function.h"
#include <QApplication>
#include <vector>
#include <iostream>
#include <conio.h>

int id = 0;
vector<Vehicle*> vehicles;
string saveFD = "default.bin";
int main(int argc, char *argv[])
{
    /**
     *@brief variable to handler a name of file
     *
     */
    string readFD = "default.bin";
    /**
     *@brief if statement for checking filename
     *
     */

    try {
        if (argc == 2)
        {
            ifstream file;
            file.open(argv[1], ios::binary | ios::app);
            if (!file.good())
            {
                cout << "Failed to open the file, the default file will be used" << endl;
                cout << "Press any key to continue" << endl;
                _getch();
            }
            else
            {
                saveFD = argv[1];
                readFD = argv[1];
                file.close();
            }
        }

        if (argc == 3)
        {
            ifstream filer;
            filer.open(argv[1], ios::binary | ios::app);
            if (!filer.good())
            {
                cout << "Failed to open the file to read, the default file will be used" << endl;
                cout << "Press any key to continue" << endl;
                _getch();
            }
            else
            {
                readFD = argv[1];
                filer.close();
            }

            ofstream filew;
            filew.open(argv[2], ios::binary | ios::app);
            if (!filew.good())
            {
                cout << "Failed to open the file to write, the default file will be used" << endl;
                cout << "Press any key to continue" << endl;
                _getch();
            }
            else
            {
                saveFD = argv[2];
                filew.close();
            }
        }
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    if (argc > 3)
    {
        cout << "Too many arguments, the default file will be used" << endl;
        cout << "Press any key to continue" << endl;
        _getch();
    }

    readVehiclesFromFile(readFD, vehicles);
    for (const auto &vehicle: vehicles)
    {
        if (vehicle->is())
        {
            vehicle->setDay();
            vehicle->doCost();
        }
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
