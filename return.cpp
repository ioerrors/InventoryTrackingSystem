////////////////////////////////return.cpp file  //////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action type return which is a child of 
// and inherits from transaction class
//-----------------------------------------------------------------------------


#include "BSTree.h"
#include "HashTable.h"
#include "history.h"
#include "customer.h"
#include <iostream>
#include <sstream>  
using namespace std;

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
// PRE: return exists, Format setMovieData: "5000 D C 3 1971 Ruth Gordon"
// POST: movieData is set to setMovieData, 
//       and customerID is set to setCustomerID
bool Return::setData(string setMovieData) {
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


//---------------------------------------------------------------------------
// display()
// Description: displays command
// PRE: return exists
// POST: movieData and customerID are printed to out with Return statement
bool Return::display() {
    cout << "Return:" << CustomerID << " " << movieData;
    return true;
}   

//---------------------------------------------------------------------------
// doTransaction()
// Description: performs the action relevant to the correct
//              movie and customer
// PRE: customer exists, movie is in stock
// POST: movie is Returned(stock incremented by one), 
//       transation is added to customer history
bool Return::doTransaction(HashTable& customers, BSTree& movies) {
  Customer current;
  if (customers.getCustomer(customerID, current)) {
    current.addHistory("Borrow " + movieData);
    Movie* foundMe;
   
    MovieFactory makeType = new MovieFactory();
    stringstream ss(movieData); 
    string data;
    ss >> data;
    Movie findMe = makeType.getMovie(data);
    data = "";
    //store rest of movieData as string
    while(!ss.eof()) {
        ss >> data;
    }
    findMe.setData(data);

    if (movies.retrieve(findMe, foundMe) ) {
      if (foundMe.borrowStock(1)) {
        current.addHistory("Borrow: " + movieData);
        return true;
      } else {
        cout << "Borrow failed: not enough in stock";
        return false; 
      }
    } else {
      cout << "Borrow failed: movie not found";
      return  false;
    }
  } else {
      cout << "Borrow failed: invalid customerID";
      return  false;
  }
}

