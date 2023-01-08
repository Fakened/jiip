#include "matrixLib.h"


int ** addMatrix(int ** A, int ** B, int width, int height){
    int i, j;
    int **matA = new int *[height];
    for(i = 0; i < height; i++){
        matA[i]= new int [width];
        for(j = 0; j < width; j++){
            matA[i][j] = A[i][j] + B[i][j];;
        }
    }

    return matA;
}

double ** addMatrix(double ** A, double ** B, int width, int height){
    int i,j;
    double **matA = new double *[height];
    for(i = 0; i < height; i++){
        matA[i]= new double [width];
        for(j = 0; j < width; j++){
            matA[i][j] = A[i][j] + B[i][j];
        }
    }

    return matA;
}

int ** subtractMatrix(int ** A, int ** B, int width, int height){
    int i, j;
    int **matA = new int *[height];
    for(i = 0; i < height; i++){
        matA[i]= new int [width];
        for(j = 0; j < width; j++){
            matA[i][j] = A[i][j] - B[i][j];
        }
    }

    return matA;
}

double ** subtractMatrix(double ** A, double ** B, int width, int height){
    int i,j;
    double **matA = new double *[height];
    for(i = 0; i < height; i++){
        matA[i]= new double [width];
        for(j = 0; j < width; j++){
            matA[i][j] = A[i][j] - B[i][j];
        }
    }

    return matA;
}

int ** multiplyByScalarMatrix(int ** A, int scalar, int width, int height){
    int i, j;
    int **matA = new int *[height];
    for(i = 0; i < height; i++){
        matA[i]= new int [width];
        for(j = 0; j < width; j++){
            matA[i][j] *= scalar;
        }
    }
    return matA;
}

double ** multiplyByScalarMatrix(double ** A, double scalar, int width, int height){
    int i,j;
    double **matA = new double *[height];
    for(i = 0; i < height; i++){
        matA[i]= new double [width];
        for(j = 0; j < width; j++){
            matA[i][j] = A[i][j] * scalar;
        }
    }

    return matA;
}

int ** transpozeMatrix(int ** A, int width, int height){
    int i,j;
    int **matA = new int *[width];
    for(i = 0; i < width; i++){
        matA[i]= new int [height];
        for(j = 0; j < width; j++){
            matA[i][j] = A[j][i];
        }
    }
    return matA;
}

double ** transpozeMatrix(double ** A, int width, int height){
    int i,j;
    double **matA = new double *[width];
    for(i = 0; i < width; i++){
        matA[i]= new double [height];
        for(j = 0; j < width; j++){
            matA[i][j] = A[j][i];
        }
    }
    return matA;
}