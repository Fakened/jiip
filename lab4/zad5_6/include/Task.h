#pragma once
#include <iostream>


using namespace std;

class Task{
    public:
        virtual ~Task() = default;
        virtual void print() = 0;
        virtual void setID(const int ID) = 0;
        virtual void setDate(const string &date) = 0;
        virtual const int getID() = 0;
        virtual const string &getDate() = 0;
};