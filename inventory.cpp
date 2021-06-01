////////////////////////////////inventory.cpp file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action type Inventory
// inherits from Transaction
//-----------------------------------------------------------------------------
#include "BSTree.h"
#include "HashTable.h"
#include "inventory.h"
#include <iostream>
#include <sstream>  
using namespace std;


//-----------------------------------------------------------------------------
// Inventory CONSTRUCTOR
// Description: creates an empty Inventory
// PRE: Memory is available for Inventory
// POST: Empty Inventory is created
Inventory::Inventory() {

}


//-----------------------------------------------------------------------------
// Inventory DESTRUCTOR
// Description: deallocates all memory allocated for Inventory
// PRE: Inventory exists
// POST: All Inventory memory is freed
Inventory::~Inventory() {

}

//---------------------------------------------------------------------------
// doTransaction()
// Description: performs the action of printing inventory
// PRE: BSTree movies exists, is not null
// POST: movies in stock are printed
void Inventory::doTransaction(HashTable& customers, BSTree& movies) {
    cout << "Inventory: " << endl;
    cout << movies;
}



//---------------------------------------------------------------------------
// setData()
// Description: is irrelevant in this class
// PRE: Inventory exists
// POST: nothing changes
void Inventory::setData(int setCustomerID, string setMovieData){
    
}   
    
 