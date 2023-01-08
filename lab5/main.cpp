#include <iostream>
using namespace std;


class Point {
    double x;
    double y;
    double z;

public:
    Point() : 
    x(0), y(0), z(0) {}

    Point(double x, double y, double z):
    x(x), y(y), z(z) {}

    void print() {
        cout << x << " " << y << " " << z << endl;
    }

    bool operator==(const Point &rhs) {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }

    bool operator!=(const Point &rhs) {
        return x != rhs.x || y != rhs.y || z != rhs.z;
    }

    friend ostream &operator<<(ostream &lhs, const Point &rhs);
    friend istream &operator>>(istream &is, Point &rhs);
    friend Point distanceBetwenPoints(const Point &first, const Point &second);
};

ostream &operator<<(ostream &lhs, const Point &rhs) {
    return lhs << rhs.x << " " << rhs.y << " " << rhs.z;
}

istream &operator>>(istream &is, Point &rhs) {
    is >> rhs.x;
    is >> rhs.y;
    is >> rhs.z;
    return is;
}

Point distanceBetwenPoints(const Point &first, const Point &second){
    return {(first.x-second.x), (first.y-second.y), (first.z-second.z)};
}

int main() {
    Point p1;
    Point p2{5, 5, 6};

    cout << p1 << endl;
    cout << p2 << endl;
    cout << distanceBetwenPoints(p1, p2) << endl;
    cin >> p1;
    return 0;
}