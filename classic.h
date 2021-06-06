////////////////////////////////classic.h file  ///////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a classic class which is a type of movie 
// child of the movie class, inheriting from Movie
//-----------------------------------------------------------------------------

#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"

class Classic : public Movie
{
public:
    
    Classic();               // constructor
    ~Classic();              // destructor
    
    
    // Accessors
    char getGenre() const;
    string getTitle() const;       
    string getDirector() const;
    int getStock() const;
    int getReleaseYear() const;


    // Mutators
    bool addStock(int); 
    bool subStock(int);            // subtract from stock
    void addSameMovies(Movie*&);            // add the same movie to the list of same movies
    set<string> getActors() const;      // get the actors of the movie object

    void setData(string movieData);  
    
    // Overloaded operators
    bool operator==(const otherMovie&) const;  // check if movies are equal
    bool operator!=(const otherMovie&) const;  // check if movies are not equal
    bool operator>(const otherMovie&) const;   // check if this movie is greater than rhs movie
    bool operator<(const otherMovie&) const;   // check if this movie is less than rhs movie
    
private:
    Set<String> actorsList;       // List of actors
};

#endif