////////////////////////////////inventory.h file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action type Inventory
// inherits from Transaction
//-----------------------------------------------------------------------------
#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <sstream>

#include "transaction.h"
#include "hashTable.h"
#include "BSTree.h"

using namespace std;

class Inventory: public Transaction {
public:
    
    //---------------------------------------------------------------------------
    // Inventory CONSTRUCTOR
    // Description: creates an empty Inventory
    // PRE: Memory is available for Inventory
    // POST: Empty Inventory is created
    Inventory();

    //---------------------------------------------------------------------------
    // Inventory DESTRUCTOR
    // Description: deallocates all memory allocated for Inventory
    // PRE: Inventory exists
    // POST: All Inventory memory is freed
    ~Inventory();

    //---------------------------------------------------------------------------
    // doTransaction()
    // Description: performs the action of printing inventory
    // PRE: BSTree movies exists, is not null
    // POST: movies in stock are printed
    bool doTransaction(HashTable& customers, BSTree& movies);

    //---------------------------------------------------------------------------
    // setData()
    // Description: is irrelevant in this class
    // PRE: Inventory exists
    // POST: nothing changes
    bool setData(string setMovieData);
    
};
#endif
