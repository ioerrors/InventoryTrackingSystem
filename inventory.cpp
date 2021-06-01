////////////////////////////////inventory.h file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action type Inventory
// inherits from Transaction
//-----------------------------------------------------------------------------

class Inventory: public Transaction {
public:
    Inventory();     // constructor
    ~Inventory();    // destructor

    //---------------------------------------------------------------------------
    // doTransaction()
    // Description: performs the action of printing inventory
    // PRE: BSTree movies exists, is not null
    // POST: movies in stock are printed
    void doTransaction(HashTable& customers, BSTree& movies);



    //---------------------------------------------------------------------------
    // setData()
    // Description: is irrelevant in this class
    // PRE: Inventory exists
    // POST: nothing changes
    virtual void setData(int setCustomerID, string setMovieData);   
    
};