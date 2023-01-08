#include "Person.h"

Person::Person(){
    name = "default";
    lastName = "default";
    age = 0;
}
Person::Person(const string &name, const string &lastName, const int &age){
    this->name = name;
    this->lastName = lastName;
    this->age = age;
}


Student::Student(const string &name, const string &lastName, const int &age, const string &studentsID) : Person(name, lastName, age)
{
    this->studentsId = studentsID;
}

void Student::print(){
    cout << name << " " << lastName << " " << age << " " << studentsId << endl;
}

Worker::Worker(const string &name, const string &lastName, const int &age, const int &money) : Person(name, lastName, age)
{
    this->money = money;
}

void Worker::print(){
    cout << name << " " << lastName << " " << age << " " << money << endl;
}