#pragma once
#include <vector>
#include "Task.h"

using namespace std;


class TaskNote : public Task
{
private:
    int ID;
    string note;
    string date;

public:
    TaskNote(const int ID, const string &date, const string &note);
    ~TaskNote();
    void print() override;

    void setID(const int ID) override;
    void setDate(const string &date) override;
    void setNote(const string &note);

    const int getID() override;
    const string &getDate() override;
    const string &getNote() const;
};
