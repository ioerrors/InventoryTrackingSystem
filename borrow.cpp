////////////////////////////////borrow.h file  ///////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a borrow class which is a type of transaction 
// child of the transaction class, inheriting from transaction
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Borrow CONSTRUCTOR
// Description: creates an empty Borrow
// PRE: Memory is available for Borrow
// POST: Empty Borrow is created
Borrow::Borrow() {
    movieData = "";
    customerID = NULL;     
}


//-----------------------------------------------------------------------------
// Borrow DESTRUCTOR
// Description: deallocates all memory allocated for Borrow
// PRE: Borrow exists
// POST: All Borrow memory is freed
Borrow::~Borrow() {
    delete movieData;
    delete customerID;
}


//-----------------------------------------------------------------------------
// setData()
// Description: sets data fields
// PRE: borrow exists, 
//      Format setMovieData = "2000 D F Sleepless in Seattle, 1993"   
// POST: movieData is set to setMovieData, 
//       and customerID is set to setCustomerID
void Borrow::setData(string setMovieData) {
    //turn into stringstream?
    customerID << setMovieData;
    movieData << setMovieData;
}


//-----------------------------------------------------------------------------
// display()
// Description: displays command
// PRE: borrow exists
// POST: movieData and customerID are printed to out with borrow statement
void Borrow::display() {

}
       
//-----------------------------------------------------------------------------
// doTransaction()
// Description: performs the action relevant to the correct
//              movie and customer
// PRE: customer exists, movie is in stock
// POST: movie is borrowed(stock reduced by one), 
//       transation is added to customer history
void Borrow::doTransaction(HashTable& customers, BSTree& movies) {

}
