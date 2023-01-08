#ifndef CHECKER_DOOR_H
#define CHECKER_DOOR_H

#include <iostream>

using namespace std;

class Door {
private:
    double price;
    string colour;
    int sizeofarr;
    double *arr;

public:
    Door(double price, string colour, int sizeofarr, double *arr);

    Door() = default; 

    ~Door();



    double getPrice();
    void setPrice(double price);

    string getColour();
    void setColour(string colour);

    double getSizeofarr();
    void setSizeofarr(int sizeofarr);


    double getArr();
    void setArr(double *arr);
    void printArr();

    Door(Door & door);

    void printData() const;


};


#endif //CHECKER_Door_H