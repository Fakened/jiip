#include <iostream>

using namespace std;

class MVector {
    double x;
    double y;
    double z;

public:
    MVector();
    MVector(double x, double y, double z);
    ~MVector();

    MVector operator+(const MVector &rhs);
    MVector &operator+=(double rhs);
    MVector operator-(const MVector &rhs);
    MVector &operator-=(double rhs);
    MVector operator*(const double rhs);
    MVector &operator*=(double rhs);
    double operator*(const MVector &rhs);
    friend ostream &operator<<(ostream &lhs, const MVector &rhs);
    double operator[](char idx);

    void setX(double x);
    void setY(double y);
    void setZ(double z);
    double getX();
    double getY();
    double getZ();
    
    double length();
};