#include <iostream>
#include <vector>
#include <ctime>
#include <string>

#include "Task.h"
#include "TaskList.h"
#include "TaskNote.h"

using namespace std;

enum menu{
    SCaddTask = 1,
    SCprintList = 2,
    SCprintIDtask = 3,
    SCdeleteTask = 4,
    SCexit = 5
};
enum subMenu{
    SCtlist = 1,
    SCtnote = 2
};

void printMenu(){
    string arr[5] = {"1 - Dodaj zadanie", "2 - Wyswietl zadania", "3 - Wyswietl zadanie o podanym ID", "4 - Usun zadanie", "5 - Wyjscie"};
    for (string i : arr)
        cout << i << endl;
}
void printSubMenu(){
    string arr[2] = {"1 - Lista", "2 - Notatka"};
    for (auto i : arr)
        cout << i << endl;
}

void addToList(vector<Task *> &zadania, const int *id, const string *processDate){
    string answer;
    vector<string> arr;
    cin.clear();
    cout << "Podaj liste: ";
    getchar();
    while (getline(cin, answer))
    {
        cin.clear();
        if (answer != "\n")
            arr.push_back(answer);
    }
    cin.clear();
    TaskList *task = new TaskList(*id, *processDate, arr);
    zadania.push_back(task);
}
void addToNote(vector<Task *> &zadania, const int *id, const string *processDate){
    string note = "";
    cout << "Podaj notatke: ";
    getchar();
    getline(cin, note);
    TaskNote *task = new TaskNote(*id, *processDate, note);

    zadania.push_back(task);
}

void addTask(vector<Task *> &zadania){
    int id;
    int n = zadania.size();
    if (n != 0)
    {
        id = zadania[n - 1]->getID() + 1;
    }
    else
        id = 1001;

    time_t t = time(0);
    tm *now = localtime(&t);
    string date = to_string(now->tm_year + 1900) + "-" + to_string(now->tm_mon + 1) + "-" + to_string(now->tm_mday);
    int x;
    printSubMenu();
    cout << "Wpisz wybor: ";
    cin >> x;
    switch (x)
    {
    case SCtlist:
        addToList(zadania, &id, &date);
        break;
    case SCtnote:
        addToNote(zadania, &id, &date);
        break;
    }
}
void printList(vector<Task *> &zadania){
    system("cls");
    int n = zadania.size();
    for (int i = 0; i < n; i++)
        zadania[i]->print();
    system("pause");
}
void printIDtask(vector<Task *> &zadania){
    int id;
    system("cls");
    cout << "Podaj ID do znalezienia: ";
    cin >> id;
    int n = zadania.size();
    for (int i = 0; i < n; i++)
        if (zadania[i]->getID() == id)
        {
            zadania[i]->print();
            break;
        }

    system("pause");
}
void deleteTask(vector<Task *> &zadania){
    system("cls");
    cout << "ID\tDate" << endl;
    int n = zadania.size();
    for (int i = 0; i < n; i++)
        cout << zadania[i]->getID() << "\t" << zadania[i]->getDate() << endl;

    int id;
    cout << "Prosze podac ID zadania do usuniecia: ";
    cin >> id;
    for (int i = 0; i < n; i++)
        if (zadania[i]->getID() == id)
        {
            zadania[i]->~Task();
            zadania.erase(zadania.begin() + i);
            break;
        }

    system("pause");
}

int main(){
    vector<Task *> zadania;
    int x;
    while (true){
        printMenu();
        cout << "Wpisz wybor: ";
        cin >> x;

        switch (x){
        case SCaddTask:
            addTask(zadania);
            break;
        case SCprintList:
            printList(zadania);
            break;
        case SCprintIDtask:
            printIDtask(zadania);
            break;
        case SCdeleteTask:
            deleteTask(zadania);
            break;
        case SCexit:
            system("cls");
            return 0;
        }

        system("cls");
    }
    return 0;
}
