////////////////////////////////transactioninventory.h file  //////////////////
//-----------------------------------------------------------------------------
// Created by Group 1 on 05/19/2021.
//-----------------------------------------------------------------------------
// This is a class to collect information about total transaction objects
// and provide access to the transaction data obects
//-----------------------------------------------------------------------------

class TransactionInventory {
public:
    TransactionInventory();               // constructor
    ~ TransactionInventory();              // destructor
    
Transaction* create(char type, int customerID, Movie*& m);   // create transactions
};
