#include <iostream>
#include "Variable.h"

using namespace std;

int main()
{
    Variable s;
    s.setInt(97);
    cout << s.getChar() << endl;
    cout << s.getInt() << endl;
    //cout << s.getDouble() << endl;
    //cout << s.getChar() << endl;
    //cout << s.getShort() << endl;
    //cout << s.getUnsigned() << endl;
}

