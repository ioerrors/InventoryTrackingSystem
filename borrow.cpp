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
#include <stack>
#include <string>

#include "BSTree.h"
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
  customerID = 0;
}

Borrow::~Borrow() {}
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

  customerID = stoi(data); // store customerID
  data = "";
  ss >> data; // clear media type
  data = "";

  // store rest of movieData as string
  getline(ss, movieData);
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
bool Borrow::doTransaction(HashTable &customers, BSTree &movies) {
  Customer *current;
  if (customers.getCustomer(customerID, current)) {
    // current->addHistory("Borrow " + movieData);
    Movie *foundMe;

    MovieFactory *makeType = new MovieFactory();
    stringstream ss(movieData);
    string data;
    ss >> data;
    // char type = data;
    Movie *findMe = makeType->getMovie(data);

    if (data.compare("C") == 0) {
      data = "";
      string month;
      ss >> month;
      string year;
      ss >> year;

      getline(ss, data);

      // Hal Ashby, Harold and Maude, Ruth Gordon 3 1971
      string movieFakeData =
          "FAKE DIRECTOR, FAKE TITLE, " + data + " " + month + " " + year;
      findMe->setData(movieFakeData);
    }
    // Command "Nancy Savoca, Dogfight,"
    // movie "Steven Spielberg, Schindler's List, 1993"
    else if (data.compare("D") == 0) {
      data = "";
      getline(ss, data);
      string movieFakeData = data + " 1993";
      findMe->setData(movieFakeData);
    }
    // Command "Annie Hall, 1977"
    // movie "Steven Spielberg, Schindler's List, 1993"
    else if (data.compare("F") == 0) {
      data = "";
      getline(ss, data);
      string movieFakeData = "Fake Director," + data;
      findMe->setData(movieFakeData);
    } else {
      cout << "Borrow failed: invalid Movie type: " << endl;
      cout << movieData << endl << endl;
      return false;
    }
    if (movies.retrieve(*findMe, foundMe)) {
      if (foundMe->subStock(1)) {
        current->addHistory("Borrowed:" + movieData + ".");
        // REMOVE LATER Just for testing:
        // cout << "Borrow Successful: " << endl;
        // cout << movieData;
        return true;
      } else {
        cout << "Borrow failed: not enough in stock:" << endl;
        cout << movieData << endl << endl;
        return false;
      }
    } else {
      cout << "Borrow failed: movie not found: " << endl;
      cout << movieData << endl << endl;
      return false;
    }
  } else {
    cout << "Borrow failed: invalid customerID:" << endl;
    cout << movieData << endl << endl;
    return false;
  }
}
