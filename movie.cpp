////////////////////////////////movie.cpp file ////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a movie class/interface which stores
// and allows access to various movie attributes
//-----------------------------------------------------------------------------

#include <iostream>
#include <iterator>
#include <set>

#include "classic.h"
#include "movie.h"

using namespace std;

//-----------------------------------------------------------------------------
// Overloaded Operator <<
// Description: prints movie contents to ostream
// PRE: Movie exists
// POST: All contained data fields are printed in order
ostream &operator<<(ostream &os, const Movie &mov) {
  string type = "C";
  os << mov.getGenre() + ", ";
  if (type == mov.getGenre()) {
    os << to_string(mov.getStock()) + ",";
    os << mov.getDirector() + ",";
    os << mov.getTitle() + ", ";
    for (string actor : mov.getActors()) {
      os << actor << ", ";
    }
    os << to_string(mov.getMonth()) + " ";
    os << to_string(mov.getReleaseYear());
    os << endl;
  } else {
    os << to_string(mov.getStock()) + ", ";
    os << mov.getGenre() + "";
    os << mov.getDirector() + ",";
    os << mov.getTitle() + ", ";
    os << to_string(mov.getReleaseYear());
    os << endl;
  }
  return os;
}

//-----------------------------------------------------------------------------
// Movie CONSTRUCTOR
// Description: creates an empty Movie
// PRE: memory is available for Movie
// POST: empty Movie is created
Movie::Movie() {
  genre = '`';
  mediaType = 'D';
  title = "";
  director = "";
  stock = 0;
  year = 0;
  month = 0;
}

//-----------------------------------------------------------------------------
// Movie DESTRUCTOR
// Description: deallocates all memory allocated for Movie
// PRE: Movie exists
// POST: all MOvie memory is freed
Movie::~Movie() {}

//-----------------------------------------------------------------------------
// getTitle()
// Description: returns the title
// PRE: assumes title exist
// POST: the title is returned
string Movie::getTitle() const {
  // do we need this?
  return this->title;
}
  
//-----------------------------------------------------------------------------
// getDirector()
// Description: returns the director name
// PRE: assumes director name exist
// POST: the director name is returned
string Movie::getDirector() const { return this->director; }

//-----------------------------------------------------------------------------
// getStock()
// Description: returns the stock amount
// PRE: assumes stock amount exist
// POST: the stock amount is returned
int Movie::getStock() const { return this->stock; }

//-----------------------------------------------------------------------------
// getReleaseYear()
// Description: returns the release year
// PRE: assumes the release year exist
// POST: the release year is returned
int Movie::getReleaseYear() const { return this->year; }

//-----------------------------------------------------------------------------
// addStock()
// Description: adds stock when a movie is returned
// PRE: assumes that the movie exist
// POST: adds 1 to the stock counter
bool Movie::addStock(int newStock) {
  if (newStock >= 0) {
    stock += newStock;
    return true;
  } else {
    return false;
  }
}

//-----------------------------------------------------------------------------
// subStock()
// Description: subs stock when a movie is borrow
// PRE: assumes that the movie exist
// POST: subs 1 on the stock counter
bool Movie::subStock(int removeStock) {
  if (stock > 0) {
    stock -= removeStock;
    return true;
  } else {
    return false;
  }
}

// will not accept actors for non classic movies
//-----------------------------------------------------------------------------
// addActor()
// Description: add an actor to a Classic movie with multiple
//              major actors.
// PRE: assume the movie is a Classic movie type
// POST: the name of the major actor is added to the set
bool Movie::addActor(string actor) {
  if (this->getGenre() == "C") {
    int a = actorsList.size();
    actorsList.insert(actor);
    int b = actorsList.size();
    return b > a;
  } else {
    return false;
  }
}

//-----------------------------------------------------------------------------
// getGenre()
// Description: returns the genre type
// PRE: assumes genre set to return is valid
// POST: the genre type is returned
string Movie::getGenre() const { return this->genre; }

//-----------------------------------------------------------------------------
// getMonth()
// Description: return the release month
// PRE: assumes the release month exist
// POST: the release month is returned
int Movie::getMonth() const { return this->month; }

//-----------------------------------------------------------------------------
// getActors()
// Description: returns the major actors in the movie
// PRE: assumes that one or more major actors exist
// POST: the list of actors is returned
set<string> Movie::getActors() const { return this->actorsList; }

//-----------------------------------------------------------------------------
// setData()
// Description: set data fields
// PRE: assumes formats  are either"Gus Van Sant, Good Will Hunting, 2000"
//      or "Rob Reiner, When Harry Met Sally, 1989"
//      or "Hal Ashby, Harold and Maude, Ruth Gordon 3 1971"
//      and movie exist
// POST: the data fields are set
bool Movie::setData(string movieData) { return false; }

// same one in customer.h?
//-----------------------------------------------------------------------------
// display()
// Description: prints out the customer's name and ID
// PRE: assumes customer's name and ID exist
// POST: the customer's name and ID is printed
void Movie::display() const { cout << this; }

//-----------------------------------------------------------------------------
// operator ==
// Description: checks if the movies are equal
// PRE: assumes that the movies exist
// POST: returns true if the movies are equal
bool Movie::operator==(const Movie &otherMovie) const {
  return otherMovie == *this;
} // check if movies are equal

//-----------------------------------------------------------------------------
// operator !=
// Description: checks if the movies are not equal
// PRE: assumes that the movies exist
// POST: returns true if the movies are not equal
bool Movie::operator!=(const Movie &otherMovie) const {
  return otherMovie != *this;
} // check if movies are not equal

//-----------------------------------------------------------------------------
// operator >
// Description: checks if LHS is sorted greater then the RHS
// PRE: assumes that the movies exist
// POST: returns true if the LHS movie is sorted greater than the
//       RHS movie
bool Movie::operator>(const Movie &otherMovie) const {
  return otherMovie < *this;
} // check if this movie is greater than other movie

//-----------------------------------------------------------------------------
// operator <
// Description: checks if LHS is sorted lesser then the RHS
// PRE: assumes that the movies exist
// POST: returns true if the LHS movie is sorted lesser than the
//       RHS movie
bool Movie::operator<(const Movie &otherMovie) const {
  return otherMovie > *this;
} // check if this movie is less than other movie
