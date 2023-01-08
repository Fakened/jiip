#pragma once
#include <iostream>
#include "Figure.h"

using namespace std;

class Circle: public Figure{
    protected:
        double radius;
    public:
        Circle();
        Circle(double xyz[], const double radius);
        void print() override;
        double area() override;
        double perimeter() override;
        double getRadius();
        void setRadius(double radius);
};