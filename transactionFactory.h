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
  TransactionFactory();  // constructor
  ~TransactionFactory(); // destructor

  Transaction *getTransaction(string type);
};
#endif
