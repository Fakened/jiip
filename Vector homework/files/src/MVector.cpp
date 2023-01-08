#include "MVector.h"
#include <cmath>

MVector::MVector(): x(1), y(1), z(1) {}

MVector::MVector(double x, double y, double z): x(x), y(y), z(z) {}

MVector::~MVector(){}

MVector MVector::operator+(const MVector &rhs){
    return {(this->x + rhs.x), (this->y + rhs.y), (this->z + rhs.z)};
}

MVector &MVector::operator+=(double rhs){
    x += rhs;
    y += rhs;
    z += rhs;
    return *this;
}

MVector MVector::operator-(const MVector &rhs){
    return {(this->x - rhs.x), (this->y - rhs.y), (this->z - rhs.z)};
}

MVector &MVector::operator-=(double rhs){
    x -= rhs;
    y -= rhs;
    z -= rhs;
    return *this;
}

MVector MVector::operator*(const double rhs){
    return {(this->x * rhs), (this->y * rhs), (this->z * rhs)};
}

MVector &MVector::operator*=(double rhs){
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;
}

double MVector::operator*(const MVector &rhs){
    return (this->x * rhs.x + this->y * rhs.y + this->z * rhs.z);
}

ostream &operator<<(ostream &lhs, const MVector &rhs) {
    return lhs << rhs.x << " " << rhs.y << " " << rhs.z;
}

double MVector::operator[](char idx){
    if (idx == 'x' || idx == 'X'){
        return x;
    } else if (idx == 'y' || idx == 'Y') {
        return y;
    } else if (idx == 'z' || idx == 'Z'){
        return z;
    } else {
        return 0;
    }
}

void MVector::setX(double x){
    this->x = x;
}

void MVector::setY(double y){
    this->y = y;
}

void MVector::setZ(double z){
    this->z = z;
}

double MVector::getX(){
    return x;
}

double MVector::getY(){
    return y;
}

double MVector::getZ(){
    return z;
}

double MVector::length(){
    return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
};