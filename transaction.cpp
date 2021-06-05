////////////////////////////////transaction.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action types, is a parent class
//-----------------------------------------------------------------------------

class Transaction {
public:

    //-----------------------------------------------------------------------------
    // Transaction CONSTRUCTOR
    // Description: creates an empty Transaction
    // PRE: Memory is available for Transaction
    // POST: empty Transaction is created
    Transaction() {

    }                      

    //---------------------------------------------------------------------------
    // doTransaction()
    // Description: function overloaded in the children classes
    // PRE: transaction exists
    // POST: no action is taken in the virtual doTransaction();
    virtual bool doTransaction(HashTable& customers, BSTree& movies){
        return false;
    }

    //---------------------------------------------------------------------------
    // setData()
    // Description: sets data fields
    // PRE: transaction
    // POST: function is not carried out except in children classes
    virtual bool setData(string setMovieData) {
        return false;
    }

};
