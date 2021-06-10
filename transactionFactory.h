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


class TransactionFactory {
public:
  //---------------------------------------------------------------------------
  // TransactionFactory CONSTRUCTOR
  // Description: creates an empty TransactionFactor
  // PRE: memory is available for TransactionFactor
  // POST: empty TransactionFactor is created
  TransactionFactory(); 

  //---------------------------------------------------------------------------
  // Customer DESTRUCTOR
  // Description: deallocates all memory allocated for TransactionFactory
  // PRE: TransactionFactory exists
  // POST: all TransactionFactory memory is freed
  ~TransactionFactory();

  //---------------------------------------------------------------------------
  // getTransaction()
  // Description: returns constructor based on transaction type
  // PRE: Transaction type and constructor for type H, I, R, B exists
  // POST: a transaction constructor is returned if the
  //       movie type given is valid
  Transaction *getTransaction(string type);
};
#endif
