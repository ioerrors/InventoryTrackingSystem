////////////////////////////////transaction.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action types, is a parent class
//-----------------------------------------------------------------------------

class Transaction {
public:
    Transaction();              // constructor
    ~Transaction();             // destructor

    // Transaction* create(char type, int customerID, Movie*& m);   // create transactions
    //---------------------------------------------------------------------------
    // doTransaction()
    // Description: function overloaded in the children classes
    // PRE: transaction exists
    // POST: no action is taken in the virtual doTransaction();
    virtual void doTransaction(HashTable& customers, BSTree& movies);

    //---------------------------------------------------------------------------
    // setData()
    // Description: sets data fields
    // PRE: transaction
    // POST: function is not carried out except in children classes
    virtual void setData(int setCustomerID, string setMovieData);

};
