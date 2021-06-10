////////////////////////////////customer.h file  //////////////////////////////
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

  //---------------------------------------------------------------------------
  // Customer CONSTRUCTOR
  // Description: creates Customer copy
  // PRE: memory is available for Customer
  // POST: Customer copy is created
  Customer(int cID, string first, string last);

  //---------------------------------------------------------------------------
  // Customer DESTRUCTOR
  // Description: deallocates all memory allocated for Customer
  // PRE: Customer exists
  // POST: all Customer memory is freed
  ~Customer(); // destructor

  // no display in cpp
  // is it inherited?
  // Accessors
  //---------------------------------------------------------------------------
  // display()
  // Description: prints out the customer's name and ID
  // PRE: assumes customer's name and ID exist
  // POST: the customer's name and ID is printed
  void display() const; // display customer's name and id

  //---------------------------------------------------------------------------
  // getID()
  // Description: returns the customer's ID
  // PRE: assumes customer's ID exist
  // POST: the customer's ID is returned
  int getID() const;      // return ID of customer

  //---------------------------------------------------------------------------
  // getName()
  // Description: returns the first name and last name of customer 
  // PRE: assumes the first name and last name of customer exist
  // POST: the customer's first name and last name is returned
  string getName() const; // return full name of customer
  
  //---------------------------------------------------------------------------
  // getFirstName()
  // Description: returns the first name of the customer
  // PRE: assumes the first name of the customer exist
  // POST: the customer's first name is returned
  string getFirstName() const;

  //---------------------------------------------------------------------------
  // getLastName()
  // Description: returns the last name of the customer
  // PRE: assumes the last name of the custimer exist
  // POST: the customer's last name is returned
  string getLastName() const;

  // basically an overloaded << operator just for history
  //---------------------------------------------------------------------------
  // getHistory()
  // Description: returns the transaction history of the customer with the
  //              most recent one being printed first
  // PRE: assumes that customer exit
  // POST: the transaction history of the customer is returned
  stringstream getHistory();

  // Mutators
  //---------------------------------------------------------------------------
  // addHistory()
  // Description: add transaction event to customer's transaction history
  // PRE: assumes customer exist
  // POST: a transaction event is added to the customer's transaction history
  void addHistory(string transaction); // add transaction to history

  //---------------------------------------------------------------------------
  // setCustomerInfo()
  // Description: sets the customer data fields
  // PRE: assumes that the data fields exist
  // POST: return true if the customer data fields are set
  bool setCustomerInfo(int cID, string first, string last);

  //---------------------------------------------------------------------------
  // setID()
  // Description: sets the customer ID
  // PRE: assumes customer's ID exist
  // POST: returns true if the customer ID is set
  bool setID(int cID);

  //---------------------------------------------------------------------------
  // setFirstName()
  // Description: sets the customer's first name
  // PRE: assumes customer's first name exist 
  // POST: returns true if the customer's first name is set
  bool setFirstName(string first);

  //---------------------------------------------------------------------------
  // setLastName()
  // Description: sets the customer's last name 
  // PRE: assumes customer's last name exist
  // POST: returns true if the customer's last name is set
  bool setLastName(string last);

private:


  string lastName;  // lastname of the customer
  string firstName; // firstname of the customer

  int customerID;        // unique user ID
  stack<string> history; // stack of transaction strings
  stack<string> storage; // manage reset of stack
};
#endif
