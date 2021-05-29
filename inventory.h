////////////////////////////////inventory.h file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action type Inventory
// inherits from Transaction
//-----------------------------------------------------------------------------

class Inventory: public Transaction {
public:
    Inventory();             // constructor
    virtual ~Inventory();    // destructor
    
    
    //---------------------------------------------------------------------------
    // doTransaction()
    // Description: performs the action of printing inventory
    // PRE: BSTree movies exists, is not null
    // POST: movies in stock are printed
    void doTransaction(BSTree movies);
};