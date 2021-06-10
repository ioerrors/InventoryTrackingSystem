/////////////////////////transactionFactory.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to build the action types
//-----------------------------------------------------------------------------
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

#include "borrow.h"
#include "history.h"
#include "inventory.h"
#include "return.h"
#include "transactionFactory.h"

//-----------------------------------------------------------------------------
// TransactionFactory CONSTRUCTOR
// Description: creates an empty TransactionFactor
// PRE: memory is available for TransactionFactor
// POST: empty TransactionFactor is created
TransactionFactory::TransactionFactory() {}

//-----------------------------------------------------------------------------
// Customer DESTRUCTOR
// Description: deallocates all memory allocated for TransactionFactory
// PRE: TransactionFactory exists
// POST: all TransactionFactory memory is freed
TransactionFactory::~TransactionFactory() {}


//-----------------------------------------------------------------------------
// getTransaction()
// Description: returns constructor based on transaction type
// PRE: Transaction type and constructor for type H, I, R, B exists
// POST: a transaction constructor is returned if the
//       movie type given is valid
Transaction *TransactionFactory::getTransaction(string type) {
  if (type == "H") {
    return new History();
  } else if (type == "I") {
    return new Inventory();
  } else if (type == "R") {
    return new Return();
  } else if (type == "B") {
    return new Borrow();
  } else {
    return nullptr;
  }
}
