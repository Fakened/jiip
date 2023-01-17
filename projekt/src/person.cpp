//
// Created by User on 15.01.2023.
//

#include "person.h"

Person::Person(const string &name, int age) : name(name), age(age) {
}

Person::Person(const string &name) : name(name) {

}

const string &Person::getName() const {
    return name;
}

void Person::setName(const string &name) {
    Person::name = name;
}
