////////////////////////////////business.cpp file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice & Abraham Sham on 05/25/2021.
//
// CPP file to initiate the creation of BSTree with movies and
// the initiation of processing transactions.
//
// To test the functions of this program, like having the data
// printed out in specific orders, and certain error messages are
// printed.
//-----------------------------------------------------------------------------
#include <iostream>
#include <set>
#include <sstream>
#include <stack>

#include "BSTree.h"
#include "customer.h"
#include "hashTable.h"
#include "movieFactory.h"
#include "transactionFactory.h"

using namespace std;

//-----------------------------------------------------------------------------
// createBSTreeMovies()
// Description: creates a BSTree and stores the movies
//              from data found in the txt files
// PRE: assumes data from txt file is in the correct format
// POST: a BSTree filled with movies from the data found 
//       in the txt files is created
void createBSTreeMovies(ifstream &movieFile, BSTree &movies) {
  MovieFactory factory;
  stack<Movie *> classicsStack;
  stack<Movie *> search;
  set<Movie *> classics;
  set<Movie *> dramas;
  set<Movie *> comedies;
  while (!movieFile.eof()) {
    string movieType = "";
    movieFile >> movieType;
    Movie *movie = factory.getMovie(movieType);
    string data = "";
    getline(movieFile, data, ',');
    stringstream ss(data);
    int stock = 0;
    ss >> stock;
    getline(movieFile, data);
    if (movie != nullptr) {
      movie->addStock(stock);
      movie->setData(data);

      // for classicsStack only
      if (movieType == "C,") {
        if (classicsStack.empty()) {
          classicsStack.push(movie);
        }
        stack<string> addFromMe;
        bool moreActors = false;
        // Iterate till the end of stack
        while (!classicsStack.empty()) {
          search.push(classicsStack.top());
          classicsStack.pop();
        }
        while (!search.empty()) {
          moreActors = false;
          if (search.top()->getTitle() == movie->getTitle()) {
            // Movie* retain = search.top();

            for (string actor : search.top()->getActors()) {
              addFromMe.push(actor);
            }
            while (!addFromMe.empty()) {
              int a = movie->getActors().size();
              movie->addActor(addFromMe.top());
              int b = movie->getActors().size();
              if (b > a) {
                moreActors = true;
              }
              addFromMe.pop();
            }
            if (moreActors) {
              movie->addStock(search.top()->getStock());
            }
          } else {
            classicsStack.push(search.top());
          }
          search.pop();
        }
        classicsStack.push(movie);
      }
      if (movieType == "D,") {
        dramas.insert(movie);
        // dramas.erase(movie);
      }
      if (movieType == "F,") {
        comedies.insert(movie);
      }
      //
    } //<---we have a set full of all our movies
  }   // now we want a bst of our movies.
  while (!classicsStack.empty()) {
    Movie *real = classicsStack.top();
    classicsStack.pop();
    classics.insert(real);
  }

  for (Movie *cur : comedies) {
    movies.insert(cur);
  }

  for (Movie *cur : dramas) {
    movies.insert(cur);
  }
  for (Movie *cur : classics) {
    movies.insert(cur);
  }
}


//-----------------------------------------------------------------------------
// createHashTableCustomers()
// Description: creates a hashtable of customers based on the txt file
// PRE: assumes format from txt file is valid format: 3333 Witch Wicked
// POST: a hashtable of customers based on the txt file is created
void createHashTableCustomers(ifstream &customerFile, HashTable &customers) {
  while (!customerFile.eof()) {
    int customerID;
    string data;
    customerFile >> customerID;

    string lastName;
    customerFile >> lastName;
    string firstName;
    customerFile >> firstName;
    Customer *cust = new Customer(customerID, firstName, lastName);
    customers.addCustomer(cust);
    // delete cust;
  }
}

//-----------------------------------------------------------------------------
// processTransactions()
// Description: processes transactions based on the commands from the txt files
// PRE: assumes that valid transactions are defined
// POST: the transactions are processed
void processTransactions(ifstream &transactionFile, HashTable &customers,
                         BSTree &movies) {
  //    MovieFactory* makeType = new MovieFactory();
  TransactionFactory *factory = new TransactionFactory();

  while (!transactionFile.eof()) {
    string transType;
    transactionFile >> transType;
    Transaction *action = factory->getTransaction(transType);
    string data;
    getline(transactionFile, data);
    if (action != nullptr) {
      action->setData(data);
      action->doTransaction(customers, movies);
    } else {
      cout << "Transaction Failed, invalid Transaction Code: ";
      cout << transType << endl;
      cout << endl;
    }
    delete action;
    // cout << endl;
  }
  delete factory;
}

//-----------------------------------------------------------------------------
// main()
// Description: reads the txt files, stores and process the data
// PRE: assume txt files are in the valid format
// POST: the data from the txt files are stored and processed
int main() {
  ifstream movieFile("data4movies.txt");         // read the movies text file
  ifstream customerFile("data4customers.txt");   // read the customers text file
  ifstream transactionFile("data4commands.txt"); // read the commands text file

  if (!customerFile) // repeat for movieFile and transactionFile
    cout << "Customer file cannot be oppened" << endl;
  if (!movieFile) // repeat for movieFile and transactionFile
    cout << "Movie file cannot be oppened" << endl;
  if (!transactionFile) // repeat for movieFile and transactionFile
    cout << "Transaction file cannot be oppened" << endl;
  BSTree movies;
  HashTable customers;
  createBSTreeMovies(movieFile, movies);
  createHashTableCustomers(customerFile, customers);

  processTransactions(transactionFile, customers, movies);
  return 0;
}
