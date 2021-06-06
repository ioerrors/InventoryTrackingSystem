//-----------------------------------------------------------------------------
#include <iostream>
#include <sstream>
#include <stack>
#include <set>


#include "BSTree.h"
#include "hashTable.h"
#include "transactionFactory.h"
#include "movieFactory.h"
#include "customer.h"

class Business {



public:

	Business();

	void createBSTreeMovies(ifstream& movieFile);
	void createHashTableCustomers(ifstream& customerFile);
	void processTransactions(ifstream& transactionFile);

private:

  void createBSTreeMoviesHelper(set<Movie*>& movieSet, BSTree::Node* current);
  BSTree movies;
  HashTable customers;
};
