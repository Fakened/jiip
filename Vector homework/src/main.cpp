#include <iostream>
#include "MVector.h"

using namespace std;

int main() {
    MVector x(2,2,2), f, s(3,4,5);
    double a;
    cout << f << endl;
    cout << s << endl;

    cout << "\n------------------------\n+111\n";
    s=s+f;
    cout << s << endl;

    cout << "\n------------------------\n+=5\n";
    s+=5;
    cout << s << endl;

    cout << "\n------------------------\n-111\n";
    s = s-f;
    cout << s << endl;

    cout << "\n------------------------\n-=5\n";
    s-=5;
    cout << s << endl;

    cout << "\n------------------------\n*=2\n";
    s*=2;
    cout << s << endl;

    cout << "\n------------------------\n*4\n";
    s=s*2;
    cout << s << endl;

    cout << "\n------------------------\n*x\n";
    a=s*x;
    cout << a << endl;

    cout << "\n------------------------\n";
    cout << s['x'] << " " << s['X'] << " " << s['y'] << " " << s['Y'] << " " << s['z'] << " " << s['Z'] << "\n";
    s.setX(2);
    s.setY(2);
    s.setZ(2);
    cout << s.getX() << " " << s.getY() << " " << s.getZ() << "\n";
    cout << s.length() << "\n";
    return 0;
}