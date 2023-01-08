#include <iostream>
#include "doors.h"

using namespace std;


int main() {
    {
        // --------------------------zadanie 1 -----------------------
        double *x = new double[5];
        double *y = new double[7];
        for(int i = 0; i<5; i++){
            x[i]=i;
            y[i]=i+10;
        }

        
        Door p1(2,"white", 5, x), p2(3,"black", 3, x);
        
        cout<<p1.getPrice();

        cout << "Initial values" << endl;
        p1.printData();
        p2.printData();

        cout << endl << "Create copy of Door" << endl;
        Door p1c = p1, p2c = p2;
        //Update copied Doors names
        p1c.setColour("P1c");
        p2c.setColour("P2c");

        cout << "Values after copying" << endl;
        p1.printData();
        p2.printData();
        p1c.printData();
        p2c.printData();

        cout << endl << "Update P1 and P2 x and y (increase 10)" << endl;
        p1.setArr(y);
        p2.setArr(y);


        cout << "Values after update values" << endl;
        p1.printData();
        p2.printData();
        p1c.printData();
        p2c.printData();
        delete [] x;
        delete [] y;

    }
    {
    //---------------- zadanie 2 ----------------------------

    
    double *x = new double[5];
    for(int i = 0; i<5; i++){
            x[i]=i;
        }
    Door doors[4];
    cout << "\n\n";
    for(int i = 0; i<4; i++){
        doors[i].setPrice(i);
        doors[i].setColour("green");
        doors[i].setSizeofarr(i+1);
        doors[i].setArr(x);

    }

    
    for(int i = 0; i<4; i++){
        cout<<doors[i].getPrice() << " "<<doors[i].getColour() << " "<< doors[i].getSizeofarr() << " ";
        doors[i].printArr();
        cout << "\n";
    }
    delete [] x;
    }
    cout << "End program" << endl;


    return 0;
}
