////////////////////////////////hashTable.cpp file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This class is a data structure to hold customers
// in a quickly accessable format
//-----------------------------------------------------------------------------
// Implementation of hash functions based on public domain
// Standardized and somewhat broken now
// sha1 hashing implementations
// it is still my favorite hashing algorithm though
//-----------------------------------------------------------------------------
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

#include "BSTree.h"
#include "borrow.h"
#include "customer.h"
#include "hashTable.h"
#include "history.h"
#include "movieFactory.h"
#include "transaction.h"
#include <unordered_map>

using namespace std;


//-----------------------------------------------------------------------------
// Hashtable CONSTRUCTOR
// Description: Creates and empty HashTable object  
// PRE: Memory is available for HashTable object
// POST: New empty HashTable object is created
HashTable::HashTable() { std::unordered_map<int, Customer *, KeyHasher> mappy; }


//-----------------------------------------------------------------------------
// Hashtable DESTRUCTOR
// Description: Frees memory in use by HashTable, deletes hashtable
// PRE: HashTable exists 
// POST: Memory freed, all objects destructors are called
HashTable::~HashTable() { mappy.clear(); }

//-----------------------------------------------------------------------------
// getCustomer()
// Description: finds a customer in the HashTable
// PRE: HashTable Exists
// POST: Customer, if exists, is found by hashing the cID parameter, and
//       the found customer object is set to the second param (returns true)
//       if customer is not found, returns false 
bool HashTable::getCustomer(const int hashMe, Customer *&setMe) const {
  std::unordered_map<int, Customer *, KeyHasher>::const_iterator find =
      mappy.find(hashMe);
  if (find != mappy.end()) {
    setMe = find->second;
  } else {
    return false;
  }
  if (setMe == nullptr) {
    return false;
  } else {
    return true;
  }
}


//-----------------------------------------------------------------------------
// addCustomer()
// Description: Adds a customer to the HashTable
// PRE: Customer object exists, HashTable exists
// POST: returns true if successfully added customer 
bool HashTable::addCustomer(Customer *&cust) {
  int hashMe = cust->getID();
  mappy.insert({ hashMe, cust });

  // For Testing
  // cout << endl << "Hash Table of Customers, after add of: " << cust->getID() <<
  // " " << cust->getName() << endl; for (auto const &pair : mappy) { cout <<
  // pair.first <<  " = " << pair.second->getID() <<  " " << pair.second->getName()
  // << endl;
  // }

  return true;
}
