#include <iostream>
#include "palindrom.h"

using namespace std;


int main() {
    {
        Palindrom p;
        cout << "IsEmpty: " << p.isEmpty() << "\n";
        p.setText("asd");
        cout << "IsEmpty: " << p.isEmpty() << "\n";
        cout <<"Palindrom getText(): "<< p.getText() << "\n";
        cout <<"Palindrom printText(): ";
        p.print();
        cout << "Pushchar x: ";
        p.pushChar('x');
        p.print();
        cout << "Popchar: ";
        cout<< p.popChar() << "\n";
        cout << "Clear: isEmpty==";
        p.clear();
        cout << p.isEmpty();

    }
    return 0;
}
