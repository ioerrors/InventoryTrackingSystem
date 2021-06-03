////////////////////////////////return.h file  ////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action type return which is a child of 
// and inherits from transaction class
//-----------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Return CONSTRUCTOR
// Description: creates an empty Return
// PRE: Memory is available for Return
// POST: Empty Return is created  
Return::Return() {
    movieData = "";
    customerID = NULL;
}

//---------------------------------------------------------------------------
// Return DESTRUCTOR
// Description: deallocates all memory allocated for Return
// PRE: Return exists
// POST: All Return memory is freed
Return::~Return() {
    delete movieData;
    delete customerID;
}


//---------------------------------------------------------------------------
// setData()
// Description: sets data fields
// PRE: return exists, Format setMovieData: "R 5000 D C 3 1971 Ruth Gordon"
// POST: movieData is set to setMovieData, 
//       and customerID is set to setCustomerID
void Return::setData(string setMovieData) {

}


//---------------------------------------------------------------------------
// display()
// Description: displays command
// PRE: return exists
// POST: movieData and customerID are printed to out with Return statement
void Return::display() {

}

//---------------------------------------------------------------------------
// doTransaction()
// Description: performs the action relevant to the correct
//              movie and customer
// PRE: customer exists, movie is in stock
// POST: movie is Returned(stock incremented by one), 
//       transation is added to customer history
void Return::doTransaction(HashTable& customers, BSTree& movies) {

}
/*    
private:
    string movieData;               // string to track the movie to borrow
    int customerID;                 // customer responsible for the transaction
};
*/