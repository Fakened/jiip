#include "Circle.h"

Circle::Circle(double xyz[], const double radius) : Figure(xyz), radius(radius){}

void Circle::print(){
    cout << "x:" << xyz[0] << " y:" << xyz[1] << " z:" << xyz[2] << " r:" << radius << endl;
}

double Circle::area(){
    return radius*radius*3.14;
}

double Circle::perimeter(){
    return 2*3.14*radius;
}

double Circle::getRadius(){
    return radius;
}

void Circle::setRadius(double radius){
    this->radius = radius;
}