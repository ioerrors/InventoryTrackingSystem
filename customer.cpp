#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP

#include "customer.h"

Customer::Customer() {
    setID("");
    setFirstName("");
    setLastName("");
}

Customer::Customer(int cID, string first, string last) {
    setID(cID);
    setFirstName(first);
    setLastName(last);
}

Customer::~Customer() {

}

int Customer::getID() const {
    return customerID;
}

string Customer::getName() const {
    // seaching only shows long way of returning multiple items
    // since we cant do return firstname && lastname
}

string Customer::getFirstName() const {
    return firstName;
}

string Customer::getLastName() const {
    return lastName;
}

historyNode* Customer::getHistory() {
    return headHistory;
}

void Customer::addHistory(string transaction) {
    // history.push_back(transaction);
}

bool Customer::setCustomerInfo(int cID, string first, string last) {
    return setID(cID) && setFirstName(first) && setLastName(last);
}

bool Customer::setID(int cID) {
    customerID = id;
    return true;
}

bool setFirstName(string first) {
    firstName = first;
    return true;
}

bool setLastName(string last) {
    lastName = last;
    return true;
}

#endif