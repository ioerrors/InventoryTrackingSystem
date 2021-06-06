////////////////////////////////transaction.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action types, is a parent class
//-----------------------------------------------------------------------------
#include "BSTree.h"
#include "hashTable.h"
#include "transaction.h"
#include "movieFactory.h"
#include "history.h"
#include "borrow.h"
#include "customer.h"
#include <iostream>
#include <sstream>
#include <stack>

//---------------------------------------------------------------------------
// doTransaction()
// Description: function overloaded in the children classes
// PRE: transaction exists
// POST: no action is taken in the virtual doTransaction();
virtual bool Transaction::doTransaction(HashTable& customers, BSTree& movies){
	return false;
}

//---------------------------------------------------------------------------
// setData()
// Description: sets data fields
// PRE: transaction
// POST: function is not carried out except in children classes
virtual bool Transaction::setData(string setMovieData) {
	return false;
}

