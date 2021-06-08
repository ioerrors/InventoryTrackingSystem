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


void createBSTreeMoviesHelper(set<Movie *> &movieSet, BSTree::Node *current,
                              BSTree &movies) {

  /*
  if (current->left == nullptr) {
    return;
  }

  //createBSTreeMoviesHelper(movieSet, current->left, movies);


  Movie *first = *movieSet.begin();
  current->data = first;
  movieSet.erase(first);

  //createBSTreeMoviesHelper(movieSet, current->right, movies);

   */
}

void createBSTreeMovies(ifstream &movieFile, BSTree &movies) {
  MovieFactory factory;
  stack<Movie*> classicsStack;
  stack<Movie*> search;
  set<Movie*> classics;
  set<Movie*> dramas;
  set<Movie*> comedies;
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
    if(movie != nullptr) {
      movie->addStock(stock);
      movie->setData(data);


      //for classicsStack only
      if (movieType == "C,") {
	      if(classicsStack.empty()) {
          classicsStack.push(movie);  
        }
        stack<string> addFromMe;
        bool moreActors = false;
        // Iterate till the end of set
        while (!classicsStack.empty()) {
          search.push(classicsStack.top());
          classicsStack.pop();
        }
        while (!search.empty()) {
          moreActors = false;
          if(search.top()->getTitle() == movie->getTitle()) {
            //Movie* retain = search.top();

            for(string actor : search.top()->getActors()) {
              addFromMe.push(actor);
            }
            while(!addFromMe.empty()) {
              int a = movie->getActors().size();
              movie->addActor(addFromMe.top());
              int b = movie->getActors().size();
              if(b > a) {
                  moreActors = true;
              }
              addFromMe.pop();
            }
            if(moreActors) {
                movie->addStock(search.top()->getStock());
            }
          } else {
            classicsStack.push(search.top());
          }
          search.pop();
        }
        classicsStack.push(movie);        
      }
      if(movieType == "D,") {
        dramas.insert(movie);
        //dramas.erase(movie);
      }
      if (movieType == "F,") {
        comedies.insert(movie);
      }
    }//<---we have a set full of all our movies
  }// now we want a bst of our movies.

  while(!classicsStack.empty()) {
    Movie* real = classicsStack.top();
    classicsStack.pop();
    classics.insert(real);
  }
  cout << "Comedy: " << endl;
  for (Movie* cur : comedies) {
    cout << *cur << endl;
    movies.insert(cur);
  }
  cout << "Comedy BST: " << endl;
  cout << movies;
  cout << "Drama: " << endl;
  for (Movie* cur : dramas) {
    cout << *cur;
    cout << endl;
    movies.insert(cur);
  }
  cout << "Drama BST: " << endl;
  cout << movies;

  cout << "Classic: " << endl;
  for (Movie* cur : classics) {
    cout << *cur << endl;
    movies.insert(cur);
  }
  cout << "Classic BST: " << endl;
  cout << movies;
  //createBSTreeMoviesHelper(setOfMovies, movies.getRoot(), movies);
}

// 3333 Witch Wicked
void createHashTableCustomers(ifstream &customerFile, HashTable &customers) {
  while (!customerFile.eof()) {
    int customerID;
    string data;
    customerFile >> customerID;
    //customerID = stoi(data);
    string lastName;
    customerFile >> lastName;
    string firstName;
    customerFile >> firstName;
    Customer *cust = new Customer(customerID, firstName, lastName);
    customers.addCustomer(cust);
  }
}

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
    action->setData(data);
    action->doTransaction(customers, movies);
  }
}

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
  cout << endl << "BSTree of Movies: " << endl; 
  cout << movies;
  createHashTableCustomers(customerFile, customers);
  processTransactions(transactionFile, customers, movies);
  return 0;
}
