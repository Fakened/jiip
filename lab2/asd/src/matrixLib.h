#include <iostream>

using namespace std;

int ** addMatrix(int ** A, int ** B, int width, int height);
double ** addMatrix(double ** A, double * B, int width, int height);

int ** subtractMatrix(int ** A, int ** B, int width, int height);
double ** subtractMatrix(double ** A, double ** B, int width, int height);

int ** multiplyByScalarMatrix(int ** A, int scalar, int width, int height);
double ** multiplyByScalarMatrix(double ** A, double scalar, int width, int height);

int ** transpozeMatrix(int ** A, int width, int height);
double ** transpozeMatrix(double ** A, int width, int height);

