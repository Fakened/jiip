#include "Figure.h"

Figure::Figure(double xyz[]){
    this->xyz = new double[3];
    for(int i=0; i<3; i++){
        this->xyz[i] = xyz[i];
    }
}

Figure::~Figure(){
    delete [] xyz;
}

void Figure::print(){};


void Figure::setXyz(double *xyz){
    this->xyz = xyz;
}