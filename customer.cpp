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
// Customer COPY CONSTRUCTOR
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
// Description: returns the customer's ID
// PRE: assumes customer's ID exist
// POST: the customer's ID is returned
int Customer::getID() const { return customerID; }

//-----------------------------------------------------------------------------
// getName()
// Description: returns the first name and last name of customer 
// PRE: assumes the first name and last name of customer exist
// POST: the customer's first name and last name is returned
string Customer::getName() const {
  string fullName = firstName + " " + lastName;
  return fullName;
}

//-----------------------------------------------------------------------------
// getFirstName()
// Description: returns the first name of the customer
// PRE: assumes the first name of the customer exist
// POST: the customer's first name is returned
string Customer::getFirstName() const { return firstName; }

//-----------------------------------------------------------------------------
// getLastName()
// Description: returns the last name of the customer
// PRE: assumes the last name of the custimer exist
// POST: the customer's last name is returned
string Customer::getLastName() const { return lastName; }

//-----------------------------------------------------------------------------
// getHistory()
// Description: returns the transaction history of the customer with the
//              most recent one being printed first
// PRE: assumes that customer exit
// POST: the transaction history of the customer is returned
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
// addHistory()
// Description: add transaction event to customer's transaction history
// PRE: assumes customer exist
// POST: a transaction event is added to the customer's transaction history
void Customer::addHistory(string transaction) { history.push(transaction); }

//-----------------------------------------------------------------------------
// setCustomerInfo()
// Description: sets the customer data fields
// PRE: assumes that the data fields exist
// POST: return true if the customer data fields are set
bool Customer::setCustomerInfo(int cID, string first, string last) {
  return setID(cID) && setFirstName(first) && setLastName(last);
}

//-----------------------------------------------------------------------------
// setID()
// Description: sets the customer ID
// PRE: assumes customer's ID exist
// POST: returns true if the customer ID is set
bool Customer::setID(int cID) {
  customerID = cID;
  return true;
}

//-----------------------------------------------------------------------------
// setFirstName()
// Description: sets the customer's first name
// PRE: assumes customer's first name exist 
// POST: returns true if the customer's first name is set
bool Customer::setFirstName(string first) {
  firstName = first;
  return true;
}

//-----------------------------------------------------------------------------
// setLastName()
// Description: sets the customer's last name 
// PRE: assumes customer's last name exist
// POST: returns true if the customer's last name is set
bool Customer::setLastName(string last) {
  lastName = last;
  return true;
}
