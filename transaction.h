////////////////////////////////transaction.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Group 1 on 05/19/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action types, is a parent class
//-----------------------------------------------------------------------------

class Transaction {
public:
    Transaction();               // constructor
    ~ Transaction();             // destructor

    Transaction* create(char type, int customerID, Movie*& m);   // create transactions

private:
    Movie* movie                 // Node to track movies
    char transType               // transaction type of movies       
};
