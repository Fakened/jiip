#include "Trapeze.h"

Trapeze::Trapeze(double xyz[], const double a, const double b,const double c, const double d, const double h) : Figure(xyz), a(a), b(b), c(c), d(d), h(h){}

void Trapeze::print(){
    cout << "x:" << xyz[0] << " y: " << xyz[1] << " z: " << xyz[2] << " a: " << a << " b: " << b << " c: "<< c << " d: " << d << " h: " << h << endl;
}

double Trapeze::area(){
    return (a+b)*h/2;
}

double Trapeze::perimeter(){
    return a+b+c+d;
}

double Trapeze::getA(){
    return a;
}
double Trapeze::getB(){
    return b;
}
double Trapeze::getC(){
    return c;
}
double Trapeze::getD(){
    return d;
}
double Trapeze::getH(){
    return h;
}

void Trapeze::setA(double a){
    this->a = a;
}
void Trapeze::setB(double b){
    this->b = b;
}
void Trapeze::setC(double c){
    this->c = c;
}
void Trapeze::setD(double d){
    this->d = d;
}
void Trapeze::setH(double h){
    this->h = h;
}