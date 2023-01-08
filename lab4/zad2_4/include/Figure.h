#pragma once
#include <iostream>


using namespace std;

class Figure{
    protected:
        double *xyz;
    public:
        Figure();
        Figure(double xyz[]);
        ~Figure();
        virtual void print();
        virtual double area() = 0;
        virtual double perimeter() = 0;
        void setXyz(double *xyz);
};