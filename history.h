////////////////////////////////history.h file  ///////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a history class which is an action type
// child and inheriting from Transaction class
//-----------------------------------------------------------------------------

class History: public Transaction {
public:
    History();  // constructor
    ~History();       // destructor
    

    //---------------------------------------------------------------------------
    // setData()
    // Description: sets data field
    // PRE: history exists, customer exists
    // POST: movieData is ignored, 
    //       and customerID is set to setCustomerID
    void setData(string setMovieData);
    
    //---------------------------------------------------------------------------
    // doTransaction()
    // Description: performs the action relevant to the correct customer
    // PRE: customer exists, movie is in stock
    // POST: transaction history for customer is printed
    void doTransaction(HashTable& customers, BSTree& movies);
    
private:           
    int customerID;                 // customer responsible for the transaction
};
