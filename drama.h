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
  //---------------------------------------------------------------------------
  // Comedy CONSTRUCTOR
  // Description: creates an empty Comedy
  // PRE: Memory is available for Comedy
  // POST: Empty Comedy is created
  Drama();  // constructor

  //---------------------------------------------------------------------------
  // Comedy DESTRUCTOR
  // Description: deallocates all memory allocated for Drama
  // PRE: Drama exist
  // POST: all Drama memory is freed
  ~Drama(); // destructor

  // Accessors
  //---------------------------------------------------------------------------
  // getGenre()
  // Description: returns the genre type
  // PRE: assumes genre set to return is valid
  // POST: the genre type is returned
  string getGenre() const;

  //---------------------------------------------------------------------------
  // getTitle()
  // Description: returns the title
  // PRE: assumes title exist
  // POST: the title is returned
  string getTitle() const;

  //---------------------------------------------------------------------------
  // getDirector()
  // Description: returns the director name
  // PRE: assumes director name exist
  // POST: the director name is returned
  string getDirector() const;

  //---------------------------------------------------------------------------
  // getStock()
  // Description: returns the stock amount
  // PRE: assumes stock amount exist
  // POST: the stock amount is returned
  int getStock() const;

  //---------------------------------------------------------------------------
  // getReleaseYear()
  // Description: returns the release year
  // PRE: assumes the release year exist
  // POST: the release year is returned
  int getReleaseYear() const;

  // Mutators
  //---------------------------------------------------------------------------
  // addStock()
  // Description: adds stock when a movie is returned
  // PRE: assumes that the movie exist
  // POST: adds 1 to the stock counter
  bool addStock(int);

  //---------------------------------------------------------------------------
  // subStock()
  // Description: subs stock when a movie is borrow
  // PRE: assumes that the movie exist
  // POST: subs 1 on the stock counter
  bool subStock(int); // subtract from stock
  // void addSameMovies(Movie*&);            // add the same movie to the list
  // of same movies

  //---------------------------------------------------------------------------
  // setData()
  // Description: sets data fields
  // PRE: Drama exists, stock is already set using addStock()
  //    input format "Phillippe De Broca, King of Hearts, 1967"
  // POST: all data fields set
  bool setData(string movieData);

  // Overloaded operators
  //---------------------------------------------------------------------------
  // operator ==
  // Description: checks if the movies are equal
  // PRE: assumes that the movies exist
  // POST: returns true if the movies are equal
  bool operator==(const Movie &otherMovie) const; // check if movies are equal

  //---------------------------------------------------------------------------
  // operator !=
  // Description: checks if the movies are not equal
  // PRE: assumes that the movies exist
  // POST: returns true if the movies are not equal
  bool operator!=(const Movie &otherMovie) const; // check if movies are not
                                                  // equal

  //---------------------------------------------------------------------------
  // operator >
  // Description: checks if the movie type, director, and title is greater
  // PRE: assumes that the movies exist
  // POST: returns true if the LHS movie is sorted greater than the
  //       RHS movie
  bool operator>(const Movie &otherMovie) const;  // check if this movie is
                                                  // greater than rhs movie
  //---------------------------------------------------------------------------
  // operator <
  // Description: checks if the movie type, director, and title is lesser
  // PRE: assumes that the movies exist
  // POST: returns true if the LHS movie is sorted lesser than the
  //       RHS movie
  bool operator<(const Movie &otherMovie) const;  // check if this movie is less
                                                  // than rhs movie
};

#endif
