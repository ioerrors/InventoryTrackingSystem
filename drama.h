////////////////////////////////drama.h file  /////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a drama class which is a type of movie 
// child of the movie class, inheriting from Movie
//-----------------------------------------------------------------------------

#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

class Drama : public Movie {
public:
    
    Drama();      // constructor
    ~Drama();     // destructor
    
    // Accessors
    string getGenre() const;
    string getTitle() const;       
    string getDirector() const;
    int getStock() const;
    int getReleaseYear() const;
    
    // Mutators
    bool addStock(int); 
    bool subStock(int);            // subtract from stock
    // void addSameMovies(Movie*&);            // add the same movie to the list of same movies
    bool setData(string movieData);


    // Overloaded operators
    bool operator==(const Movie& otherMovie) const;   // check if movies are equal
    bool operator!=(const Movie& otherMovie) const; // check if movies are not equal
    bool operator>(const Movie& otherMovie) const;  // check if this movie is greater than rhs movie
    bool operator<(const Movie& otherMovie) const;  // check if this movie is less than rhs movie
};

#endif
