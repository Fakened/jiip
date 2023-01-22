//
// Created by User on 15.01.2023.
//

#ifndef PERSON_H
#define PERSON_H
#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

/**
 *@class Person
 *@brief Represents a person.
 *The Person class represents a person with properties such as name and age. It has functions to set and get the name of the person.
 */
class Person
{
    public:
        /**
         *@var name
         *@brief Name of the person.
         */
        string name;
    /**
     *@var age
     *@brief Age of the person.
     */
    int age;
    /**
     *@brief Constructor for the Person class.
     *@param name Name of the person.
     *@param age Age of the person.
     */
    Person(const string &name, int age);
    /**
     *@brief Constructor for the Person class.
     *@param name Name of the person.
     */
    Person(const string &name);
    /**
     *@brief Setter for the person's name.
     *@param name Name to set for the person.
     */
    void setName(const string &name);
    /**
     *@brief Getter for the person's name.
     *@return Name of the person.
     */
    const string &getName() const;
};


#endif	//PROJEKTCMD_PERSON_H
