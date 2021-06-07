////////////////////////////////inventory.cpp file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action type Inventory
// inherits from Transaction
//-----------------------------------------------------------------------------

#include <iostream>
#include <sstream>

#include "inventory.h"
#include "transaction.h"

using namespace std;

//-----------------------------------------------------------------------------
// Inventory CONSTRUCTOR
// Description: creates an empty Inventory
// PRE: Memory is available for Inventory
// POST: Empty Inventory is created
Inventory::Inventory() {}

//-----------------------------------------------------------------------------
// Inventory DESTRUCTOR
// Description: deallocates all memory allocated for Inventory
// PRE: Inventory exists
// POST: All Inventory memory is freed
Inventory::~Inventory() {}

//---------------------------------------------------------------------------
// doTransaction()
// Description: performs the action of printing inventory
// PRE: BSTree movies exists, is not null
// POST: movies in stock are printed
bool Inventory::doTransaction(HashTable &customers, BSTree &movies) {
  cout << "Inventory: " << endl;
  cout << movies;
  return true;
}

//---------------------------------------------------------------------------
// setData()
// Description: is irrelevant in this class
// PRE: Inventory exists
// POST: nothing changes
bool Inventory::setData(string setMovieData) { return false; }
