#pragma once
#include <iostream>
#include "Figure.h"

using namespace std;

class Square: public Figure{
    protected:
        double a;
    public:
        Square();
        Square(double xyz[], const double a);
        void print() override;
        double area() override;
        double perimeter() override;
        double getA();
        void setA(double a);
};