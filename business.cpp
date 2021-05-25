int main() {
    ifstream movieFile("data4movies.txt");           // read the movies text file
    ifstream customerFile("data4customers.txt");     // read the customers text file
    ifstream transactionFile("data4commands.txt");   // read the commands text file
    
    if (!customerFile)                // repeat for movieFile and transactionFile
        cout << "Customer file cannot be oppened" << endl;
    if (!movieFile)                   // repeat for movieFile and transactionFile
        cout << "Movie file cannot be oppened" << endl;
    if (!transactionFile)             // repeat for movieFile and transactionFile
        cout << "Transaction file cannot be oppened" << endl;
    
    movies = createBSTreeMovies(movieFile);
    customers = createHashTableCustomers(customerFile);
    processTransactions(transactionFile);
    



    return 0;
}


BSTree Business::createBSTreeMovies(ifstream movieFile) {
  //creates the BSTree for movies, and returns
}

HashTable Business::createHashTableCustomers(ifstream customerFile) {
  //creates the HashTable for customers, and returns
}

void processTransactions(transactionFile) {
  char transType << transactionFile;
  switch transType {
    case 'B' {
      int customerID << transactionFile;
      char typeOfMedia << transactionFile;
      char movieType << transactionFile;
      string movieData << transactionFile;
      //add << transactionFile to movieData
      //until string contains 9 1938 Katherine Hepburn
      Transaction borrow = new Borrow(customerID, movieData);
      borrow.doTransaction(movies, customers);
      break;
    }
    case 'R' {
      break;
    }
    case 'I' {
      break;
    }
    case H {
      break;
    }
  }

}