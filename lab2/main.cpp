#include <iostream>
#include <string>

using namespace std;

class Student{
    string imie;
    string nazwisko;
    int wiek;
    int waga;
    string kolor;
    double pieniadze;
    int punkty = 0;

public:
    void read(){
        cout << "Podaj imie: ";
        cin >> imie;
        cout << "Podaj nazwisko: ";
        cin >> nazwisko;
        cout << "Podaj wiek: ";
        cin >> wiek;
        cout << "Podaj wage: ";
        cin >> waga;
        cout << "Podaj ulubiny kolor: ";
        cin >> kolor;
        cout << "Podaj ilosc pieniedzy w portfelu: ";
        cin >> pieniadze;
    }

    void print(){
        cout << imie << "\n";
        cout << nazwisko << "\n";
        cout << wiek << "\n";
        cout << waga << "\n";
        cout << kolor << "\n";
        cout << pieniadze << "\n";
        cout << punkty << "\n -------------------------\n";
    }

    void punkts(){
        punkty = (int)(pieniadze*wiek/waga);
    }

   void code(){
        string cod, number;
        cout << "\n\n";
        cod += imie[0]; 
        cod += nazwisko[0];
        number = to_string(wiek);
        cod += number;
        cout << cod << "\n\n";
   }

};





int main() {
    Student xyz;
    xyz.read();
    xyz.punkts();
    xyz.print();
    xyz.code();

}