////////////////////////////////borrow.h file  ///////////////////////////////
//-----------------------------------------------------------------------------
// Created by Group 1 on 05/19/2021.
//-----------------------------------------------------------------------------
// This is a borrow class which is a type of transaction 
// child of the transaction class, inheriting from transaction
//-----------------------------------------------------------------------------

class Borrow: public TransactionFactory {
public:
    Borrow(int, Movie*);  // constructor
    virtual ~Borrow();    // destructor
    virtual bool perform(MovieInventory&, CustomerInventory&);   // perform borrow movie
    
private:
    Movie* movie;                   // Node to track movies to borrow
    int customerID;                 // customer responsible for the transaction
};