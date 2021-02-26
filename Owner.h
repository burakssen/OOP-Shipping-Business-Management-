/*
 * Name : Burak Şen
 * Id: 150170063
 */
#ifndef _OWNER
#define _OWNER

#include "Person.h"

class Owner: public Person{ //owner class with instance of a person class
    double ownership;
public:
    Owner();
    Owner(string,string);
    void setOwnerShip(double);
    double getOwnerShip();
};
Owner::Owner():Person(){}

Owner::Owner(string name,string surname):Person(name,surname){} // we create an owner with a person name and surname

void Owner::setOwnerShip(double ownership) { // we set the owner a ownership
    this->ownership = ownership;
}

double Owner::getOwnerShip() { // we get owners ownership
    return this->ownership;
}


#endif //_OWNER
