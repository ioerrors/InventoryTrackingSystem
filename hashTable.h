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

class HashTable {
public:
    
    HashTable ();           
    ~HashTable ();            // desctructor
    

    //find
    bool getCustomer (const int cID, Customer*&) const;            // get Customer
    
    //insert
    bool addCustomer(Customer*&);                                 // add Customer 
    
private:
	//accepts customer ID converted to an istream
	void sha1StandardImplemenation(istream &is);
	//returns message digest, after padding
	string paddAndReturn();

	static void reset(uint32_t message[], std::string &buffer, uint64_t &transforms);


	static uint32_t rol(const uint32_t value, const size_t bits);


	static uint32_t blk(const uint32_t block[16], const size_t i);


	void sha1StandardImplemenation(std::istream &is);

    uint32_t message[5];
    string buffer;
    uint64_t transforms;
};
#endif // HASHTABLE_H