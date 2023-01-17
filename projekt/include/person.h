//
// Created by User on 15.01.2023.
//

#ifndef PROJEKTCMD_PERSON_H
#define PROJEKTCMD_PERSON_H
#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
class Person {
public:
    string name;
    int age;
    Person(const string &name, int age);
    Person(const string &name);
    void setName(const string &name);
    const string & getName() const;
};


#endif //PROJEKTCMD_PERSON_H
