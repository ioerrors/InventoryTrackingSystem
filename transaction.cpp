////////////////////////////////transaction.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action types, is a parent class
//-----------------------------------------------------------------------------

#include "transaction.h"

#include <iostream>
#include <sstream>
#include <stack>
#include "history.h"
#include "inventory.h"
#include "return.h"
#include "borrow.h"


Transaction::Transaction() {}

Transaction::~Transaction() {}


//---------------------------------------------------------------------------
// doTransaction()
// Description: function overloaded in the children classes
// PRE: transaction exists
// POST: no action is taken in the virtual doTransaction();
bool Transaction::doTransaction(HashTable& customers, BSTree& movies) { return false; }

//---------------------------------------------------------------------------
// setData()
// Description: sets data fields
// PRE: transaction
// POST: function is not carried out except in children classes
bool Transaction::setData(string setMovieData) { return false; }

