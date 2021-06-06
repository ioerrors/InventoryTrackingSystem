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
    ~HashTable ();            // desctructor
    

    //find
    bool getCustomer (const int cID, Customer*&) const;            // get Customer
    
    //insert
    bool addCustomer(Customer*&);                                 // add Customer 

    //returns message digest, after padding
    string paddAndReturn();

private:


    struct KeyHasher
    {
      std::string operator()(const int& k) const
      {
        using std::string;
        string data;
        data = "thisisnotahashingalgorithm";
        //data = this.paddAndReturn();
        return data;
      }
    };

    //accepts customer ID converted to a string
    void sha1String(const string& s);
	//accepts customer ID converted to an istream
	void sha1StandardImplemenation(istream &is);


	void reset(uint32_t message[], std::string &buffer, uint64_t &transforms);

	void bufferToBlock(const std::string &buffer, uint32_t block[16]);
	static uint32_t rol(const uint32_t value, const size_t bits);


	uint32_t blk(const uint32_t block[16], const size_t i);

	void transform(uint32_t message[], uint32_t block[16], uint64_t &transforms);
	void R4(uint32_t block[16], const uint32_t v, uint32_t &w, const uint32_t x, const uint32_t y, uint32_t &z, const size_t i);
	void R3(uint32_t block[16], const uint32_t v, uint32_t &w, const uint32_t x, const uint32_t y, uint32_t &z, const size_t i);
	void R2(uint32_t block[16], const uint32_t v, uint32_t &w, const uint32_t x, const uint32_t y, uint32_t &z, const size_t i);
	void R1(uint32_t block[16], const uint32_t v, uint32_t &w, const uint32_t x, const uint32_t y, uint32_t &z, const size_t i);
	void R0(const uint32_t block[16], const uint32_t v, uint32_t &w, const uint32_t x, const uint32_t y, uint32_t &z, const size_t i);
    uint32_t message[5];
    string buffer;
    uint64_t transforms;

    unordered_map<int&, Customer, KeyHasher> mappy;
};
#endif // HASHTABLE_H
