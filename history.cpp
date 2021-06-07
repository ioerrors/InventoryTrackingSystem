////////////////////////////////history.cpp file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a history class which is an action type
// child and inheriting from Transaction class
//-----------------------------------------------------------------------------

#include <iostream>
#include <sstream>

#include "transaction.h"
#include "history.h"



using namespace std;


//-----------------------------------------------------------------------------
// History CONSTRUCTOR
// Description: creates an empty History
// PRE: Memory is available for History
// POST: Empty History is created
History::History() {
    customerID = 0;
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
    customerID = stoi(data); //store customerID
    return true;
}

//-----------------------------------------------------------------------------
// doTransaction()
// Description: performs the action relevant to the correct customer
// PRE: customer exists, movie is in stock
// POST: transaction history for customer is printed
//        ASSUMPTION: History is not needed to be added as a transaction
//                    to the transaction history for a customer
bool History::doTransaction(HashTable& customers, BSTree& movies) {
    Customer* current;
    if (customers.getCustomer(customerID, current)) {
    	stringstream out = current->getHistory();
        while(!out.eof()) {
        	string data;
        	out >> data;
        	cout << data;
        }
        return true;
    } else {
        cout << "History: invalid customerID";
        return false;
    }
}
