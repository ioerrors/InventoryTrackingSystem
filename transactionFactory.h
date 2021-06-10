/////////////////////////transactionFactory.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to build the action types
//-----------------------------------------------------------------------------
#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>

#include "history.h"
#include "inventory.h"
#include "return.h"
#include "borrow.h"
//#include "transactionFactory.h"

class TransactionFactory {
public:
  //---------------------------------------------------------------------------
  // TransactionFactory CONSTRUCTOR
  // Description: creates an empty Transaction
  // PRE: memory is available for Transaction
  // POST: empty Transaction is created
  TransactionFactory();  // constructor

  //---------------------------------------------------------------------------
  // Customer DESTRUCTOR
  // Description: deallocates all memory allocated for Transaction
  // PRE: Transaction exists
  // POST: all Transaction memory is freed
  ~TransactionFactory(); // destructor

  //---------------------------------------------------------------------------
  // getTransaction()
  // Description: returns constructor based on transaction type
  // PRE: Transaction type and constructor for type H, I, R, B exists
  // POST: a transaction constructor is returned if the
  //       movie type given is valid
  Transaction *getTransaction(string type);
};
#endif
