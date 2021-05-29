////////////////////////////////movie.h file  /////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Group 1 on 05/19/2021.
//-----------------------------------------------------------------------------
// This is a movie class which stores 
// and allows access to various movie attributes
//-----------------------------------------------------------------------------
#ifndef MOVIE_H
#define MOVIE_H

class Movie {
public:

    Movie();                                        // constructor
    Movie(char, char, string, string, int, int);    // genre, mediatype, title, director, stock, year released
    virtual ~Movie();                               // destructor
    
    // Overloaded operators
    virtual bool operator==(const Movie& otherMovie) const;    // check if movies are equal
    virtual bool operator!=(const Movie& otherMovie) const;  // check if movies are not equal
    virtual bool operator>(const Movie& otherMovie) const;   // check if this movie is greater than other movie
    virtual bool operator<(const Movie& otherMovie) const;   // check if this movie is less than other movie
    
    char getGenre() const;                          // get the genre of the movie object
   // char getType() const;                           // get the type of the movie object
    string getTitle() const;                        // get the title of the movie object
    string getDirector() const;                     // get the director's name of the movie object
    int getStock() const;                           // get the stock of the movie object
    int getReleaseYear() const;                     // get the release year date of the movie object
    //bool getCountedStatus() const;                  // returns true if movie has already been counted
    virtual string getActor() const;                // get the actor of the movie object
    //virtual int getMonth() const;                   // get the month of classic of the movie object
    
    virtual void display() const;                   // print out movie data and return string

    string setTitle() const;
    string setDirector() const;
    int setStock() const;
    int setReleaseYear() const;
    virtual string setActor() const;

    virtual bool addStock(int);                     // add to stock
    virtual bool subStock(int);                      // subtract to stock
    //void setCounted(bool);                          // mark movie as counted in inventory
    bool addSameMovie(Movie*&);             // add the same movie to the list of same movies
    
protected:
    //char genre;                                     // genre of the movie
    //char type;                                      // media type of the movie
    string title;                                   // title of movie
    string director;                                // director of movie
    int stock;                                      // number of movie left in stock
    int year;                                       // year released
    //bool counted;                                   // keeps track of inventory status of the movie
};

#endif