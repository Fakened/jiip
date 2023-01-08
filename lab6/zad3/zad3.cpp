#include <iostream>
#include "function.h"
#include <functional>
using namespace std;


int main(){
    double result, tmp = 0.2;
    result = functionMax([](double x)->double {return (x * x) / sin(x);}, -2, 3.5, 0.1);
    cout << result << endl;
    result = functionMax([](double x)->double {return (x * x + 2 * x - 5);}, -2, 3.5, 0.1);
    cout << result << endl;
    result = functionMax([](double x)->double {return sin(x);}, -2, 3.5, 0.000001);
    cout << result << endl;
    result = functionMax([&tmp](double x)->double {return sin(x)*tmp;}, -2, 3.5, 0.000001);
    cout << result << endl;
    result = functionMax([tmp](double x)->double {return sin(x)*tmp;}, -2, 3.5, 0.000001);
    cout << result << endl;
}
 