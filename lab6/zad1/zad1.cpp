#include <iostream>
#include "Foo.h"

using namespace std;

int main()
{
    Foo a1;
    Foo a2;
    Foo a3;
    Foo a4;
    {
        Foo a5;
        Foo a6;
        Foo a7;
        a1.getInstances();
    }
    Foo a8;
    Foo a9;
    a1.getInstances();
}

