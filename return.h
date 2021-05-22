////////////////////////////////return.h file  ////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Group 1 on 05/19/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action type return which is a child of 
// and inherits from transaction class
//-----------------------------------------------------------------------------

class Return: public Transaction {
public:
    Return(int, Movie*);     // constructor
    virtual ~Return();       // destructor
    int getCustomerID();     // get ID of the customer of the transaction
    virtual bool perform(MovieInventory&, CustomerInventory&);  // perform Return movie
    
private:
    Movie* movie;            // movie to Return
    int customerID;          // customer responsible for the transaction
};