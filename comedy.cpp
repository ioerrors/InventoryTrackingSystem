////////////////////////////////comedy.cpp file ////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a comedy class which is a type of movie
// child of the movie class, inheriting from Movie
//-----------------------------------------------------------------------------

#include "comedy.h"
#include <sstream>

//-----------------------------------------------------------------------------
// Comedy CONSTRUCTOR
// Description: creates an empty Comedy
// PRE: Memory is available for Comedy
// POST: Empty Comedy is created
Comedy::Comedy() {
  genre = "F";
  mediaType = "D";
  title = "";
  director = "";
  stock = 0;
  year = 0;
  month = 0;
}

Comedy::~Comedy() {}

string Comedy::getGenre() const { return "F"; }

//-----------------------------------------------------------------------------
// setData()
// Description: sets data fields
// PRE: Comedy exists, stock is already set using addStock()
//    input format "Rob Reiner, When Harry Met Sally, 1989"
// POST: all data fields set
bool Comedy::setData(string movieData) {
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

bool Comedy::operator==(const Movie &otherMovie) const {
  if (otherMovie.getGenre().compare("F") != 0) {
    return false; // genre is different
  }
  if (title.compare(otherMovie.getTitle()) != 0) {
    return false; // title is different
  }
  if (year != otherMovie.getReleaseYear()) {
    return false; // year released is different
  }
  return true;
}

bool Comedy::operator!=(const Movie &otherMovie) const {
  return !(*this == otherMovie);
}

bool Comedy::operator>(const Movie &otherMovie) const {
  if (otherMovie.getGenre().compare("F") != 0) {
    return false;
  }
  if (title.compare(otherMovie.getTitle()) > 0) {
    return true; // title is greater
  } else if (title.compare(otherMovie.getTitle()) == 0) {
    if (year > otherMovie.getReleaseYear()) {
      return true; // release is greater(more recent)
    }
    return false; // release is less or same
  }
  return false; // title is less
}

bool Comedy::operator<(const Movie &otherMovie) const {
  if (*this == otherMovie) {
    return false;
  }
  if (*this > otherMovie) {
    return false;
  }
  return true;
}
