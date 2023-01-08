#include <iostream>
#include "matrixLib.h"


using namespace std;

int main() {
    int i,j, k = 0;
    double **x = new double*[3];

    for(i = 0; i<3; i++){
        x[i]= new double [3];
        for(j = 0; j<3; j++){
            x[i][j] = j+k;
        }
        k+=10;
    }

    for(i = 0; i<3; i++){
            for(j = 0; j<3; j++){
                cout << x[i][j] << " ";
            }
            cout << "\n";
        }
    cout << "\n --------------------- \n";
    double **y = new double*[3];
    for(i = 0; i<3; i++){
        y[i]= new double [3];
    }
    y = transpozeMatrix(x, 3, 3);

    for(i = 0; i<3; i++){
        for(j = 0; j<3; j++){
            cout << y[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;

}