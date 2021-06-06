////////////////////////////////return.h file  ////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action type return which is a child of 
// and inherits from transaction class
//-----------------------------------------------------------------------------
#ifndef RETURN_H
#define RETURN_H

#include "BSTree.h"
#include "hashTable.h"
#include "history.h"
#include "customer.h"
#include "return.h"
#include <iostream>
#include <sstream>

#include "transaction.h"

using namespace std;
class Return: public Transaction {
public:

    //---------------------------------------------------------------------------
    // Return CONSTRUCTOR
    // Description: creates an empty Return
    // PRE: Memory is available for Return
    // POST: Empty Return is created   
    Return();

    //---------------------------------------------------------------------------
    // Return DESTRUCTOR
    // Description: deallocates all memory allocated for Return
    // PRE: Return exists
    // POST: All Return memory is freed
    ~Return();               
    
    
    //---------------------------------------------------------------------------
    // setData()
    // Description: sets data fields
    // PRE: return exists, Format setMovieData: "R 5000 D C 3 1971 Ruth Gordon"
    // POST: movieData is set to setMovieData, 
    //       and customerID is set to setCustomerID
    bool setData(string setMovieData);


    //---------------------------------------------------------------------------
    // display()
    // Description: displays command
    // PRE: return exists
    // POST: movieData and customerID are printed to out with Return statement
    bool display();

    //---------------------------------------------------------------------------
    // doTransaction()
    // Description: performs the action relevant to the correct
    //              movie and customer
    // PRE: customer exists, movie is in stock
    // POST: movie is Returned(stock incremented by one), 
    //       transation is added to customer history
    bool doTransaction(HashTable& customers, BSTree& movies);
    
private:
    string movieData;               // string to track the movie to Return
    int customerID;                 // customer responsible for the transaction
};
#endif
