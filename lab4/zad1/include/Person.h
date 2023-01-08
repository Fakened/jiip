#include <iostream>

using namespace std;

class Person {
    protected:
        string name;
        string lastName;
        int age;
    public:
        Person();
        Person(const string &name, const string &lastName, const int &age);
        virtual void print() = 0;
};

class Student: public Person{
    protected:
        string studentsId;
    public:
        Student(const string &name, const string &lastName, const int &age, const string &studentsID);
        void print() override;
};

class Worker: public Person{
    protected:
        int money;
    public:
        Worker(const string &name, const string &lastName, const int &age, const int &money);
        void print() override;
};

