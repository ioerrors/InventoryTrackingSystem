////////////////////////////////classic.h file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a Classic class which is a type of Movie
// child of the Movie class, inheriting from Movie
//-----------------------------------------------------------------------------
// Note on implemenation:
//
// in the data4movies.txt
// C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938
// C, 10, George Cukor, Holiday, Cary Grant 9 1938
//
// could be built into the movie set as:
//
// C, 20, George Cukor, Holiday, <Katherine Hepburn, Cary Grant> 9 1938
//
// OR into the movie set as:
//
// C, 20, George Cukor, Holiday, Katherine Hepburn 9 1938
// C, 20, George Cukor, Holiday, Cary Grant 9 1938
//
// These could both be valid based on the design document
//
// "In addition, for classical movies, one movie (e.g., Holiday)
// may have multiple lines so the total stock of this movie
// will be the sum of all the stocks in the lines about this movie
// (e.g., 20 for Holiday in the above example)."
//
// We have implemented one object per movie, with a list of actors.
// This requires the addition of one check for title after checking the
// normal sorting criteria of Release date --> Actor for Classics
// which if positive will add to the existing actor list
// rather than return a false negative in comparison operations
//-----------------------------------------------------------------------------
#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"
#include <set>

using namespace std;

class Classic : public Movie {
public:
  //-----------------------------------------------------------------------------
  // Classic CONSTRUCTOR
  // Description: creates an empty Classic
  // PRE: memory is available for Classic
  // POST: empty Classic is created
  Classic();

  //---------------------------------------------------------------------------
  // Classic DESTRUCTOR
  // Description: deallocates all memory allocated for Classic
  // PRE: Classic exists
  // POST: all Classic memory is freed
  virtual ~Classic();

  // Accesors
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

  //---------------------------------------------------------------------------
  // getMonth()
  // Description: return the release month
  // PRE: assumes the release month exist
  // POST: the release month is returned
  int getMonth() const; // get the month of release

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

  //---------------------------------------------------------------------------
  // getActors()
  // Description: returns the major actors in the movie
  // PRE: assumes that one or more major actors exist
  // POST: the list of actors is returned
  set<string> getActors(); // get the actors of the movie object

  //---------------------------------------------------------------------------
  // setData()
  // Description: sets data fields
  // PRE: classic exists, stock is already set using addStock()
  //    input format "Hal Ashby, Harold and Maude, Ruth Gordon 3 1971"
  // POST: all data fields set
  bool setData(string movieData);

  //---------------------------------------------------------------------------
  // addActor()
  // Description: add an actor to a Classic movie with multiple
  //              major actors.
  // PRE: assume the movie is a Classic movie type
  // POST: the name of the major actor is added to the set
  bool addActor(string actor);
  // Overloaded operators

  // check if movies are equal and adds actor to actor list
  //---------------------------------------------------------------------------
  // operator ==
  // Description: checks if the movies are equal
  // PRE: assumes that the movies exist
  // POST: returns true if the movies are equal
  bool operator==(const Movie &otherMovie) const;

  // check if movies are not equal
  //---------------------------------------------------------------------------
  // operator !=
  // Description: checks if the movies are not equal
  // PRE: assumes that the movies exist
  // POST: returns true if the movies are not equal
  bool operator!=(const Movie &otherMovie) const;

  // check if this movie is greater than other movie
  //---------------------------------------------------------------------------
  // operator >
  // Description: checks if the release year, then the release month,
  //              then the alphabetical order of the first actor on the list
  //              is greater
  // PRE: assumes that the movies exist
  // POST: returns true if the LHS movie is sorted greater than the
  //       RHS movie
  bool operator>(const Movie &otherMovie) const;

  // check if this movie is less than other movie
  // this < otherMovie
  //---------------------------------------------------------------------------
  // operator <
  // Description: checks if the release year, then the release month,
  //              then the alphabetical order of the first actor on the list
  //              is lesser
  // PRE: assumes that the movies exist
  // POST: returns true if the LHS movie is sorted lesser than the
  //       RHS movie
  bool operator<(const Movie &otherMovie) const;
};

#endif
