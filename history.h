////////////////////////////////history.h file  ///////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a history class which is an action type
// child and inheriting from Transaction class
//-----------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H

#include "BSTree.h"
#include "hashTable.h"
#include <iostream>
#include <sstream>

#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>


#include "transaction.h"


class History: public Transaction {
public:
    //---------------------------------------------------------------------------
    // History CONSTRUCTOR
    // Description: creates an empty History
    // PRE: Memory is available for History
    // POST: Empty History is created
    History();

    //---------------------------------------------------------------------------
    // History DESTRUCTOR
    // Description: deallocates all memory allocated for History
    // PRE: History exists
    // POST: All History memory is freed
    ~History();
    

    //---------------------------------------------------------------------------
    // setData()
    // Description: sets data field
    // PRE: history exists, customer exists
    // POST: movieData is ignored, 
    //       and customerID is set to setCustomerID
    bool setData(string setMovieData);
    
    //---------------------------------------------------------------------------
    // doTransaction()
    // Description: performs the action relevant to the correct customer
    // PRE: customer exists, movie is in stock
    // POST: transaction history for customer is printed
    bool doTransaction(HashTable& customers, BSTree& movies);
    
private:           
    int customerID;                 // customer responsible for the transaction
};
#endif
