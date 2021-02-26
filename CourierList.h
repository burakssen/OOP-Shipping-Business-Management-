/*
 * Name : Burak Şen
 * Id: 150170063
 */
#ifndef _COURIERLIST
#define _COURIERLIST
#include "Courier.h"

using namespace std;

class CourierNode{ //Courier list node
    Courier *courier;
    CourierNode* next;
    public:
        CourierNode(Courier&);
        CourierNode *getNext();
        void setNext(CourierNode&);
        Courier*getCourier();
        ~CourierNode();
};

CourierNode::CourierNode(Courier& courier){ // create a courier node
    this->courier = &courier;
    this->next = NULL;
}

CourierNode *CourierNode::getNext(){ //get courier node next
    return this->next;
}

void CourierNode::setNext(CourierNode &node) { // set courier node next
    this->next = &node;
}

Courier*CourierNode::getCourier() { // get courier
    return this->courier;
}

CourierNode::~CourierNode() { //courier node destructor
}

class CourierList{ //courierlist constructor
    CourierNode *CourierHead;
    public:
        CourierList();
        void addCourier(Courier&);
        CourierNode *getHead();
        void setCourierHead(CourierNode&);
        int length_list();
        ~CourierList();
        void delete_all_list(CourierNode&);

};
CourierList::CourierList() { //assign head to courierlist
    this->CourierHead = NULL;
}

void CourierList::addCourier(Courier &newCourier) {//in this function we add couriers to courierlist
    CourierNode* traverse;
    CourierNode* newnode;
    newnode = new CourierNode(newCourier); // we create new courier node
    if(this->CourierHead == NULL){ //if courier head is null
        this->CourierHead = newnode; // we add courier to head
        return;
    }
    traverse = this->CourierHead;
    while(traverse->getNext() != NULL){ // if iterate our pointer to the end of the list
        traverse = traverse->getNext();
    }
    traverse->setNext(*newnode); //we add courier to the end of the list
}

CourierNode *CourierList::getHead() { //get courierlist head
    return this->CourierHead;
}

void CourierList::setCourierHead(CourierNode &courierNode) { //we set courierlist head
    this->CourierHead = &courierNode;
}

int CourierList::length_list() { //we return lenght of the courier list
    CourierNode*traverse;
    traverse = this->CourierHead;
    int length = 0;
    while(traverse){
        length++;
        traverse = traverse->getNext();
    }
    return length;
}

void CourierList::delete_all_list(CourierNode &temp) { //we delete all of the courierlist list
    if(temp.getNext() != NULL){
        delete_all_list(*temp.getNext());
    }
    delete &temp;
}

CourierList::~CourierList() { // courierlist destructor
    if(this->CourierHead != NULL){
        delete_all_list(*this->CourierHead);
    }
}

#endif //_COURIERLIST
