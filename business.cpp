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

  MovieFactory factory = new MovieFactory();
  set<Movie> setOfMovies; 
  while(!movieFile.eof()) {
    char movieType << movieFile;
    Movie movie = factory.getMovie(movieType);
    movie.setData(movieFile.getLine());
    setOfMovies.insert(movie);
  }
  
}

HashTable Business::createHashTableCustomers(ifstream customerFile) {
  //creates the HashTable for customers, and returns
}

void processTransactions(transactionFile) {
  
  TransactionFactory factory = new TransactionFactory();

  while(!transactionFile.eof()) {
    char transType << transactionFile;
    Transaction action = factory.getTransaction(transType);
    action.setData(transactionFile.getLine());
    action.doTransaction();
    delete action;
  }
}

inside transaction Inventory:
  movieX.display();