////////////////////////////////hashTable.h file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This class is a data structure to hold customers
// in a quickly accessable format
// Implemented hashing algorithm based on public domain worked implemenations
// of the now defunct SHA1 standard
//-----------------------------------------------------------------------------

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include "customer.h"

class HashTable {

public:
  //---------------------------------------------------------------------------
  // Hashtable CONSTRUCTOR
  // Description: Creates and empty HashTable object  
  // PRE: Memory is available for HashTable object
  // POST: New empty HashTable object is created
  HashTable();

  //---------------------------------------------------------------------------
  // Hashtable DESTRUCTOR
  // Description: Frees memory in use by HashTable, deletes hashtable
  // PRE: HashTable exists 
  // POST: Memory freed, all objects destructors are called
  ~HashTable();

  //---------------------------------------------------------------------------
  // getCustomer()
  // Description: finds a customer in the HashTable
  // PRE: HashTable Exists
  // POST: Customer, if exists, is found by hashing the cID parameter, and
  //       the found customer object is set to the second param (returns true)
  //       if customer is not found, returns false 
  bool getCustomer(const int cID, Customer *&) const;

  //---------------------------------------------------------------------------
  // addCustomer()
  // Description: Adds a customer to the HashTable
  // PRE: Customer object exists, HashTable exists
  // POST: returns true if successfully added customer 
  bool addCustomer(Customer *&);

private:
  
  //---------------------------------------------------------------------------
  // KeyHasher HASHING IMPLEMENTATION
  // Description: custom hashing algorithm for our HashTable
  // PRE: HashTable Exists, unordered Map is passed this hasher as a param
  // POST: Key int is hashed, and returned
  struct KeyHasher {
    std::size_t operator()(const int &k) const {
      using std::size_t;
      using std::hash;
      // using Customer;

      // write hashing code here
      int res = k ^ (k + 41);
      if (res % 2 == 0) {
        res = (res + 41) ^ k;
      }
      res = res * 62 + k;
      res = res / 3 - k / 2;

      // return value below
      size_t final = res;
      return final;
    }
  };

  std::unordered_map<int, Customer *, KeyHasher> mappy;
};
#endif // HASHTABLE_H
