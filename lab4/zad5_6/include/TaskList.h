#pragma once
#include <vector>
#include "Task.h"

using namespace std;

class TaskList : public Task
{
    private:
        int ID;
        string date;
        vector<string> arr;

    public:
        TaskList(const int ID, const string &date, const vector<string> &arr);
        ~TaskList();
        void print() override;

        void setID(const int ID) override;
        void setDate(const string &date) override;
        void setArr(const vector<string> &arr);

        const int getID() override;
        const string &getDate() override;
        const vector<string> &getArr() const;
};
