#include <iostream>
#include "TaskList.h"

using namespace std;

TaskList::TaskList(const int ID, const string &date, const vector<string> &arr) : date{date}, arr{arr}, ID{ID} {}

TaskList::~TaskList(){};

void TaskList::print(){
    cout << ID << "\t" << date << "\t" << endl;

    for (auto &el : arr)
        cout << "- " << el << endl;
}

void TaskList::setID(const int ID){
    this->ID = ID;
}

void TaskList::setDate(const string &date){
    this->date = date;
}

void TaskList::setArr(const vector<string> &arr){
    this->arr = arr;
}

const int TaskList::getID(){
    return ID;
}

const string &TaskList::getDate(){
    return date;
}

const vector<string> &TaskList::getArr() const{
    return arr;
}
