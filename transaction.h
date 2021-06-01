////////////////////////////////transaction.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action types, is a parent class
//-----------------------------------------------------------------------------

class Transaction {
public:

    //-----------------------------------------------------------------------------
    // Transaction DESTRUCTOR
    // Description: creates an empty Transaction
    // PRE: Memory is available for Transaction
    // POST: empty Transaction is created
    Transaction();          

    //-----------------------------------------------------------------------------
    // Transaction DESTRUCTOR
    // Description: deallocates all memory allocated for Transaction
    // PRE: Transaction exists
    // POST: All Transaction memory is freed
    ~Transaction();             

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
