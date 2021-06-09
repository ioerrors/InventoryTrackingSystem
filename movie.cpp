////////////////////////////////movie.cpp file /////////////////////////////////
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

Movie::Movie() {
  genre = '`';
  mediaType = 'D';
  title = "";
  director = "";
  stock = 0;
  year = 0;
  month = 0;
}

Movie::~Movie() {}

string Movie::getTitle() const {
  // do we need this?
  return this->title;
}

string Movie::getDirector() const { return this->director; }

int Movie::getStock() const { return this->stock; }

int Movie::getReleaseYear() const { return this->year; }

bool Movie::addStock(int newStock) {
  if (newStock >= 0) {
    stock += newStock;
    return true;
  } else {
    return false;
  }
}

bool Movie::subStock(int removeStock) {
  if (stock > 0) {
    stock -= removeStock;
    return true;
  } else {
    return false;
  }
}

// will not accept actors for non classic movies
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

string Movie::getGenre() const { return this->genre; }

int Movie::getMonth() const { return this->month; }

set<string> Movie::getActors() const { return this->actorsList; }

bool Movie::setData(string movieData) { return false; }

void Movie::display() const { cout << this; }

bool Movie::operator==(const Movie &otherMovie) const {
  return otherMovie == *this;
} // check if movies are equal
bool Movie::operator!=(const Movie &otherMovie) const {
  return otherMovie != *this;
} // check if movies are not equal
bool Movie::operator>(const Movie &otherMovie) const {
  return otherMovie < *this;
} // check if this movie is greater than other movie
bool Movie::operator<(const Movie &otherMovie) const {
  return otherMovie > *this;
} // check if this movie is less than other movie
