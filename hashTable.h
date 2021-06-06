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
    
  HashTable ();           
  ~HashTable ();            // destructor
  

  //find
  bool getCustomer (const int cID, Customer*&) const;            // get Customer
  
  //insert
  bool addCustomer(Customer*&);                                 // add Customer 

  //returns message digest, after padding
  string paddAndReturn();

private:
  struct Key
  {
    int x;
    bool operator==(const Key &other) const
    { return (x == other.x);
    }
  };
  struct KeyHasher {
    std::size_t operator()(const Key& k) const
    {
    using std::size_t;
    using std::hash;
    using std::string;

    //write hashing code here
    int res = k.x^(k.x + 42);
    res = res * 62 + KeyHasher()(k);
    res = res / 3 + KeyHasher()(k);
    res = res + 42 + KeyHasher()(k);
    //return value below
    size_t final = res;
    return final;
    }
  };


  std::unordered_map<Key, Customer*, KeyHasher> mappy;
};
#endif // HASHTABLE_H
