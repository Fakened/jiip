#include <iostream>
#include "TaskNote.h"

using namespace std;

TaskNote::TaskNote(const int ID, const string &date, const string &note) : note(note){
    this->ID = ID;
    this->date = date;
}

TaskNote::~TaskNote(){};

void TaskNote::print(){
    cout << ID << "\t" << date << "\t" << note << endl;
}

void TaskNote::setID(const int ID){
    this->ID = ID;
}
void TaskNote::setDate(const string &date){
    this->date = date;
}
void TaskNote::setNote(const string &note){
    this->note = note;
}

const int TaskNote::getID(){
    return ID;
}
const string &TaskNote::getDate(){
    return date;
}
const string &TaskNote::getNote() const{
    return note;
}
