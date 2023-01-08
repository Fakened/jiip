#pragma once
#include <iostream>
#include "Figure.h"

using namespace std;

class Trapeze: public Figure{
    protected:
        double a;
        double b;
        double c;
        double d;
        double h;
    public:
        Trapeze();
        Trapeze(double xyz[], const double a, const double b,const double c, const double d, const double h);
        void print() override;
        double area() override;
        double perimeter() override;
        double getA();
        double getB();
        double getC();
        double getD();
        double getH();
        void setA(double a);
        void setB(double b);
        void setC(double c);
        void setD(double d);
        void setH(double h);
};