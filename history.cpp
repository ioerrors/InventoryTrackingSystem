////////////////////////////////history.cpp file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a history class which is an action type
// child and inheriting from Transaction class
//-----------------------------------------------------------------------------


#include "BSTree.h"
#include "HashTable.h"
#include "history.h"
#include <iostream>
#include <sstream>  
using namespace std;


//-----------------------------------------------------------------------------
// History CONSTRUCTOR
// Description: creates an empty History
// PRE: Memory is available for History
// POST: Empty History is created
History::History() {
    customerID = NULL;
}

//-----------------------------------------------------------------------------
// History DESTRUCTOR
// Description: deallocates all memory allocated for History
// PRE: History exists
// POST: All History memory is freed
History::~History() {
    delete customerID;
}
    
  
//-----------------------------------------------------------------------------
// setData()
// Description: sets data field
// PRE: history exists type is already parsed
//      and setMovieData format:  " XXXX"
// POST: 
bool History::setData(string setMovieData) {
    stringstream ss(setMovieData); 
    string data;
    ss >> data;
    customerID = (int) data; //store customerID
    return true;
}

//-----------------------------------------------------------------------------
// doTransaction()
// Description: performs the action relevant to the correct customer
// PRE: customer exists, movie is in stock
// POST: transaction history for customer is printed
bool History::doTransaction(HashTable& customers, BSTree& movies) {
    Customer current;
    if (customers.getCustomer(customerID, current)) {
        cout << current.getHistory();
        return true;
    } else {
        cout << "History: invalid customerID";
        return false;
    }
}
