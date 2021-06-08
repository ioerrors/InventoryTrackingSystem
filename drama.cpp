////////////////////////////////drama.cpp file /////////////////////////////////
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

Drama::~Drama() {}

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
  //year = stoi(data);
  return true;
}

bool Drama::operator==(const Movie &otherMovie) const {
  if (director.compare(otherMovie.getDirector()) != 0) {
    return false; // directors are different
  }
  if (title.compare(otherMovie.getTitle()) != 0 ) {
    return false; // titles are different
  }
  return true;
}

bool Drama::operator!=(const Movie &otherMovie) const {
  return !(*this == otherMovie);
}

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

bool Drama::operator<(const Movie &otherMovie) const {
  if (*this == otherMovie)
    return false;
  if (*this > otherMovie)
    return false;
  return true;
}


