/*
 * Name : Burak Şen
 * Id: 150170063
 */

#ifndef _BUSINESS
#define _BUSINESS

#include "OwnerList.h"
#include "CourierList.h"

class Business
{
    string name;//private name
    string adress;//private adress
    OwnerList *ownerList;//private ownerlist
    CourierList *courierList;//private courierlist

public:
    Business();
    Business(string, string, OwnerList &, int);
    void operator=(Business &);
    void list_owners();
    void list_couriers();
    void hire_courier(Courier &);
    void fire_courier(Courier &);
    void operator()();
    int calculate_shipment_capacity();
    Courier *operator[](int);
    ~Business();
};
Business::Business(){};
Business::Business(string name, string adress, OwnerList &ownerList, int number_of_owners = 0)
{//business constructor
    this->ownerList = &ownerList;//assign ownerlist
    this->courierList = new CourierList;//create new courier list
    this->name = name;//assign name
    this->adress = adress;//assign adress
    this->ownerList->setOwnerShip(number_of_owners);//set ownership
}

void Business::operator=(Business &business)//assignment operator overload
{   //whit this function we can assign bussines to other business
    this->ownerList = business.ownerList;
    this->adress = business.adress;
    this->name = business.name;
}

void Business::list_owners()
{   //this function print out owners
    OwnerNode *traverse;
    traverse = this->ownerList->getHead();
    if(traverse){ //if there is any owner
        while (traverse) //we print them one by one
        {
            cout << traverse->getOwner()->getName() << " " << traverse->getOwner()->getSurname() << " " << traverse->getOwner()->getOwnerShip() << endl;
            traverse = traverse->getNext();
        }
    }
    else{ //else we print error message
        cout<<"There is no owner"<<endl;
    }
}

void Business::list_couriers()
{//with this function we print out couriers
    if (this->courierList->getHead() != NULL)//if there is any courier
    {
        CourierNode *traverse;
        traverse = this->courierList->getHead();
        while (traverse) //we print them one by one
        {
            cout << traverse->getCourier()->getName() << " " << traverse->getCourier()->getSurname() << " " << traverse->getCourier()->getVehicle() << endl;
            traverse = traverse->getNext();
        }
    }
    else//else we print error message
    {
        cout << "There is no courier" << endl;
    }
}

void Business::hire_courier(Courier &newCourier)
{//with this function we can hire new courier
    this->courierList->addCourier(newCourier);
}

void Business::fire_courier(Courier &remove_courier)
{//with this function we can fire a courier
    CourierNode *traverse;
    CourierNode *tail;
    traverse = this->courierList->getHead()->getNext();
    tail = this->courierList->getHead();
    if (tail->getCourier() == &remove_courier)
    {//iiif our head is the courier that we want to remove
        delete tail;//we delete it
        this->courierList->setCourierHead(*traverse);//next courier will be head
        return;
    }
    while (traverse != NULL)
    {
        if (traverse->getCourier() == &remove_courier)
        {//if we find the desired courier we delete it and return
            tail->setNext(*traverse->getNext());
            traverse = traverse->getNext();
            return;
        }
        tail = tail->getNext();
        traverse = traverse->getNext();
    }
    //if we coldn't find it we print error message
    cout << "Couldn't Find The Courier" << endl;
}

void Business::operator()()
{// () operator overloading in this function we print all of the info of business
    cout << this->name << " " << this->adress << endl;
    if(this->ownerList->getHead() != NULL){// print all owners
        this->list_owners();
    }
    else{
        cout<<"There is no Owner"<<endl;
    }
    this->list_couriers();//print all couriers
    if (this->calculate_shipment_capacity()) //print capacity
    {
        cout << this->calculate_shipment_capacity() << endl;
    }
}

int Business::calculate_shipment_capacity()//this function calculates shipment capacity and returns
{
    CourierNode *traverse;
    traverse = this->courierList->getHead();
    int result = 0;
    while (traverse)
    {
        result += traverse->getCourier()->getTransportation_Cap();
        traverse = traverse->getNext();
    }
    return result;
}

Courier *Business::operator[](int index)
{// [] opertor overloading in this function we can return a spesific courier
    if (this->courierList->getHead() != NULL)
    {
        CourierNode *traverse;
        traverse = this->courierList->getHead();
        for (int i = 0; i < this->courierList->length_list(); i++)
        {
            if (traverse)
            {
                if (i == index)
                {
                    return traverse->getCourier();
                }
                traverse = traverse->getNext();
            }
        }
    }
    return NULL;
}

Business::~Business()//business constructor we delete courierlist because courierlist created in this scope
{
    delete this->courierList;
}
#endif //_BUSINESS
