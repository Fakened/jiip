#include "doors.h"

Door::Door(double price, string colour, int sizeofarr, double *xarr) {
    int i;
    this->price = price;
    this->colour = colour;
    this->sizeofarr = sizeofarr;
    arr = new double[sizeofarr];
    for(i=0;i<sizeofarr;i++){
        arr[i]=xarr[i];
    }
}

Door::Door(Door & door){
    int i;
    price = door.price;
    colour = door.colour;
    sizeofarr = door.sizeofarr;
    arr = new double[sizeofarr];
    for(i=0;i<sizeofarr;i++){
        arr[i]=door.arr[i];
    }
}

Door::~Door(){
    delete [] arr;
}

double Door::getPrice() {
    return price;
}

void Door::setPrice(double price) {
    this->price = price;
}

string Door::getColour(){
    return colour;
}

void Door::setColour(string colour){
    this->colour = colour;
}

double Door::getSizeofarr() {
    return sizeofarr;
}

void Door::setSizeofarr(int sizeofarr) {
    this->sizeofarr = sizeofarr;
}

double Door::getArr(){
    return *arr;
}

void Door::setArr(double *xarr){
    int i;
     arr = new double[sizeofarr];
    for(i=0;i<sizeofarr;i++){
        arr[i]=xarr[i];
    }
}

void Door::printArr(){
    for(int i = 0; i<sizeofarr; i++){
        cout << arr[i]<< " ";
    }
}


void Door::printData() const {
    int i;
    cout << "Door " << price << " (sizeofarr = " << sizeofarr << ") Arr: ";
    for(i =0; i<sizeofarr; i++){
        cout << arr[i]<< " ";
    }
    cout << "\n";
}

