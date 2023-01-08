
#include "function.h"
int printWithCounter(const string& text)
{
    for (auto letter : text)
    {
        if (letter == 'a' || letter == 'z')
            ++counter;
    }
    cout << text << endl;
    return counter;
}