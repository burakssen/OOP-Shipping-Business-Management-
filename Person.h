/*
 * Name : Burak Şen
 * Id: 150170063
 */
#ifndef _PERSON
#define _PERSON

using namespace std;

class Person
{
    string name;
    string surname;

public:
    Person();
    Person(string, string);
    string getName();
    string getSurname();
    void setName(string);
    void setSurname(string);
};
Person::Person() {} //

Person::Person(string name, string surname) // person constructor
{
    this->name = name;
    this->surname = surname;
}

string Person::getName() // name get
{
    return this->name;
}
string Person::getSurname() // surname get
{
    return this->surname;
}

void Person::setName(string data) // we set person name
{
    this->name = data;
}

void Person::setSurname(string data) //we set person surname
{
    this->surname = data;
}

#endif //_PERSON
