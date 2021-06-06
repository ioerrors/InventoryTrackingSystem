////////////////////////////////hashTable.h file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This class is a data structure to hold customers
// in a quickly accessable format
//-----------------------------------------------------------------------------
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>


class HashTable {
    
HashTable () {

}

~HashTable (){
}          
    


    //find
    bool HashTable::getCustomer (const int cID, Customer*&) const {

    }            
    
    //insert
    bool HashTable::addCustomer(Customer*&) {

    }                             
    

    //accepts customer ID converted to an istream
    void sha1StandardImplemenation(istream &is);

    string paddAndReturn();

static uint32_t rol(const uint32_t value, const size_t bits) {
        return (value << bits) | (value >> (32 - bits));
    }


static uint32_t blk(const uint32_t block[16], const size_t i) {
    return rol(block[(i+13)&15] ^ block[(i+8)&15] ^ block[(i+2)&15] ^ block[i], 1);
}





void HashTable::sha1StandardImplemenation(std::istream &is) {
    while (true)
    {
        char sbuf[64];
        is.read(sbuf, 64 - buffer.size());
        buffer.append(sbuf, (std::size_t)is.gcount());
        if (buffer.size() != 64)
        {
            return;
        }
        uint32_t block[16];
        buffer_to_block(buffer, block);
        transform(message, block, transforms);
        buffer.clear();
    }
}



//returns message digest, after padding
string HashTable::paddAndReturn() {
    /* Total number of hashed bits */
    uint64_t total_bits = (transforms*64 + buffer.size()) * 8;

    /* Padding */
    buffer += (char)0x80;
    size_t orig_size = buffer.size();
    while (buffer.size() < 64)
    {
        buffer += (char)0x00;
    }

    uint32_t block[16];
    buffer_to_block(buffer, block);

    if (orig_size > 64 - 8)
    {
        transform(message, block, transforms);
        for (size_t i = 0; i < 16 - 2; i++)
        {
            block[i] = 0;
        }
    }

    /* Append total_bits, split this uint64_t into two uint32_t */
    block[16 - 1] = (uint32_t)total_bits;
    block[16 - 2] = (uint32_t)(total_bits >> 32);
    transform(message, block, transforms);

    /* Hex std::string */
    std::ostringstream result;
    for (size_t i = 0; i < sizeof(message) / sizeof(message[0]); i++)
    {
        result << std::hex << std::setfill('0') << std::setw(8);
        result << message[i];
    }

    /* Reset for next run */
    reset(message, buffer, transforms);

    return result.str();
}
