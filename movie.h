////////////////////////////////movie.h file  /////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a movie class/interface which stores 
// and allows access to various movie attributes
//-----------------------------------------------------------------------------

#ifndef MOVIE_H
#define MOVIE_H

class Movie {
public:
    virtual ~Movie();                               // destructor
    
    // Overloaded operators
    virtual bool operator==(const Movie& otherMovie) const;    // check if movies are equal
    virtual bool operator!=(const Movie& otherMovie) const;  // check if movies are not equal
    virtual bool operator>(const Movie& otherMovie) const;   // check if this movie is greater than other movie
    virtual bool operator<(const Movie& otherMovie) const;   // check if this movie is less than other movie

    virtual char getGenre() const;                          // get the genre of the movie object
    char getMediaType() const;                      // get the type of the movie object, i.e. DVD
    
    string getTitle() const;                        // get the title of the movie object
    string getDirector() const;                     // get the director's name of the movie object
    
    int getStock() const;                           // get the stock of the movie object
    int getReleaseYear() const;                     // get the release year date of the movie object

    string getActor() const;                // get the actor of the movie object
    virtual int getMonth() const;                   // get the month of classic of the movie object
    
    virtual void display() const;                   // print out movie data and return string


    virtual void setData(string movieData); 

    bool addStock(int newStock);           // add to stock
    bool subStock(int removeStock);           // subtract from stock
    
    virtual bool addSameMovie(Movie*&);             // add the same movie to the list of same movies
    
protected:
    char genre;                                     // genre of the movie
    char mediaType;                                 // media type of the movie
    string title;                                   // title of movie
    string director;                                // director of movie
    int stock;                                      // number of movie left in stock
    int year;                                       // year released
    int month;                                      // month released
};

#endif