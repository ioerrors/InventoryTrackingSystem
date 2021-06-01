////////////////////////////////return.h file  ////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action type return which is a child of 
// and inherits from transaction class
//-----------------------------------------------------------------------------

class Return: public Transaction {
public:
    Return();  // constructor
    ~Return();                         // destructor
    
    
    //---------------------------------------------------------------------------
    // setData()
    // Description: sets data fields
    // PRE: return exists
    // POST: movieData is set to setMovieData, 
    //       and customerID is set to setCustomerID
    void setData(string setMovieData);


    //---------------------------------------------------------------------------
    // display()
    // Description: displays command
    // PRE: return exists
    // POST: movieData and customerID are printed to out with Return statement
    void display();

    //---------------------------------------------------------------------------
    // doTransaction()
    // Description: performs the action relevant to the correct
    //              movie and customer
    // PRE: customer exists, movie is in stock
    // POST: movie is Returned(stock incremented by one), 
    //       transation is added to customer history
    void doTransaction(HashTable& customers, BSTree& movies);
    
private:
    string movieData;               // string to track the movie to borrow
    int customerID;                 // customer responsible for the transaction
};