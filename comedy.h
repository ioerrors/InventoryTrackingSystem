////////////////////////////////comedy.h file  ////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a comedy class which is a type of movie 
// child of the movie class, inheriting from Movie
//-----------------------------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy : public Movie {
public:

    Comedy();         // constructor
    virtual ~Comedy();        // destructor
    
    string getGenre() const;
    string getTitle() const;       
    string getDirector() const;
    int getStock() const;
    int getReleaseYear() const;

    bool addStock(int); 
    bool subStock(int);

    bool setData(string movieData);

    // Overloaded operators
    bool operator==(const Movie& otherMovie) const;   // check if movies are equal
    bool operator!=(const Movie& otherMovie) const; // check if movies are not equal
    bool operator>(const Movie& otherMovie) const;  // check if this movie is greater than other movie
    bool operator<(const Movie& otherMovie) const;  // check if this movie is less than other movie
};

#endif
