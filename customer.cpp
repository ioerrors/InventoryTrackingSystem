////////////////////////////////customer.cpp file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold a single customer
//-----------------------------------------------------------------------------
#include <iostream>
#include <sstream>
#include <stack>

#include "BSTree.h"
#include "customer.h"
#include "hashTable.h"
#include "movieFactory.h"
#include "transaction.h"

using namespace std;

//-----------------------------------------------------------------------------
// Customer CONSTRUCTOR
// Description: creates an empty Customer
// PRE: memory is available for Customer
// POST: empty Customer is created
Customer::Customer() {
  setID(0);
  setFirstName("");
  setLastName("");
}

//-----------------------------------------------------------------------------
// Customer CONSTRUCTOR
// Description: creates Customer copy
// PRE: memory is available for Customer
// POST: Customer copy is created
Customer::Customer(int cID, string first, string last) {
  setID(cID);
  setFirstName(first);
  setLastName(last);
}

//-----------------------------------------------------------------------------
// Customer DESTRUCTOR
// Description: deallocates all memory allocated for Customer
// PRE: Customer exits
// POST: all Customer memory is freed
Customer::~Customer() {
  while (!history.empty()) {
    history.pop();
  }
  while (!storage.empty()) {
    history.pop();
  }
}

//-----------------------------------------------------------------------------
// getID()
// Description: 
// PRE: 
// POST: 
int Customer::getID() const { return customerID; }

//-----------------------------------------------------------------------------
// 
// Description: 
// PRE: 
// POST: 
string Customer::getName() const {
  string fullName = firstName + " " + lastName;
  return fullName;
}

//-----------------------------------------------------------------------------
// 
// Description: 
// PRE: 
// POST: 
string Customer::getFirstName() const { return firstName; }

//-----------------------------------------------------------------------------
// 
// Description: 
// PRE: 
// POST: 
string Customer::getLastName() const { return lastName; }

//-----------------------------------------------------------------------------
// 
// Description: 
// PRE: 
// POST: 
stringstream Customer::getHistory() {
  stringstream os;

  // <---top of history is most recent transaction
  while (!history.empty()) {
    os << history.top();
    storage.push(history.top());
    history.pop();
  }
  // <--top of storage is least recent transaction
  while (!storage.empty()) {
    history.push(storage.top());
    storage.pop();
  }
  // <--top of history is most recent transaction
  return os;
}

//-----------------------------------------------------------------------------
// 
// Description: 
// PRE: 
// POST: 
void Customer::addHistory(string transaction) { history.push(transaction); }

//-----------------------------------------------------------------------------
// 
// Description: 
// PRE: 
// POST: 
bool Customer::setCustomerInfo(int cID, string first, string last) {
  return setID(cID) && setFirstName(first) && setLastName(last);
}

//-----------------------------------------------------------------------------
// 
// Description: 
// PRE: 
// POST: 
bool Customer::setID(int cID) {
  customerID = cID;
  return true;
}

//-----------------------------------------------------------------------------
// 
// Description: 
// PRE: 
// POST: 
bool Customer::setFirstName(string first) {
  firstName = first;
  return true;
}

//-----------------------------------------------------------------------------
// 
// Description: 
// PRE: 
// POST: 
bool Customer::setLastName(string last) {
  lastName = last;
  return true;
}
