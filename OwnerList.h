/*
 * Name : Burak Şen
 * Id: 150170063
 */
#ifndef _OWNERLIST
#define _OWNERLIST
#include <iostream>
#include "Owner.h"

using  namespace std;

class OwnerNode{ // ownernode
    Owner* owner;
    OwnerNode *next;
    public:
        OwnerNode();
        OwnerNode(Owner&);
        OwnerNode* getNext();
        void setNext(OwnerNode&);
        void setOwnerShip(double);
        Owner *getOwner();
};

OwnerNode::OwnerNode() {}

OwnerNode::OwnerNode(Owner& owner) { // ownernode constructor we assign our owner to owner node
    this->owner = &owner;
    this->next = NULL;
}

OwnerNode *OwnerNode::getNext() { // get owner node next
    return this->next;
}

void OwnerNode::setNext(OwnerNode &next) { // set owner node's next
    this->next = &next;
}

void OwnerNode::setOwnerShip(double ownership) { //set owner node's owner to an ownership
    this->owner->setOwnerShip(ownership);
}

Owner*OwnerNode::getOwner() { // get owner from the owner node
    return this->owner;
}

class OwnerList{ //ownerlist class
    int number_of_owners;
    OwnerNode *OwnerHead;
    public:
        OwnerList();
        void addOwner(Owner&);
        void setOwnerShip(int);
        int getOwnerNum();
        OwnerNode *getHead();
        ~OwnerList();
        void delete_all_list(OwnerNode&);
};

OwnerList::OwnerList() { // constructor of the ownerlist
    this->number_of_owners = 0;
    this->OwnerHead = NULL;
}

void OwnerList::addOwner(Owner &newowner) { //we add an owner to the ownerlist
    OwnerNode *traverse;
    OwnerNode *newnode;
    newnode = new OwnerNode(newowner);
    if(this->OwnerHead == NULL){ //if owner list's head is empty we add an owner to the head
        this->OwnerHead = newnode;
        this->number_of_owners++;   // we increase owner number
        return;
    }
    traverse = this->OwnerHead;
    while(traverse->getNext() != NULL){ // we iterate our pointer to the end of the list
        traverse = traverse->getNext();
    }
    this->number_of_owners++; // we increase owner number
    traverse->setNext(*newnode); // we add a new owner to the ownerlist's end
}

void OwnerList::setOwnerShip(int number_of_orders) { //we set ownership to all of our owners
    if(this->number_of_owners != 0){
        OwnerNode*traverse;
        traverse = this->OwnerHead;
        double temp_ownership = 100 / number_of_orders;
        while(traverse){
            traverse->setOwnerShip(temp_ownership);
            traverse = traverse->getNext();
        }
    }
}

int OwnerList::getOwnerNum() { //we get number of owners
    return this->number_of_owners;
}

OwnerNode* OwnerList::getHead() { //we get owner head
    return this->OwnerHead;
}

void OwnerList::delete_all_list(OwnerNode &temp) { //we delete all of the owners from the owner list
    if(temp.getNext() != NULL){
        delete_all_list(*temp.getNext());
    }
    delete &temp;
}

OwnerList::~OwnerList() { // ownerlist destructor
    if(this->OwnerHead != NULL){
        delete_all_list(*this->OwnerHead);
    }
}

#endif //_OWNERLIST
