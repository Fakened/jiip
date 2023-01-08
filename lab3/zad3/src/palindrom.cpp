#include "palindrom.h"

Palindrom::Palindrom(string text){
    this->text = text;
}
Palindrom::~Palindrom(){
}


bool Palindrom::isEmpty(){
    return text.empty();
}

void Palindrom::setText(string text){
    this->text = text;
}

string Palindrom::getText(){
    string x = "";
    for(int i = 0; i< text.length(); i++){
        x += text[i];
    }
    for(int i = text.length()-1; i>=0; i--){
        x += text[i];
    }
    return x;
}

void Palindrom::print(){
    cout << getText() << "\n";
}

void Palindrom::pushChar(char ch){
    text.push_back(ch);
}

char Palindrom::popChar(){
    char ch;
    ch = text.back();
    text.pop_back();
    return ch;
}

void Palindrom::clear(){
    text = "";
}

