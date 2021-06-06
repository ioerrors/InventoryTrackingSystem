////////////////////////////////borrow.cpp file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a borrow class which is a type of transaction 
// child of the transaction class, inheriting from transaction
//-----------------------------------------------------------------------------
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>

#include "borrow.h"
#include "movieFactory.h"

using namespace std;

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
  movieData = ss.str();
  return true;
}


//-----------------------------------------------------------------------------
// display()
// Description: displays command
// PRE: borrow exists
// POST: movieData and customerID are printed to out with borrow statement
bool Borrow::display() {
  cout << "Borrow: " << customerID << " " << movieData;
  return true;
}
       
//-----------------------------------------------------------------------------
// doTransaction()
// Description: performs the action relevant to the correct
//              movie and customer
// PRE: customer exists, movie is in stock
// POST: movie is borrowed(stock reduced by one), 
//       transation is added to customer history
bool Borrow::doTransaction(HashTable& customers, BSTree& movies) {
  Customer* current;
  if (customers.getCustomer(customerID, current)) {
    current->addHistory("Borrow " + movieData);
    Movie* foundMe;
   
    MovieFactory makeType;
    stringstream ss(movieData); 
    string data;
    ss >> data;
    char type = data;
    Movie* findMe = makeType.getMovie(type);
    
    if (data == "C") {
      data = "";
      string month;
      ss >> month;
      string year;
      ss >> year;

      getline(ss, data);

      //Hal Ashby, Harold and Maude, Ruth Gordon 3 1971
      string movieFakeData = "Hal Ashby, Harold and Maude, " 
                           + data  + " " + month + " " + year;
      findMe->setData(movieFakeData);
    } 
    //Command "Nancy Savoca, Dogfight,"
    //movie "Steven Spielberg, Schindler's List, 1993"
    else if (data == "D") {
      data = "";
      getline(ss, data);
      string movieFakeData = data + " 1993";
      findMe->setData(movieFakeData);
    } 
    //Command "Annie Hall, 1977"
    //movie "Steven Spielberg, Schindler's List, 1993"
    else if (data == "F") {
      data = "";
      getline(ss, data);
      string movieFakeData = "Fake Director," + data;
      findMe->setData(movieFakeData);
    } else {
      cout << "Borrow failed: invalid Movie type";
      return false;
    }
    if (movies.retrieve(*findMe, foundMe) ) {
      if (foundMe->subStock(1)) {
        current->addHistory("Borrow: " + movieData);
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
