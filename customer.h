////////////////////////////////customer.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold a single customer
//-----------------------------------------------------------------------------
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <sstream>
#include <stack>
using namespace std;

class Customer {

public:
  //---------------------------------------------------------------------------
  // Customer CONSTRUCTOR
  // Description: creates an empty Customer
  // PRE: memory is available for Customer
  // POST: empty Customer is created
  Customer(); // constructor

  Customer(int cID, string first, string last); // ID, first, last

  ~Customer(); // destructor

  // Accessors
  void display() const; // display customer's name and id

  int getID() const;      // return ID of customer
  string getName() const; // return full name of customer
  string getFirstName() const;
  string getLastName() const;

  // basically an overloaded << operator just for history
  stringstream getHistory();

  // Mutators
  void addHistory(string transaction); // add transaction to history
  bool setCustomerInfo(int cID, string first, string last);
  bool setID(int cID);
  bool setFirstName(string first);
  bool setLastName(string last);

private:
  // not sure about these structs

  string lastName;  // lastname of the customer
  string firstName; // firstname of the customer

  int customerID;        // unique user ID
  stack<string> history; // stack of transaction strings
  stack<string> storage; // manage reset of stack
};
#endif
