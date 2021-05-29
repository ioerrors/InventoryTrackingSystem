////////////////////////////////history.h file  ///////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a history class which is an action type
// child and inheriting from Transaction class
//-----------------------------------------------------------------------------

class History: public Transaction {
public:
    History(int customerID);  // constructor
    virtual ~History();       // destructor
    
    
    //---------------------------------------------------------------------------
    // doTransaction()
    // Description: performs the action relevant to the correct customer
    // PRE: customer exists, movie is in stock
    // POST: transaction history for customer is printed
    void doTransaction(HashTable customers);
    
private:           
    int customerID;                 // customer responsible for the transaction
};
