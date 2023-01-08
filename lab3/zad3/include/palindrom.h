#ifndef CHECKER_PALINDROM_H
#define CHECKER_PALINDROM_H

#include <iostream>

using namespace std;

class Palindrom {
private:
    string text;

public:
    Palindrom(string text);

    Palindrom() = default; 

    ~Palindrom();

    bool isEmpty();
    void setText(string text);
    string getText();
    void print();
    void pushChar(char ch);
    char popChar();
    void clear();


};


#endif //CHECKER_Palindrom_H