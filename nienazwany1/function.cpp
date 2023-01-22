#include "function.h"

void cls()
{
    #if defined(_WIN32)
    system("cls");


    #else
        system("clear");
    #endif
}
