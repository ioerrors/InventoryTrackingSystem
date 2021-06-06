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


HashTable::HashTable () {
  reset(message, buffer, transforms);
  std::unordered_map<int, Customer, KeyHasher> mappy;
}

HashTable::~HashTable () {
  delete[] message;
  delete buffer;
  delete transforms;
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
  string hashMe = "" + data;
  sha1String(hashMe);
  mappy[data] = customer;
  reset(message, buffer, transforms);
  return true;
}                             
    

void reset(uint32_t message[], std::string &buffer, uint64_t &transforms)
{
    /* SHA1 initialization constants */
    message[0] = 0x67452301;
    message[1] = 0xefcdab89;
    message[2] = 0x98badcfe;
    message[3] = 0x10325476;
    message[4] = 0xc3d2e1f0;

    /* Reset counters */
    buffer = "";
    transforms = 0;
}



static uint32_t rol(const uint32_t value, const size_t bits) {
        return (value << bits) | (value >> (32 - bits));
    }


static uint32_t blk(const uint32_t block[16], const size_t i) {
    return rol(block[(i+13)&15] ^ block[(i+8)&15] ^ block[(i+2)&15] ^ block[i], 1);
}

//accepts customer ID, passes it converted as an istream
void SHA1::sha1String(const std::string &s)
{
    istringstream is(s);
    sha1StandardImplemenation(is);
}


