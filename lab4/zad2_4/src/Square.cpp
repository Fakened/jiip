#include "Square.h"

Square::Square(double xyz[], const double a) : Figure(xyz), a(a){}

void Square::print(){
    cout << "x:" << xyz[0] << " y: " << xyz[1] << " z: " << xyz[2] << " a: " << a << endl;
}

double Square::area(){
    return a*a;
}

double Square::perimeter(){
    return 4*a;
}

double Square::getA(){
    return a;
}

void Square::setA(double a){
    this->a = a;
}
