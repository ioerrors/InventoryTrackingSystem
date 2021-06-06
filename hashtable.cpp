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
#include <string>
#include <stack>
#include <unordered_map>

#include "hashTable.h"
#include "BSTree.h"
#include "transaction.h"
#include "movieFactory.h"
#include "history.h"
#include "borrow.h"
#include "customer.h"

using namespace std;

HashTable::HashTable () {
  std::unordered_map<int, Customer*, KeyHasher> mappy;
}

HashTable::~HashTable () {
	delete mappy;
}          
    


//find
bool HashTable::getCustomer (const int cID, Customer*& setMe) const {
  string hashMe = "" + cID;
  setMe = mappy[hashMe];
  return true;
}            

//insert
bool HashTable::addCustomer(Customer*& customer) {
  int data = customer->getID();
  mappy[data] = customer;
  return true;
}                             
