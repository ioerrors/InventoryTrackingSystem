////////////////////////////////hashTable.h file  /////////////////////////////
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

HashTable::HashTable() {
  // std::unordered_map<int, Customer*, KeyHasher> mappy;
}

HashTable::~HashTable() {}

// find
bool HashTable::getCustomer(const int cID, Customer *&setMe) const {
  Key hashMe;
  hashMe.x = cID;
  std::unordered_map<Key, Customer *, KeyHasher>::const_iterator got =
      mappy.find(hashMe);
  setMe = got->second;
  if (setMe == nullptr) {
    return false;
  } else {
    return true;
  }
}

// insert
bool HashTable::addCustomer(Customer *&cust) {
  int data = cust->getID();
  Key hashMe;
  hashMe.x = data;
  mappy.insert({hashMe, cust});
  return true;
}
