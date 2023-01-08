#include "function.h"

double functionMax(function<double(double)> equ, double startX, double endX, double step) {
    double max = equ(startX);
    for (startX; startX < endX; startX += step) {
        if (equ(startX) > max) {
            max = equ(startX);
        }
    }
    return max;
}
