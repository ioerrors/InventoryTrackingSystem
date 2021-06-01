////////////////////////////////history.cpp file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a history class which is an action type
// child and inheriting from Transaction class
//-----------------------------------------------------------------------------


#include "BSTree.h"
#include "history.h"
#include <iostream>
#include <sstream>  
using namespace std;


//-----------------------------------------------------------------------------
// History CONSTRUCTOR
// Description: creates an empty History
// PRE: Memory is available for History
// POST: Empty History is created
History::History();  // constructor

//-----------------------------------------------------------------------------
// History DESTRUCTOR
// Description: deallocates all memory allocated for History
//              calls makeEmpty()
// PRE: History exists
// POST: All History memory is freed, objects deleted
History::~History();
    
H 5000
    //---------------------------------------------------------------------------
    // setData()
    // Description: sets data field
    // PRE: history exists, customer exists
    // POST: movieData is ignored, 
    //       and customerID is set to setCustomerID
    void History::setData(string setMovieData) {
        customerID << setMovieData;
    }
    
    //---------------------------------------------------------------------------
    // doTransaction()
    // Description: performs the action relevant to the correct customer
    // PRE: customer exists, movie is in stock
    // POST: transaction history for customer is printed
    void doTransaction(HashTable& customers, BSTree& movies) {
        Customer current;
        if (customers.getCustomer(customerID, current)) {
            current.
        }


    }
    
private:           
    int customerID;                 // customer responsible for the transaction
};
