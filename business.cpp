#include <iostream>
#include <sstream>
#include <stack>
#include <set>

#include "business.h"
#include "BSTree.h"
#include "hashTable.h"
#include "transactionFactory.h"
#include "movieFactory.h"
#include "customer.h"


using namespace std;

Business::Business() {
    ifstream movieFile("data4movies.txt");           // read the movies text file
    ifstream customerFile("data4customers.txt");     // read the customers text file
    ifstream transactionFile("data4commands.txt");   // read the commands text file
    
    if (!customerFile)                // repeat for movieFile and transactionFile
        cout << "Customer file cannot be oppened" << endl;
    if (!movieFile)                   // repeat for movieFile and transactionFile
        cout << "Movie file cannot be oppened" << endl;
    if (!transactionFile)             // repeat for movieFile and transactionFile
        cout << "Transaction file cannot be oppened" << endl;
    
    createBSTreeMovies(movieFile);
    createHashTableCustomers(customerFile);
    processTransactions(transactionFile);

}


void Business::createBSTreeMovies(ifstream& movieFile) {
  //creates the BSTree for movies, and returns

  MovieFactory factory;
  set<Movie*> setOfMovies;
  while(!movieFile.eof()) {
    string movieType;
    movieFile >> movieType;
    Movie* movie = factory.getMovie(movieType);
    string data;
    getline(movieFile, data);
    movie->setData(data);
    setOfMovies.insert(movie);
  } //<---we have a set full of all our movies
  // now we want a bst of our movies.
  createBSTreeMoviesHelper(setOfMovies, movies.getRoot());
}

void Business::createBSTreeMoviesHelper(set<Movie*>& movieSet, BSTree::Node* current) {
  if (current == nullptr) {
    return;
  }

  createBSTreeMoviesHelper(movieSet, current->left);


  Movie* first = *movieSet.begin();
  current->data = first;
  movieSet.erase(first);

  createBSTreeMoviesHelper(movieSet, current->right);
} 

//3333 Witch Wicked
void Business::createHashTableCustomers(ifstream& customerFile) {
  while(!customerFile.eof()) {
    int customerID;
    string data;
    customerFile >> data;
    customerID = stoi(data);
    string lastName;
    customerFile >> lastName;
    string firstName;
    customerFile >> firstName;
    Customer* cust = new Customer(customerID, firstName, lastName);
    customers.addCustomer(cust);
  }
}

void Business::processTransactions(ifstream& transactionFile) {
  //    MovieFactory* makeType = new MovieFactory();
  TransactionFactory* factory = new TransactionFactory();

  while(!transactionFile.eof()) {
    string transType;
    transactionFile >> transType;
    Transaction* action = factory->getTransaction(transType);
    string data;
    getline(transactionFile, data);
    action->setData(data);
    action->doTransaction(customers, movies);
  }
}

