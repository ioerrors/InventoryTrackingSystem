////////////////////////////////movie.h file  /////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a movie class/interface which stores
// and allows access to various movie attributes
//-----------------------------------------------------------------------------
#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <set>
using namespace std;

class Movie {

  //---------------------------------------------------------------------------
  // Overloaded Operator <<
  // Description: prints movie contents to ostream
  // PRE: Movie exists
  // POST: All contained data fields are printed in order
  friend ostream &operator<<(ostream &os, const Movie &);

public:
  //---------------------------------------------------------------------------
  // Movie CONSTRUCTOR
  // Description: creates an empty Movie
  // PRE: memory is available for Movie
  // POST: empty Movie is created
  Movie();

  //---------------------------------------------------------------------------
  // Movie DESTRUCTOR
  // Description: deallocates all memory allocated for Movie
  // PRE: Movie exists
  // POST: all MOvie memory is freed
  virtual ~Movie();

  // Overloaded operators
  //---------------------------------------------------------------------------
  // operator ==
  // Description: checks if the movies are equal
  // PRE: assumes that the movies exist
  // POST: returns true if the movies are equal
  virtual bool operator==(const Movie &otherMovie) const; // check if movies are
                                                          // equal
  
  //---------------------------------------------------------------------------
  // operator !=
  // Description: checks if the movies are not equal
  // PRE: assumes that the movies exist
  // POST: returns true if the movies are not equal
  virtual bool operator!=(const Movie &otherMovie) const; // check if movies are
                                                          // not equal
  
  //---------------------------------------------------------------------------
  // operator >
  // Description: checks if LHS is sorted greater then the RHS
  // PRE: assumes that the movies exist
  // POST: returns true if the LHS movie is sorted greater than the
  //       RHS movie
  virtual bool operator>(const Movie &otherMovie) const;  // check if this movie
                                                          // is greater than
                                                          // other movie

  //---------------------------------------------------------------------------
  // operator <
  // Description: checks if LHS is sorted lesser then the RHS
  // PRE: assumes that the movies exist
  // POST: returns true if the LHS movie is sorted lesser than the
  //       RHS movie
  virtual bool operator<(const Movie &otherMovie) const;  // check if this movie
                                                          // is less than other
                                                          // movie

  //---------------------------------------------------------------------------
  // getGenre()
  // Description: returns the genre type
  // PRE: assumes genre set to return is valid
  // POST: the genre type is returned
  virtual string getGenre() const; // get the genre of the movie object
  
  //---------------------------------------------------------------------------
  // getMediaType()
  // Description: returns the media type
  // PRE: assumes media type set to return is valid
  // POST: the media type is returned
  char getMediaType() const;       // get the type of the movie object, i.e. DVD

  //---------------------------------------------------------------------------
  // getTitle()
  // Description: returns the title
  // PRE: assumes title exist
  // POST: the title is returned
  string getTitle() const;    // get the title of the movie object
  
  //---------------------------------------------------------------------------
  // getDirector()
  // Description: returns the director name
  // PRE: assumes director name exist
  // POST: the director name is returned
  string getDirector() const; // get the director's name of the movie object

  //---------------------------------------------------------------------------
  // getStock()
  // Description: returns the stock amount
  // PRE: assumes stock amount exist
  // POST: the stock amount is returned
  int getStock() const;       // get the stock of the movie object
  
  //---------------------------------------------------------------------------
  // getReleaseYear()
  // Description: returns the release year
  // PRE: assumes the release year exist
  // POST: the release year is returned
  int getReleaseYear() const; // get the release year date of the movie object

  //---------------------------------------------------------------------------
  // getActors()
  // Description: returns the major actors in the movie
  // PRE: assumes that one or more major actors exist
  // POST: the list of actors is returned
  virtual set<string> getActors() const; // get the actors of the movie object
  
  //---------------------------------------------------------------------------
  // getMonth()
  // Description: return the release month
  // PRE: assumes the release month exist
  // POST: the release month is returned
  virtual int getMonth() const; // get the month of classic of the movie object

  //---------------------------------------------------------------------------
  // display()
  // Description: prints out the customer's name and ID
  // PRE: assumes customer's name and ID exist
  // POST: the customer's name and ID is printed
  void display() const; // print out movie data and return string

  // created a movie()
  // add stock(stock) preconditioned
  // assumed format "Gus Van Sant, Good Will Hunting, 2000"
  //        or     "Rob Reiner, When Harry Met Sally, 1989"
  //        or     "Hal Ashby, Harold and Maude, Ruth Gordon 3 1971"
  //---------------------------------------------------------------------------
  // setData()
  // Description: set data fields
  // PRE: assumes formats  are either"Gus Van Sant, Good Will Hunting, 2000"
  //      or "Rob Reiner, When Harry Met Sally, 1989"
  //      or "Hal Ashby, Harold and Maude, Ruth Gordon 3 1971"
  //      and movie exist
  // POST: the data fields are set
  virtual bool setData(string movieData);

  //---------------------------------------------------------------------------
  // addActor()
  // Description: add an actor to a Classic movie with multiple
  //              major actors.
  // PRE: assume the movie is a Classic movie type
  // POST: the name of the major actor is added to the set
  virtual bool addActor(string name);

  //---------------------------------------------------------------------------
  // addStock()
  // Description: adds stock when a movie is returned
  // PRE: assumes that the movie exist
  // POST: adds 1 to the stock counter
  bool addStock(int newStock);    // add to stock

  //---------------------------------------------------------------------------
  // subStock()
  // Description: subs stock when a movie is borrow
  // PRE: assumes that the movie exist
  // POST: subs 1 on the stock counter
  bool subStock(int removeStock); // subtract from stock

protected:
  string genre;     // genre of the movie
  string mediaType; // media type of the movie
  string title;     // title of movie
  string director;  // director of movie
  int stock;        // number of movie left in stock
  int year;         // year released
  int month;        // month released
  set<string> actorsList;
};

#endif
