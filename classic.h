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

struct actorNode {
    string actor; // major actor of the movie
    int stock;    // the number of stock for movies
    actorNode* next; // Node to keep track of actor 
};

class Classic : public Movie
{
public:
    
    Classic(char genre, char mediaType, string title, string director, int stock, int yearRelease, int monthReleased, string actor);               // constructor
    ~Classic();                                     // destructor
    
    // Overloaded operators
    bool operator==(const Movie&) const;  // check if movies are equal
    bool operator!=(const Movie&) const;  // check if movies are not equal
    bool operator>(const Movie&) const;   // check if this movie is greater than rhs movie
    bool operator<(const Movie&) const;   // check if this movie is less than rhs movie
    
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

private:
    vector<Movie*> sameMoviesList;                  // List for the same movies
    string actor;				 // store the actor
    //int monthReleased;                              // month of the movie release

    string releaseDate;
    
};

#endif