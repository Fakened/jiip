#include <iostream>
#include "Circle.h"
#include "Square.h"
#include "Trapeze.h"

using namespace std;



int main() {
    {
        double tab[3] = {1,2,3};
        Circle c(tab, 10);
        Figure *wsk = &c;
        wsk->print();
        cout << wsk->area() << endl;
        cout << wsk->perimeter() << endl;

        Square s(tab, 4);
        Figure *asd = &s;
        asd->print();
        cout << asd->area() << endl;
        cout << asd->perimeter() << endl;

        Trapeze t(tab, 4, 4, 4, 4, 4);
        Figure *qwe = &t;
        qwe->print();
        cout << qwe->area() << endl;
        cout << qwe->perimeter() << endl;

    }


    cout << "End program" << endl;


    return 0;
}