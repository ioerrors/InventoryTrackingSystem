/////////////////////////transactionFactory.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to build the action types
//-----------------------------------------------------------------------------
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>


#include "hashTable.h"
#include "BSTree.h"

//#include "transactionFactory.h"


class Transaction {
public:

    Transaction();              // constructor
    virtual ~Transaction();             // destructor



    //---------------------------------------------------------------------------
    // doTransaction()
    // Description: function overloaded in the children classes
    // PRE: transaction exists
    // POST: no action is taken in the virtual doTransaction();
    virtual bool doTransaction(HashTable& customers, BSTree& movies);

    //---------------------------------------------------------------------------
    // setData()
    // Description: sets data fields
    // PRE: transaction
    // POST: function is not carried out except in children classes
    virtual bool setData(string setMovieData);

};
#endif
