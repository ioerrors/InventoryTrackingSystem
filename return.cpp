////////////////////////////////return.cpp file  //////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the action type return which is a child of 
// and inherits from transaction class
//-----------------------------------------------------------------------------


#include "BSTree.h"
#include "hashTable.h"
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
  movieData = ss.str()
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
    current.addHistory("Return " + movieData);
    Movie* foundMe;
   
    MovieFactory makeType = new MovieFactory();
    stringstream ss(movieData); 
    string data;
    ss >> data;
    Movie findMe = makeType.getMovie(data);
    data = "";
    //store rest of movieData as string
    data = ss.str();
    findMe.setData(data);


    if (data == "C") {
      data = "";
      string month;
      ss >> month;
      string year;
      ss >> year;

      getline(ss, data);

      // fake date to conform to expected format:
      // "Hal Ashby, Harold and Maude, Ruth Gordon 3 1971"
      string movieFakeData = "Hal Ashby, Harold and Maude, " 
                           + data  + " " + month + " " + year;
      findMe.setData(movieFakeData);
    } 
    // Command format "Nancy Savoca, Dogfight,"
    // movie format "Steven Spielberg, Schindler's List, 1993"
    else if (data == "D") {
      data = "";
      getline(ss, data);
      string movieFakeData = data + " 1993";
      findMe.setData(movieFakeData);
    } 
    // Command format "Annie Hall, 1977"
    // movie format  "Steven Spielberg, Schindler's List, 1993"
    else if (data == "F") {
      data = "";
      getline(ss, data);
      string movieFakeData = "Fake Director," + data;
      findMe.setData(movieFakeData);
    } else {
      cout << "Return failed: invalid Movie type";
      return false;
    }


    //find movie
    if (movies.retrieve(findMe, foundMe) ) {
      int x = 0;
      data = "";
      ostream findBorrow << current.getHistory();

      //check if borrowed
      while(std::getline(findBorrow, data)) {
        if (data = "Borrow " + movieData) {
            x--;
        }
        else if (data = "Return " + movieData) {
            x++;
        }
      }
      // at this moment:
      // if x = 0, all copies of this movie that were
      //           borrowed by this customer are already returned.
      // if x < 0, at least one copy of this movie 
      //           is borrowed by this customer and can be returned
      // x is never > 0
      if (x < 0) {
        foundMe.addStock(1);
        current.addHistory("Return: " + movieData);
        return true;
      } else {
        cout << "Return failed: movie not borrowed or already returned";
        return false; 
      }
    } else {
      cout << "Return failed: movie not found";
      return  false;
    }
  } else {
    cout << "Return failed: invalid customerID";
    return  false;
  }
}

