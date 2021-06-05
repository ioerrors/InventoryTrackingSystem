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
bool Borrow::setData(string setMovieData) {
    stringstream ss(setMovieData); 
    string data;
    ss >> data;
    customerID = (int) data; //store customerID
    ss >> data; //clear media type
    data = "";

    //store rest of movieData as string
    while(!ss.eof()) {
        ss >> movieData;
    }
    return true;
}


//-----------------------------------------------------------------------------
// display()
// Description: displays command
// PRE: borrow exists
// POST: movieData and customerID are printed to out with borrow statement
bool Borrow::display() {
    cout << "Borrow:" << CustomerID << " " << movieData;
    return true;
}
       
//-----------------------------------------------------------------------------
// doTransaction()
// Description: performs the action relevant to the correct
//              movie and customer
// PRE: customer exists, movie is in stock
// POST: movie is borrowed(stock reduced by one), 
//       transation is added to customer history
bool Borrow::doTransaction(HashTable& customers, set<movie> movies) {
    Customer current;
    if (customers.getCustomer(customerID, current)) {
        cout << current.getHistory();
        return true;
    } else {
        cout << "Borrow: invalid customerID";
        return  false;
    }
}
