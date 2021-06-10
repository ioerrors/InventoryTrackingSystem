////////////////////////////////drama.cpp file ////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a drama class which is a type of movie
// child of the movie class, inheriting from Movie
//-----------------------------------------------------------------------------

#include "drama.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
//-----------------------------------------------------------------------------
// Comedy CONSTRUCTOR
// Description: creates an empty Comedy
// PRE: Memory is available for Comedy
// POST: Empty Comedy is created
Drama::Drama() {
  genre = "D";
  mediaType = "D";
  title = "";
  director = "";
  stock = 0;
  year = 0;
  month = 0;
}

//-----------------------------------------------------------------------------
// Comedy DESTRUCTOR
// Description: deallocates all memory allocated for Drama
// PRE: Drama exist
// POST: all Drama memory is freed
Drama::~Drama() {}

//-----------------------------------------------------------------------------
// getGenre()
// Description: returns the genre type
// PRE: assumes genre set to return is valid
// POST: the genre type is returned
string Drama::getGenre() const { return "D"; }

//-----------------------------------------------------------------------------
// setData()
// Description: sets data fields
// PRE: Drama exists, stock is already set using addStock()
//    input format "Phillippe De Broca, King of Hearts, 1967"
// POST: all data fields set
bool Drama::setData(string movieData) {
  stringstream ss(movieData);
  string data;

  // get director
  getline(ss, data, ',');
  director = data;
  data = "";

  // get title
  getline(ss, data, ',');
  title = data;

  // get year
  data = "";
  ss >> year;
  // year = stoi(data);
  return true;
}

//-----------------------------------------------------------------------------
// operator ==
// Description: checks if the movies are equal
// PRE: assumes that the movies exist
// POST: returns true if the movies are equal
bool Drama::operator==(const Movie &otherMovie) const {
  if (director.compare(otherMovie.getDirector()) != 0) {
    return false; // directors are different
  }
  if (title.compare(otherMovie.getTitle()) != 0) {
    return false; // titles are different
  }
  return true;
}

//-----------------------------------------------------------------------------
// operator !=
// Description: checks if the movies are not equal
// PRE: assumes that the movies exist
// POST: returns true if the movies are not equal
bool Drama::operator!=(const Movie &otherMovie) const {
  return !(*this == otherMovie);
}

//-----------------------------------------------------------------------------
// operator >
// Description: checks if the movie type, director, and title is greater
// PRE: assumes that the movies exist
// POST: returns true if the LHS movie is sorted greater than the
//       RHS movie
bool Drama::operator>(const Movie &otherMovie) const {
  if (otherMovie.getGenre().compare("C") == 0) {
    return false;
  }
  if (otherMovie.getGenre().compare("F") == 0) {
    return true;
  }
  if (director.compare(otherMovie.getDirector()) > 0) {
    return true;
  } else if (director.compare(otherMovie.getDirector()) == 0) {
    return title.compare(otherMovie.getTitle()) > 0;
  }
  return false;
}

//-----------------------------------------------------------------------------
// operator <
// Description: checks if the movie type, director, and title is lesser
// PRE: assumes that the movies exist
// POST: returns true if the LHS movie is sorted lesser than the
//       RHS movie
bool Drama::operator<(const Movie &otherMovie) const {
  if (*this == otherMovie)
    return false;
  if (*this > otherMovie)
    return false;
  return true;
}
