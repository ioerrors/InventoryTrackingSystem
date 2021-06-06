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
  } //<---we have a set full of all our movies
  // now we want a bst of our movies.
  BSTree movies;
  createBSTreeMoviesHelper(setOfMovies, movies.getRoot());
  return movies;
}

void Business::createBSTreeMoviesHelper(set<Movie>& movieSet, Node* current) {
  if (current == nullptr) {
    return;
  }

  createBSTreeMoviesHelper(movieSet, current->left);

  Movie* first = movieSet.begin();
  current->data = *first;
  movieSet.erase(first);

  createBSTreeMoviesHelper(movieSet, current->right);
} 
  
HashTable Business::createHashTableCustomers(ifstream customerFile) {
  while(!customerFile.eof()) {
    char movieType << customerFile;
    Movie movie = factory.getMovie(movieType);
    movie.setData(customerFile.getLine());
    setOfMovies.insert(movie);
  }
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

