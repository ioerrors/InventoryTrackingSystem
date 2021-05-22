////////////////////////////////inventory.h file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Group 1 on 05/19/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action type Inventory
// inherits from Transaction
//-----------------------------------------------------------------------------

class Inventory: public Transaction {
public:
    
    Inventory();             // constructor
    virtual ~Inventory();    // destructor
    virtual bool perform(MovieInventory&, CustomerInventory&);     // perform inventory

private:
    Movie* movie                 // Node to track the movies in the inventory
};