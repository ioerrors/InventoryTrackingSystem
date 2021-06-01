////////////////////////////////borrow.h file  ///////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a borrow class which is a type of transaction 
// child of the transaction class, inheriting from transaction
//-----------------------------------------------------------------------------

class Borrow: public Transaction {
public:

    //---------------------------------------------------------------------------
    // Borrow DESTRUCTOR
    // Description: deallocates all memory allocated for Borrow
    // PRE: Borrow exists
    // POST: All Borrow memory is freed    
    Borrow();

    //---------------------------------------------------------------------------
    // setData()
    // Description: sets data fields
    // PRE: return exists
    // POST: movieData is set to setMovieData, 
    //       and customerID is set to setCustomerID
    ~Borrow();
    
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
    // POST: movie is borrowed(stock reduced by one), 
    //       transation is added to customer history
    void doTransaction(HashTable& customers, BSTree& movies);
    
private:
    string movieData;               // string to track the movie to borrow
    int customerID;                 // customer responsible for the transaction
};