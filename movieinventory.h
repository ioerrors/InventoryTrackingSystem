////////////////////////////////movieinventory.h file  ////////////////////////
//-----------------------------------------------------------------------------
// Created by Group 1 on 05/19/2021.
//-----------------------------------------------------------------------------
// This is a class to collect information about total movie objects
// and provide access to the movie data obects
//-----------------------------------------------------------------------------


class MovieInventory {
public:
    
    MovieInventory();           // constructor
    ~MovieInventory();          // destructor

    bool getMovie (Movie*);                 // get movie from the tree
    bool addMovie(Movie*);                  // add movie node
    bool borrowMovie (Movie*, string);      // check borrowed movie
    bool returnMovie(Movie*, string);       // check returned movie
    void addAllSameMovie(Movie*, int)       // add quantities of all same movies

private:
    Movie* newMovie;            // Node to track the new movie
    vector<BST> inventory;      // sorting inventory to store movies 
};