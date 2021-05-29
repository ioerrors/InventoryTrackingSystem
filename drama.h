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
    
    Drama(char genre, char mediaType, string title, string director,
          int stock, int yearRelease);      // constructor
    ~Drama();                               // destructor
    
    // Accessors
    char getGenre() const;
    string getTitle() const;       
    string getDirector() const;
    int getStock() const;
    int getReleaseYear() const;
    
    // Mutators
    virtual bool addStock(int); 
    virtual bool subStock(int);            // subtract from stock
    virtual void addSameMovies(Movie*&);            // add the same movie to the list of same movies
    string setTitle() const;
    string setDirector() const;
    int setStock() const;
    int setReleaseYear() const;
    virtual string setActor() const;

    // Overloaded operators
    virtual bool operator==(const Movie& otherMovie) const;   // check if movies are equal
    virtual bool operator!=(const Movie& otherMovie) const; // check if movies are not equal
    virtual bool operator>(const Movie& otherMovie) const;  // check if this movie is greater than rhs movie
    virtual bool operator<(const Movie& otherMovie) const;  // check if this movie is less than rhs movie
};

#endif