//accepts customer ID converted to an istream
void HashTable::sha1StandardImplemenation(std::istream &is) {
  char sbuf[64];
  is.read(sbuf, 64 - buffer.size());
  buffer.append(sbuf, (std::size_t)is.gcount());
  uint32_t block[16];
  bufferToBlock(buffer, block);
  transform(message, block, transforms);
  buffer.clear();
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
    bufferToBlock(buffer, block);

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

static void R0(const uint32_t block[16], const uint32_t v, uint32_t &w, const uint32_t x, const uint32_t y, uint32_t &z, const size_t i)
{
    z += ((w&(x^y))^y) + block[i] + 0x5a827999 + rol(v, 5);
    w = rol(w, 30);
}


static void R1(uint32_t block[16], const uint32_t v, uint32_t &w, const uint32_t x, const uint32_t y, uint32_t &z, const size_t i)
{
    block[i] = blk(block, i);
    z += ((w&(x^y))^y) + block[i] + 0x5a827999 + rol(v, 5);
    w = rol(w, 30);
}


static void R2(uint32_t block[16], const uint32_t v, uint32_t &w, const uint32_t x, const uint32_t y, uint32_t &z, const size_t i)
{
    block[i] = blk(block, i);
    z += (w^x^y) + block[i] + 0x6ed9eba1 + rol(v, 5);
    w = rol(w, 30);
}


static void R3(uint32_t block[16], const uint32_t v, uint32_t &w, const uint32_t x, const uint32_t y, uint32_t &z, const size_t i)
{
    block[i] = blk(block, i);
    z += (((w|x)&y)|(w&x)) + block[i] + 0x8f1bbcdc + rol(v, 5);
    w = rol(w, 30);
}


static void R4(uint32_t block[16], const uint32_t v, uint32_t &w, const uint32_t x, const uint32_t y, uint32_t &z, const size_t i)
{
    block[i] = blk(block, i);
    z += (w^x^y) + block[i] + 0xca62c1d6 + rol(v, 5);
    w = rol(w, 30);
}


/*
 * Hash a single 512-bit block. This is the core of the algorithm.
 */
static void transform(uint32_t message[], uint32_t block[16], uint64_t &transforms)
{
    /* Copy message[] to working vars */
    uint32_t a = message[0];
    uint32_t b = message[1];
    uint32_t c = message[2];
    uint32_t d = message[3];
    uint32_t e = message[4];

    /* 4 rounds of 20 operations each. Loop unrolled. */
    R0(block, a, b, c, d, e,  0);
    R0(block, e, a, b, c, d,  1);
    R0(block, d, e, a, b, c,  2);
    R0(block, c, d, e, a, b,  3);
    R0(block, b, c, d, e, a,  4);
    R0(block, a, b, c, d, e,  5);
    R0(block, e, a, b, c, d,  6);
    R0(block, d, e, a, b, c,  7);
    R0(block, c, d, e, a, b,  8);
    R0(block, b, c, d, e, a,  9);
    R0(block, a, b, c, d, e, 10);
    R0(block, e, a, b, c, d, 11);
    R0(block, d, e, a, b, c, 12);
    R0(block, c, d, e, a, b, 13);
    R0(block, b, c, d, e, a, 14);
    R0(block, a, b, c, d, e, 15);
    R1(block, e, a, b, c, d,  0);
    R1(block, d, e, a, b, c,  1);
    R1(block, c, d, e, a, b,  2);
    R1(block, b, c, d, e, a,  3);
    R2(block, a, b, c, d, e,  4);
    R2(block, e, a, b, c, d,  5);
    R2(block, d, e, a, b, c,  6);
    R2(block, c, d, e, a, b,  7);
    R2(block, b, c, d, e, a,  8);
    R2(block, a, b, c, d, e,  9);
    R2(block, e, a, b, c, d, 10);
    R2(block, d, e, a, b, c, 11);
    R2(block, c, d, e, a, b, 12);
    R2(block, b, c, d, e, a, 13);
    R2(block, a, b, c, d, e, 14);
    R2(block, e, a, b, c, d, 15);
    R2(block, d, e, a, b, c,  0);
    R2(block, c, d, e, a, b,  1);
    R2(block, b, c, d, e, a,  2);
    R2(block, a, b, c, d, e,  3);
    R2(block, e, a, b, c, d,  4);
    R2(block, d, e, a, b, c,  5);
    R2(block, c, d, e, a, b,  6);
    R2(block, b, c, d, e, a,  7);
    R3(block, a, b, c, d, e,  8);
    R3(block, e, a, b, c, d,  9);
    R3(block, d, e, a, b, c, 10);
    R3(block, c, d, e, a, b, 11);
    R3(block, b, c, d, e, a, 12);
    R3(block, a, b, c, d, e, 13);
    R3(block, e, a, b, c, d, 14);
    R3(block, d, e, a, b, c, 15);
    R3(block, c, d, e, a, b,  0);
    R3(block, b, c, d, e, a,  1);
    R3(block, a, b, c, d, e,  2);
    R3(block, e, a, b, c, d,  3);
    R3(block, d, e, a, b, c,  4);
    R3(block, c, d, e, a, b,  5);
    R3(block, b, c, d, e, a,  6);
    R3(block, a, b, c, d, e,  7);
    R3(block, e, a, b, c, d,  8);
    R3(block, d, e, a, b, c,  9);
    R3(block, c, d, e, a, b, 10);
    R3(block, b, c, d, e, a, 11);
    R4(block, a, b, c, d, e, 12);
    R4(block, e, a, b, c, d, 13);
    R4(block, d, e, a, b, c, 14);
    R4(block, c, d, e, a, b, 15);
    R4(block, b, c, d, e, a,  0);
    R4(block, a, b, c, d, e,  1);
    R4(block, e, a, b, c, d,  2);
    R4(block, d, e, a, b, c,  3);
    R4(block, c, d, e, a, b,  4);
    R4(block, b, c, d, e, a,  5);
    R4(block, a, b, c, d, e,  6);
    R4(block, e, a, b, c, d,  7);
    R4(block, d, e, a, b, c,  8);
    R4(block, c, d, e, a, b,  9);
    R4(block, b, c, d, e, a, 10);
    R4(block, a, b, c, d, e, 11);
    R4(block, e, a, b, c, d, 12);
    R4(block, d, e, a, b, c, 13);
    R4(block, c, d, e, a, b, 14);
    R4(block, b, c, d, e, a, 15);

    /* Add the working vars back into message[] */
    message[0] += a;
    message[1] += b;
    message[2] += c;
    message[3] += d;
    message[4] += e;

    /* Count the number of transformations */
    transforms++;
}


static void bufferToBlock(const std::string &buffer, uint32_t block[16]) {
    /* Convert the std::string (byte buffer) to a uint32_t array (MSB) */
    for (size_t i = 0; i < 16; i++)
    {
        block[i] = (buffer[4*i+3] & 0xff)
                   | (buffer[4*i+2] & 0xff)<<8
                   | (buffer[4*i+1] & 0xff)<<16
                   | (buffer[4*i+0] & 0xff)<<24;
    }
}
