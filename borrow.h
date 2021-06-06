////////////////////////////////borrow.h file  ///////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a borrow class which is a type of transaction 
// child of the transaction class, inheriting from transaction
//-----------------------------------------------------------------------------
#ifndef BORROW_H
#define BORROW_H



#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>


#include "transaction.h"
#include "hashTable.h"


using namespace std;

class Borrow: public Transaction {
public:

    //---------------------------------------------------------------------------
    // Borrow CONSTRUCTOR
    // Description: creates an empty Borrow
    // PRE: Memory is available for Borrow
    // POST: Empty Borrow is created   
    Borrow();

    //---------------------------------------------------------------------------
    // Borrow DESTRUCTOR
    // Description: deallocates all memory allocated for Borrow
    // PRE: Borrow exists
    // POST: All Borrow memory is freed
    ~Borrow();
    
    //---------------------------------------------------------------------------
    // setData()
    // Description: sets data fields
    // PRE: borrow exists, 
    //      Format setMovieData = "B 2000 D F Sleepless in Seattle, 1993"   
    // POST: movieData is set to setMovieData, 
    //       and customerID is set to setCustomerID
    bool setData(string setMovieData);

 
    //---------------------------------------------------------------------------
    // display()
    // Description: displays command
    // PRE: borrow exists
    // POST: movieData and customerID are printed to out with borrow statement
    bool display();
           
    //---------------------------------------------------------------------------
    // doTransaction()
    // Description: performs the action relevant to the correct
    //              movie and customer
    // PRE: customer exists, movie is in stock
    // POST: movie is borrowed(stock reduced by one), 
    //       transation is added to customer history
    bool doTransaction(HashTable&, BSTree&);
    
private:
    string movieData;               // string to track the movie to borrow
    int customerID;                 // customer responsible for the transaction
};
#endif
