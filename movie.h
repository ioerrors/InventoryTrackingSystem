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

  //-----------------------------------------------------------------------------
  // Overloaded Operator <<
  // Description: prints movie contents to ostream
  // PRE: Movie exists
  // POST: All contained data fields are printed in order
  friend ostream &operator<<(ostream &os, const Movie &);

public:
  Movie();
  virtual ~Movie();
  // Overloaded operators
  virtual bool operator==(const Movie &otherMovie) const; // check if movies are
                                                          // equal
  virtual bool operator!=(const Movie &otherMovie) const; // check if movies are
                                                          // not equal
  virtual bool operator>(const Movie &otherMovie) const;  // check if this movie
                                                          // is greater than
                                                          // other movie
  virtual bool operator<(const Movie &otherMovie) const;  // check if this movie
                                                          // is less than other
                                                          // movie

  virtual string getGenre() const; // get the genre of the movie object
  char getMediaType() const;       // get the type of the movie object, i.e. DVD

  string getTitle() const;    // get the title of the movie object
  string getDirector() const; // get the director's name of the movie object

  int getStock() const;       // get the stock of the movie object
  int getReleaseYear() const; // get the release year date of the movie object

  virtual set<string> getActors() const; // get the actors of the movie object
  virtual int getMonth() const; // get the month of classic of the movie object

  void display() const; // print out movie data and return string

  // created a movie()
  // add stock(stock) preconditioned
  // assumed format "Gus Van Sant, Good Will Hunting, 2000"
  //        or     "Rob Reiner, When Harry Met Sally, 1989"
  //        or     "Hal Ashby, Harold and Maude, Ruth Gordon 3 1971"
  virtual bool setData(string movieData);
  virtual bool addActor(string name);
  bool addStock(int newStock);    // add to stock
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
