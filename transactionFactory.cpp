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

TransactionFactory::TransactionFactory() {}
TransactionFactory::~TransactionFactory() {
}

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
