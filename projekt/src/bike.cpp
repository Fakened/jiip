//
// Created by User on 15.01.2023.
//

#include "bike.h"
Bike::Bike(int id, const string& name, float price, bool rent, const string &date, const string& who, string  type, int size, int bikeID) : Vehicle(id, name, price, rent, date, who), type(std::move(type)), size(size), bikeID(bikeID) {

}

Bike::Bike() {
    type = "none";
    size = 0;
    bikeID = 0;
}


bool Bike::is(const string &type) {
    if (type == vType) {
        return true;
    }
    return false;
}

const string &Bike::getType() const {
    return type;
}

void Bike::setType(const string &type) {
    Bike::type = type;
}

int Bike::getSize() const {
    return size;
}

void Bike::setSize(int size) {
    Bike::size = size;
}

int Bike::getBikeId() const {
    return bikeID;
}

void Bike::setBikeId(int bikeId) {
    bikeID = bikeId;
}

void Bike::saveToFile(ofstream &fd, char vt) {
    Vehicle::saveToFile(fd, 'b');
    size_t hold;
    hold = type.size();
    fd.write((char *) &hold, sizeof(hold));
    fd.write((char *) &type[0], hold);
    fd.write((char *) &size, sizeof(int));
    fd.write((char *) &bikeID, sizeof(int));

}

void Bike::readFromFile(ifstream &fd) {
    Vehicle::readFromFile(fd);
    size_t hold;
    fd.read((char *) &hold, sizeof(hold));
    type.resize(hold);
    fd.read((char *) &type[0], hold);
    fd.read((char *) &size, sizeof(int));
    fd.read((char *) &bikeID, sizeof(int));
}

void Bike::print(const Vehicle &vehicle) {
    cout << vehicle << setw(80) << type << setw(10) << size << setw(15) << bikeID << endl;
}
