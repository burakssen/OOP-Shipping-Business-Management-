/*
 * Name : Burak Şen
 * Id: 150170063
 */
#ifndef _COURIER
#define _COURIER

#include "Person.h"

class Courier : public Person //Courier class extends Person
{
    string vehicle;
    int transportation_cap;

public:
    Courier(Courier &);
    Courier(string, string, string);
    bool operator==(Courier &);
    string getVehicle();
    int getTransportation_Cap();
    void printCourier();
};
Courier::Courier(Courier &temp) //Courier copy constructor we can create a courier with same variables
{
    this->vehicle = temp.getVehicle();
    this->transportation_cap = temp.getTransportation_Cap();
    this->setName(temp.getName());
    this->setSurname(temp.getSurname());
}
Courier::Courier(string name, string surname, string vehicle) : Person(name, surname) // courier constructor we can create a courier class
{                                                                                     //and with in this we can create a person for the courier and assign name and surname
    if(vehicle == "car" && vehicle == "motorcycle" && vehicle == "bicycle"){
        this->vehicle = vehicle;
        if (this->vehicle == "car") // we determine transportation cap for the courier
        {
            this->transportation_cap = 200;
        }
        else if (this->vehicle == "motorcycle")
        {
            this->transportation_cap = 35;
        }
        else if (this->vehicle == "bicycle")
        {
            this->transportation_cap = 10;
        }
    }
    else{
        cout<<"You can't create a courier with this vehicle, automaticly a bicycle assigned to courier"<<endl;
        this->vehicle = "bicycle";
        this->transportation_cap = 10;
    }

}
bool Courier::operator==(Courier &courier)
{   // == operator overloading in this function we control if our courier equals to choosen courier we return true
    return this->getName() == courier.getName() &&
           this->getSurname() == courier.getSurname() &&
           this->vehicle == courier.vehicle &&
           this->transportation_cap == courier.transportation_cap;
}

string Courier::getVehicle() // get courier vehicle
{
    return this->vehicle;
}

int Courier::getTransportation_Cap() //get transportation cap
{
    return this->transportation_cap;
}

void Courier::printCourier() // print our courier
{
    if (this != NULL)
    {
        cout << this->getName() << " " << this->getSurname() << " " << this->getVehicle() << " " << this->getTransportation_Cap() << endl;
    }
    else
    {
        cout << "Courier not found" << endl;
    }
}
#endif //_COURIER
