////////////////////////////////transaction.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action types, is a parent class
//-----------------------------------------------------------------------------

#include "transaction.h"

#include "borrow.h"
#include "history.h"
#include "inventory.h"
#include "return.h"
#include <iostream>
#include <sstream>
#include <stack>

//-----------------------------------------------------------------------------
// Transaction CONSTRUCTOR
// Description: creates an empty Transaction
// PRE: memory is available for Transaction
// POST: empty Transaction is created
Transaction::Transaction() {}

//-----------------------------------------------------------------------------
// Transaction DESTRUCTOR
// Description: deallocates all memory allocated for Transaction
// PRE: Transaction exists
// POST: all Transaction memory is freed
Transaction::~Transaction() {}

//-----------------------------------------------------------------------------
// doTransaction()
// Description: function overloaded in the children classes
// PRE: transaction exists
// POST: no action is taken in the virtual doTransaction();
bool Transaction::doTransaction(HashTable &customers, BSTree &movies) {
  return (*this).doTransaction(customers, movies);
}

//-----------------------------------------------------------------------------
// setData()
// Description: sets data fields
// PRE: transaction
// POST: function is not carried out except in children classes
bool Transaction::setData(string setMovieData) {
  return (*this).setData(setMovieData);
}
