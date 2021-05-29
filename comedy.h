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

    Comedy(char genre, char mediaType, string title, string director,
           int stock, int yearRelease);         // constructor
    ~Comedy();                                  // destructor
    
    char getGenre() const;
    string getTitle() const;       
    string getDirector() const;
    int getStock() const;
    int getReleaseYear() const;

    virtual bool addStock(int); 
    virtual bool subStock(int);   
    string setTitle() const;
    string setDirector() const;
    int setStock() const;
    int setReleaseYear() const;
    virtual string setActor() const;

    // Overloaded operators
    virtual bool operator==(const Movie& otherMovie) const;   // check if movies are equal
    virtual bool operator!=(const Movie& otherMovie) const; // check if movies are not equal
    virtual bool operator>(const Movie& otherMovie) const;  // check if this movie is greater than other movie
    virtual bool operator<(const Movie& otherMovie) const;  // check if this movie is less than other movie
};

#endif