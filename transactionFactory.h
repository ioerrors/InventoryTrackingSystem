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


#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "inventory.h"
#include "history.h"
//#include "transactionFactory.h"


class TransactionFactory {
public:

    TransactionFactory();              // constructor
    virtual ~TransactionFactory();             // destructor

    Transaction* getTransaction(const char type) {
        if(type == 'H') {
            return new History();
        } else if (type == 'I') {
            return new Inventory();                
        } else if (type == 'R') {
            return new Return();
        } else if (type == 'B') {
            return new Borrow();
        } else {
            throw;
        }
    }

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
