////////////////////////////////history.h file  ///////////////////////////////
//-----------------------------------------------------------------------------
// Created by Group 1 on 05/19/2021.
//-----------------------------------------------------------------------------
// This is a history class which is an action type
// child and inheriting from Transaction class
//-----------------------------------------------------------------------------

class History: public Transaction {
public:
    
    History(int);            // constructor
    virtual ~History();      // destructor
    
    virtual bool perform(MovieInventory&, CustomerInventory&);  // perform history
    
private:
    Movie* movie    // Node to track movies for history
    int customerID; // customer responsible for the transaction
};